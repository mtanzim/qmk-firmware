/* Copyright 2020 marksard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// place overrides here

// If you use the HashTwenty(alpha), please enable USE_HASHTWENTY
// #define USE_HASHTWENTY

// If you plug in the USB on the right side, please enable MASTER_RIGHT
// #define MASTER_RIGHT
#ifdef OLED_ENABLE

void render_logo(void);
void update_key_status(uint16_t keycode, keyrecord_t *record);
void render_key_status(void);
void update_lock_status(void);
void render_lock_status(void);

#define RENDER_LOGO() render_logo()
#define UPDATE_KEY_STATUS(a, b) update_key_status(a, b)
#define RENDER_KEY_STATUS() render_key_status()
#define UPDATE_LOCK_STATUS() update_lock_status()
#define RENDER_LOCK_STATUS() render_lock_status()

#ifdef RGBLIGHT_ENABLE
  void update_led_status(void);
  void render_led_status(void);
  #define UPDATE_LED_STATUS() update_led_status()
  #define RENDER_LED_STATUS() render_led_status()
#else
  #define UPDATE_LED_STATUS()
  #define RENDER_LED_STATUS()
#endif

#else

#define RENDER_LOGO()
#define UPDATE_KEY_STATUS(a, b)
#define RENDER_KEY_STATUS()
#define UPDATE_LOCK_STATUS()
#define RENDER_LOCK_STATUS()
#define UPDATE_LED_STATUS()
#define RENDER_LED_STATUS()

#endif

#define OLED_FONT_H "glcdfont.c"