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
#include "shiftlayer.h"

static uint16_t tap_timer;

#define _MAIN 0
#define _RIFT 1
#define _MODS 2
#define _STEP 3
#define _JUMP 4
#define _WAKE 5

enum whitefox_keycodes {
	RIFT = SAFE_RANGE,
	STEP,
	JUMP,
	MCTL,
	MGUI,
	MALT,
	RF_AT,
	RF_HASH,
	RF_CIRC,
	RF_PLUS,
	RF_PIPE,
	RF_TILD,
	RF_LCBR,
	RF_RCBR,
	RF_LESS,
	GB_PWR,
	GB_WAKE,
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
#define GB_LOCK LCTL(LALT(KC_L))

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Main Layer
 * ,---------------------------------------------------------------.
 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Lck|
 * |---------------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del|
 * |---------------------------------------------------------------|
 * |Step  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
 * |---------------------------------------------------------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
 * |---------------------------------------------------------------|
 * |Ctrl|Gui |Alt |         Space         |Menu|Jump|  |Lef|Dow|Rig|
 * `---------------------------------------------------------------'
 */
[_MAIN] = KEYMAP(
  KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, DE_EQL,  DE_BSLS, DE_GRV,  GB_LOCK,

  KC_TAB,      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_LBRC, DE_RBRC, KC_BSPC,      KC_DEL,

  STEP,            DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, DE_QUOT, XXXXXXX, KC_ENT,   KC_PGUP,

  RIFT,       XXXXXXX, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, RIFT,          KC_UP,   KC_PGDN,

  MCTL,       MGUI,       MALT,                            KC_SPC,                          KC_MENU, JUMP,    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
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


/* Mods Layer (will activate on pressing Ctrl, Alt and GUI keys to compensate for strange keymap)
 * ,---------------------------------------------------------------.
 * |   |   |  2|  3|   |   |  6|  7|  8|  9|  0|   |   |   |   |   |
 * |---------------------------------------------------------------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
 * |---------------------------------------------------------------|
 * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
 * |---------------------------------------------------------------|
 * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
 * |---------------------------------------------------------------|
 * |    |    |    |                       |    |    |  |   |   |   |
 * `---------------------------------------------------------------'
 */
[_MODS] = KEYMAP(
  _______, _______, DE_2,    DE_3,    _______, _______, DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    _______, _______, _______, _______, XXXXXXX,

  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,

  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,  _______,

  _______,    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,

  _______,    _______,    _______,                         _______,                         _______, _______, XXXXXXX, _______, _______, _______
),

/* Step Layer
 * ,---------------------------------------------------------------.
 * |RST| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|SCR|SCL|BRK|
 * |---------------------------------------------------------------|
 * |     |   |   |  €|   |   |   |  ü|   |  ö|   |   |   |     |INS|
 * |---------------------------------------------------------------|
 * |      |  ä|  ß|   |   |   |   |   |   |   |   |   |        |HOM|
 * |---------------------------------------------------------------|
 * |        |   |   |   |   |   |   |  µ|   |   |   |      |   |END|
 * |---------------------------------------------------------------|
 * |    |    |    |                       |    |    |  |   |   |   |
 * `---------------------------------------------------------------'
 */
[_STEP] = KEYMAP(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, XXXXXXX,

  XXXXXXX,     XXXXXXX, XXXXXXX, DE_EURO, XXXXXXX, XXXXXXX, XXXXXXX, DE_UE,   XXXXXXX, DE_OE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_INS,

  _______,         DE_AE,   DE_SS,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_HOME,

  _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_MU,   XXXXXXX, XXXXXXX, XXXXXXX, _______,       XXXXXXX, KC_END,

  _______,    _______,    _______,                         XXXXXXX,                         XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Jump Layer
 * ,---------------------------------------------------------------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
 * |---------------------------------------------------------------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
 * |---------------------------------------------------------------|
 * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
 * |---------------------------------------------------------------|
 * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
 * |---------------------------------------------------------------|
 * |    |    |    |                       |    |    |  |   |   |   |
 * `---------------------------------------------------------------'
 */
[_JUMP] = KEYMAP(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GB_PWR,

  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_BTN3,

  KC_CAPS,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2,  KC_WH_U,

  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1,       KC_MS_U, KC_WH_D,

  XXXXXXX,    XXXXXXX,    XXXXXXX,                         XXXXXXX,                         XXXXXXX, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R
),

/* Wake Layer
 * ,---------------------------------------------------------------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
 * |---------------------------------------------------------------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
 * |---------------------------------------------------------------|
 * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
 * |---------------------------------------------------------------|
 * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
 * |---------------------------------------------------------------|
 * |    |    |    |                       |    |    |  |   |   |   |
 * `---------------------------------------------------------------'
 */
[_WAKE] = KEYMAP(
  GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE,

  GB_WAKE,     GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE,      GB_WAKE,

  GB_WAKE,         GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE,  GB_WAKE,

  GB_WAKE,    GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE,       GB_WAKE, GB_WAKE,

  GB_WAKE,    GB_WAKE,    GB_WAKE,                         GB_WAKE,                         GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE, GB_WAKE
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
	switch (keycode) {
		case RIFT:
			if (record->event.pressed) {
				shiftlayer_on(_RIFT, MOD_BIT(KC_LSFT));
			} else {
				shiftlayer_off(_RIFT, MOD_BIT(KC_LSFT));
			}
			return false;
			break;
		case STEP:
			if (record->event.pressed) {
				layer_on(_STEP);
			} else {
				layer_off(_STEP);
			}
			return false;
			break;
		case JUMP:
			if (record->event.pressed) {
				clear_mods();
				layer_on(_JUMP);
			} else {
				layer_off(_JUMP);
			}
			return false;
			break;
		case MCTL:
			if (record->event.pressed) {
				modlayer_on(_MODS, MOD_BIT(KC_LCTL));
			} else {
				modlayer_off(_MODS, MOD_BIT(KC_LCTL), (MOD_BIT(KC_LCTL)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)));
			}
			return false;
			break;
		case MGUI:
			if (record->event.pressed) {
				modlayer_on(_MODS, MOD_BIT(KC_LGUI));
			} else {
				modlayer_off(_MODS, MOD_BIT(KC_LGUI), (MOD_BIT(KC_LCTL)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)));
			}
			return false;
			break;
		case MALT:
			if (record->event.pressed) {
				modlayer_on(_MODS, MOD_BIT(KC_LALT));
			} else {
				modlayer_off(_MODS, MOD_BIT(KC_LALT), (MOD_BIT(KC_LCTL)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)));
			}
			return false;
			break;
		case RF_AT:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_Q, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			} else {
				unregister_shiftlayer_code(DE_Q, _RIFT, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			}
			return false;
			break;
		case RF_HASH:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_HASH, MOD_BIT(KC_LSFT), 0);
			} else {
				unregister_shiftlayer_code(DE_HASH, _RIFT, MOD_BIT(KC_LSFT), 0);
			}
			return false;
			break;
		case RF_CIRC:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_CIRC, MOD_BIT(KC_LSFT), 0);
			} else {
				unregister_shiftlayer_code(DE_CIRC, _RIFT, MOD_BIT(KC_LSFT), 0);
			}
			return false;
			break;
		case RF_PLUS:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_PLUS, MOD_BIT(KC_LSFT), 0);
			} else {
				unregister_shiftlayer_code(DE_PLUS, _RIFT, MOD_BIT(KC_LSFT), 0);
			}
			return false;
			break;
		case RF_PIPE:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_LESS, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			} else {
				unregister_shiftlayer_code(DE_LESS, _RIFT, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			}
			return false;
			break;
		case RF_TILD:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_PLUS, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			} else {
				unregister_shiftlayer_code(DE_PLUS, _RIFT, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			}
			return false;
			break;
		case RF_LCBR:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_7, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			} else {
				unregister_shiftlayer_code(DE_7, _RIFT, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			}
			return false;
			break;
		case RF_RCBR:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_0, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			} else {
				unregister_shiftlayer_code(DE_0, _RIFT, MOD_BIT(KC_LSFT), MOD_BIT(DE_ALGR));
			}
			return false;
			break;
		case RF_LESS:
			if (record->event.pressed) {
				register_shiftlayer_code(DE_LESS, MOD_BIT(KC_LSFT), 0);
			} else {
				unregister_shiftlayer_code(DE_LESS, _RIFT, MOD_BIT(KC_LSFT), 0);
			}
			return false;
			break;
		case GB_PWR:
			if (record->event.pressed) {
				tap_timer = timer_read();
			} else {
				if (timer_elapsed(tap_timer) < 2000) {
					layer_on(_WAKE);
					register_code(KC_SLEP);
					unregister_code(KC_SLEP);
				} else {
					register_code(KC_PWR);
					unregister_code(KC_PWR);
				}
			}
			return false;
			break;
		case GB_WAKE:
			if (record->event.pressed) {
				register_code(KC_WAKE);
				unregister_code(KC_WAKE);
				layer_off(_WAKE);
			}
			return false;
			break;
	};
	return true;
};

