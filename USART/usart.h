#include<avr/io.h>

void USART_init()
{
  UBBRH=0;
  UBBRL=77.125;
  UCSRA=0X00;
  UCSRB=0b00011000;
  UCSRC=0b10000110;
   }

void transmit_int(int n)
{
 int i,n,a[];
for(i=0;n!=0;i++)
{
a[i]=n%10;
n=n/10;
}

for(i=i-1;i>0;i--)
{while(!UCSRA&(1<<UDRE));

 UDR=a[i];
}}


void transmit_char(char ch)
{
while(!UCSRA&(1<<UDRE));
   UDR=ch;
}

void transmit_string(char*s)
{
while (*s!='\0')
{
while(!UCSRA&(1<<UDRE));
  UDR=*s;
s++;
  }}
  
  
char receive_char()
{ 
while(!UCSRA&(1<<RXC));
return UDR;
}

char receive_string()
{ while(*s!='\0');


{ 
while(!UCSRA&(1<<RXC));
return UDR;

UDR=*s;
s++;
}
  

}

int receive_int()
{ 
while(!UCSRA&(1<<RXC));
return UDR;
}