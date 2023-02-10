#include <avr/io.h>

void Initialize(){
    // Outputs
    DDRB |= (1 << DDB1);

    // Inputs
    DDRD &= ~(1 << DDD7);
}

int main(void)
{
    Initialize();
    while (1)
    {
        // Toggles LED
        if(PIND & (1 << PIND7)){
            PORTB |= (1 << PORTB1);
        } else{
            PORTB &= ~(1 << PORTB1);
        }

    }
}
