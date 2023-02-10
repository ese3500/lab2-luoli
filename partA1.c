#include <avr/io.h>

void Initialize(){
    // Outputs
    DDRB |= (1 << DDB1);
    DDRB |= (1 << DDB2);
    DDRB |= (1 << DDB3);
    DDRB |= (1 << DDB4);
}

int main(void)
{
    Initialize();
        while (1)
        {
            PORTB |= (1 << PORTB1);
            PORTB |= (1 << PORTB2);
            PORTB |= (1 << PORTB3);
            PORTB |= (1 << PORTB4);
        }
}