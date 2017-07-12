#include <stdlib.h>
#include <avr/io.h>


#define F_CPU 8000000
#define LED1_AUS PORTD &= ~(1<<PD0)
#define LED1_EIN PORTD |= (1<<PD0)


int main(void)

{
	unsigned long i = 0;
	unsigned short k = 0;
	
	DDRD = 0xFF;
	PORTD = 0x00;
	
		do
		{
	
			for(i=0; i<=530000; i++)
			{
					LED1_EIN;
			}
			
			for(i=0; i<=530000; i++)
			{
					LED1_AUS;
			}
		k++;
		}while(k <= 30);
	
	
	return 0;
}