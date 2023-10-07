# Smart_Fire_System
The graduation project for ITI Summer Diploma in embedded systems using AVR (based on ATmega32 Microcontroller)
The project is work to safe and place from fire by using Smoke detector, Tempreture sensore, Fans, water motors, 3 Leds, buzzer and LCD
the LCD is used to print the tempretue and the state:
if no smoke then it keep providing the user by the current tempreture:
if the current tempreture is between 30 and 40 then the green led will turn on and LCD print "Turn on Fans". and fans start working
if the current tempreture is higher thant 40 then the yellow led will turn on and LCD print "Warning, HOT".
if the current tempreture is less than 30  then the green led will turn on and LCD print "Fine".
if smoke detected the red led will turn on and the buzzer will start working,also the LCD prints : "Smoke Detected, Turn on Water" and the water pump start to work.
Architecture layout: 
2- HAL (LCD / LM35/ Smoke sensor)
3- MCAL (ADC / DIO)
4- LIB (STD_TYPES / BIT_MATH)
Simulation was built on Proteus to get the best results.

