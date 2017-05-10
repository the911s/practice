#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/atomic.h>

#include "../LiquidCrystalLib/LiquidCrystalLib.h"
#include "../LiquidCrystalLib/LiquidCrystalLib.cpp"

// Test LED ports
#define TEST_LED_PORT			PORTB
#define TEST_LED_PORT_DIR		DDRB
#define TEST_LED_PIN			0

using namespace std;

volatile uint16_t seconds = 0;

ISR( TIMER1_COMPA_vect )
{
	seconds++;
}

// Converts a single-digit minute value into a double-digit value ("1" becomes "01")
void parse_minute ( char min_array[], const uint8_t min )
{
	if ( min < 10 )
		sprintf( min_array, "0%d", min );
	else 
		sprintf( min_array, "%d", min );
}

int main(void) 
{
	
	sei();												// Enable global interrupts
	TCCR1B |= 1 << CS10 | 1 << CS11 | 1 << WGM12;		// Set timer prescale to 64
	TIMSK |= 1 << OCIE1A; 								// Timer should use Output Compare A Match Interrupt Enable
	OCR1A = 15624; 										// Set value of Output Compare Register 1A 
	
	char time[] = "12:00";
	char minute_char[] = "00";
	uint8_t hour = 11;
	uint8_t minute = 53;
	uint16_t seconds_copy; 
	
	// Illuminate the test LED
	//TEST_LED_PORT_DIR |= 1 << TEST_LED_PIN;
	//TEST_LED_PORT |= 1 << TEST_LED_PIN;
 	// Turn off the test LED
	//TEST_LED_PORT_DIR |= 1 << TEST_LED_PIN;
	//TEST_LED_PORT &= ~(1 << TEST_LED_PIN);
	
	LiquidCrystalLib screen( &PORTC, &PORTD, &DDRC, &DDRD, 4, 5, 6 );
	
	parse_minute( minute_char, minute );
	sprintf(time, "%d:%s", hour, minute_char);
	screen.write_str(time);
	
	while(1)
	{
		// Protect the seconds variable within a critical section
		// Otherwise the interrupt "thread" may try to modify it while it's being read
		ATOMIC_BLOCK( ATOMIC_FORCEON )
		{
			seconds_copy = seconds;
		}
	
		if (seconds_copy >= 480) {
			minute ++;
			seconds = 0;
			
			if (minute >= 60) {
				hour ++;
				minute = 0;
				
				if (hour > 12) {
					hour = 1;
				}
			}
			
			parse_minute( minute_char, minute );
			
			screen.clear();
			sprintf(time, "%d:%s", hour, minute_char);
			_delay_ms(100);
			screen.write_str(time);		
		
		}
	}
	
	return (0);
}