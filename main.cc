// Simple led counter program

#define F_CPU 16000000UL    //define CPU clock cylces in Herz for usage on _delay_ms()

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

int main()
{
    // config I/O ports
    PORTB   = 0B00000000; // clear PORTB pins on startup
    DDRB    = 0B11111111; // setup PORTB pins as output


    uint8_t             counter {  };

    // delay amount for usage in _delay_ms()
    constexpr uint16_t  delay_value { 250 };

    while (true)
    {
        ++counter;

        // turn on led according to counter value
        PORTB = counter;

        // delay in ms
        _delay_ms(delay_value);
    }
}
