// When two motors using this code are running , they will trace an eight(8).

#include"motor.h"
#include<util/delay.h>

main()
{
  DDRB = 0xFF;
  
  forward();
  _delay_ms(5000);
  
  axial_right();
  _delay_ms(1000);
  forward();
  _delay_ms(5000);
  
  axial_left();
  _delay_ms(1000);
  forward();
  _delay_ms(5000);
  
  axial_left();
  _delay_ms(1000);
  forward();
  _delay_ms(5000);
  
  axial_left();
  _delay_ms(1000);
  forward();
  _delay_ms(5000);
  
  axial_left();
  _delay_ms(1000);
  forward();
  _delay_ms(5000);
  
  axial_right();
  _delay_ms(1000);
  forward();
  _delay_ms(5000);
  
  axial_right();
  _delay_ms(1000);
  forward();
  _delay_ms(5000);
}