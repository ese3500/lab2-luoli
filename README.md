# Lab 2 Morse Code Decoder

Everything (hopefully) should work if you import the code and flash the Arduino with it. Please see lab2_luoli.pdf for circuit setup.

I ultimately decided to prescale the system clock by 1024 as not prescaling / prescaling to 64 all led to the overflow counter overflowing (esp if I only used an int). Although technically overflow isn't needed anymore as scaling it by 1024 prevents overflow as we are working in ms, the overflow counter mechanism does still work if we change the prescaler to 256 (you can print the overflow variable and see it increasing). 

Furthermore, instead of doing edge detection like in lecture, I ended up setting TCNT1 to zero on a rising edge and just read its value and store it into another variable (period) on the falling edge. The same is done when comparing whether 1000ms has passed for the space; we end up comparing if TCNT1 - period is greater than 16000000 / 1024 = 15625.

Note that although the time intervals for indicating whether a dot or dash was pressed did not change, the time interval for indicating a space increased from 400ms to 1000ms.
