/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "whitefox.h"
#include "keymap_german.h"

#define _MAIN 0
#define _JUMP 1

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Main Layer
 * ,---------------------------------------------------------------.
 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Ins|
 * |---------------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del|
 * |---------------------------------------------------------------|
 * |Fn0   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
 * |---------------------------------------------------------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
 * |---------------------------------------------------------------|
 * |Ctrl|Gui |Alt |         Space         |Menu|Fn0 |  |Lef|Dow|Rig|
 * `---------------------------------------------------------------'
 */
[_MAIN] = KEYMAP(
  KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, DE_EQL,  DE_BSLS, DE_GRV,  KC_APP,

  KC_TAB,      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Y,    DE_U,    DE_I,    DE_O,    DE_P,    DE_LBRC, DE_RBRC, KC_BSPC,      KC_DEL,

  KC_FN0,          DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, DE_QUOT, XXXXXXX, KC_ENT,   KC_PGUP,

  KC_LSFT,    XXXXXXX, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_RSFT,       KC_UP,   KC_PGDN,

  KC_LCTL,    KC_LGUI,    KC_LALT,                         KC_SPC,                          KC_MENU, KC_FN0,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
),


/* Jump Layer
 * ,---------------------------------------------------------------.
 * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |RST|
 * |---------------------------------------------------------------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |INS|
 * |---------------------------------------------------------------|
 * |      |   |   |   |   |   |   |   |   |   |   |   |        |HOM|
 * |---------------------------------------------------------------|
 * |        |   |   |   |   |   |   |   |   |   |   |      |   |END|
 * |---------------------------------------------------------------|
 * |    |    |    |                       |    |    |  |   |   |   |
 * `---------------------------------------------------------------'
 */
[_JUMP] = KEYMAP(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, RESET,

  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_INS,

  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,  KC_HOME,

  _______,    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, KC_END,

  _______,    _______,    _______,                         _______,                         _______, _______, XXXXXXX, _______, _______, _______
),

};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(_JUMP),
};
