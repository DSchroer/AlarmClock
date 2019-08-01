/* Nokia 5110 LCD AVR Library
 *
 * Copyright (C) 2015 Sergey Denisov.
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 *
 * Original library written by SkewPL, http://skew.tk
 */

#ifndef __NOKIA_5110_H__
#define __NOKIA_5110_H__

#include <avr/pgmspace.h>
#include <stdint.h>

/*
 * LCD's port
 */
#define PORT_LCD PORTB
#define DDR_LCD DDRB

/*
 * LCD's pins
 */
#define LCD_SCE PB0
#define LCD_RST PB1
#define LCD_DC PB2
#define LCD_DIN PB3
#define LCD_CLK PB4

#define LCD_CONTRAST 0x40

/*
 * Must be called once before any other function, initializes display
 */
void nokia_lcd_init(void);

/*
 * Clear screen
 */
void nokia_lcd_clear(void);

/**
 * Power of display
 * @lcd: lcd nokia struct
 * @on: 1 - on; 0 - off;
 */
void nokia_lcd_power(uint8_t on);

/**
 * Set single pixel
 * @x: horizontal pozition
 * @y: vertical position
 * @value: show/hide pixel
 */
void nokia_lcd_set_pixel(uint8_t x, uint8_t y, uint8_t value);

/*
 * Render screen to display
 */
void nokia_lcd_render(void);

#endif
