#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

#include "inc/uart.h";

#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER ((F_CPU / (BAUD_RATE * 16UL))-1)

volatile long long edge = 0;
volatile long long period = 0;
volatile long long overflow = 0;
volatile long long currOverflow = 0;
volatile long long lastOverflow = 0;
volatile int spaceIndicator = 1;
volatile int reading = 0;
char String[25];
char toDisplay[25];

void Initialize(){
    cli();
    // input output
    DDRB &= ~(1 << DDB0);
    DDRB |= (1 << DDB1);
    DDRB |= (1 << DDB2);

    // timer scale to /256
    TCCR1B |= (1 << CS10);
    TCCR1B &= ~(1 << CS11);
    TCCR1B |= (1 << CS12);

    // timer 1 to normal
    TCCR1A &= ~(1 << WGM10);
    TCCR1A &= ~(1 << WGM11);
    TCCR1B &= ~(1 << WGM12);
    TCCR1B &= ~(1 << WGM13);

    // look for rising edge
    TCCR1B |= (1 << ICES1);

    // clear input capture
    TIFR1 |= (1 << ICF1);

    // enable input capture interrupt
    TIMSK1 |= (1 << ICIE1);

    // clear and enable timer overflow capture interrupt
    TIFR1 |= (1 << TOV1);
    TIMSK1 |= (1 << TOIE1);

    sei();
}

ISR(TIMER1_OVF_vect){
    overflow += 1;
}

ISR(TIMER1_CAPT_vect){
    if(PINB & (1 << PINB0)){
        TCNT1 = 0;
        overflow = 0;
        reading = 1;
        spaceIndicator = 1;
        TCCR1B &= ~(1 << ICES1);
    } else {
        period = TCNT1;
        currOverflow = overflow;
        reading = 0;
        spaceIndicator = 0;
        TCCR1B |= (1 << ICES1);
    }
}

int main(void)
{

    Initialize();
    UART_init(BAUD_PRESCALER);
    while (1)
    {
        // for printing space --> if interval is >= 400 ms
        if(TCNT1 - period > 15625 && spaceIndicator == 0){
            sprintf(toDisplay, "%s", String);
            if(strcmp(toDisplay, "01") == 0){
                UART_putstring("A");
            } else if (strcmp(toDisplay, "1000") == 0){
                UART_putstring("B");
            } else if (strcmp(toDisplay, "1010") == 0){
                UART_putstring("C");
            } else if (strcmp(toDisplay, "100") == 0){
                UART_putstring("D");
            } else if (strcmp(toDisplay, "0") == 0){
                UART_putstring("E");
            } else if (strcmp(toDisplay, "0010") == 0){
                UART_putstring("F");
            } else if (strcmp(toDisplay, "110") == 0){
                UART_putstring("G");
            } else if (strcmp(toDisplay, "0000") == 0){
                UART_putstring("H");
            } else if (strcmp(toDisplay, "00") == 0){
                UART_putstring("I");
            } else if (strcmp(toDisplay, "0111") == 0){
                UART_putstring("J");
            } else if (strcmp(toDisplay, "101") == 0){
                UART_putstring("K");
            } else if (strcmp(toDisplay, "0100") == 0){
                UART_putstring("L");
            } else if (strcmp(toDisplay, "11") == 0){
                UART_putstring("M");
            } else if (strcmp(toDisplay, "10") == 0){
                UART_putstring("N");
            } else if (strcmp(toDisplay, "111") == 0){
                UART_putstring("O");
            } else if (strcmp(toDisplay, "0110") == 0){
                UART_putstring("P");
            } else if (strcmp(toDisplay, "1101") == 0){
                UART_putstring("Q");
            } else if (strcmp(toDisplay, "010") == 0){
                UART_putstring("R");
            } else if (strcmp(toDisplay, "000") == 0){
                UART_putstring("S");
            } else if (strcmp(toDisplay, "1") == 0){
                UART_putstring("T");
            } else if (strcmp(toDisplay, "001") == 0){
                UART_putstring("U");
            } else if (strcmp(toDisplay, "0001") == 0){
                UART_putstring("V");
            } else if (strcmp(toDisplay, "011") == 0){
                UART_putstring("W");
            } else if (strcmp(toDisplay, "1001") == 0){
                UART_putstring("X");
            } else if (strcmp(toDisplay, "1011") == 0){
                UART_putstring("Y");
            } else if (strcmp(toDisplay, "1100") == 0){
                UART_putstring("Z");
            } else if (strcmp(toDisplay, "01111") == 0){
                UART_putstring("1");
            } else if (strcmp(toDisplay, "00111") == 0){
                UART_putstring("2");
            } else if (strcmp(toDisplay, "00011") == 0){
                UART_putstring("3");
            } else if (strcmp(toDisplay, "00001") == 0){
                UART_putstring("4");
            } else if (strcmp(toDisplay, "00000") == 0){
                UART_putstring("5");
            } else if (strcmp(toDisplay, "10000") == 0){
                UART_putstring("6");
            } else if (strcmp(toDisplay, "11000") == 0){
                UART_putstring("7");
            } else if (strcmp(toDisplay, "11100") == 0){
                UART_putstring("8");
            } else if (strcmp(toDisplay, "11110") == 0){
                UART_putstring("9");
            } else if (strcmp(toDisplay, "11111") == 0){
                UART_putstring("0");
            } else {
                UART_putstring("Error\n");
            }

            UART_putstring(" ");
            spaceIndicator = 1;
            sprintf(String, "");
        } else if(reading == 0) {
            int hi = 0;
            if(period < 0){
                hi = ((65536*(currOverflow+1) + period)*1024000 / 16000000 );
            } else {
                hi = ((65536*currOverflow + period)*1024000 / 16000000 );
            }
            if(hi > 30 && hi <= 200){
                char dot[] = "0";
                strcat(String, dot);
                PORTB |= (1 << PORTB1);
                _delay_ms(50);
                PORTB &= ~(1 << PORTB1);
            } else if(hi > 200 && hi <= 400) {
                char dash[] = "1";
                strcat(String, dash);
                PORTB |= (1 << PORTB2);
                _delay_ms(50);
                PORTB &= ~(1 << PORTB2);
            }
            reading = 1;
        }
    }
}