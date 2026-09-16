#include <LPC214x.H>           /* LPC214x definitions */
void ADCInit (void)
 {
  PINSEL1 |= 0x04000000;  /*For Channel AD0.2 is P0.29*/
  IODIR0  |= ~(0x04000000);
  AD0CR   |= 0x00200204;	 /*0x04 selects AD0.2 to mux output, 0x20 makes ADC in operational*/
  AD0GDR; 	             /*A read on AD0GDR clears the DONE bit*/
 }

void ADC_StartConversion(void)
 {
   AD0CR |= (1<<24);
 }
void ADC_StopConversion(void)
 {
   AD0CR &= (~(1<<24));
 }

unsigned int ADC_ReadChannel(void)
 {
//   unsigned int i;
   unsigned long ADC_Val, t;
   ADC_StartConversion();
   while((AD0DR2&0x80000000)==0); /*wait until ADC conversion completes*/
    if(AD0STAT & 0x00000400)
	  {
	   //printstr("OVR",0,1);
	   return(0);
	  }
   t = AD0DR2;
   ADC_Val = ((t>>6) & 0x000003FF);//(AD0DR2 & 0x000003FF); //((AD0CR>>6) & 0x000003FF);
   //ADC_StopConversion();
   return(ADC_Val);
 }
