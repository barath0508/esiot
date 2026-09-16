void clrscr(char ch);
void lcdinit(void);
void lcdcmd(char);
void lcddat(char);
void gotoxy(char,char); //x,y ; x-char position(0 - 16) y-line number 0 or 1
void printstr(char *,char,char);    //string,column(x),line(y)
void wait (void);
void split_numbers(unsigned int number);
void Wait_Msg(void);
void Welcome_Msg(void);
