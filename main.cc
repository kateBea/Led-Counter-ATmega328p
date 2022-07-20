// Simple led counter program

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

int main()
{
    // config I/O ports
    PORTC   = 0B11111111;
    DDRC    = 0B00000000;


    uint32_t            counter {  };
    constexpr uint32_t  limit  { 256 };
    constexpr uint16_t  delay_value { 500 };

    while (true)
    {
        ++counter;

        // turn on led according to counter value
        DDRC = static_cast<uint8_t> (counter);
        _delay_ms(delay_value);

        if (counter == limit) 
        {
            DDRC    = 0b00000000;
            counter = 0;
        }
    }
}
