
   #include <LPC214x.h>
   #include "defs.h"
/*******************************Global variables********************************************/
   unsigned int thousands,hundreds,tens,ones;
/*******************************************************************************************/  
				
   void init_Matrix_7seg(void)
    {
      IODIR1 |= 0xff0f0000;  // set 7seg LEDs as output ports and matrix's MSB as inputs and LSB as outputs
	  IODIR0 |= S7SEG_ENB;   // set P0.19 to P0.22 as outputs to drive 7seg enable pins
	  IOPIN0 |= S7SEG_ENB;	 // since we are using active low 7 seg display, the enable signals
	                         // should be initially set to HIGH.
    }
/********************************************************************************************/
   unsigned long scan_row(unsigned int row_num)
	 {
	  //unsigned int row,i;
	  unsigned long val;
	  
	  IOSET1 = ROW_MASK;          //clear the previous scan row output ie make all row ops high
	  switch(row_num)
	   {
	    case 1: IOCLR1 = ROW1;break;  // make P1.16 low
		case 2: IOCLR1 = ROW2;break;  // make P1.17 low
		case 3: IOCLR1 = ROW3;break;  // make P1.18 low
		case 4: IOCLR1 = ROW4;break;  // make P1.19 low
		//default: row = ERR;
	   }
//	  for(i=0;i<=65000;i++);
	  val = IOPIN1;         // read the matrix inputs
	  val = ((val >> 20) & 0x0000000F)^0x0000000F; // shift the colum value so that it comes to LSB 
	                                               // XORing is done to take 1's complement of 
												   // shifted value.
	  return(val);
	 }
/*******************************************************************************************/
   unsigned int catch_key(void)
    {
	 unsigned long v;
	 v = scan_row(1);	      
	 switch(v)
	  {
	   case 1: return(13);
	   case 2: return(14);
	   case 4: return(15);
	   case 8: return(16); 
	  }
     v = scan_row(2);
	 switch(v)
	  {
	   case 1: return(9);
	   case 2: return(10);
	   case 4: return(11);
	   case 8: return(12); 
	  }
     v = scan_row(3);
	 switch(v)
	  {
	   case 1: return(5);
	   case 2: return(6);
	   case 4: return(7);
	   case 8: return(8); 
	  }
     v = scan_row(4);
	 switch(v)
	  {
	   case 1: return(1);
	   case 2: return(2);
	   case 4: return(3);
	   case 8: return(4); 
	   default: return(0);
	  }
	}
/******************************************************************************************/   
   void clearall_7seg(void)
    {
	   IOPIN1 &= ~S7SEG_LED;  // make all the 7seg led pins to LOW 
	   IOPIN0 |= S7SEG_ENB	  // Disable all the 7 seg display
	}
/*****************************************************************************************/
   void clearDigit_7seg(int digit_num)
    {
	   IOPIN0 |= S7SEG_ENB; // clear enables first
	   switch(digit_num)
	    {
	     case 1: {
		         IOPIN0 = ~DIGI1_ENB;	 // now enable only the digit1
	             break;
				 }
	     case 2: {
		         IOPIN0 = ~DIGI2_ENB;	 // now enable only the digit2
	             break;
				 }
	     case 3: {
		         IOPIN0 = ~DIGI3_ENB;	 // now enable only the digit3
	             break;
				 }
	     case 4: {
		         IOPIN0 = ~DIGI4_ENB;	 // now enable only the digit4
	             break;
				 }
	    }
	   IOPIN1 &= ~S7SEG_LED;   // make all the 7seg LED pins LOW
	}
/******************************************************************************************/
   void Digit_Dispay(int digit_num, unsigned int value)
     {
	   clearDigit_7seg(digit_num);
	   switch(value)
	    {
		  case 0:  IOPIN1 |= ZERO;break;
		  case 1:  IOPIN1 |= ONE; break;
		  case 2:  IOPIN1 |= TWO; break;
		  case 3:  IOPIN1 |= THREE; break;
		  case 4:  IOPIN1 |= FOUR; break;
		  case 5:  IOPIN1 |= FIVE; break;
		  case 6:  IOPIN1 |= SIX; break;
		  case 7:  IOPIN1 |= SEVEN; break;
		  case 8:  IOPIN1 |= EIGHT; break;
		  case 9:  IOPIN1 |= NINE; break;
		}
	 }
/******************************************************************************************/
   void Alpha_Dispay(int digit_num, unsigned int value)
     {
	   clearDigit_7seg(digit_num);
	   switch(value)
	    {
		  case 1:  IOPIN1 |= ZERO;break;
		  case 2:  IOPIN1 |= ONE; break;
		  case 3:  IOPIN1 |= TWO; break;
		  case 4:  IOPIN1 |= THREE; break;
		  case 5:  IOPIN1 |= FOUR; break;
		  case 6:  IOPIN1 |= FIVE; break;
		  case 7:  IOPIN1 |= SIX; break;
		  case 8:  IOPIN1 |= SEVEN; break;
		  case 9:  IOPIN1 |= EIGHT; break;
		  case 10:  IOPIN1 |= NINE; break;
		  case 11: IOPIN1 |= AAA; break;
		  case 12: IOPIN1 |= bbb; break;
		  case 13: IOPIN1 |= ccc; break;
		  case 14: IOPIN1 |= ddd; break;
		  case 15: IOPIN1 |= eee; break;
		  case 16: IOPIN1 |= fff; break;
		}
	 }
/*******************************************************************************************/
   void split_numbers(unsigned int number)
    {
     thousands = (number /1000);
     number %= 1000;
     hundreds = (number / 100);
     number %= 100;
     tens = (number / 10);
     number %= 10;
     ones = number ;
    }
/*******************************************************************************************/
   void Display_Number(unsigned int num)
    {
	 unsigned int i;
	 if(num <= 9999)
	 { 									 
	  clearall_7seg();
	  split_numbers((unsigned int)num);
	  Digit_Dispay(4, ones);
	  for(i=0;i<10000;i++);
	  Digit_Dispay(3, tens);
	  for(i=0;i<10000;i++);
	  Digit_Dispay(2, hundreds);
	  for(i=0;i<10000;i++);
	  Digit_Dispay(1, thousands);
	  for(i=0;i<10000;i++);
	 }

	}
    

