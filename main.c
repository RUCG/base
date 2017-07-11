#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 8'000'000UL




#define LED1_AUS PORTD &= ~(1<<PD0);//ein Bit wird gelöscht
#define LED1_EIN PORTD |= (1<<PD0);// Ein Bit auf eins
#define LICHT_STOPP  !(PINB & (1<<PB1))


int main (void)
{

	while(1)
	{
	
		long i = 0;

		DDRD = 0xFF; //Port D als Ausgang setzen
		PORTD = 0;// alle Pins an Port D ansprechen

		DDRB &= ~(1<<PB1);
		PORTB |=(1<<PB1);

		

		while(LICHT_STOPP)
		{
			PORTD = 129;
		}

		for(i=0; i<200000; i++)//Die Zeit ist doppelt so lang um eine optische Täuschung hervor zu rufen
		{
			PORTD = 129;
		}



		while(LICHT_STOPP)
		{
			PORTD = 66;
		}
		for(i=0; i<100000; i++) //Pause für s leuchten
		{
			PORTD = 66;
		}


		while(LICHT_STOPP)
		{
			PORTD = 36;
		}
		for(i=0; i<100000; i++) 
		{
			PORTD = 36;
		}


		while(LICHT_STOPP)
		{
			PORTD = 24;
		}
		for(i=0; i<200000; i++) //Die Zeit ist doppelt so lang um eine optische Täuschung hervor zu rufen
		{
			PORTD = 24;
		}


		while(LICHT_STOPP)
		{
			PORTD = 36;
		}
		for(i=0; i<100000; i++) 
		{
			PORTD = 36;
		}


		while(LICHT_STOPP)
		{
			PORTD = 66;
		}
		for(i=0; i<100000; i++) 
		{
			PORTD = 66;
		}

		PORTD = 0;
		
	}	
			
	return 0;
}//end of main