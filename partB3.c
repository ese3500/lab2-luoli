#include <avr/io.h>
#include <util/delay.h>

volatile int counter = 0;

void Initialize(){
    // Outputs
    DDRB |= (1 << DDB1);
    DDRB |= (1 << DDB2);
    DDRB |= (1 << DDB3);
    DDRB |= (1 << DDB4);

    // Inputs
    DDRD &= ~(1 << DDD7);
}

int main(void)
{
    Initialize();
    while (1)
    {
        if(PIND & (1 << PIND7)){
            counter++;
            _delay_ms(5000);
        }
        if(counter % 4 == 0){
            PORTB |= (1 << PORTB1);
            PORTB &= ~(1 << PORTB4);
        } else if(counter % 4 == 1){
            PORTB |= (1 << PORTB2);
            PORTB &= ~(1 << PORTB1);
        } else if(counter % 4 == 2){
            PORTB |= (1 << PORTB3);
            PORTB &= ~(1 << PORTB2);
        } else{
            PORTB |= (1 << PORTB4);
            PORTB &= ~(1 << PORTB3);
        }

    }
}
