#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _COMBO 2
#define _COMBO_FL 3

#define _______ KC_TRNS

#define CTRL_ALT_CANC LALT(LCTL(KC_DEL))

#define M_COPY M(0)
#define M_PASTE M(1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Ins |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Home|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space/FN       |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_INS, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,  KC_RBRC, KC_BSLS,KC_DEL, \
  KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,  KC_ENT      ,    KC_HOME,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT, KC_UP,  KC_END, \
  TO(_COMBO), KC_LGUI,KC_LALT,                LT(_FL,KC_SPC),                        KC_RALT, MO(_FL), KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |~ `| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |~ ` |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |Del |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |PgUp|
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |PgDn|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC, KC_GRV ,  \
  _______,_______, _______,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______, \
  _______,_______,_______,_______, _______,_______, _______,_______,_______,_______,_______,_______, KC_PGUP, _______, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_HOME,KC_PGDN, KC_END),
/* Keymap _COMBO: (Combo Layer) Combination base Layer
   * ,----------------------------------------------------------------.
   * |Esc      | 1|  2|  3|  4|  5| 6| 7| 8| 9| 0|  [|  ]|Backsp |Ins |
   * |----------------------------------------------------------------|
   * |Tab  |  '|  ,|  .|  P|  Y|  Y|  U|  I|  O|  P|  /|  -|  \  |~ ` |
   * |----------------------------------------------------------------|
   * |Backsp|  A|  O|  E|  F|  G|  H|  J|  K|  L|  ;|  '|Return|KC_DEL|
   * |----------------------------------------------------------------|
   * |LShift|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|RShift| Up|COMBO |
   * |----------------------------------------------------------------|
   * |Menu|App |Gui |       Space        |Gui| App|Menu |Lef|Dow| Rig |
   * `----------------------------------------------------------------'
   */
  [_COMBO] = LAYOUT_ansi(
 KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPACE,KC_INS, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_GRAVE, \
  KC_BSPC,KC_A,ALT_T(KC_S),SFT_T(KC_D),CTL_T(KC_F),KC_G,KC_H,CTL_T(KC_J),SFT_T(KC_K),ALT_T(KC_L),KC_SCLN,KC_QUOT,KC_ENT,KC_DEL,  \
  KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSHIFT,KC_UP,TO(_BL), \
  KC_MENU, KC_APP, KC_LGUI,                LT(_COMBO_FL,KC_SPC),        KC_RGUI, KC_APP, KC_MENU, KC_LEFT,KC_DOWN,KC_RIGHT),
/* Keymap _COLEMAK_FL: Colemak Function Layer
   * ,----------------------------------------------------------------.
   * |~ `| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|PrtScr |Ins |
   * |----------------------------------------------------------------|
   * |     |   |    |   |   |   |    |Hme |Up|End|   |   |   |   |Del |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |Lft|Dwn|Rht|   |   |        |PgUp|
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |PgU|NOP|PgD |   |      |    |PgDn|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
 [_COMBO_FL] = LAYOUT_ansi(
  _______, KC_F1 ,  KC_F2,  KC_F3, KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9  , KC_F10, KC_F11, KC_F12,KC_PSCR,_______,  \
  _______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_UP  ,KC_END  ,_______,_______,_______, _______,_______, \
  _______  ,_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______, \
  _______  ,_______,_______,_______,_______,_______,_______,KC_PGUP,XXX,KC_PGDOWN ,_______,_______, KC_PGUP, _______, \
  _______  ,_______,_______,                 _______,               _______,_______   ,_______,KC_HOME, KC_PGDN, KC_END),

};
