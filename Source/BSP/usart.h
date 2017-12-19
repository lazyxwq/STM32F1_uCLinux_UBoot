#ifndef _USART_H
#define _USART_H
#include <includes.h>
#include "header.h"
#define USART1_BPS	115200

struct Usart_Driver
{	
	// ����һ֡����
	uint8 (* write)(uint8 *buf, uint32 len);
	
	// ����һ֡����,0:�ɹ�����һ֡ 1:���ղ��ɹ�
	uint8 (* read)(uint8 *buf, uint32 *len);
	
	// ��ս��ջ�����
	uint8 (* flush)(void);
};

void USART1_Configuration(uint32 bps);
void USART3_Configuration(uint32 bps);
void USART4_Configuration(uint32 bps);
void FSMC_CPLD_Init(void);

void Usart232SendData(uint8 data);
void Usart422SendByte(uint8 data);


void Uart4SendData(uint8 data);
void Uart4SendBuf(uint8 *Buf,uint8 len);
void my_print(u8* str);

extern const struct Usart_Driver usart_232_driver;
extern const struct Usart_Driver usart_422_driver;

/***********************************************************
// �÷�˵��

��main()�����ж�uart0���г�ʼ��
	uart0_driver->init();
	
	// ��������
	uart0_driver->write(cmd, len);
	
	// ��������,����ϳ�ʱ����ʹ��
	while (1) {
		if (uart0_driver->read(cmd, *len) != 0)
			break; // ���յ�����
			
		// δ���յ�����,��������
		.......................
	}
	
	// ���ճ�ʱ�˳�
	.....................

***********************************************************/


#endif
