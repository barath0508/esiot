#include <LPC214x.h>

#define RS     0x00000400  /* P0.10 */
#define CE     0x00001800  /* P1.11 */


void clrscr(char ch);
void lcdinit(void);
void lcdcmd(char);
void lcddat(char);
void gotoxy(char,char); //x,y ; x-char position(0 - 16) y-line number 0 or 1
void printstr(char *,char,char);    //string,column(x),line(y)
void wait (void);
void split_numbers(unsigned int number);


#define SET 1
#define OFF 0

unsigned int thousands,hundreds,tens,ones;

void wait (void)  {                        /* wait function */
  int  d;
  for (d = 0; d < 100000; d++);           /* only to delay for LED flashes */
}


void lcdinit()
{
    IODIR0 |= 0x0000FFFF;
	IOCLR0 |= 0X00000FFF;
	lcdcmd(0x28);
    lcdcmd(0x28);
    lcdcmd(0x0c);
    lcdcmd(0x06);
    lcdcmd(0x01);
    lcdcmd(0x0f);
    wait();
}


void gotoxy(char x, char y)
{
    if(y == 0)
        lcdcmd(0x80+x);
    else
        lcdcmd(0xc0+x);

}


void printstr(char *str, char x, char y)
{
    char i;
    gotoxy(x,y);
    wait();//(500);
    for(i=0;str[i]!='\0';i++)
        lcddat(str[i]);

}
void lcdcmd(char cmd)
{
unsigned char LCDDAT;
	 LCDDAT = (cmd & 0xf0);       //higher nibble
	 IOSET0 = LCDDAT;
     IOCLR0 = RS;
	 IOSET0 = CE;
     wait();//(100);                           //enable lcd
	 IOCLR0 = CE;
	 IOCLR0 = 0X00000FFF;


     LCDDAT = ((cmd<<0x04) & 0xf0);            //lower nibble
	 IOSET0 = LCDDAT;
     IOCLR0 = RS;
	 IOSET0 = CE;
     wait();//(100);                           //enable lcd
	 IOCLR0 = CE;
	 IOCLR0 = 0X00000FFF;

}

void lcddat(char cmd)
{
   unsigned char LCDDAT;
	 LCDDAT = (cmd & 0xf0);       //higher nibble
	 IOSET0 = LCDDAT;
     IOSET0 = RS;
	 IOSET0 = CE;
     wait();//(100);                           //enable lcd
	 IOCLR0 = CE;
	 IOCLR0 = 0X00000FFF;

     LCDDAT = ((cmd<<0x04) & 0xf0);            //lower nibble
	 IOSET0 = LCDDAT;
     IOSET0 = RS;
	 IOSET0 = CE;
     wait();//(100);                           //enable lcd
	 IOCLR0 = CE;
	 IOCLR0 = 0X00000FFF;
 }

void clrscr(char ch)
{
    if(ch==0)
    {
        printstr("                  ",0,0);
        gotoxy(0,0);
    }
    else if(ch == 1)
    {
        printstr("                  ",0,1);
        gotoxy(0,1);
    }
    else
    {
        lcdcmd(0x01);
       // delay(100);
    }
}

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

void Wait_Msg(void)
{
 lcdcmd(0x01);
 printstr("  PLEASE WAIT   ", 0, 0);
}
void Welcome_Msg(void)
{
 lcdcmd(0x01);
 printstr("   DAC Program  ", 0, 0);
 printstr("    Executed    ", 0, 1);
}
