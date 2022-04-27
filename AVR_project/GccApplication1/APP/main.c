/*
 * GccApplication1.c
 *
 * Created: 03/04/2022 10:07:52 ص
 * Author : dell
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
#include "STEPPER.h"
#include "DC_MOTOR.h"
#include "WDT.h"
#include "SERVO.h"
#include "UART.h"
#include "SPI.h"
#include "AT24C16A.h"
void EXT_INT_EXC(void);
void TIMER_0_EXC(void);

#define F_CPU 16000000UL
#include <util/delay.h>



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

	u8 Falg_control_Blink_Led = 1 ;
	
	u8 Falg_control_Motor = 1 ;
	u8 Falg_control_Dirction_Right = 1 ;
	u8 Falg_control_Dirction_lift = 1 ;
	
	u8 Falg_control_LCD_State_FW =1 ;
	u8 Falg_control_LCD_State_BW =1 ;
	
	u16 Local_u8KeyPressed = 0 ;
					

	while(1)
	{	
		
		Local_u8KeyPressed = M_UartRec();
		H_LcdGoTo(0,1);
		H_LcdWriteString("STATE : Forward");
		H_LcdGoTo(1,1);
		H_LcdWriteString("CCS : OFF");		
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
			if (Falg_control_Blink_Led==1){H_LedBlink(G_LED);}
			if (Falg_control_Blink_Led==0){H_LedOff(G_LED);}	
			Falg_control_Blink_Led = Falg_control_Blink_Led ^= 1 ;
		}		
		
		//******************************LED_DIRICTION**************************//

		
		if (Local_u8KeyPressed == 'X') //control_Motor
		{
			if (Falg_control_Motor==1)
			{
				H_LedOn(Motor_LED);
			}
			if (Falg_control_Motor==0)
			{
				H_LedOff(Motor_LED);
			}			
			Falg_control_Motor = Falg_control_Motor ^= 1 ;
		}	
		
		
		if (Local_u8KeyPressed == 'R') //control_Dirction_Right
		{
			if (Falg_control_Dirction_Right==1)
			{
				H_LedOn(Right_LED);
				H_LedOff(Lift_LED);
			}
			if (Falg_control_Dirction_Right==0)
			{
				H_LedOff(Right_LED);
			}			
			Falg_control_Dirction_Right = Falg_control_Dirction_Right ^= 1 ;
		}			
		
		
		if (Local_u8KeyPressed == 'L') //control_Dirction_lift
		{
			if (Falg_control_Dirction_lift==1)
			{
				H_LedOn(Lift_LED);
				H_LedOff(Right_LED);
			}
			if (Falg_control_Dirction_lift==0)
			{
				H_LedOff(Lift_LED);
			}			
			Falg_control_Dirction_lift = Falg_control_Dirction_lift ^= 1 ;
		}	
		
		
		//******************************LCD**************************//
		
		
		if (Local_u8KeyPressed == 'D') //control_LCD_State_FW 
		{
			H_LcdGoTo(0,9);
			H_LcdWriteString("Forward ");
			if (Falg_control_LCD_State_FW==1)
			{
				H_LedOff(Motor_LED);
				Falg_control_Motor = Falg_control_Motor ^= 1 ;
			}
			Falg_control_LCD_State_FW = Falg_control_LCD_State_FW ^= 1 ;
		}			
		
		
		
		if (Local_u8KeyPressed == 'W') //control_LCD_State_BW
		{
			H_LcdGoTo(0,9);
			H_LcdWriteString("Backward");
			if (Falg_control_LCD_State_BW==1)
			{
				H_LedOff(Motor_LED);
				Falg_control_Motor = Falg_control_Motor ^= 1 ;				
			}	
			Falg_control_LCD_State_BW = Falg_control_LCD_State_BW ^= 1 ;	
		}

		//******************************CCS**************************//

		
		
				
	
					

	}
}



