// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define MUSE 3 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  '   |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Command |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------|  "   |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf|      |  L1  |                                       |  L2  |      |   [  |   ]  |  _   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |  L1  |Space |------|       |------|  L3    |  L2  |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_QUOT,
        KC_LGUI,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   KC_DQUO,
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_NO,  MO(SYMB),
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                      MO(SYMB),KC_SPC,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             TG(SYMB),       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,          KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_MINS,
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  MO(MDIA),  KC_NO,  KC_LBRC,KC_RBRC,          KC_UNDS,
             KC_LALT,         CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN, MO(MUSE), MO(MDIA)
    ),
/* Keymap 1: Cursor + Num Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | PgUp |  Up  | PgDn |      |      |           |      |  *   |  7   |  8   |  9   |  (   |   )    |
 * |--------+------+------+------+------+------|      |           |  +   |------+------+------+------+------+--------|
 * |        | Home | Left | Down |Rignt | End  |------|           |------|  =   |  4   |  5   |  6   |  {   |   }    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |  -   |  0   |  1   |  2   |  3   |  [   |   ]    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  .   |  =   |  /   |      |
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
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_PGUP,KC_UP,  KC_PGDN,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,
       KC_PLUS, KC_ASTR, KC_7,   KC_8,   KC_9,    KC_LPRN, KC_RPRN,
                KC_EQL,  KC_4,   KC_5,   KC_6,    KC_LCBR, KC_RCBR,
       KC_MINS, KC_0,    KC_1,   KC_2,   KC_3,    KC_LBRC, KC_RBRC,
                         KC_0,   KC_DOT, KC_EQL,  KC_SLSH, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Delete + shift cursor
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |ShPgUp| ShUp |ShPgDn|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |ShHome|ShLeft|ShDown|ShRigt|ShEnd |------|           |------| F15  | Bksp |Enter | Del  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | F16  |      |      |      |      |        |
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
       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,       LSFT(KC_PGUP), LSFT(KC_UP),   LSFT(KC_PGDN), KC_TRNS,      KC_TRNS,
       KC_TRNS, LSFT(KC_HOME), LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), LSFT(KC_END),
       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                                                             KC_TRNS,       KC_TRNS,
                                                                            KC_TRNS,
                                                          KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_F15,  KC_BSPC, KC_ENTER, KC_DELT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_F16,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk | Cclk |      |           |      | Cclk | Lclk | MsUp | Rclk |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght| Lclk |------|           |------| Lclk |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | WhUp | Cclk | WhDn | Rclk |      |           |      | Rclk | WhUp | Cclk | WhDn |      |        |
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

[MUSE] = KEYMAP(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
       KC_TRNS, KC_TRNS, KC_WH_U, KC_BTN3, KC_WH_D, KC_BTN2, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_ACL0, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_BTN3, KC_BTN1,  KC_MS_U,  KC_BTN2, KC_TRNS, KC_TRNS,
                 KC_BTN1, KC_MS_L,  KC_MS_D,  KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_BTN2, KC_WH_U,  KC_BTN3,  KC_WH_D, KC_TRNS, KC_TRNS,
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
