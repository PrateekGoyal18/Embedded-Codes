/*
  In this project, we will design a Robotic Car which if face any obstacle, will stop.
  In this project, we will use one TSOP sensor module in PA1.
*/

#include<avr/io.h>

void forward()
{
  PORTC&=~(1<<0);
  PORTC|=(1<<1);
  PORTC&=~(1<<2);
  PORTC|=(1<<3);
}

void stop()
{
  PORTC&=~(1<<0);
  PORTC&=~(1<<1);
  PORTC&=~(1<<2);
  PORTC&=~(1<<3);
}

void motor_init()
{
  DDRC=0B00001111;
}

int main()
{
  motor_init();
  DDRA&=~(1<<1);
  PORTA|=(1<<1);
  while(1)
  {
    if(!(PINA&(1<<1)))
    stop();
	
    else
    forward();
  }
}
