#ifndef _VARIABLE_H
#define _VARIABLE_H 
/***********************************************************
* �� �� ����variable.h 
 
* ��    �������ļ�ΪWEKK231�������������õ���ȫ�ֱ���������

* ��    �ߣ�������

* ������ڣ�2012��4��30�� 11:58:51
***********************************************************/

#include "header.h"


typedef unsigned char  uint8;    /* �޷���8λ���ͱ��� */
typedef signed   char  int8;     /* �з���8λ���ͱ��� */
typedef unsigned short uint16;   /* �޷���16λ���ͱ��� */
typedef signed   short int16;    /* �з���16λ���ͱ��� */
typedef unsigned long   uint32;  /* �޷���32λ���ͱ��� */
typedef signed   long   int32;   /* �з���32λ���ͱ��� */
typedef float          fp32;     /* �����ȸ�������32λ���ȣ� */
typedef double         fp64;     /* ˫���ȸ�������64λ���ȣ� */


extern volatile uint8 g_vucControllerTest;//0������̬��0xAB�����뵽����ָ��

extern volatile uint8 g_ucPcCmdType;
extern uint8 gDBFRecvflag; // ����DBF���ݽ���
extern uint8 gDBFSendBSTflag; // ��DBF D7/D8����ģʽ�·���BST����
extern volatile int32 g_vulPsamRetStatus;	//psam����״̬
extern volatile uint8 g_vucPcOrder;	        //��¼��λ����ָ������
extern volatile uint32 g_vulCurtime;
extern volatile uint8 g_vucPsamCommandType;	//psam��������
extern volatile uint8 g_vucControllerTest;
extern volatile uint8 g_vucLogInShow;
extern volatile uint8 g_vucHeartflag;
extern volatile uint8 g_vucPowerOnFlag; // �ϵ緵�ر�־λ���ϵ緢��B0ָ����ϵ�������û���յ���λ���ĳ�ʼ��ָ��ǰ������һ���������λ������B0����֡��
extern uint32 g_ulMacId;
extern volatile uint8 g_vucPhyType;
extern volatile uint8 g_vucCmdTarget;
extern uint8 llcVSI; // LLC������ֶ�
extern uint8 gLlcSendInterval; 
extern volatile uint8 g_vucDownloadFlag;
extern volatile uint8 g_vucRfv4DataFlag;
extern volatile uint32 g_vucPsam1Ok; 
extern volatile uint32 g_vucPsam2Ok;
extern volatile uint8 g_vucSdOk;


extern volatile uint32 g_vulSdCount;//SD��д��������
extern volatile uint32 g_vulSdTimes;//���״�����¼
extern volatile uint32 g_vulSdDownInforLen;//д��SD�������������ݳ���
extern volatile uint32 g_vulSdUpInforLen;//д��SD�������������ݳ���
extern volatile uint32 g_vulSdWriteInforLen;//д��SD�����ڷ�����λ�����ݳ���
extern volatile uint32 g_vulSdReceiveInforaLen;//д��SD�����ڽ�����λ�����ݳ���
extern volatile uint8 g_vucCrcFlag; //CRC��ʶ
extern uint32 g_ulSLen; 
extern uint32 g_ulTLen; 
extern volatile uint8 g_vucSendFlag; //���ͱ�ʶ��ʶ

extern uint8 a_ucSBuf[];
extern uint8 a_ucTBuf[];
extern uint8 g_cRfv4DataBuf[];
extern uint8 a_ucVInforBuf[]; // ������Ϣ����
extern uint8 a_ucRsuControllerVerInfoBuf[]; // ����汾
extern uint8 a_ucRsuVerInfoBuf[];
extern uint8 a_ucRsuRfv4Buf[];

//  ����ϵͳ
extern uint8 g_uint8RSUVerInfo[]; // ������汾
extern uint8 g_uint8CTRLVerInfo[]; // �������ӳ���汾

extern uint8 a_ucSdDownInforBuf[]; //SD��������Ϣ�������л���
extern uint8 a_ucSdUpInforBuf[]; //SD��������Ϣ�������л���

extern uint8 a_ucSdWriteInforBuf[]; //SD��������Ϣ���ڷ�����λ������
extern uint8 a_ucSdReceiveInforBuf[]; //SD��������Ϣ���ڽ�����λ������

extern uint8 a_ucSDReadBuf[];
extern uint8 a_ucSDWriteBuf[];

extern uint8 a_ucShowinforBuf[10];
extern uint8 a_ucTransInforBuf[10];
extern volatile uint8 g_vucShowInforLen;
extern volatile uint8 g_vucShowInforType; // ��ʾ��Ϣ��־
#endif  
