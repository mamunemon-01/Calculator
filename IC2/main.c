#include<avr/io.h>
#include<util/delay.h>

static int op1=0, op2=0, x=0, optr = 0, rslt = 0;

int main(void)
{
	DDRD = 0xFF;
	PORTD = 0xFF;
	_delay_ms(50);
	DDRB = 0x00;
	
	while(1)
	{
		if(PINB == 0b11110000)
		{
			PORTD = 0b11111000;
		}
		else PORTD = PINB;
		_delay_ms(5);
	}
	return 0;
}