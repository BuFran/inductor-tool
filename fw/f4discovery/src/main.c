/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <stdio.h>
#include <errno.h>
#include <stddef.h>
#include <sys/types.h>

#include "leds.h"
#include "serial.h"
#include "pwm.h"

static uint8_t rbuf[1024];
static uint8_t tbuf[1024];

int main(void)
{
    rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_168MHZ]);

    leds_init();
    pwm_init();

	FILE* us2 = fopenserial(1, 115200, tbuf,1024,rbuf,1024);

	while (1) {
        fprintf(us2,"X");

		for (int i = 0; i < 10000000; i++)	/* Wait a bit. */
			__asm__("nop");

        LED_TGL(LED0);
	}

	return 0;
}
