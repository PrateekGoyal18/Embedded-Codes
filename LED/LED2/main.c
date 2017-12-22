#include<avr/io.h>
#include<util/delay.h>

main()
{
  DDRC = 0b11111111;
  while(1)
  {
    for(int i=1;i<=128;i=i*2)
	{
	  PORTC = i;
	  _delay_ms(1000);
	}
  }
}
