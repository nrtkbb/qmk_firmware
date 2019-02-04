#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    MO(_FN2), KC_VOLU,  KC_MPLY,  KC_MPRV, \
    MO(_FN1), KC_VOLD,  KC_MUTE,  KC_MNXT, \
    KC_F1,    KC_F2,    KC_VOLD,  KC_VOLU, \
    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    KC_ESC,   KC_P7,    KC_P8,    KC_P9,   \
    KC_TAB,   KC_P4,    KC_P5,    KC_P6,   \
    KC_ENT,   KC_P1,    KC_P2,    KC_P3,   \
    _______,  KC_P0,    KC_P0,    KC_DOT   \
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI, \
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD, \
    _______,  _______,  _______,  RESET,  \
    BL_STEP,  _______,  _______,  _______  \
  )

};
