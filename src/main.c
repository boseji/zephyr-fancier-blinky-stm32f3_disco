/*
 * Copyright (c) 2020 Abhijit Bose <https://boseji.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

void main(void)
{
	struct device *gpioe;
	int i;
	/* LED Pins */
	uint8_t pins[] = {9 /*LD3*/, 10 /*LD5*/, 11 /*LD7*/, 12 /*LD9*/,
			13 /*LD10*/, 14 /*LD8*/, 15 /*LD6*/, 8 /*LD4*/};

	/* Get instance of GPIOE */
	gpioe = device_get_binding("GPIOE");
	if (gpioe == NULL) {
		return;
	}

	/* Enabled All pins for Output*/
	for (i=0;i<sizeof(pins);i++) {
		gpio_pin_configure(gpioe, pins[i], GPIO_OUTPUT_ACTIVE);
	}

	/* Perform Initial configuration */
	i = 0;
	gpio_pin_set(gpioe, pins[i], 0); // For the fist time ON

	/* Start the Infinite Loop */
	while (1) {

		/* First GPIO Toggle */
		gpio_pin_toggle(gpioe, pins[i]);
		/* Increment the Counter avoiding overflow */
		if (i < sizeof(pins)-1) {
			i++;
		}
		else {
			i = 0;
		}
		/* Second GPIO Toggle - give the ripple effect */
		gpio_pin_toggle(gpioe, pins[i]);
		/* Wait for a short time */
		k_msleep(60);

	}/* End of While */
}
