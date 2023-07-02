/*
 * main.c
 *
 *  Created on: 2 Jul 2023
 *      Author: george yaccoup
 */
#include "DIO_init.h"
#include "stdTypes.h"
#include <util/delay.h>
int main() {
	DIO_voidSetPinDirection(DIO_GROUP_C, DIO_PIN_0, DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_C, DIO_PIN_1, DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_A, DIO_PIN_0, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_GROUP_A, DIO_PIN_1, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_GROUP_A, DIO_PIN_2, DIO_OUTPUT);
	DIO_voidSetPinValue(DIO_GROUP_C, DIO_PIN_0, DIO_HIGH);
	DIO_voidSetPinValue(DIO_GROUP_C, DIO_PIN_1, DIO_HIGH);
	DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_0,DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_1,DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_2, DIO_LOW);
	u8 counter = 0;
	while (1) {
		if (DIO_u8GetPinValue(DIO_GROUP_C, DIO_PIN_0) == 0)
			counter++;
		if (DIO_u8GetPinValue(DIO_GROUP_C, DIO_PIN_1) == 0)
			counter--;
		if (counter == 1) {
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_0, DIO_HIGH);
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_1, DIO_LOW);
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_2, DIO_LOW);
			_delay_ms(500);
		}
		if (counter == 2) {
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_0, DIO_HIGH);
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_1, DIO_HIGH);
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_2, DIO_LOW);
			_delay_ms(500);

		}
		if (counter == 3) {
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_0, DIO_HIGH);
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_1, DIO_HIGH);
			DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_2, DIO_HIGH);
			_delay_ms(500);
		}

	}
}
