CODE
#include<reg51.h> #define Icd_data P2
sbit lcd
_rs
= P2^0;
sbit
lcd
Len = P211;
sbit m1=P1^0; sbit m2=P1^1;
Oy
void delay(unsignedint t)
{unsignedint ij ;
for(i=0;i<ti++) for(j=0;j<1275;j++);
}
void tx(unsignedchar*tx)
{
for;*tx =! 10';tx++)
S BU F= *t x ; while(TI = 0);
TI-0; }
}
void sertx(unsignedchar tx)
{SBUF-Ix; while(TI
= 0); TI-0;
}
unsignedchar receiver 
{unsignedchar rx;
while(RI==0)
rx=SBUF;
RI=0; return rx;
}
void lcdcmd (unsignedchar value)
{
lcd_data=value&(0xf0); //send msb 4bits
Icd_rs=0; //select command register
lcd_en=1; //enable the led to execute command
delay(3);
led_en=0;
Icd_data=((value<<4)&(0xfO)); //send Isb 4bits
lcd_rs=0; //select command register lcd_en=1;
//enable the Icd to execute command
delay (3);
            lcd_en=0;
}
void lcd _init(void)
{
Icdcmd(0x02);

Icdcmd(0x02); lcdcmd(0x28); //intialise the lcd
i 4 bit mode*/ lcdcmd(0x28); //intialise the lcd
in 4 bit mode*/
Icdcmd(0x0e);
//cursor blinking Icdcmd(0x06);
//move the cursor to right side
Icdcmd(0x01);
//clear the lcd
}
void lcddata(unsignedchar value)
{
Icd_data=value&(0xf0); /send msb 4bits
lcd _rs=1; //select data register lcd_en=1;
//enable the lcd to execute data
delay(3);
lcd_en=0;
      lcd_data=value&(0xf0); //send lsb 4bits
Icd_rs=1; //select data register lcd_en=1; //enable the Icd to execute data
delay(3); 
lcd_en=0;
delay(3);
}
void msgdisplay(unsignedchar b[]) / send string to lcd
{
unsignedchar s,count1=0; for(s=0;b[s]!=10;++) {
count1++;    if(s==16)
lcdmd(0xc0);  if(s==32)
{
lcdcmd(1);
count 1=0;
 }
Icddata(b[s]);
}
}
void main {unsignedchar
rcv,str [30];
unsignedint i=0;
TMOD=0×20;
TH1=0xFD; //9600 baud rate SCON-0x50; TR1=1;
lcd init();
msgdisplay(" GSM BASED DOOR");  lcdmd()xc(); 
msgdisplay(" OPEN
AND CLOSE ");
 tx"ATtr\n"); delay(350);
//
do {
// rev=receive); // } while(rcv
!= 'K'); tx("AT&Wr\n"); delay(350);

tx("AT+CMGF=1\r\n"); delay(350); / / do {
// rev-receive;
/ while(rev=! 'K');
tx"AT+CNMI=1,2,0,0\r\n");  delay(350);
// do {
rev=receive): }
while(rev !-'K');
tx(“AT+CGMGS=\”9177087303\”r\n”);   tx(“GSM MODEM INTIALIZED\r\n”);    tx(“GSM MODEM INTIALIZED\r\n”);
sertx(0x1A);

