//************************************************************************
/*---------------2 Practical 2: Displaying Digits on Seven Segment Displays  -------------*/
//------portb=(0-4)->b,a,com,g,f****portd=(0-4)->dot,c,com,d,e----------
///------for comman anode use ~ in function seven_seg_disp()-------------
//************************************************************************
#include<avr/io.h>
//#define F_CPU 1000000UL
#include<util/delay.h>

void seven_seg_disp(unsigned char);

int main()

{
	DDRB = 0XFF;
	DDRD = 0XFF;
	unsigned char i;
	
	while(1)
	for(i=0;i<10;i++)
	{
	seven_seg_disp(i);
	_delay_ms(500);
	}

	


	return 0;		
}

void seven_seg_disp(unsigned char i)
{

 switch(i)
 {
	case 0:
	{
	PORTB = ~0B00001011;
	PORTD = ~0B00011010;
	break;
	}
	case 1: 
	{
	PORTB = ~0B00000001;
	PORTD = ~0B00000010;
	break;
	}
	case 2:
	{
	PORTB = ~0B00010011;
	PORTD = ~0B00011000;
	break;
	}
	case 3:
	{
	PORTB = ~0B00010011;
	PORTD = ~0B00001010;
	break;
	}
	case 4:
	{
	PORTB = ~0B00011001;
	PORTD = ~0B00000010;
	break;
	}
	case 5:
	{
	PORTB = ~0B00011010;
	PORTD = ~0B00001010;
	break;
	}
	case 6:
	{
	PORTB = ~0B00011010;
	PORTD = ~0B00011010;
	break;
	}
	case 7:
	{
	PORTB = ~0B00000011;
	PORTD = ~0B00000010;
	break;
	}
	case 8:
	{
	PORTB = ~0B00011011;
	PORTD = ~0B00011010;
	break;
	}
	case 9:
	{
	PORTB = ~0B00011011;
	PORTD = ~0B00000010;
	break;
	}

 }

}	



//************************************END**************************************************

