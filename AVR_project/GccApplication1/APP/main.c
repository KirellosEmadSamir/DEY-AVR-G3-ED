/*
 * GccApplication1.c
 *
 * Created: 03/04/2022 10:07:52 ص
 * Author : GROUP A
 */ 
#include "BIT_MATH.h"
#include "REG.h"
#include "STD.h"
#include "DIO.h"
#include "LED.h"
#include "P_B.h"
#include "SSD.h"
#include "KEY_PAD.h"
#include "LCD.h"
#include "ADC.h"
#include "EXT_INT.h"
#include "TEMP.h"
#include "TIMER_0.h"
#include "TIMER_1.h"
//#include "TIMER_2.h"
#include "STEPPER.h"
#include "DC_MOTOR.h"
#include "WDT.h"
#include "SERVO.h"
#include "UART.h"
#include "SPI.h"
#include "AT24C16A.h"
#include "ULTRASONIC.h"


#define F_CPU 16000000UL
#include <util/delay.h>

void TIMER_0_EXC(void);
void TIMER_2_EXC(void);

void EXT_INT_EXC(void);

int main(void)
{
	H_LedInit(R_LED);
	H_LedInit(G_LED);
	H_LedInit(B_LED);
	H_LedInit(Motor_LED);
	H_LedInit(Right_LED);
	H_LedInit(Lift_LED);	
	H_LedInit(BAZER);
	H_LcdInit();
	M_UartInit();
	M_Timer0Init();
	//M_Timer2Init();


	u8 Falg_control_Blink_Led = 1 ;
		
	u8 Falg_control_LCD_State_FW =1 ;
	u8 Falg_control_LCD_State_BW =1 ;

	u8 Falg_control_CCS = 1;

	u8 Local_u8KeyPressed = 0;


					
		H_LcdGoTo(0,1);
		H_LcdWriteString("STATE : Forward");
		H_LcdGoTo(1,1);
		H_LcdWriteString("CCS : OFF");

	while(1)
	{	
		Local_u8KeyPressed = M_UartRec();	
		//H_LcdWriteCharacter(Local_u8KeyPressed);

		//******************************LEDS**************************//

		if (Local_u8KeyPressed == 'A') //Togel R_led
		{
			H_LedTog(R_LED);
		}

		
		if (Local_u8KeyPressed == 'B') //Togel Bazer
		{
			H_LedTog(BAZER);
		}		
		
		
		if (Local_u8KeyPressed == 'C') //control_Blink_Led
		{
			if (Falg_control_Blink_Led==1)
			{
				H_LedBlink(G_LED);
				/*M_Timer2SetTime(200);
				M_Timer2_SetCallBack(TIMER_2_EXC);
				M_Timer2Start();*/                                 
			}
			/*if (Falg_control_Blink_Led==0)
			{
				M_Timer2Stop();
				H_LedOff(G_LED);
			}
			Falg_control_Blink_Led = Falg_control_Blink_Led ^= 1 ; */
		}		
		
		//******************************LED_DIRICTION**************************//

		
		if (Local_u8KeyPressed == 'X') //control_Motor
		{
				H_LedTog(Motor_LED);
				H_LcdGoTo(1,7);
				H_LcdWriteString("OFF");
				Falg_control_CCS=1;
				M_Timer0Stop();			
		}	
		
		
		if (Local_u8KeyPressed == 'R') //control_Dirction_Right
		{
				H_LedTog(Right_LED);
				H_LedOff(Lift_LED);
		}			
		
		
		if (Local_u8KeyPressed == 'L') //control_Dirction_lift
		{
				H_LedTog(Lift_LED);
				H_LedOff(Right_LED);
		}	
		
		
		//******************************LCD**************************//
		
		
		if (Local_u8KeyPressed == 'D') //control_LCD_State_FW 
		{
			H_LcdGoTo(0,9);
			H_LcdWriteString("Forward ");
			if (Falg_control_LCD_State_BW==0)
			{
				H_LedOff(Motor_LED);
				Falg_control_LCD_State_BW = 1 ;
			}
			Falg_control_LCD_State_FW = 1 ;
		}			
		
		
		
		if (Local_u8KeyPressed == 'W') //control_LCD_State_BW
		{
			H_LcdGoTo(0,9);
			H_LcdWriteString("Backward");
			if (Falg_control_LCD_State_FW==1)
			{
				H_LedOff(Motor_LED);
				Falg_control_LCD_State_FW = 0 ;			
			}	
			Falg_control_LCD_State_BW = 0 ;	
		}

		//******************************CCS**************************//

			if (Local_u8KeyPressed == 'S') //control_Blink_Led
			{
				if (Falg_control_CCS==1)
				{
					H_LcdGoTo(1,7);
					H_LcdWriteString("ON ");
					M_Timer0SetTime(200);
					M_Timer0_SetCallBack(TIMER_0_EXC);
					M_Timer0Start();
				}
				if (Falg_control_CCS==0)
				{
					H_LcdGoTo(1,7);
					H_LcdWriteString("OFF");
					M_Timer0Stop();
					H_LedOff(Motor_LED);
				}
				Falg_control_CCS = Falg_control_CCS ^= 1 ;
			}	
			
	
					

	}
}
/*
void TIMER_2_EXC (void)
{
	H_LedTog(G_LED);
}
*/


void TIMER_0_EXC (void)
{
	H_UltraInit();
	H_UltraTrigger();
	H_UltraUltraRissingEdge();
	H_UltraUltraFallingEdge();
	u32 Local_u32_Distance ;
	Local_u32_Distance = H_UltraDistance();
	//H_LcdGoTo(1,12);
	//H_LcdWriteNumber(Local_u32_Distance); 

	if (Local_u32_Distance > 5)
	{
		H_LedOn(Motor_LED);
	}
	if (Local_u32_Distance <= 5)
	{
		H_LedOff(Motor_LED);
	}
}

