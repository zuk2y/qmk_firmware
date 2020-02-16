#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,                         KC_JYEN, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_RBRC,                        KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_INS ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MHEN,                        KC_HENK, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RO,   \
    KC_LCTL, KC_LGUI, KC_LALT, KC_APP,           LOWER,   KC_LSFT, KC_LCTL,       KC_ENT, KC_SPC , RAISE,            KC_HOME, KC_END,  KC_PGUP, KC_PGDN  \
  ),

  /* Lower */
  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                         KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_EQL,                         KC_JYEN, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PEQL, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_PSCR,          _______, _______, _______,      _______, _______, _______,          _______, _______, _______, _______  \
  ),

  /* Raise */
  [_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                         KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, KC_UP,   _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, \
    _______, _______, _______, KC_PSCR,          _______, _______, _______,      _______, _______, _______,          _______, _______, _______, _______  \
  ),

  /* Adjust */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
