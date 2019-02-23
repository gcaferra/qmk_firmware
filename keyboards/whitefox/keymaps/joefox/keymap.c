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

#define _BL 0
#define _FL 1
#define _MAC_BL 2
#define _MAC_FL 3

#define PERMISSIVE_HOLD 1

#define CTRL_AC LALT(LCTL(KC_DEL))

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|  \|Ins|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del|
     * |---------------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |Hom|
     * |---------------------------------------------------------------|
     * |Shif|   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |End|
     * |---------------------------------------------------------------|
     * |Fn0|Gui |Alt |         Space/Fn0|Fn0 |Alt |Gui |   |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [_BL] = LAYOUT( \
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_MINS,KC_EQL, KC_GRV, TO(_MAC_BL), KC_INS, \
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, \
        KC_BSPACE,KC_A,ALT_T(KC_S),SFT_T(KC_D),CTL_T(KC_F),KC_G,KC_H,CTL_T(KC_J),SFT_T(KC_K),ALT_T(KC_L),KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,KC_HOME,\
        KC_LSHIFT,KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSHIFT,  KC_UP,  KC_END,\
        KC_RGUI,  KC_RCTRL,  KC_LALT,             LT(_FL,KC_SPC)      ,       KC_RALT,KC_RGUI, KC_TRNS,     KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    [_FL] = LAYOUT( \
        KC_TRNS,KC_F1,KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7, KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_GRAVE,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_PSCR,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_VOLU,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_PGUP,KC_VOLD,\
        KC_TRNS,KC_TRNS,KC_TRNS,               KC_TRNS,                         KC_TRNS,KC_TRNS,KC_TRNS,     KC_HOME,KC_PGDN,KC_END  \
    ),
    [_MAC_BL] = LAYOUT( \
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4, KC_5,  KC_6,   KC_7,   KC_8,   KC_9,  KC_0, KC_MINS,KC_EQL, KC_GRV, TO(_BL), KC_INS, \
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC, KC_BSLS,    KC_DEL, \
        KC_BSPC,KC_A,ALT_T(KC_S),SFT_T(KC_D),CTL_T(KC_F),KC_G,KC_H,CTL_T(KC_J),SFT_T(KC_K),ALT_T(KC_L),KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,      KC_HOME,\
        KC_LSFT,KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,  KC_END,\
        KC_RGUI,KC_RCTL, KC_LALT,             LT(_MAC_FL,KC_SPC)   ,       KC_APP,KC_RGUI, KC_TRNS,     KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    [_MAC_FL] = LAYOUT( \
        KC_ESC,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_GRAVE,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_PSCR,KC_SLCK,KC_PAUS,KC_TRNS,     KC_PSCR,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_VOLU,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_PGUP,KC_VOLD,\
        KC_TRNS,KC_TRNS,KC_TRNS,               KC_TRNS,                         KC_TRNS,KC_TRNS,KC_TRNS,     KC_HOME,KC_PGDN,KC_END  \
    ),
};
