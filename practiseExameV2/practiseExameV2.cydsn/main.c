/**
 ***********************************************************************************
 * 
 * 
 * Exam of Embedded Systems 2
 * Date: November 4th 2019
 * Time: 14:00 - 16:30
 *
 * TO_DO: Exercise 1
 * Student's name:
 * Student's number: 
 *
 *
 * Preface:
 *
 * In this exam you will simulate the charging/discharging process for the
 * battery of an electric car. Your system will consider the following hardware
 * components:
 *
 *   Battery level LEDS: An array of three LEDs which indicates the level of
 *                       charge of the battery.
 *   Charger status LED: A single LED which indicates the state of the charger.
 *   Potentiometer:      A three-terminal variable resistor which simulates the 
 *                       level of charge of the battery.
 * 
 * The system monitors the voltage level of the battery and adjusts its 
 * charging state accordingly: a fast-charge state for a low charged battery
 * (below 12.0 volts), a slow-charge state for a medium charged battery
 * (between 12.0 and 13.2 volts) and a no-charge state for a fully charged
 * battery (13.2 volts or higher).
 *
 * IMPORTANT: WHEN YOU HAVE FINISHED, DELIVER A ZIP FILE OF YOUR COMPLETE
 *            PROJECT!! PACKAGE THE battery_charging.cysdn DIRECTORY INTO A ZIP
 *            FILE AND PUT IT ON YOUR USB STICK!
 * 
 * Good luck!
 * 
 * 
 ***********************************************************************************
 * 
 * EXERCISES:
 *
 * Exercise 1: Getting started
 *
 * 1a: Enter your name and student number in the lines at the beginning of this
 *     file. 
 * 
 * 1b: Create a new (empty) project for your exam. Make sure to check that you
 *     are using the correct target hardware (your type of board). Call this
 *     project "battery_charging" and look carefully where this is stored. Copy
 *     the content of this file with the exercises and code in the main.c file 
 *     of your project. Build the project and see if you can run and debug it.
 * 
 * 1c: If the battery level has not changed, there is no need to do anything. 
 *     We might as well wait for a while until we check the voltage level
 *     again. Fill in the code in the main loop to let the program sleep for a
 *     while before we check the battery again. How long do you let the program
 *     sleep?
 * 
 * 
 ***********************************************************************************
 *
 * Exercise 2: Battery level indicator
 * 
 * The current level of the battery condition has to be indicated by three
 * LEDs, see the function setBatteryIndicator.
 *
 * 2a: Connect three LEDs to your PSoC board. Make sure the LEDs can be
 *     controlled by three consecutive pins of the same port on you PSoC. Draw
 *     in your top-design how you have connected the three LEDs. 
 *
 * 2b: Fill in the code of the function setBatteryIndicator (the voltage 
 *     reading function will be completed in Exercise 3). Make sure you use
 *     individual Write functions for each pin (each LED).
 * 
 * TO DO!!!2c: Instead of individual Write functions for each pin you can also use one
 *     single Write function to set the value for a set of consecutive pins at
 *     once. Describe what has to be changed in your design to be able to use
 *     such a function. Also provide the Write calls that you would use in this
 *     case to control the LEDs. Put your answer below:
 *
 *       Description:
 *       New Pin Write function calls:
 *
 *
 ***********************************************************************************
 * 
 * Exercise 3: Battery voltage sensing
 * 
 * The system has to sense the current voltage reading of the battery. We
 * simulate this with the use of a variable resistor (potentiometer) from your
 * kit. 
 *
 * 3a: Connect the variable resistor to you PSoC such that you will be able to
 *     read its setting. Draw in your top-design how you have connected your
 *     resistor.
 *
 * 3b: Complete the code of the function readResistorValue to read the resistor
 *     value. 
 *
 * 3c: What are the maximum and the minimum values that you can read from your
 *     resistor?
 *
 *       Maximum: 255 in decimals
 *       Minimum: 0 in decimals
 *
 * 3d: Complete the code of the function readBatteryVoltage to convert the
 *     resistor value into a voltage value between 0.0 and 14.0 volts
 *
 * 3e: Complete the code of the function readBatteryLevel to convert the
 *     voltage reading into a battery level. Make sure you use macros to define
 *     the different voltage levels.
 *
 *
 ***********************************************************************************
 * 
 * Exercise 4: Charger State Indication
 *
 * The state of the charger has to be indicated with a single LED:
 *   LED constantly on for no charge 
 *   LED blinks slow for regular charging 
 *   LED blinks fast for fast charge 
 *   LED off for unknown state 
 *
 * The blinking rate of the LED should be controlled by a PWM module
 *
 * 4a: Connect another LED to the PSoC to be used for the charger indicator.
 *     Draw the connections in the top-design.
 *
 * 4b: Configure a PWM module in your top-design and connect it to your led.
 *
 * 4c: Complete the code of the function setChargerIndicator such that the 
 *     charger indicator LED performs the correct function. Choose the
 *     frequency of the blinking rates yourself.
 *
 * 4d: Provide and explain the choices you have made for your PWM module:
 *
 *       Input clock frequency:
 *       PWM period:
 *       Fast blinking frequency and corresponding PWM duty cycle setting:
 *       Slow blinking frequency and corresponding PWM duty cycle setting:
 *
 *
 ***********************************************************************************
 *
 * Exercise 5: Theoretical questions
 * 
 * 5a: How many bytes does the PSoC use to store the following variables:
 *
 *       int:
 *       float:
 *       double:
 *
 * 5b: Does the PSoC use little endian or big endian? 
 *
 * 5c: How many bits does the PSoC use to store a memory pointer?  
 *
 * 5d: Given your answers for 5a and 5c, how many integers could theoretically
 *     be stored and addressed in the PSoC?
 * 
 * 
 * REMINDER: Hand in a zip file ("battery_charging.cydsn.zip") of your complete
 * project!!
 *
 *
 ***********************************************************************************/

