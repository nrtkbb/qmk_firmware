#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXX  KC_NO
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

#define KC_LRBW RGB_M_R

// yfuku
#define KC_ KC_TRNS

#define KC_L1_JA LT(3, KC_LANG1)
#define KC_L2_JA LT(4, KC_LANG1)
#define KC_L1_EN LT(3, KC_LANG2)
#define KC_L2_EN LT(4, KC_LANG2)
#define KC_L1_SPC LT(3, KC_SPC)
#define KC_L2_ENT LT(4, KC_ENT)

#define KC_ADJD MO(16)
#define KC_VD KC__VOLDOWN
#define KC_VU KC__VOLUP

#define KC_CMDTAB LCMD(KC_TAB)
#define KC_CMDSPC LCMD(KC_SPC)
#define KC_CMDL LCMD(KC_LEFT)
#define KC_CMDR LCMD(KC_RIGHT)

#define KC_CL RCTL(KC_L)
#define KC_CA LCTL(KC_A)
#define KC_CE LCTL(KC_E)
#define KC_CAR LCTL(KC_RIGHT)
#define KC_CAL LCTL(KC_LEFT)

// shift_t
#define KC_S_ESC LSFT_T(KC_ESC)
#define KC_S_BS LSFT_T(KC_BSPC)
#define KC_S_L1 LSFT_T(KC_LANG1)
#define KC_S_L2 LSFT_T(KC_LANG2)
#define KC_S_MINS LSFT_T(KC_MINS)
#define KC_S_TAB LSFT_T(KC_TAB)
#define KC_S_JA LSFT_T(KC_LANG1)
#define KC_S_EN LSFT_T(KC_LANG2)

// cmd_t
#define KC_M_BS LCMD_T(KC_BSPC)
#define KC_M_DEL LCMD_T(KC_DEL)
#define KC_M_ESC LCMD_T(KC_ESC)
#define KC_M_EN LCMD_T(KC_LANG2)
#define KC_M_JA LCMD_T(KC_LANG1)
#define KC_M_SPC LCMD_T(KC_SPC)

// ctl_t
#define KC_C_ESC LCTL_T(KC_ESC)
#define KC_C_L1 CTL_T(KC_LANG1)
#define KC_C_L2 CTL_T(KC_LANG2)
#define KC_C_BS LCTL_T(KC_BSPC)
#define KC_C_DEL LCTL_T(KC_DEL)
#define KC_C_TAB LCTL_T(KC_TAB)
#define KC_C_MINS LCTL_T(KC_MINS)
#define KC_C_ENT LCTL_T(KC_ENT)

// alt_t
#define KC_A_ESC ALT_T(KC_ESC)
#define KC_A_DEL ALT_T(KC_DEL)

// hyper
#define KC_HA HYPR(KC_A)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc( \
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     TAB , Q  , W  , E  , R  , T  ,XXXX,      XXXX, Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
    S_ESC, A  , S  , D  , F  , G  ,LPRN,      RPRN, H  , J  , K  , L  ,SCLN,S_ESC,
  //|----+----+----+----+----+----+----+     |----+----+----+----+----+----+----|
     XXXX, Z  , X  , C  , V  , B  ,LBRC,      RBRC, N  , M  ,COMM,DOT ,SLSH,XXXX,
  //`----+----+----+----+----+----+----/     \----+----+----+----+----+----+----'
                 A_DEL,S_EN,M_SPC,C_BS,     C_BS,L2_ENT,S_JA,A_DEL
  //               `----+----+----+----'    `----+----+----+----'
  ), 

  [_RAISE] = LAYOUT_kc( \
  //   \ ^ ! & |      @ = + * % -
  // ` # $ " ' ~ 
  //      

  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
         ,BSLS,CIRC,EXLM,AMPR,PIPE,XXXX,      XXXX,AT  ,EQL ,PLUS,ASTR,PERC,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     GRV ,HASH,DLR ,DQT ,QUOT,TILD,CMDR,      CMDL,LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     XXXX, 1  , 2  , 3  , 4  , 5  ,CAR ,      CAL , 6  , 7  , 8  , 9  , 0  ,XXXX,
  //`----+----+----+----+----+----+----/     \----+----+----+----+----+----+----'
                        , HA ,BSPC,ENT ,         ,    ,    ,  
  //               `----+----+----+----'    `----+----+----+----'
  ),
 
  [_LOWER] = LAYOUT_kc( \
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----/     \----+----+----+----+----+----+----'
                        ,    ,    ,    ,         ,    ,    ,    
  //               `----+----+----+----'    `----+----+----+----'
  ),
 
 [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RST,  LRST,  LRBW, XXXXX, XXXXX, XXXXX,      ,         , F1   , F2   , VD   , VU   , XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,      ,         , XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,      ,         , XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                           GUIEI, LOWER,   SPC,XXXXX,    XXXXX,    ENT, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

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
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

