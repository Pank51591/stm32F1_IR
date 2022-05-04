
// 基本定时器TIMx,x[6,7]定时应用
#include "stm32f10x.h"
#include "sys.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h"
//#include "bsp_IR.h"
#include "bsp_usart_dma.h"


volatile uint32_t time = 0; // ms 计时变量 

extern uint8_t Remote;

int main(void)
{
	Systick_Init();
	
  GENERAL_TIM_Init(); 
	
	USART_Config();
	
	printf("初始化成功！开始监测红外！\r\n");
	
	while(1){
		if( Remote != 0 )              //如果变量里面有值则代表收到遥控按键了，如果有遥控按键值为0就需要改Remote的初始值和这里的判断了  
        {
            Remote_Scan(Remote);     //遥控按键处理
        }  
		
	}

}
/*********************************************END OF FILE**********************/

