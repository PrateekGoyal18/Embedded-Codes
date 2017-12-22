#include<avr/io.h>
#include<util/delay.h>

main()
{
  int i,j;
  DDRC = 0b11111111;
  while(1)
  {
    for(i=1,j=128;i<=128,j>=1;i=i*2,j=j/2)     // Converge and Diverge in one loop
	{
	  PORTC = i+j;
	  _delay_ms(1000);
	}
  }
}
