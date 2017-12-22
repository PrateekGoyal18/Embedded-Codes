#include<avr/io.h>
#include"usart.h"
#include<util/delay.h>

int main()
{
  //int i,j;
  int i;
  
  DDRC=0b11111111;
  USART_init();
  
  
  
while(1)
{
  i=receive_int()-'0';
  
  if (i==1)
  {
    //while(1)
   //{
     PORTC = 0b11111111;
	 //_delay_ms(1000);
	 //PORTC = 0b00000000;
	 //_delay_ms(1000);
    // } 
  }
  
  else if (i==2)
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
  
  else if(i==3)
  { 
    /* while(1)
	{ 
	  for(i=0,j=128;i<128,j>0;i=i*2,j=j/2)     
	  {
	    PORTC = i+j;
	    _delay_ms(1000);
	  }
    } */
	PORTC=0x04;
  }
  
  else PORTC=0b01010101; 
 }
}