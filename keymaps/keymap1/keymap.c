/* Copyright 2018 James Laird-Wah
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
#include QMK_KEYBOARD_H
/* layer constants */
enum {
  DEF = 0,
  FUN,
  MOU,
  ARR
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(RESET, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TG(2), KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, RGB_MOD, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, KC_PGUP, KC_A, KC_S, LT(3,KC_D), KC_F, KC_G, KC_NO, KC_ENT, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_PGDN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_TAB, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS, KC_LSFT, KC_RSFT, KC_BSPC, KC_SPC, LCTL_T(KC_DEL), RCTL_T(KC_ENT), KC_LGUI, KC_RALT, MO(1), MO(1)),
	[1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO, KC_NO, KC_MINS, KC_7, KC_8, KC_9, KC_PAST, KC_NO, KC_NO, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV, KC_NO, KC_NO, KC_EQL, KC_4, KC_5, KC_6, KC_PPLS, KC_NO, KC_NO, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_DQUO, KC_UNDS, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, KC_NO, KC_QUOT, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO),
	[2] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TAB, KC_TRNS, KC_MS_U, KC_TRNS, KC_BTN3, KC_TRNS, RGB_TOG, KC_MPRV, KC_MNXT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_F12, KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_TRNS, KC_TRNS, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_END, KC_PSCR, KC_INS, KC_TRNS, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_BSLS, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO)
};/* template for new layouts:
LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                         _______,                                 _______,
                                            _______,                           _______,
                                               _______,                     _______,
                                                  _______,               _______,
                                      _______,                                        _______
  )
*/


static void set_numpad_colours(int r, int g, int b, void (*write)(int, uint8_t, uint8_t, uint8_t)) {
  for (int i=50; i<=60; i++) {
      write(i, r, g, b);
  }
  for (int i=10; i<=20; i++) {
      write(i, r, g, b);
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  if (state & (1<<MOU)) {
    set_numpad_colours(0, 0, 100, &set_led_to);
  } else if (state & (1<<FUN)) {
    set_numpad_colours(100, 0, 100, &set_led_to);
  } else if (state & (1<<ARR)) {
    set_numpad_colours(0, 100, 0, &set_led_to);
  } else {
    set_numpad_colours(0, 0, 0, &set_led_to);
  }

  return state;
}

/* vim: set ts=2 sw=2 et: */
