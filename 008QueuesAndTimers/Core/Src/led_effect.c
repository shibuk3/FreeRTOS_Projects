/*
 * led_effect.c
 *
 *  Created on: Apr 21, 2024
 *      Author: shibu
 */


#include "main.h"

void led_effect_stop(void)
{
	xTimerStop(handle_led_timer,portMAX_DELAY);
}

void led_effect()
{
	led_effect_stop();
	xTimerStart(handle_led_timer,portMAX_DELAY);
}

void turn_on_led()
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
}

void turn_off_led()
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}

void LED_effect1()
{
	static int flag = 1;
	(flag ^= 1) ? turn_off_led() : turn_on_led();
}
