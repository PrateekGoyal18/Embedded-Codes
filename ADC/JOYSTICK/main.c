#include<avr/io.h>
#include<util/delay.h>

int adc_read()
{
  ADCSRA|=(1<<ADSC);
  while(!(ADCSRA&(1<<ADIF)));
  return ADCH;
}

main()
{
  DDRC=0xFF;
  DDRA=0x00;
  PORTA=0xFF;
  ADCSRA=0b10000111;
  ADMUX=0b11100000;
  
  int x,y;
  while(1)
  {
    x=adc_read(0);      // PORTA0 with the x axis pin
	y=adc_read(1);      // PORTA1 with the y axis pin
	
	if(x<150 && y>150 && y<154)
	PORTC=0x01;
	
	else if(x>154 && y>150 && y<154)
	PORTC=0x02;
	
	else if(y<150 && x>150 && x<154)
	PORTC=0x03;
	
	else if(y>154 && x>150 && x<154)
	PORTC=0x04;
	
	else if(x>150 && x<154 && y>150 && y<154)
	PORTC=0x05;
	
	else 
	PORTC=0x06;
  }
}