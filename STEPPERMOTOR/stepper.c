/************************************************************************************/
/* FILE       : main_LCD_Test.c                                                   */
/* AUTHOR     : Rajasekaran.K, SM Micrro System, Tamabaram, Chennai                 */
/* DESCRIPTION: This file is part of example projects given with SM Micrro system's */
/* ARM LPC2148 development Board. The example projects should be used only for      */
/* educational purpose and not for product development                              */
/************************************************************************************/
/* This is a test program to display strings in LCD module in the ARM LPC2148		*/
/* development board itself                                                         */  
/************************************************************************************/                                                       
#include <LPC214x.H>     /* LPC214x definitions */

#define step1     0x00010000  /* P1.16 */
#define step2     0x00020000  /* P1.17 */


void wait (void) 
{                        /* wait function */
  int  d;
  for (d = 0; d < 10000; d++);           /* only to delay for LED flashes */
}

void call_stepper_forw()
{
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00040000; 
 wait(); 
 wait();  
// wait();  
 //wait();  
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00060000;
 wait(); 
 wait();  
// wait();  
// wait();  
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00070000; 
 wait(); 
 wait();  
// wait();  
// wait();  
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00050000;   
 wait(); 
 wait();  
// wait();  
// wait();  
}

/*void call_reverse(void)
{
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00050000; 
 wait(); 
 wait();  
// wait();  
 //wait();  
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00070000;
 wait(); 
// wait();  
 //wait();  
 //wait();  
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00060000; 
 wait(); 
// wait();  
 //wait();  
 //wait();  
 IOCLR1 = 0X00FF0000;
 IOSET1 = 0X00040000;   
 wait(); 
// wait();  
 //wait();  
 //wait();  
} */




int main (void)
 {  
  IODIR1 |= 0xFFFFFFFF;
	IOCLR1 |= 0X00FF0000; 
	wait();
  while(1)		  /*Loop Forever*/
    {
	  call_stepper_forw();
    //call_reverse();			
	  wait();	  	  	  	  
	//  wait();	
//	  wait(); 
	 // wait();   	   	  	  	  
	  IOCLR1 = 0X00FF0000; 	  
	}                            
 }  