#include "project.h"

typedef enum CHARGE_STATES {
  UNKOWN_CHARGE,
  FAST_CHARGE,
  REGULAR_CHARGE,
  NO_CHARGE
} CHARGE_STATES;

typedef enum BATT_LEVELS {
  LEVEL_UNKNOWN,
  LEVEL_FULL,
  LEVEL_MEDIUM,
  LEVEL_LOW
} BATT_LEVELS;

int readResistorValue() {

  /* TO_DO: Exercise 3b
   * Fill in the code for this function to read the resistor value
   */
  while(!ADC_SAR_1_IsEndConversion(ADC_SAR_1_RETURN_STATUS)) ; 
  
  int resistorValue = ADC_SAR_1_GetResult16();

  return resistorValue;

}

float readBatteryVoltage() {

  /* Sense the battery voltage. We simulate this process by reading out the
   * potentiometer (variable resistor) and converting its value into a voltage
   * level between 0 and 14 volts
   */
  int r_value;
  float	voltage;

  r_value = readResistorValue();

  /* TO_DO: Exercise 3d:
   * Fill in the code for this function to simulate the sensing of the battery
   * voltage. Convert the reading from the potentiometer into a digital voltage
   * value between 0.0 and 14.0 volts
   */
   voltage = r_value * (14.0 / 255);

  /* Temporary setting for debugging purposes */
  //voltage = 12.4;

  return voltage;

}

BATT_LEVELS readBatteryLevel() {

  /* Determines the current battery level according to its voltage reading */
  float voltage;
  BATT_LEVELS level;

  voltage = readBatteryVoltage();

  /* TO_DO: Exercise 3e
   * Fill in the code to convert the voltage reading to a battery level
   */
/*
    if(voltage > 11){
      level = LEVEL_FULL;
    }else if(voltage > 7){
      level = LEVEL_MEDIUM;
    }else if(voltage > 3){
      level = LEVEL_LOW;
    }else if(voltage < 1){
      level = LEVEL_UNKNOWN;
    }*/
    if(voltage < 0.5){
      level = LEVEL_UNKNOWN;
    }else if(voltage < 3.5){
      level = LEVEL_LOW;
    }else if(voltage < 7){
      level = LEVEL_MEDIUM;
    }else if(voltage > 10.5){
      level = LEVEL_FULL;
    }


  /* Temporary setting for debugging purposes */
  //level = LEVEL_MEDIUM;

  return level;

}

