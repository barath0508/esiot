/************************************************************************************/
/* FILE       : main_ADC_Test.c                                                     */
/* AUTHOR     : Rajasekaran.K, SM Micrro System, Tamabaram, Chennai                 */
/* DESCRIPTION: This file is part of example projects given with SM Micrro system's */
/* ARM LPC2148 development Board. The example projects should be used only for      */
/* educational purpose and not for product development                              */
/************************************************************************************/
/* This is a test program to ADC in the ARM LPC2148	development board           	*/
/************************************************************************************/                                                       
#include <LPC214x.H>           /* LPC214x definitions */
#include "ADC_Driver.c"	           /* contains prototypes of driver functions*/ 
#include "lcd.c"
#include <stdio.h>

int main (void)
 {
  unsigned int adc_val;
  unsigned int temp;
  unsigned char buf[4] = {0,0,0,0};
  ADCInit();
  lcdinit();
     //wait();
  	 clrscr(10);
     printstr("ANALOGTODIGITAL",0,0);
	 wait();
  while (1) 		           /* Loop forever */
   {
	 adc_val = ADC_ReadChannel();
	 temp = (unsigned int)((3*adc_val*100)/1024);
	 sprintf(buf,"%d",temp);
	 printstr(buf,0,1);

   }                                 
  
 }




