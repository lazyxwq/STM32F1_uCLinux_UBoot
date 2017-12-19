
/***********************************************************
* �� �� ����main.c 
 
* ��    ��������������

***********************************************************/


#include <includes.h>		 
#include "header.h"
#include "core_cm3.h"
#include "setup.h"

#pragma import(__use_no_semihosting)

#pragma diag_suppress 870 

 
/******************************************************************************  
*��׼����Ҫ��֧�ֺ���  
******************************************************************************/  
_sys_exit(int x)  
{  
   x = x;  
}
void (*theKernel)(int zero, int arch, unsigned int param);	//�˶��������ڱ��ļ��Ŀ�ͷ��wyw,20131225


extern void SystemInit(void);
u8 *g_strShowBoot = "Boot��������";
u8 *g_strShowUpdate = "Ӧ�ó���";
#if 1						
u8 *g_strShowJump = "��ת���ں�����"; 	
#else
u8 *g_strShowJump = "Try jump to the kernel \r\n";
#endif

u8 *g_strShowInfo = "Ӧ�ó������";
u8 *g_strShow = "Try to junmp to the kernel";
#if   BOOTSTART_InOrOut
char *g_strCmdLine = "noinitrd root=mtd1 ro rootfstype=jffs2 init=/linuxrc console=ttyS0";
#else
char *g_strCmdLine = "init=/linuxrc console=ttyS0";
#endif
int main (void)
{		 
	
	/*
	 * ��ʼ��Ӳ������
	 */
	/* SYSCLK, HCLK, PCLK2 and PCLK1 configuration -----------------------------*/
	SystemInit();

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2|RCC_APB1Periph_TIM4, ENABLE); // TIM2��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE); // TIM2��ʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

	GPIO_Configuration(); // ��� GPIO����
	GPIO_SetBits(GPIOB,GPIO_Pin_0);

	FSMC_SRAM_Init(); // SRAM��ʼ��
	FSMC_NOR_Init(); // NOR��ʼ��	
	
	USART1_Configuration(USART1_BPS); // RS232����						 	 		

	setup_start_tag();
	//setup_memory_tags();
	setup_commandline_tag(g_strCmdLine);
	setup_end_tag();
		
	theKernel = (void (*)(int, int, unsigned int))((uint32_t)KernelStartAddrss);
	theKernel(0, 2189, ((uint32_t)TagStartAddress));

	
	while (1) 
	{
		
	}                                 
}
