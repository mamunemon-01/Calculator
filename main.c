#include<avr/io.h>
#include<util/delay.h>

static int arraySd[10] = { 0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

static int arraySc[10] = { 0b01001000, 0b11111001, 0b10100100, 0b10110000, 0b10010001,
				0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};

void calcu(void);

void show(int n);

static int op1=0, op2=0, x=0, optr = 0, rslt = 0, err = 0;

int main(void)
{
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRB = 0xF0;
	PORTB = 0b00001111;
	PORTC = 0xFF;
	PORTD = 0x00;
	_delay_ms(50);
	PORTC = 0b11111011;
	PORTD = 0b01110110;
	_delay_ms(100);
	PORTC = 0xFF;
	PORTD = 0x00;

	while(1)
	{
		while(1)
		{
			x=PINB;
			if(x!=0b00001111)
			{
				break;
			}
		}

		PORTB = 0b11101111;
		x=PINB;
		if(x!=0b11101111)
		{
			//r1 = 0;

			x&= 0b00001111;

			if(x==0b00001110)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+7;
				show(op2);
			}
			//search();
		}

		PORTB = 0b11101111;
		x=PINB;
		if(x!=0b11101111)
		{
			//r1 = 0;

			x&= 0b00001111;

			if(x==0b00001101)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+8;
				show(op2);
			}
			//search();
		}


		PORTB = 0b11101111;
		x=PINB;
		if(x!=0b11101111)
		{
			//r1 = 0;

			x&= 0b00001111;

			if(x==0b00001011)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+9;
				show(op2);
			}
			//search();
		}


		PORTB = 0b11101111;
		x=PINB;
		if(x!=0b11101111)
		{
			//r1 = 0;

			x&= 0b00001111;

			if(x==0b00000111)
			{

				calcu();
				if(err == 1){
					err = 0;
					goto on;
				}
				op2=0;
				optr = 4;
				show(op1);
			}
			//search();
		}

		PORTB = 0b11011111;
		x=PINB;
		if(x!=0b11011111)
		{
			//r1 = 1;

			x&= 0b00001111;

			if(x==0b00001110)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+4;
				show(op2);
			}
		}


		PORTB = 0b11011111;
		x=PINB;
		if(x!=0b11011111)
		{
			//r1 = 1;

			x&= 0b00001111;

			if(x==0b00001101)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+5;
				show(op2);
			}
		}

		PORTB = 0b11011111;
		x=PINB;
		if(x!=0b11011111)
		{
			//r1 = 1;

			x&= 0b00001111;

			if(x==0b00001011)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+6;
				show(op2);
			}
		}

		PORTB = 0b11011111;
		x=PINB;
		if(x!=0b11011111)
		{
			//r1 = 1;

			x&= 0b00001111;

			if(x==0b00000111)
			{
				calcu();
				if(err == 1){
					err = 0;
					goto on;
				}
				op2 = 0;
				optr = 3;
				show(op1);
			}
		}

		PORTB = 0b10111111;
		x=PINB;
		if(x!=0b10111111)
		{
			//r1 = 2;
			x&= 0b00001111;

			if(x==0b00001110)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+1;
				show(op2);
			}
		}

		PORTB = 0b10111111;
		x=PINB;
		if(x!=0b10111111)
		{
			//r1 = 2;
			x&= 0b00001111;

			if(x==0b00001101)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+2;
				show(op2);
			}
			//search();

		}

		PORTB = 0b10111111;
		x=PINB;
		if(x!=0b10111111)
		{
			//r1 = 2;
			x&= 0b00001111;

			if(x==0b00001011)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2=op2*10+3;
				show(op2);
			}
		}

		PORTB = 0b10111111;
		x=PINB;
		if(x!=0b10111111)
		{
			//r1 = 2;
			x&= 0b00001111;

			if(x==0b00000111)
			{
				calcu();
				if(err == 1){
					err = 0;
					goto on;
				}
				op2 = 0;
				optr = 2;
				show(op1);
			}
			//search();

		}

		PORTB = 0b01111111;
		x=PINB;
		if(x!=0b01111111)
		{
			//r1 = 3;
			x&= 0b00001111;

			if(x==0b00001110)
			{
				on:
				op1 = op2 = optr = rslt = 0;
				PORTC = 0xFF;
				PORTD = 0x00;
				_delay_ms(10);
				show(0);
			}
		}

		PORTB = 0b01111111;
		x=PINB;
		if(x!=0b01111111)
		{
			//r1 = 3;
			x&= 0b00001111;

			if(x==0b00001101)
			{
				if(optr == 5)
				{
					op2 = 0;
					optr = 0;
				}
				op2 = op2*10 + 0;
				show(op2);
			}
			//search();
		}

		PORTB = 0b01111111;
		x=PINB;
		if(x!=0b01111111)
		{
			//r1 = 3;
			x&= 0b00001111;

			if(x==0b00001011)
			{
				calcu();
				if(err == 1){
					err = 0;
					goto on;
				}
				optr = 5;
				show(op1);
			}
		}

		PORTB = 0b01111111;
		x=PINB;
		if(x!=0b01111111)
		{
			//r1 = 3;
			x&= 0b00001111;

			if(x==0b00000111)
			{
				calcu();
				if(err == 1){
					err = 0;
					goto on;
				}
				op2 = 0;
				optr = 1;
				show(op1);
			}
		}
	}
	return 0;
}

void calcu(void)
{
	if(optr == 1)
	{
		rslt = op1+op2;
	}
	else if(optr == 2)
	{
		rslt = op1-op2;
	}
	else if(optr == 3)
	{
		rslt = op1*op2;
	}
	else if(optr == 4)
	{
		rslt = op1/op2;
	}
	else if(optr == 5)
	{}

	if(optr != 0)
	{
		if(rslt<100) op1 = rslt;
		else
		{
			PORTB = 0b00001111;
			while(1)
			{
				PORTC = 0b00000110;
				PORTD = 0b01111001;

				PORTB = 0b01111111;
				x=PINB;
				if(x!=0b01111111)
				{
					//r1 = 3;
					x&= 0b00001111;

					if(x==0b00001110)
					{
						err = 1;
						break;
					}
				}
			}
		}
	}
	else op1 = op2;
}

void show(int n)
{
	PORTC = arraySc[n%10];
	PORTD = arraySd[n/10];
	_delay_ms(50);
}