void setBatteryIndicator(BATT_LEVELS level) {

  /* Lights up three LEDs to indicate the battery level as follows:
   *   One LED: battery level is low
   *   Two consecutive LEDs: battery level is medium
   *   Three consecutive LEDs: battery level is full
   *   Two not consecutive LEDs: battery level is unknown
   */

  /* TO_DO: Exercise 2b
   * Write the code for this function
   */
  switch(level)
{
  case LEVEL_UNKNOWN:
    LED_1_Write(1);
    LED_2_Write(0);
    LED_3_Write(1);
    break;
    
   case LEVEL_FULL:
    LED_1_Write(1);
    LED_2_Write(1);
    LED_3_Write(1);
    break;
    
    case LEVEL_MEDIUM:
    LED_1_Write(1);
    LED_2_Write(1);
    LED_3_Write(0);
    break;
    
    case LEVEL_LOW:
    LED_1_Write(1);
    LED_2_Write(0);
    LED_3_Write(0);
    break;
    
    default:
          ;
   }

}

void setChargerIndicator(CHARGE_STATES state) {

  /* Lights up the charger led to indicate its state as follows:
   *   LED constantly on for no charge
   *   LED blinks slow for regular charging
   *   LED blinks fast for fast charge
   *   LED off for unknown state
   */

  /* TO_DO: Exercise 4c
   * Write code for this function. Make sure you use a PWM module
   */
  switch(state)
{
    case NO_CHARGE:
    PWM_1_WriteCompare(255);
    break;
    
    case REGULAR_CHARGE:
    PWM_1_WriteCompare(65);
    break;
    
    case FAST_CHARGE:
    PWM_1_WriteCompare(192);
    break;
    
    case UNKOWN_CHARGE:
    PWM_1_WriteCompare(0);
    break;
    
    default:
          ;
}

}

void initBatterySensor(void) {

  /* TO_DO: 
   * Put initialization code here (if you need any)
   */
  ADC_SAR_1_Start(); // Start het ADC_SAR component
  ADC_SAR_1_StartConvert() ; // Start de ADC conversie continu in free-running mode.

}

void initBatteryLevelIndicator(void) {

  /* TO_DO: 
   * Put initialization code here (if you need any)
   */
  

}

void initChargerStateIndicator(void) {

  /* TO_DO: 
   * Put initialization code here (if you need any)
   */
  PWM_1_Start();
  Clock_1_Start();

}

void batteryChargerInit(void) {

  initBatterySensor();
  initBatteryLevelIndicator();
  initChargerStateIndicator();

}


int main(void) {

  /* Variable declaration */
  BATT_LEVELS last_battery_level = LEVEL_UNKNOWN, cur_battery_level = LEVEL_UNKNOWN;
  CHARGE_STATES charger_state = UNKOWN_CHARGE;

  /* Enable global interrupts */
  CyGlobalIntEnable;

  /* Place your initialization/startup code here */
  batteryChargerInit();
  

  for(;;) {

    /* Place your application code here */
    cur_battery_level = readBatteryLevel();

    /* The battery level has changed, get to work */
    if (cur_battery_level != last_battery_level) {

      setBatteryIndicator(cur_battery_level);

      switch (cur_battery_level) {

        case LEVEL_LOW:
          charger_state = FAST_CHARGE;
          break;

        case LEVEL_MEDIUM:
          charger_state = REGULAR_CHARGE;
          break;

        case LEVEL_FULL:
          charger_state = NO_CHARGE;
          break;

        default:
          ;

      }

      setChargerIndicator(charger_state);
      last_battery_level = cur_battery_level;

    }

    /* The battery level has not changed, sleep for a while */
    else { 

      /* TO_DO: Exercise 1c
       * Let the program sleep for a while
       */
      CyDelay(500);

    }

  }

}

/* [] END OF FILE */
