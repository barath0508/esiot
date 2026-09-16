#include<LPC214X.H>
#include "lcd.h"

void wait_long (void) 
{                        /* wait function */
  int  d;
  for (d = 0; d < 1000000; d++);           /* only to delay */
}

int main()
 {
	lcdinit();       /*Initialize lcd*/
  Wait_Msg();	   /*Display message - "Please Wait"*/
  Welcome_Msg();   /*Display message - "Welcome to SM MICRRO"*/
	wait_long();
	wait_long();	
	IODIR0 = 0X00000FFF;
	IODIR1 = 0XFFFF0000;
	IOSET0 = 0XFFFFFFFF;	
	IOCLR1 = 0XFFFF0000;	
    PINSEL1 |= 0x00080000;  //Enable pin 0.25   as DAC   
//	DACR = 0X00017FC0;		// 000 = 0V(min),7FC = 1.6V,FFF = 3.3V(max)
	DACR = 0X00010000;
	while(1);
}


