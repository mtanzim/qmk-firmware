// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#include QMK_KEYBOARD_H

enum layers {
  _ART_BASE,
  _ART_NUM,
  _ART_CUS,
  _ART_PUNC,
  _ART_MOU,
  _ART_NAV,
  _ART_SYM,
};

#include "aliases.c"
#include "combos.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ART_BASE] = LAYOUT(
    LT(_ART_SYM,KC_A),KC_R,KC_T,LT(_ART_NUM,KC_S),
    LT(_ART_PUNC,KC_E),KC_Y,KC_I,LT(_ART_CUS,KC_O)
),

[_ART_NUM] = LAYOUT(
    KC_1,KC_2,KC_3,KC_TRNS,
    KC_4,KC_5,KC_6,KC_TRNS
),


[_ART_PUNC] = LAYOUT(
    KC_EXLM,KC_BSLS,KC_SCLN,KC_GRV,
    KC_TRNS,KC_QUES,KC_MINS,KC_EQL
),

[_ART_CUS] = LAYOUT(
    KC_MPLY,KC_MUTE,KC_KB_VOLUME_UP,KC_TRNS,
    KC_MPRV,KC_MNXT,KC_KB_VOLUME_DOWN,KC_TRNS
),

[_ART_SYM] = LAYOUT(
    KC_TRNS,KC_LPRN,KC_RPRN,KC_LCBR,
    KC_TRNS,KC_LBRC,KC_RBRC,KC_RCBR
),

[_ART_MOU] = LAYOUT(
    KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,
    KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D
),

[_ART_NAV] = LAYOUT(
    KC_HOME,KC_UP,KC_END,KC_PGUP,
    KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN
),
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    
    // // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);

    // switch (get_highest_layer(layer_state)) {
    //     case _QWERTY:
    //         oled_write_P(PSTR("Default\n"), false);
    //         break;
    //     case _FN:
    //         oled_write_P(PSTR("FN\n"), false);
    //         break;
    //     case _ADJ:
    //         oled_write_P(PSTR("ADJ\n"), false);
    //         break;
    //     default:
    //         // Or use the write_ln shortcut over adding '\n' to the end of your string
    //         oled_write_ln_P(PSTR("Undefined"), false);
    // }

    // // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}