while(1);
{ 
do
  { 
     rcv = receive();
}
while( rcv ! =‘*’);
sertx(rcv);

    rcv=receive();
sertx(rcv);

        if(rcv==‘1’)
{
         lcdmd(0x01);
msgdisplay("DOOR OPEN.");
m1=1; m2=0;
delay(200);  m1=m2=0;
lcdmd(0x01);
}

if(rcv==‘2’)
{
lcdmd(0x01);
msgdisplay("DOOR CLOSE.");
 m1=0;
m2=0;
delay(200);
m1=m2=0;
Icdcmd(0x01);
}
}
}CODE
#include<reg51.h> #define Icd_data P2
sbit lcd
_rs
= P2^0;
sbit
lcd
Len = P211;
sbit m1=P1^0; sbit m2=P1^1;
Oy
void delay(unsignedint t)
{unsignedint ij ;
for(i=0;i<ti++) for(j=0;j<1275;j++);
}
void tx(unsignedchar*tx)
{
for;*tx =! 10';tx++)
S BU F= *t x ; while(TI = 0);
TI-0; }
}
void sertx(unsignedchar tx)
{SBUF-Ix; while(TI
= 0); TI-0;
}
unsignedchar receiver 
{unsignedchar rx;
while(RI==0)
rx=SBUF;
RI=0; return rx;
}
void lcdcmd (unsignedchar value)
{
lcd_data=value&(0xf0); //send msb 4bits
Icd_rs=0; //select command register
lcd_en=1; //enable the led to execute command
delay(3);
led_en=0;
Icd_data=((value<<4)&(0xfO)); //send Isb 4bits
lcd_rs=0; //select command register lcd_en=1;
//enable the Icd to execute command
delay (3);
            lcd_en=0;
}
void lcd _init(void)
{
Icdcmd(0x02);

Icdcmd(0x02); lcdcmd(0x28); //intialise the lcd
i 4 bit mode*/ lcdcmd(0x28); //intialise the lcd
in 4 bit mode*/
Icdcmd(0x0e);
//cursor blinking Icdcmd(0x06);
//move the cursor to right side
Icdcmd(0x01);
//clear the lcd
}
void lcddata(unsignedchar value)
{
Icd_data=value&(0xf0); /send msb 4bits
lcd _rs=1; //select data register lcd_en=1;
//enable the lcd to execute data
delay(3);
lcd_en=0;
      lcd_data=value&(0xf0); //send lsb 4bits
Icd_rs=1; //select data register lcd_en=1; //enable the Icd to execute data
delay(3); 
lcd_en=0;
delay(3);
}
void msgdisplay(unsignedchar b[]) / send string to lcd
{
unsignedchar s,count1=0; for(s=0;b[s]!=10;++) {
count1++;    if(s==16)
lcdmd(0xc0);  if(s==32)
{
lcdcmd(1);
count 1=0;
 }
Icddata(b[s]);
}
}
void main {unsignedchar
rcv,str [30];
unsignedint i=0;
TMOD=0×20;
TH1=0xFD; //9600 baud rate SCON-0x50; TR1=1;
lcd init();
msgdisplay(" GSM BASED DOOR");  lcdmd()xc(); 
msgdisplay(" OPEN
AND CLOSE ");
 tx"ATtr\n"); delay(350);
//
do {
// rev=receive); // } while(rcv
!= 'K'); tx("AT&Wr\n"); delay(350);

tx("AT+CMGF=1\r\n"); delay(350); / / do {
// rev-receive;
/ while(rev=! 'K');
tx"AT+CNMI=1,2,0,0\r\n");  delay(350);
// do {
rev=receive): }
while(rev !-'K');
tx(“AT+CGMGS=\”9177087303\”r\n”);   tx(“GSM MODEM INTIALIZED\r\n”);    tx(“GSM MODEM INTIALIZED\r\n”);
sertx(0x1A);

while(1);
{ 
do
  { 
     rcv = receive();
}
while( rcv ! =‘*’);
sertx(rcv);

    rcv=receive();
sertx(rcv);

        if(rcv==‘1’)
{
         lcdmd(0x01);
msgdisplay("DOOR OPEN.");
m1=1; m2=0;
delay(200);  m1=m2=0;
lcdmd(0x01);
}

if(rcv==‘2’)
{
lcdmd(0x01);
msgdisplay("DOOR CLOSE.");
 m1=0;
m2=0;
delay(200);
m1=m2=0;
Icdcmd(0x01);
}
}
}