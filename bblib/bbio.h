/*! @file bbio.h
 *  @brief A collection of basic input/output functions
 * 
 *  bbio.h provides all basic read and write functions used
 *  for digital, analog, and PWM pins.
 * 
 * 
 * 
 */

#ifndef BBIO_H_INCLUDED
#define BBIO_H_INCLUDED

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>

#define HIGH   1
#define LOW    0
#define OUTPUT 1
#define INPUT  0

/*! @brief Used to write either a 0 or a 1 to a digital pin
 *  @param pin The name of the pin to write to
 *  @param value The value to write to the digital pin. Either HIGH or LOW 
 */
void digitalWrite(const char *pin, int value);

/*! @brief Used to read the value of a digital pin
 *  @param pin The name of the pin to read from
 *  @return Returns the int value of the digital pin. Either HIGH or LOW 
 */
int digitalRead(const char *pin);

/*! @brief Used to initilize a gpio pin for the first time
 *  @param pin The name of the pin to export 
 */
void exportGpio(const char* pin);

/*! @brief Used to uninitilize a gpio pin
 *  @param pin The name of the pin to unexport
 */
void unexportGpio(const char* pin);

/*! @brief Used to set the mode of a digital pin
 *  @param pin The name of the pin
 *  @param mode The mode of pin. Can be INPUT or OUTPUT 
 */
void digitalMode(const char* pin, int mode);

/*! @brief Used to measure the time between two digital signals
 * 
 *  pulseIn first writes a digital value of parameter value to digital pin
 *  parameter pin. It then reads the pin until the value of the pin
 *  equals paramter value, measures the time inbetween, and returns the value.
 * 
 *  @param pin The name of the pin to export 
 *  @param value The digital value to be used
 *  @param timeout The maxmimum time to wait for a second pulse
 *  @return The time, in microseconds, between pulses
 */
long pulseIn(const char* pin, int value, double timeout);

/*! @brief Used to read the value of an analog pin
 *  @param pin The name of the pin to read from
 *  @return The analog value of the pin
 */
int analogRead(const char* pin);

/*! @brief Used to mux a pin
 *  
 *  On the beagleboard and beaglebone, certian pins can have multiple uses. For example
 *  some pins can be set to act as a digital pin or as a PWM pin. This is called pin muxing.
 *  See the beagleboard/beaglebone reference manual for more information.
 * 
 *  @param pin The name of the pin to mux
 *  @param mode The new mux mode of the pin
 */
void muxPin(const char* pin, int mode);

/*! @brief Used to write a pwm value
 *  @param pin The name of the pin to write to
 *  @param frequency The frequency of the pulse
 *  @param percent The percent of the pulse
 *  @param istun If true - sets pwm value. If false - stops pwm
 */
void pwmWrite(const char* pin, int frequency, int percent, int isrun);


#endif // BBIO_H_INCLUDED
