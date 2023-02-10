#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

char toPrint[] = "aa";

void Initialize(){
    cli();
    // input output
    DDRB |= (1 << DDB1);
    DDRB &= ~(1 << DDB0);

    // timer
    TCCR1B &= ~(1 << CS10);
    TCCR1B |= (1 << CS11);
    TCCR1B &= ~(1 << CS12);

    TCCR1A &= ~(1 << WGM10);
    TCCR1A &= ~(1 << WGM11);
    TCCR1B &= ~(1 << WGM12);
    TCCR1B &= ~(1 << WGM13);

    TCCR1B |= (1 << ICES1);

    TIFR1 |= (1 << ICF1);

    TIMSK1 |= (1 << ICIE1);

    sei();
}

ISR(TIMER1_CAPT_vect){
    TIFR1 |= (1 << ICF1);
    if(PINB & (1 << PINB0)){
    for(int i = 0; i < strlen(toPrint); i++){
    if(toPrint[i] == 97){ // a
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
    } else if(toPrint[i] == 98){ // b
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
    } else if(toPrint[i] == 99){ // c
        PPORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 100){ // d
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 101){ // e
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 102){ // f
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 103){ // g
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 104){ // h
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 105){ // i
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 106){ // j
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 107){ // k
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        
    } else if(toPrint[i] == 108){ // l
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 109){ // m
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

    } else if(toPrint[i] == 110){ // n
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 111){ // o
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 112){ // p
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 113){ // q
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 114){ // r
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 115){ // s
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 116){ // t
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 117){ // u
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 118){ // v
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 119){ // w
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 120){ // x
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 121){ // y
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else if(toPrint[i] == 122){ // z
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    }  else if(toPrint[i] == 122){ // 3
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    }  else if(toPrint[i] == 122){ // 5
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    }  else if(toPrint[i] == 122){ // 0
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);

        PORTB |= (1 << PORTB1);
        _delay_ms(3000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
        
    } else {
        PORTB |= (1 << PORTB1);
        _delay_ms(10000);
        PORTB &= ~(1 << PORTB1);
        _delay_ms(1000);
    }
    _delay_ms(5000);
    }

    TCCR1B &= ~(1 << ICES1);
    } else {
        TCCR1B |= (1 << ICES1);
    }
}

int main(void)
{
    Initialize();
    while (1)
    {
    }
}