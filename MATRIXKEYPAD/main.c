/*****************************************************************************************/
/* Description: This program gets input from Matrix key board and displays corresponding */
/*              Key value in 7segment display. Hence this prohram demonstrates both      */
/*              7 segment display as well as Matrix key board.                           */
/*              P1.16 to P1.23 are inputs from matrix key board,                         */
/*              P1.24 to P1.31 are outputs to 7 segment display                          */
/*****************************************************************************************/
/*              ------- matrix key board description----------                           */
/*             --        --        --        --                                          */
/*  row1    --| c |-- --| d |-- --| e |-- --| F |--    (SW1,SW2,SW3,SW4)                 */
/*             --        --        --        --                                          */
/*             --        --        --        --                                          */
/*  row2    --| 8 |-- --| 9 |-- --| A |-- --| b |--    (SW5,SW6,SW7,SW8)                 */
/*             --        --        --        --                                          */
/*             --        --        --        --                                          */
/*  row3    --| 4 |-- --| 5 |-- --| 6 |-- --| 7 |--     (SW9,SW10,SW11,SW12)             */
/*             --        --        --        --                                          */
/*             --        --        --        --                                          */
/*  row4    --| 0 |-- --| 1 |-- --| 2 |-- --| 3 |--     (SW13,SW14,SW15,SW16)            */
/*             --        --        --        --                                          */
/*****************************************************************************************/
#include <LPC214x.h>
#include "mat_7seg.h"
#include "lcd.h"

int main()
{
 unsigned int key, last_key, Disp_key;
  init_Matrix_7seg();   // Initialize matrix keyboard and 7segment dispaly
 clearall_7seg();	   // clear 7 segment display
 last_key = 0;		   // Initialize this variable to zero

  while(1)
    {
	  key = catch_key();    // scan for a valid key press
	  if(key != 0)			// zero means no key is pressed
	  {
	   if(key != last_key)  // check whether the same key is pressed again(assume this as STEP1)
	    {
		 Disp_key = key;	// valid new key is stored in another variable 
	     last_key = key;    // this variable's value is used for STEP1
	    }
	  }
	  //Display_Number(Disp_key);   /*this function is used to display number in decimal format*/
	  Alpha_Dispay(4,Disp_key);	    /*this function is used to display number in hex format (single digit only)*/
	}
	  
}

