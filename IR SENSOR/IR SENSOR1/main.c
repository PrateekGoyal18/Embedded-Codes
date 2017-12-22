#include<avr/io.h>
#include<util/delay.h>

main()
{
  DDRC = 0xff;
  DDRA&=~1;    // IR Sensor declared as an input device by giving 0 to Pin 0 of Port A
  PORTA|=1;    // IR Sensor activated 
  
  while(1)
  {
    if(!PINA&1)      // If the IR Sensor gives 0 ie, dark in front of it , then the LED's should glow
	PORTC = 0xff;
	else
	PORTC = 0x00;
  }
}