/*----------------------------------------------------------------------------
 *      Biblioteca:	LPC176x_COMM.lib
 *      Proposito:	Biblioteca do protocolo WYMA
 *----------------------------------------------------------------------------
 *      Arquivo:    COMM_CONFIG.h
 *      Proposito: 	Arquivo de definicoes do usuario para o protocolo
 *----------------------------------------------------------------------------
 *      Versao: 	1.00 	Prog: Ricardo T.   Data: 25/04/2013
 * 		Descricao:  Versao inicial
 *----------------------------------------------------------------------------
 *      Este codigo pertence a Wyma Tecnologia e Sistemas LTDA.
 *---------------------------------------------------------------------------*/

#ifndef		__COMM_CONFIG__
#define		__COMM_CONFIG__

/*----------------------------------------------------------------------------
 *      WYMA Protocol definitions 
 *---------------------------------------------------------------------------*/
#define			STX					2 	// Inicio de frame
#define			ETX					3	// Fim do frame
#define			ACK					6	// Frame sem erros
#define 		DC1					17	// Set com valor fora do range
#define 		DC2					18	// Set com comprimento do valor incorreto
#define 		DC3					19	// Set em valor somente leitura
#define 		DC4					20	// Erro generico (nao especifico)
#define			NAK					21	// Erro na verificacao de integridade do frame

/*----------------------------------------------------------------------------
 *      WYMA Protocol Class definitions 
 *---------------------------------------------------------------------------*/
#define			CLS_ACIONADOR		1
#define			CLS_PAINELSENHA		2
#define			CLS_EMISSORSENHA	3
#define			CLS_SOFTWARE		4
#define			CLS_TECLADO			5
#define			CLS_TECLADOOPINIAO	6
#define			CLS_PAINELMENSAGEM	7
#define			CLS_MIDIA			8
#define			CLS_MEDIDOR			9

/*----------------------------------------------------------------------------
 *      WYMA protocol definitions for commands and parameters
 *---------------------------------------------------------------------------*/
#define		COMM_NETCONFIG		1
#define			_DOMAINNAME			1
#define			_DHCP				2
#define			_LOCALIP			3
#define			_MASK				5		 
#define			_GATEWAY			6
#define			_DNS1				7
#define			_PING				17
#define			_IPBC				18
#define		COMM_USER			5
#define			_LOGIN				3
#define			_LOGOUT				4
#define		COMM_DISPLAY		11
#define			_DISPLAYSHOW		8

/*----------------------------------------------------------------------------
 *      WYMA protocol interfaces definitions 
 *---------------------------------------------------------------------------*/
#define			ITF_NONE		0x00
#define 		ITF_TCP  		0x01
#define 		ITF_UDP  		0x02
#define			ITF_UART0		0x04
#define			ITF_UART1		0x08
#define			ITF_USB			0x10
#define			ITF_CAN			0x20
#define			ITF_WIFI		0x40

/*----------------------------------------------------------------------------
 *      User type definitions for protocol WYMA
 *---------------------------------------------------------------------------*/

typedef struct frmRes
{
	unsigned char	idFrame;		// header - Identificacao do frame para o remetente
	unsigned char	flag;			// header - indicacao de erro
	unsigned short 	frame;			// header - numero do frame
	unsigned short	frameNum;		// header - total de frames
	unsigned char	cmdType;		// header - tipo de comando (set, get ou response)
	unsigned char	cmdNum;			// header - numero do comando
	unsigned char	cmdSub;			// header - sub-numero do comando
	unsigned short	cmdIdx;			// header - index do comando
	unsigned short	dataLen;		// header - tamanho dos dados
	unsigned char	*dataBuf;		// Dados do frame
	unsigned char 	interface;		// Interface em que chegou o dado
}FRMRES;

/*----------------------------------------------------------------------------
 *      Exported functions
 *---------------------------------------------------------------------------*/

extern int init_SocketUdp (void);
extern void setIpClient (char *rip);

extern unsigned char sendLogin(void);
extern unsigned char sendLogout(void);
extern unsigned char sendName(char *pStr, unsigned short len);
extern unsigned char sendDhcp(unsigned char status);
extern unsigned char sendIp(char *pStr);
extern unsigned char sendMask(char *pStr);
extern unsigned char sendGateway(char *pStr);
extern unsigned char sendDns(char *pStr);
extern unsigned char receiveDiscovery(void);
extern unsigned char sendIpbc(char *pStr);
extern unsigned char sendMessage(char *pStr, unsigned short len);

extern void send_Response (unsigned char flag, unsigned char *pData, unsigned short len);
extern void check_Udp (void);

#endif

 /*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
