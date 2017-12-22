#include<avr/io.h>
#include"usart.h"
#include<util/delay.h>

int main()
{
  int i,j;
  int in;
  
  DDRC=0b11111111;
  USART_init();
  
  
  
while(1)
{
  in=receive_int()-48;
  
  if (ch=='a')
  {
    while(1)
   {
     PORTC = 0b11111111;
	 _delay_ms(1000);
	 PORTC = 0b00000000;
	 _delay_ms(1000);
    } 
  }
  
  else if (ch=='b')
  { 
  /* while(1)
   {
     for(i=1;i<=128;i=i*2)
	 {
	   PORTC = i;
	   _delay_ms(1000);
	 }
    } */
	PORTC=0x06;
  }
  
  else if(ch=='c')
  { 
    while(1)
	{ 
	  for(i=0,j=128;i<128,j>0;i=i*2,j=j/2)     
	  {
	    PORTC = i+j;
	    _delay_ms(1000);
	  }
    } 
	//PORTC=0x04;
  }
  
  else PORTC=0b01010101; 
 }
}