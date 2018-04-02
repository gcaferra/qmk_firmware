#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _COLEMAK 2
#define _COLEMAK_FL 3

#define _______ KC_TRNS

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
[_BL] = KEYMAP_ANSI(
    KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_INS, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_HOME,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_END, \
  TO(_COLEMAK), KC_LGUI,KC_LALT,                LT(_FL,KC_SPC),                        KC_RALT, MO(_FL), KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

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
[_FL] = KEYMAP_ANSI(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC, KC_GRV ,  \
  _______,_______, _______,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_DEL, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,KC_PGUP, \
  _______,_______,_______,_______, _______,_______, _______,_______,_______,_______,_______,_______, _______, KC_PGDN, \
  _______,_______,_______,                 _______,               _______,_______,_______,_______,_______, _______),
/* Keymap _COLEMAK: (Colemak Layer) Colemak base Layer
    * ,----------------------------------------------------------------.
    * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|Backsp |~ `|
   * |----------------------------------------------------------------|
   * |Tab  |  '|  ,|  .|  P|  Y|  Y|  U|  I|  O|  P|  /|  -|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  O|  E|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Home|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Base|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [_COLEMAK] = KEYMAP_ANSI(
  KC_GESC,  KC_1   , KC_2   , KC_3  ,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, KC_INS, \
  KC_TAB,  KC_Q, KC_W, KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCOLON, KC_LBRC, KC_RBRC, KC_BSLASH, KC_DEL, \
  KC_LCTL, KC_A,   KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,   KC_O  ,KC_QUOTE,     KC_ENT,KC_HOME,  \
  KC_LSFT,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   KC_COMMA, KC_DOT, KC_SLASH,   KC_RSFT,KC_UP,KC_END, \
  TO(_BL), KC_LGUI,KC_LALT,                LT(_COLEMAK_FL, KC_SPC),                        KC_APP, MO(_COLEMAK_FL), KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),
/* Keymap _COLEMAK_FL: Colemak Function Layer
   * ,----------------------------------------------------------------.
   * |~ `| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
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
 [_COLEMAK_FL] = KEYMAP_ANSI(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC, KC_GRV ,  \
  _______,_______, _______,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_DEL, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,KC_PGUP, \
  _______,_______,_______,_______, _______,_______, _______,_______,_______,_______,_______,_______, _______, KC_PGDN, \
  _______,_______,_______,                 _______,               _______,_______,_______,_______,_______, _______),

};
