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

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

// common
#define KC_ KC_TRNS
#define KC_XXXX KC_NO
#define KC_RST RESET
#define KC_VD KC__VOLDOWN
#define KC_VU KC__VOLUP

// layer
#define KC_L_SPC LT(_LOWER, KC_SPC)
#define KC_R_ENT LT(_RAISE, KC_ENT)

// shift_t
#define KC_S_TAB LSFT_T(KC_TAB)
#define KC_S_ESC LSFT_T(KC_ESC)
#define KC_S_JA LSFT_T(KC_LANG1)
#define KC_S_EN LSFT_T(KC_LANG2)

// cmd_t
#define KC_M_F LCMD_T(KC_F)
#define KC_M_D LCMD_T(KC_D)
#define KC_M_J LCMD_T(KC_J)
#define KC_M_K LCMD_T(KC_K)

// ctl_t
#define KC_C_S LCTL_T(KC_S)
#define KC_C_L LCTL_T(KC_L)

// alt_t
#define KC_A_D ALT_T(KC_D)
#define KC_A_K ALT_T(KC_K)
#define KC_A_Z ALT_T(KC_Z)
#define KC_A_SL ALT_T(KC_SLSH)

// cmd+shift
#define KC_MS_A SCMD_T(KC_A)
#define KC_MS_SC SCMD_T(KC_SCLN)

//
#define KC_MR RCMD(KC_R)
#define KC_MF RCMD(KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // M_ = LCMD_T(
  // A_ = ALT_T(
  // C_ = LCTL_T(
  // MS_ = SMD_T(
  // R_ = LT(_RAISE
  // L_ = LT(_LOWER

  [_QWERTY] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         , Q  , W  , E  , R  , T  ,       Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
    S_TAB,MS_A,C_S ,A_D ,M_F , G  ,       H  ,M_J ,A_K ,C_L,MS_SC,S_ESC,
  //|----+----+----+----+----+----+     |----+----+----+----+----+----|
         , Z  , X  , C  , V  , B  ,       N  , M  ,COMM,DOT ,SLSH,    ,
  //`----+----+----+----+----+----/     \----+----+----+----+----+----'
               DEL,S_EN,L_SPC,BSPC,      BSPC,R_ENT,S_JA,DEL
  //          `----+----+----+----'     `----+----+----+----'
  ),

  //   \ ^ ! & |  @ = + * % -
  // ( # $ " ' ~  ← ↓ ↑ → ` )
  //         { [  ] }

  [_RAISE] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,BSLS,CIRC,EXLM,AMPR,PIPE,      AT  ,EQL ,PLUS,ASTR,PERC,MINS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LPRN,HASH,DLR ,DQT ,QUOT,TILD,      LEFT,DOWN, UP ,RGHT,GRV ,RPRN,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
        ,     ,    ,    ,LCBR,LBRC,      RBRC,RCBR,    ,    ,    ,    ,
  //`----+----+----+----+----+----/     \----+----+----+----+----+----'
                   ,    ,BSPC,    ,          ,    ,    ,RST
  //          `----+----+----+----'     `----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,          ,EQL ,PLUS,ASTR,PERC,MINS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,       6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,    ,COMM,DOT ,SLSH,    ,
  //`----+----+----+--+-+----+----/     \----+----+----+----+----+----'
               RST ,    ,    ,    ,          ,DEL ,    ,
  //          `----+----+----+----'     `----+----+----+----'
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
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
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}

