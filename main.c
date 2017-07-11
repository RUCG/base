#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 8'000'000UL




#define LED1_AUS PORTD &= ~(1<<PD0);//ein Bit wird gelöscht
#define LED1_EIN PORTD |= (1<<PD0);// Ein Bit auf eins
#define LICHT_STOPP  !(PINB & (1<<PB1))// Das Makro für das anhalten des Lichtes
#define LANGSAM !(PINB & (1<<PB2))// Das Makro für die Geschwindigkeits reduzierung

int main (void)
{

	while(1)// Das Licht wird zu einem Lauflicht
	{
	
		long i = 0;// Der Speichertyp der Tackte (Normal 0 Tackte)
		long o = 0;// Der Speichertyp für den zeiten Tackt

		DDRD = 0xFF; //Port D als Ausgang setzen
		PORTD = 0;// alle Pins an Port D ansprechen

		DDRB &= ~(1<<PB1);
		PORTB |=(1<<PB1);
		
		DDRB &= ~(1<<PB2);
		PORTB |=(1<<PB2);// PORT befehl für die Geschwindigkeit

		

		while(LICHT_STOPP)// während des drücken des Tasters
		{
			PORTD = 129;
		}
			while(LANGSAM)
			{
				for(o=0; o<400000; o++)
				{
				PORTD = 129;
				}
			}	
		for(i=0; i<20000; i++)//Die Zeit ist doppelt so lang um eine optische Täuschung hervor zu rufen
		{
			PORTD = 129;
		}

		
		while(LICHT_STOPP)
		{
			PORTD = 66;
		}
			while(LANGSAM)
			{
				for(o=0; o<400000; o++)
				{
				PORTD = 66;
				}
			}	
		for(i=0; i<10000; i++) //Pause für s leuchten
		{
			PORTD = 66;
		}

		while(LICHT_STOPP)
		{
			PORTD = 36;
		}
			while(LANGSAM)
			{
				for(o=0; o<400000; o++)
				{
				PORTD = 36;
				}
			}	
		for(i=0; i<10000; i++) 
		{
			PORTD = 36;
		}
		

		while(LICHT_STOPP)
		{
			PORTD = 24;
		}
			while(LANGSAM)
			{
				for(o=0; o<400000; o++)
				{
				PORTD = 24;
				}
			}
		for(i=0; i<20000; i++) //Die Zeit ist doppelt so lang um eine optische Täuschung hervor zu rufen
		{
			PORTD = 24;
		}


		while(LICHT_STOPP)
		{
			PORTD = 36;
		}
			while(LANGSAM)
			{
				for(o=0; o<400000; o++)
				{
					PORTD = 36;
				}
			}
		for(i=0; i<10000; i++) 
		{
			PORTD = 36;
		}


		while(LICHT_STOPP)
		{
			PORTD = 66;
		}
			while(LANGSAM)
			{
				for(o=0; o<400000; o++)
				{
					PORTD = 66;
				}
			}
		for(i=0; i<10000; i++) 
		{
			PORTD = 66;
		}

		PORTD = 0;
		
	}	
			
	return 0;
}//end of main