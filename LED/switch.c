/*****************************************************************************************/
/* Description: This program gets DIP switch inputs and switches ON corresponding LED    */
/*              P1.16 to P1.31 are output switch                                        */

/*****************************************************************************************/

#include<LPC214x.H>
#include "lcd.h"

int main()
{
		 lcdinit();       /*Initialize lcd*/
     Wait_Msg();	   /*Display message - "Please Wait"*/
     Welcome_Msg();   /*Display message - "Welcome to SM MICRRO"*/
  	 IO1DIR = 0xFFFF0000; 			// P1.16 TO P1.31 OUTPUT PIN
	
	   while(1)
	   {
			 IOCLR1 = 0xFFFF0000; // output pin cleared for enable the led
		 }
}



