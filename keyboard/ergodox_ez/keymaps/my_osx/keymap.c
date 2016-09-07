// make clean && make KEYMAP=my_osx SLEEP_LED_ENABLE=no
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_german.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define MUSE 3 // media keys

#define M_UENT 10
#define M_DENT 11
#define M_AROW 12

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  `   |           |  *   |   6  |   7  |   8  |   9  |   0  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  '   |           |  +   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Cmd    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------|  "   |           |  =   |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  | Cmd  |      |  L3  |                                       | Left |  Up  | Down |Right |  _   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Copy |Paste |       |VolUp |Enter |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Cut  |       |VolDn |        |      |
 *                                 |  L1  |Space |------|       |------|  L3    |  L2  |
 *                                 |      |      |  L3  |       |  L3  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,        KC_2,   KC_3,   KC_4,   KC_5,   KC_GRV,
        KC_TAB,   KC_Q,        KC_W,   KC_E,   KC_R,   KC_T,   KC_QUOT,
        KC_LGUI,  KC_A,        KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,  CTL_T(KC_Z), KC_X,   KC_C,   KC_V,   KC_B,   KC_DQUO,
        KC_LCTL,  KC_LALT,     KC_LGUI,KC_NO,  MO(MUSE),
                                               LGUI(KC_C), LGUI(KC_V),
                                                           LGUI(KC_X),
                                      MO(SYMB),KC_SPC,     MO(MUSE),
        // right hand
        KC_ASTR,  KC_6,   KC_7,    KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_PLUS,  KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,             KC_BSLS,
                  KC_H,   KC_J,    KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_MINS,
        KC_EQL,   KC_N,   KC_M,    KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                          KC_LEFT, KC_UP,  KC_DOWN,KC_RGHT,          KC_UNDS,
        KC_VOLU,  KC_ENTER,
        KC_VOLD,
        MO(MUSE), MO(MUSE), MO(MDIA)
    ),
/* Keymap 1: Cursor + Num Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |  =>  |  <   |  >   |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | HOME | PgUp |  Up  | PgDn |      |      |           |  &   |  (   |  )   |  7   |  8   |  9   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |GuiLft| Left | Down |Right |GuiRht|------|           |------|  {   |  }   |  4   |  5   |  6   |        |
 * |--------+------+------+------+------+------|      |           |  |   |------+------+------+------+------+--------|
 * |        | END  |      |      |      |      |      |           |      |  [   |  ]   |  1   |  2   |  3   |  0     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS,
       KC_TRNS,KC_HOME,      KC_PGUP,KC_UP,  KC_PGDN,KC_TRNS,       KC_TRNS,
       KC_TRNS,LGUI(KC_LEFT),KC_LEFT,KC_DOWN,KC_RGHT,LGUI(KC_RGHT),
       KC_TRNS,KC_END,       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS,
       KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       M(M_AROW), KC_LABK, KC_RABK, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
       KC_AMPR,   KC_LPRN, KC_RPRN, KC_7,   KC_8,    KC_9,    KC_TRNS,
                  KC_LCBR, KC_RCBR, KC_4,   KC_5,    KC_6,    KC_TRNS,
       KC_PIPE,   KC_LBRC, KC_RBRC, KC_1,   KC_2,    KC_3,    KC_0,
                           KC_0,    KC_0,   KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Delete + shift cursor
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |  =>  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |ShHome|ShPgUp| ShUp |ShPgDn|      |      |           |  &   |      |      |UpEtr |      |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |GuShLt|ShLeft|ShDown|ShRht |GuShRt|------|           |------| F15  | Bksp |Enter | Del  |      |        |
 * |--------+------+------+------+------+------|      |           |  |   |------+------+------+------+------+--------|
 * |        |ShEnd |      |      |      |      |      |           |      | F16  |ShEtr |DnEtr |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,               KC_F2,         KC_F3,         KC_F4,         KC_F5,        KC_TRNS,
       KC_TRNS, LSFT(KC_HOME),       LSFT(KC_PGUP), LSFT(KC_UP),   LSFT(KC_PGDN), KC_TRNS,      KC_TRNS,
       KC_TRNS, LGUI(LSFT(KC_LEFT)), LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), LGUI(LSFT(KC_RGHT)),
       KC_TRNS, LSFT(KC_END),        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,             KC_TRNS,       KC_TRNS,       KC_TRNS,
                                                             KC_TRNS,       KC_TRNS,
                                                                            KC_TRNS,
                                                          KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       M(M_AROW),KC_F6,   KC_F7,          KC_F8,      KC_F9,   KC_F10,  KC_F11,
       KC_AMPR,  KC_TRNS, KC_TRNS,        M(M_UENT),  KC_TRNS, KC_TRNS, KC_F12,
                 KC_F15,  KC_BSPC,        KC_ENTER,   KC_DELT, KC_TRNS, KC_TRNS,
       KC_PIPE,  KC_F16,  LSFT(KC_ENTER), M(M_DENT),  KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS,        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk | Cclk | WhUp |           | WhUp | Cclk | Lclk | MsUp | Rclk |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ACL0   | ACL0 |MsLeft|MsDown|MsRght| Lclk |------|           |------| Lclk |MsLeft|MsDown|MsRght| ACL0 | ACL0   |
 * |--------+------+------+------+------+------| WhDn |           | WhDn |------+------+------+------+------+--------|
 * |        |      | WhUp | Cclk | WhDn | Rclk |      |           |      | Rclk | WhUp | Cclk | WhDn |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ACL0 | ACL0 |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[MUSE] = KEYMAP(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_WH_U,
       KC_ACL0, KC_ACL0, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
       KC_TRNS, KC_TRNS, KC_WH_U, KC_BTN3, KC_WH_D, KC_BTN2, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_ACL0, KC_ACL0, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_WH_U,  KC_BTN3, KC_BTN1,  KC_MS_U,  KC_BTN2, KC_TRNS, KC_TRNS,
                 KC_BTN1, KC_MS_L,  KC_MS_D,  KC_MS_R, KC_ACL0, KC_ACL0,
       KC_WH_D,  KC_BTN2, KC_WH_U,  KC_BTN3,  KC_WH_D, KC_TRNS, KC_TRNS,
                          KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
        case M_UENT:
        if (record->event.pressed) {
          return MACRO(T(UP), T(END), T(ENTER), END);
        }
        break;
        case M_DENT:
        if (record->event.pressed) {
          return MACRO(T(DOWN), T(HOME), T(ENTER), T(UP), END);
        }
        break;
        case M_AROW:
        if (record->event.pressed) {
          return MACRO(T(EQL), D(LSFT), T(DOT), U(LSFT), END);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
