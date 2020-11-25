/**
 * Copyright (c) 2009 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
written by: Mohannad Rawashdeh
rawashdeh.mohannad@gmail.com
https://mb-raw.blogspot.com/
simple code read Button 1 - 4 and toggle the LED everytime you press the button
ref: https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v15.2.0%2Fgroup__nrf__gpio.html
*/

#include <stdbool.h>
#include <stdint.h>

#include "nrf.h"
#include "nrf_delay.h"
#include "nordic_common.h"
#include "boards.h"

#define  LED1_pin   17
#define  LED2_pin   18
#define  LED3_pin   19
#define  LED4_pin   20
#define  Button1_pin 13
#define  Button2_pin 14
#define  Button3_pin 15
#define  Button4_pin 16
#define  TURN_ON    0
#define  TURN_OFF   1
uint8_t Button_Status[4]={0,0,0,0};

static void set_led_output()
{
/*set the LED1 / LED2 / LED3 / LED4 as outputs*/
  nrf_gpio_cfg_output(LED1_pin);
  nrf_gpio_cfg_output(LED2_pin);
  nrf_gpio_cfg_output(LED3_pin);
  nrf_gpio_cfg_output(LED4_pin);
}
static void set_button_input()
{
  nrf_gpio_cfg_input(Button1_pin,NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_input(Button2_pin,NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_input(Button3_pin,NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_input(Button4_pin,NRF_GPIO_PIN_PULLUP);
}
static void All_on_off(uint16_t delay_in_ms)
{
      /*Turn all the LEDs OFF*/
      nrf_gpio_pin_write(LED1_pin,TURN_OFF);
      nrf_gpio_pin_write(LED2_pin,TURN_OFF);
      nrf_gpio_pin_write(LED3_pin,TURN_OFF);
      nrf_gpio_pin_write(LED4_pin,TURN_OFF);
      nrf_delay_ms(delay_in_ms);
      /*Turn all the LEDs ON*/
      nrf_gpio_pin_write(LED1_pin,TURN_ON);
      nrf_gpio_pin_write(LED2_pin,TURN_ON);
      nrf_gpio_pin_write(LED3_pin,TURN_ON);
      nrf_gpio_pin_write(LED4_pin,TURN_ON);
      nrf_delay_ms(delay_in_ms);
      /*Turn all the LEDs OFF*/
      nrf_gpio_pin_write(LED1_pin,TURN_OFF);
      nrf_gpio_pin_write(LED2_pin,TURN_OFF);
      nrf_gpio_pin_write(LED3_pin,TURN_OFF);
      nrf_gpio_pin_write(LED4_pin,TURN_OFF);
      nrf_delay_ms(delay_in_ms);
}
/**
 * @brief Function for application main entry.
 */
int main(void)
{

set_led_output();
set_button_input();
nrf_gpio_pin_set(LED1_pin);
nrf_gpio_pin_set(LED2_pin);
nrf_gpio_pin_set(LED3_pin);
nrf_gpio_pin_set(LED4_pin);
    while (true)
    {
      /*read the button status 
      if you press the button , only change the led status */
      if(nrf_gpio_pin_read(BUTTON_1) == 0 && Button_Status[0] == 0)
      {
        nrf_gpio_pin_toggle(LED1_pin);
        Button_Status[0] = 1;
      }
      else if(nrf_gpio_pin_read(BUTTON_1) == 1 && Button_Status[0] == 1)
      {
        Button_Status[0] = 0;
      }
      /*Button 2*/
      if(nrf_gpio_pin_read(BUTTON_2) == 0 && Button_Status[1] == 0)
      {
        nrf_gpio_pin_toggle(LED2_pin);
        Button_Status[1] = 1;
      }
      else if(nrf_gpio_pin_read(BUTTON_2) == 1 && Button_Status[1] == 1)
      {
        Button_Status[1] = 0;
      }
      /*Button 3 */
      if(nrf_gpio_pin_read(BUTTON_3) == 0 && Button_Status[2] == 0)
      {
        nrf_gpio_pin_toggle(LED3_pin);
        Button_Status[2] = 1;
      }
      else if(nrf_gpio_pin_read(BUTTON_3) == 1 && Button_Status[2] == 1)
      {
        Button_Status[2] = 0;
      }
      /*Button 4 */
      if(nrf_gpio_pin_read(BUTTON_4) == 0 && Button_Status[3] == 0)
      {
        nrf_gpio_pin_toggle(LED4_pin);
        Button_Status[3] = 1;
      }
      else if(nrf_gpio_pin_read(BUTTON_4) == 1 && Button_Status[3] == 1)
      {
        Button_Status[3] = 0;
      }
      nrf_delay_ms(1);
    }
}
/* the end ! */
