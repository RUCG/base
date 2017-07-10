#include <stdlib.h>
#include <avr/io.h>

#define LED1_AUS PORTD &= ~(1<<PD1);//ein Bit wird gelöscht
#define LED1_EIN PORTD |= ~(1<<PD1);// Ein Bit auf eins

int main (void)
{

DDRD = 0xFF; //Port D als Ausgang setzen
PORTD = 0xFF;// alle Pins an Port D auf 1

LED1_EIN;

	while(1)
	{
	
	}//end of while
	
	return 0;
}//end of main