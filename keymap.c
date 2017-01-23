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
#define _RIFT 1
#define _JUMP 2

enum whitefox_keycodes {
	RIFT = SAFE_RANGE,
	JUMP,
	RF_AT,
	RF_HASH,
	RF_CIRC,
	RF_PLUS,
	RF_PIPE,
	RF_TILD,
	RF_LCBR,
	RF_RCBR,
	RF_LESS,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define RF_AMPR DE_6
#define RF_ASTR DE_PLUS
#define RF_LPRN DE_8
#define RF_RPRN DE_9
#define RF_COLN DE_DOT
#define RF_DQOT DE_2
#define RF_MORE DE_LESS
#define RF_QST  DE_SS

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

  KC_TAB,      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_LBRC, DE_RBRC, KC_BSPC,      KC_DEL,

  JUMP,            DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, DE_QUOT, XXXXXXX, KC_ENT,   KC_PGUP,

  RIFT,       XXXXXXX, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, RIFT,          KC_UP,   KC_PGDN,

  KC_LCTL,    KC_LGUI,    KC_LALT,                         KC_SPC,                          KC_MENU, JUMP,    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
),


/* Rift Layer
 * ,---------------------------------------------------------------.
 * |   |   |  @|  #|   |   |  ^|  &|  *|  (|  )|   |  +|  ||  ~|   |
 * |---------------------------------------------------------------|
 * |     |   |   |   |   |   |   |   |   |   |   |  {|  }|     |   |
 * |---------------------------------------------------------------|
 * |      |   |   |   |   |   |   |   |   |   |  :|  "|        |   |
 * |---------------------------------------------------------------|
 * |        |   |   |   |   |   |   |   |  <|  >|  ?|      |   |   |
 * |---------------------------------------------------------------|
 * |    |    |    |                       |    |    |  |   |   |   |
 * `---------------------------------------------------------------'
 */
[_RIFT] = KEYMAP(
  _______, _______, RF_AT,   RF_HASH, _______, _______, RF_CIRC, RF_AMPR, RF_ASTR, RF_LPRN, RF_RPRN, _______, RF_PLUS, RF_PIPE, RF_TILD, _______,

  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RF_LCBR, RF_RCBR, _______,      _______,

  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, RF_COLN, RF_DQOT, XXXXXXX, _______,  _______,

  _______,    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, RF_LESS, RF_MORE, RF_QST,  _______,       _______, _______,

  _______,    _______,    _______,                         _______,                         _______, _______, XXXXXXX, _______, _______, _______
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
	switch (keycode) {
		case RIFT:
			if (record->event.pressed) {
				layer_on(_RIFT);
				register_mods(MOD_BIT(KC_LSFT));
			} else {
				layer_off(_RIFT);
				unregister_mods(MOD_BIT(DE_ALGR));
			unregister_mods(MOD_BIT(KC_LSFT));
			}
			return false;
			break;
		case JUMP:
			if (record->event.pressed) {
				layer_on(_JUMP);
			} else {
				layer_off(_JUMP);
			}
			return false;
			break;
		case RF_HASH:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
		case RF_CIRC:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
		case RF_PLUS:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
		case RF_PIPE:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
		case RF_TILD:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
		case RF_LCBR:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
		case RF_RCBR:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
		case RF_LESS:
			if (record->event.pressed) {
			} else {
			}
			return false;
			break;
	};
	return true;
};

