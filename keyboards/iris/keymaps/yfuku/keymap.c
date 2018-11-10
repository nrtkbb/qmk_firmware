#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

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

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_XXXX  KC_NO
#define KC_XXXXX KC_NO

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

//yfuku
#define KC_ KC_TRNS
#define KC_SFTESC LSFT_T(KC_ESC)
#define KC_CTLESC LCTL_T(KC_ESC)
#define KC_CMDESC LCMD_T(KC_ESC)

#define KC_L1SP LT(1, KC_SPC)
#define KC_L2ET LT(2, KC_ENT)
#define KC_ADJD MO(16)

#define KC_CMDL LCMD(KC_LEFT)
#define KC_CMDR LCMD(KC_RIGHT)

#define KC_CMDTAB LCMD(KC_TAB)

#define KC_CTLA LCTL(KC_A)
#define KC_CTLE LCTL(KC_E)
#define KC_CTLR LCTL(KC_RIGHT)
#define KC_CTLL LCTL(KC_LEFT)

#define KC_CTL1 CTL_T(KC_LANG1)
#define KC_CTL2 CTL_T(KC_LANG2)
#define KC_SFT1 LSFT_T(KC_LANG1)
#define KC_SFT2 LSFT_T(KC_LANG2)
#define KC_CMD1 LCMD_T(KC_LANG1)
#define KC_CMD2 LCMD_T(KC_LANG2)

#define KC_VD KC__VOLDOWN
#define KC_VU KC__VOLUP

#define KC_STAB S(KC_TAB)

#define KC_CTLBS LCTL_T(KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   CMDESC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,CMDESC, // esc/cmd 
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LALT, Z  , X  , C  , V  , B  ,LEFT,    RIGHT, N  , M  ,COMM,DOT ,SLSH,RALT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      CTLBS,SFT2,L1SP,         L2ET,SFT1,CTLBS
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     BSLS,LBRC,RBRC,EXLM,AMPR,PIPE,               AT  ,EQL ,PLUS,ASTR,PERC,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        RST,ADJD,XXXX,         DEL ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     BSLS,LBRC,RBRC,EXLM,AMPR,PIPE,               AT  ,EQL ,PLUS,ASTR,PERC,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     HASH,LPRN,RPRN,DQT ,QUOT,TILD,               LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     GRV ,LCBR,RCBR,    ,CIRC,DLR ,    ,       ,CMDTAB,CMDL,CMDR,CTLL,CTLR,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,BSPC,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,RMOD,RHUI,RSAI,RVAI,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,DBUG,RHUD,RSAD,RVAD,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,RST ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
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
