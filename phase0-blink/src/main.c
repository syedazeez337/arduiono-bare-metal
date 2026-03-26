#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /*
     * Set PB5 as output.
     * Datasheet: Section 14.4, DDRB register, bit 5.
     * Read-modify-write: we only touch bit 5, leaving
     * all other pins unchanged.
     */
    DDRB |= (1 << PB5);

    while (1) {
        /* PORTB bit 5 HIGH = LED on */
        PORTB |= (1 << PB5);
        _delay_ms(500);

        /* PORTB bit 5 LOW = LED off */
        PORTB &= ~(1 << PB5);
        _delay_ms(500);
    }

    return 0;
}