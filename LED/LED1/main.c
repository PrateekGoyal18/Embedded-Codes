#include<avr/io.h>
#include<util/delay.h>

main()
{
  DDRC = 0b11111111;
  while(1)
  {
    PORTC = 0b11111111;
	_delay_ms(125);
	PORTC = 0b00000000;
	_delay_ms(125);
  }
}