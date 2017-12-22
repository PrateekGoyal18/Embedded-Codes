//4 bit data lcd 16*2
//16 bit total
//8 pin data pins
//3 pins special rs r/w^-  e
//rs=0 command mode//rs=1 data mode
//r/w^- 1 read 0 write ,trigger pulse =high to low ,total time= 450 ms 
//port3 not connected to anything
//01000001 0xf0 = 0100
//00000001 0x00001111 = <<4 = 0001
//lcd_cmd(0x01); screen clear
//lcd_cmd(0x18); left shift
//lcd_cmd(0x1c); right shift
//lcd_char('a');
// lcd_string("  ");


#include<avr/io.h>
#include<util/delay.h>
#include<LCD_mega128.h>
void main()
{
  lcd_init();
  lcd_cmd(0x01);
    lcd_string("Hello");
	while(1)
{
lcd_cmd(0x18);
_delay_ms(1000)
}  
}