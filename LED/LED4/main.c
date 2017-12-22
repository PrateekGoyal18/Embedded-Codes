#include<avr/io.h>
#include<util/delay.h>

main()
{
  DDRC = 0b11111111;
  while(1)
  {
    
	for(int j=7;j>=0;j--)
	{
	  for(int i=0;i<=j;i++)
	  {
	    PORTC|=(1<<i);
	    _delay_ms(200);
		PORTC&=~(1<<i);
		_delay_ms(200);
	  }
    PORTC|=(1<<j);   
	}
  }	
}