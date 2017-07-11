#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 8'000'000UL




#define LED1_AUS PORTD &= ~(1<<PD0);//ein Bit wird gel�scht
#define LED1_EIN PORTD |= (1<<PD0);// Ein Bit auf eins
#define LICHT_STOPP  !(PINB & (1<<PB1))// Das Makro f�r das anhalten des Lichtes
#define LANGSAM !(PINB & (1<<PB2))// Das Makro f�r die Geschwindigkeits reduzierung

int main (void)
{

	while(1)// Das Licht wird zu einem Lauflicht
	{
	
		long i = 0;// Der Speichertyp der Tackte (Normal 0 Tackte)
		long o = 0;// Der Speichertyp f�r den zeiten Tackt

		DDRD = 0xFF; //Port D als Ausgang setzen
		PORTD = 0;// alle Pins an Port D ansprechen

		DDRB &= ~(1<<PB1);
		PORTB |=(1<<PB1);
		
		DDRB &= ~(1<<PB2);
		PORTB |=(1<<PB2);// PORT befehl f�r die Geschwindigkeit

		

		while(LICHT_STOPP)// w�hrend des dr�cken des Tasters
		{
			PORTD = 1;
		}
			while(LANGSAM)
			{
				for(o=0; o<1600000; o++)
				{
				PORTD = 1;
				}
			}	
		for(i=0; i<27; i++)//Die Zeit ist doppelt so lang um eine optische T�uschung hervor zu rufen
		{
			PORTD = 1;
		}

		
		while(LICHT_STOPP)
		{
			PORTD = 2;
		}
			while(LANGSAM)
			{
				for(o=0; o<1600000; o++)
				{
				PORTD = 2;
				}
			}	
		for(i=0; i<27; i++) //Pause f�r s leuchten
		{
			PORTD = 2;
		}


		while(LICHT_STOPP)
		{
			PORTD = 4;
		}
			while(LANGSAM)
			{
				for(o=0; o<1600000; o++)
				{
				PORTD = 4;
				}
			}	
		for(i=0; i<27; i++) 
		{
			PORTD = 4;
		}
		

		while(LICHT_STOPP)
		{
			PORTD = 8;
		}
			while(LANGSAM)
			{
				for(o=0; o<1600000; o++)
				{
				PORTD = 8;
				}
			}
		for(i=0; i<27; i++) //Die Zeit ist doppelt so lang um eine optische T�uschung hervor zu rufen
		{
			PORTD = 8;
		}


		while(LICHT_STOPP)
		{
			PORTD = 16;
		}
			while(LANGSAM)
			{
				for(o=0; o<1600000; o++)
				{
					PORTD = 16;
				}
			}
		for(i=0; i<27; i++) 
		{
			PORTD = 16;
		}


		while(LICHT_STOPP)
		{
			PORTD = 32;
		}
			while(LANGSAM)
			{
				for(o=0; o<1600000; o++)
				{
					PORTD = 32;
				}
			}
		for(i=0; i<27; i++) 
		{
			PORTD = 32;
		}

		PORTD = 0;
		
	}	
			
	return 0;
}//end of main