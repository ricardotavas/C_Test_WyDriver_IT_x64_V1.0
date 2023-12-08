/*
 ============================================================================
 Name        : Test_Wydriver.c
 Author      : Ricardo Tavares
 Version     :
 Copyright   : Este programa pertence a Wyma Tecnologia
 Description : Software para teste do Wydriver
 ============================================================================
 */

#include "COMM_CONFIG.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern unsigned char	numFrameServer;
unsigned char 			numFrame=0;
unsigned char 			lastNumFrame;

unsigned short getLength (char *s)
{
	int i, n=0;
	for (i=0 ; s[i]!='\0'; i++) n++;
	return n;
}

void help (void)
{
	printf ("/q\t\tTermina o programa\n");
	printf ("discovery\tLista os dispositivos encontrados na rede\n\n");
	printf ("setipbc\t\tConfigura um novo IP no display com o MAC\n");
	printf ("\t\tsintaxe: setipbc=116.214.117.0.0.1 192.168.0.1 \n\n");

	printf ("useip\t\tFornece o ip em uso para os comandos set abaixo: \n");
	printf ("\t\tsintaxe: useip=192.168.0.1\n\n");

	printf ("login\t\tLogin - Modo configuracao de rede \n");
	printf ("login\t\tLogout - Sai do modo configuracao \n\n");


	printf ("setname\t\tConfigura um nome de domínio no display\n");
	printf ("\t\tsintaxe: setname=dsp1 \n");
	printf ("setdhcp\t\tConfigura o status de busca de IP no servidor dhcp, onde 0=Desligado e 1=Ligado\n");
	printf ("\t\tsintaxe: setdhcp=1 \n");
	printf ("setip\t\tConfigura um novo IP no display\n");
	printf ("\t\tsintaxe: setip=192.168.0.1 \n");
	printf ("setmask\t\tConfigura a mascara de rede no display\n");
	printf ("\t\tsintaxe: setmask=255.255.255.0 \n");
	printf ("setgate\t\tConfigura o IP do gateway no display\n");
	printf ("\t\tsintaxe: setgate=192.168.0.1 \n");
	printf ("setdns\t\tConfigura o IP do servidor DNS no display\n");
	printf ("\t\tsintaxe: setdns=192.168.0.1 \n");
	printf ("setmsg\t\tEnvia uma mensagem para o display\n");
	printf ("\t\tsintaxe: setmsg=mensagem \n");
}

int main(void)
{
	char *p;
	int i;
	char data [255];

	init_SocketUdp ();							// Inicializa socket UDP
	printf ("\n\nTest_Wydriver\nPara obter ajuda digite /h\n\n");

	while (1)
	{
		for (i=2 ; i<255 ; i++)					// Limpa array
			data[i]=0;

		printf ("cmd:> ");
		i = scanf ("%s",data);					// Aguarda usuário digitar mensagem
		data[254]=0;							// Garante o indicador de fim de texto

		if (strcmp(data,"/q")==0)
		{
			puts(" ok");
			exit (EXIT_SUCCESS);				// Finaliza thread main
		}
		else if (strcmp(data,"/h")==0)
		{
			puts(" ok");
			help();								// Mostra ajuda
		}
		else
		{
			if (strcmp(data,"discovery")==0)
			{
				numFrame = receiveDiscovery ();	// Envia comando para descoberta de dispositivos
			}
			else if ((p=strstr(data,"setipbc=")))// Localiza substring "setipbc="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendIpbc (&data[8]);	// Configura o IP do dispositivo remoto com o MAC
			}
			else if ((p=strstr(data,"useip=")))	// Localiza substring "useip="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					setIpClient (&data[6]);		// Configura o IP em uso
				puts(" ok");
			}
			else if ((p=strstr(data,"login")))// Localiza substring "login"
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendLogin ();	// Login para modo de configuracao
			}
			else if ((p=strstr(data,"logout")))// Localiza substring "logout"
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendLogout ();	// Logout - sai do modo configuracao
			}
			else if ((p=strstr(data,"setname=")))// Localiza substring "setname="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendName (&data[8],
						getLength(&data[8]));	// Configura o nome do domínio no display
			}
			else if ((p=strstr(data,"setdhcp=")))// Localiza substring "setdhcp="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendDhcp (data[8]);	// Configura o IP em uso
			}
			else if ((p=strstr(data,"setip=")))	// Localiza substring "setip="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendIp (&data[6]);	// Configura o IP no dispositivo
			}
			else if ((p=strstr(data,"setmask=")))// Localiza substring "setmask="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendMask (&data[8]);	// Configura a mascara de IP no dispositivo
			}
			else if ((p=strstr(data,"setgate=")))// Localiza substring "setgate="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendGateway (&data[8]);	// Configura o IP do gateway no dispositivo
			}
			else if ((p=strstr(data,"setdns=")))// Localiza substring "setdns="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendDns (&data[7]);	// Configura o IP do DNS no dispositivo
			}
			else if ((p=strstr(data,"setmsg=")))// Localiza substring "setmsg="
			{
				if ((p-data)==0)				// Se encontrou a substring na posição 0
					numFrame = sendMessage (&data[7-2], getLength(&data[7-2]));
			}
			else
			{
				puts(" Ajuda: /h\n");
			}

			if (numFrame!=lastNumFrame)			// Verifica resposta
			{
				i=5;
				while (i--)
				{
					sleep(1);

					check_Udp ();
					if (numFrame==numFrameServer)
						break;
				}
				lastNumFrame=numFrame;
			}
		}
	}

	exit (EXIT_SUCCESS);					// Finaliza thread main
}
