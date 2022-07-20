// Simple led counter program

#define F_CPU 16000000UL    //define CPU clock cylces in Herz for usage on _delay_ms()

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

int main()
{
    // config I/O ports
    PORTB   = 0B00000000;
    DDRB    = 0B11111111;


    uint32_t            counter {  };
    constexpr uint32_t  limit  { 256 };
    constexpr uint16_t  delay_value { 500 };

    while (true)
    {
        ++counter;

        // turn on led according to counter value
        PORTB = static_cast<uint8_t> (counter);
        _delay_ms(delay_value);

        if (counter == limit) 
        {
            PORTB    = 0b00000000;
            counter = 0;
        }
    }
}
