#include<avr/io.h>
#include<util/delay.h>

main()
{ 
  DDRA = 0b000000000;
  PORTA = 0xff;
  DDRC = 0b11111111;
  while(1)
  {
    if((PINA&15)==1)
	 PORTC =1;
	
	if((PINA&15)==2)
	PORTC =2;
	
	if((PINA&15)==3)
	PORTC =4;
	
	if((PINA&15)==4)
	PORTC =8;
	
	if((PINA&15)==5)
	PORTC =16;
	
	if((PINA&15)==6)
	PORTC = 32;
   }
  }

