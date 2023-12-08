/*----------------------------------------------------------------------------
 *      Arquivo:    USERCOMM.c
 *      Proposito: 	Definicoes do usuario para o driver de comunicacao
 *----------------------------------------------------------------------------
 *      Versao: 	1.00 	Prog: Ricardo T.   Data: 25/11/2014
 * 		Descricao  Versao inicial
 *----------------------------------------------------------------------------
 *      Este codigo pertence a Wyma Tecnologia e Sistemas LTDA.
 *---------------------------------------------------------------------------*/

#include		"COMM_CONFIG.h"
#include 		<stdio.h>

/*----------------------------------------------------------------------------
 *      Local variables
 *---------------------------------------------------------------------------*/
unsigned char	numFrameServer=0;

/*----------------------------------------------------------------------------
 * Funcao:		cmd_DomainName
 * Descricao 	Comando para tratamento do nome do dominio (local host name)
 * Parametros: 	fr - Estrutura com informacoes do frame recebido
 * Retorno: 	Nenhum
 -----------------------------------------------------------------------------*/
void cmd_DomainName (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_DHCP
 * Descricao 	Comando para tratamento do nome do dispositivo
 -----------------------------------------------------------------------------*/
void cmd_DHCP (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_LocalIP
 * Descricao 	Comando para tratamento do IP local
 -----------------------------------------------------------------------------*/
void cmd_LocalIP (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}


/*----------------------------------------------------------------------------
 * Funcao:		cmd_Mask
 * Descricao 	Comando para tratamento da mascara de rede
 -----------------------------------------------------------------------------*/
void cmd_Mask (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_Gateway
 * Descricao 	Comando para tratamento do gateway
 -----------------------------------------------------------------------------*/
void cmd_Gateway (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_Dns1
 * Descricao 	Comando para tratamento do DNS preferencial
 -----------------------------------------------------------------------------*/
void cmd_Dns1 (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_Ping
 * Descricao 	Comando para tratamento das informacoes do dispositivo
 -----------------------------------------------------------------------------*/
void cmd_Ping (FRMRES fr)
{
	unsigned cont;

	if (fr.cmdType=='R')
	{
		if (fr.flag==ACK)
		{
			printf ("Localizado - IP: "); cont=4;
			while (fr.dataLen-- && cont--)
			{
				printf("%d",*fr.dataBuf++);
				if (cont)
					printf(".");
			}
			printf(" MAC: "); cont=6;
			while (fr.dataLen-- && cont--)
			{
				printf("%d",*fr.dataBuf++);
				if (cont)
					printf(".");
			}

			printf(" VERSAO: "); cont=4;
			while (fr.dataLen-- && cont--)
				printf("%c",*fr.dataBuf++);

			printf(" NOME: ");
			while (fr.dataLen--)
				printf("%c",*fr.dataBuf++);

			printf("\n");
		}
		else
			printf ("Localizado - Dispositivo não aceitou comando \n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_IpBroadcast
 * Descricao 	Comando para tratamento do IP com broadcast
 -----------------------------------------------------------------------------*/
void cmd_IpBroadcast (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_Login
 * Descricao 	Comando para tratamento do Login do usuario para configuracao
 -----------------------------------------------------------------------------*/
void cmd_Login (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Login bem sucedido\n");
		else
			printf ("Erro no Login\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_Logout
 * Descricao 	Comando para tratamento do Logout do usuario para configuracao
 -----------------------------------------------------------------------------*/
void cmd_Logout (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Logout bem sucedido\n");
		else
			printf ("Erro no logout\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		cmd_DisplayShow
 * Descricao 	Comando para mostrar mensagem no display
 -----------------------------------------------------------------------------*/
void cmd_DisplayShow (FRMRES fr)
{
	if (fr.cmdType=='R')
	{
		numFrameServer=fr.idFrame;
		if (fr.flag==ACK)
			printf ("Comunicação bem sucedida\n");
		else
			printf ("Erro na comunicação\n");
	}
	else if (fr.cmdType=='S')
		send_Response (DC4, (unsigned char *)"", 0);
	else if (fr.cmdType=='G')
		send_Response (DC4, (unsigned char *)"", 0);
}

/*----------------------------------------------------------------------------
 * Funcao:		len
 * Descricao 	Verifica o tamanho do array.
 * Parametros:  *pDat - Ponteiro para o array
 * Retorno: 	numero de bytes no array.
 -----------------------------------------------------------------------------*/
unsigned short len (unsigned char *pDat)
{
	unsigned short val=0;

	while (*pDat!=0)
	{
		pDat++;
		val++;
	}
	return val;
}

/*----------------------------------------------------------------------------
 * Funcao:		doArray
 * Descricao 	Transfere bytes de valor numerico para array, otimizando o
 *				numero de bytes.
 * Parametros: *array - Ponteiro para o array de 4 bytes
 *				value - Valor a ser transferido para o array
 * Retorno: 	numero de bytes transferidos para o array.
 -----------------------------------------------------------------------------*/

unsigned char doArray (unsigned char *array, unsigned int value)
{
	unsigned char numBytes=0;

	if (value > 0xFFFFFF)  									// Valor utiliza 4 bytes da vari�vel Int
	{
		*array++=(unsigned char)(value&0xFF);
		*array++=(unsigned char)((value&0xFF00)>>8);
		*array++=(unsigned char)((value&0xFF0000)>>16);
		*array  =(unsigned char)((value&0xFF000000)>>24);
		numBytes=4;
	}
	else if (value > 0xFFFF)								// Valor utiliza 3 bytes da vari�vel Int.
	{
		*array++=(unsigned char)(value&0xFF);
		*array++=(unsigned char)((value&0xFF00)>>8);
		*array  =(unsigned char)((value&0xFF0000)>>16);
		numBytes=3;
	}
	else if (value > 0xFF)
	{
		*array++=(unsigned char)(value&0xFF);				// Valor utiliza 2 bytes da vari�vel Int
		*array  =(unsigned char)((value&0xFF00)>>8);
		numBytes=2;
	}
	else
	{
		*array=(unsigned char)value;						// Valor utiliza 1 byte da vari�vel Int
		numBytes=1;
	}

	return numBytes;
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
