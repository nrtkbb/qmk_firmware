#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 3
#define SYMB 4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

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

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc |=>GAME|=>SYMB|  \   |
   * |      |      |      |      |~SYMB |Cmd   |Shift |   |Space |~META |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    _______,  _______, KC_W,    KC_E,     KC_R,     KC_T,     KC_LBRC,      KC_RBRC, KC_Y,      KC_U,      KC_I,    KC_O,    _______, _______ , \
    KC_TAB,   KC_Q,    KC_S,    KC_D,     KC_F,     KC_G,     KC_LPRN,      KC_RPRN, KC_H,      KC_J,      KC_K,    KC_L,    KC_P,    KC_MINS , \
    KC_S_ESC, KC_A,    KC_X,    KC_C,     KC_V,     KC_B,     KC_LCBR,      KC_RCBR, KC_N,      KC_M,      KC_COMM, KC_DOT,  KC_SCLN, KC_S_ESC, \
    _______,  KC_Z,    _______, KC_A_DEL, KC_L1_EN, KC_M_SPC, KC_C_BS,      KC_C_BS, KC_L2_ENT, KC_L1_JA, KC_A_DEL, _______, KC_SLSH, _______ \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   1  |   2  |   3  |   4  |   5  |   6  |  [   |   |  ]   |   7  |   8  |   9  |   0  |   -  |  ^   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |  F1  |      |Muhen | Henk |      |  (   |   |  )   | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |Reset |=>GAME|=>SYMB|  \   |
   * |      |      |      |      |~SYMB |Ctrl  |Shift |   |Space |~META |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    _______, _______, KC_RBRC, KC_EXLM, KC_AMPR, KC_PIPE, _______,   _______, KC_AT,   KC_EQL,  KC_PLUS, KC_ASTR, _______, _______, \
    KC_BSLS, KC_LBRC, KC_2,    KC_3,    KC_4,    KC_5,    _______,   _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_PERC, _______, \
    _______, KC_1,    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, KC_0,    _______, \
    RESET,   _______, _______, _______, _______, _______, _______,   KC_SPC,  _______, _______, _______, _______, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   !  |   "  |   #  |   $  |   %  |   &  |  [   |   |  ]   |   '  |   (  |   )  |   ~  |   =  |  ~   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |   +  |  *   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  \   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc |=>GAME|=>SYMB|  \   |
   * |      |      |      |      |~SYMB |Ctrl  |Shift |   |Space |~META |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
     _______, _______, KC_RBRC, KC_EXLM, KC_AMPR, KC_PIPE, _______,   _______, KC_AT,   KC_EQL,  KC_PLUS, KC_ASTR, _______, _______, \
     KC_BSLS, KC_LBRC, KC_RPRN, KC_DQT , KC_QUOT, KC_TILD, _______,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PERC, _______, \
     KC_HASH, KC_LPRN, KC_RCBR, _______, KC_CIRC, KC_DLR,  _______,   _______, _______, KC_CMDL, KC_CMDR, KC_CAL,  _______, _______, \
     KC_GRV , KC_LCBR, _______, _______,  KC_HA,  KC_BSPC,  KC_ENT,   _______, _______, _______, _______, _______, KC_CAR,  _______ \
  ),
};

