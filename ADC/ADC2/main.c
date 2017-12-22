#include<util/delay.h>
#include<avr/io.h>S
#define lcd PORTB
#define rs 0
#define rw 1
#define e 2

int adc()
{
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	return ADCH;
}
void main()
{	DDRB=0xff;
	DDRA=0x00;

	init();
	ADCSRA=0b10000111;
	ADMUX=0b11100000;

	int x,y;
	while(1)
	{
	x=adc(0);
	y=adc(1);
	
	lcd_cmd(0x80);
	str("x=");
	lcd_cmd(0x85);
	num(x);

	lcd_cmd(0xC0);
	str("y=");
	lcd_cmd(0xC5);
	num(y);

	} 
}


void lcd_cmd(char c)
{	lcd = c&0b11110000;
	lcd&=~(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<e);
	_delay_ms(1);
	lcd&=~(1<<e);
	c=(c<<4);
	lcd = c&0b11110000;
	lcd&=~(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<e);
	_delay_ms(1);
	lcd&=~(1<<e);
}


void lcd_data(char c)
{	lcd = c&0b11110000;
	lcd|=(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<e);
	_delay_ms(1);
	lcd&=~(1<<e);
	c=(c<<4);
	lcd = c&0b11110000;
	lcd|=(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<e);
	_delay_ms(1);
	lcd&=~(1<<e);
}

void init()
{	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
}



void num(int n)
{	lcd_cmd(0x04);
	int a;
	while(n)
	{	a=n%10;
		n=n/10;
		lcd_data(a+0x30);
	}
	
}

void str(char*d)
{	int i=0;
	while(d[i]!='\0')
	{	lcd_data(d[i]);
		i++;
	}
}


