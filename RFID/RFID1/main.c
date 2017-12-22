#include<avr/io.h>
#include"usart.h"
#include<util/delay.h>

int main()
{
  int i,k=0;
  char a[12],b[12]="FE0076EB0063";
  
  DDRC=0xff;
  USART_init();
  
  while(1)
  { 
    for(i=0;i<12;i++)
	{
      while(!(UCSRA&(1<<RXC)));
	  a[i]=UDR;
	}
	
	for(i=0;i<12;i++)
	{
	  if(b[i]==a[i]) 2
	  k++;
	}
	
	if(k==12)
	PORTC=0x10;
	else 
	PORTC=0b01010101;
  }
}