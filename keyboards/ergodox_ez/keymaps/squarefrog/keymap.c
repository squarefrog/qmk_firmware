#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define QWER 0 // qwerty layer
#define SYMB 1 // symbols layer
#define PTPASTE LALT(LSFT(LGUI(KC_V))) // Paste without formatting
#define RENAME LCTL(LGUI(KC_E)) // ctrl+gui+e


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * This is my current layout which serves dual purpose. The default layer is a standard QWERTY
 * layout with easy access to brackets, when coding for Objective-C. There is also a layout
 * that is geared more towards gaming so most of the more important keys reside on the left
 * hand. Additionally, there is a helper layout which provides Vim-like access to arrow keys.
 *
 * Layer 0: The basic keyboard, geared towards an OS X compliant layout.
 * Layer 1: Arrow keys, function keys, helper functions for Xcode, Photoshop etc.
 *
 * Keymap 0: Default Qwerty Layer
 *
 * ,--------------------------------------------------.      ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  ~   |      |  -   |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  [   |      |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|      |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   | LCtrl| LAlt | LGui | Vol- | Vol+ |                                  |   "  |   :  | RGui | RAlt | RCtrl |
 *   `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.      ,-------------.
 *                                      |CpsLck| Del  |      | PgUp | PgDn |
 *                               ,------|------|------|      |------+------+------.
 *                               |      |      | LAlt |      | RAlt |      |      |
 *                               | BkSp | SYMB |------|      |------| Enter| Space|
 *                               |      |Toggle| LGui |      | RGui |      |      |
 *                               `--------------------'      `--------------------'
 *
 */
[QWER] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_LBRC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_NO,
        KC_LCTL, KC_LALT, KC_LGUI, KC_VOLD, KC_VOLU,
                                                     KC_CAPS,  KC_DEL,
                                                               KC_LALT,
                                            KC_BSPC, MO(SYMB), KC_LGUI,

        // right hand
        KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL,
        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                          KC_DQUO, KC_COLN, KC_RGUI, KC_RALT,  KC_RCTL,
        KC_PGUP, KC_PGDN,
        KC_RALT,
        KC_RGUI, KC_ENT, KC_SPC
    ),

/*
 * Layer 1: Function keys and extras
 *
 * ,--------------------------------------------------.      ,--------------------------------------------------.
 * | Teensy |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |      |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
 * |        |      |      |Rename|      |      |      |      |      |      | Test |      |      |      |        |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * | CapsLk |      |      |      |      |ReTest|------|      |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |        |      |      |      |Paste |      |      |      |      |      | Mute |      |      |      |        |
 * `--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |      |      | Play |  RW  |  FF  |                                  |      |      |      |      |      |
 *   `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.      ,-------------.
 *                                      |      |      |      | Home |  End |
 *                               ,------|------|------|      |------+------+------.
 *                               |      |      |      |      |      |      |      |
 *                               |      |      |------|      |------|      |      |
 *                               |      |      |      |      |      |      |      |
 *                               `--------------------'      `--------------------'
 *
 */
[SYMB] = LAYOUT_ergodox(
        // left hand
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, RENAME,  KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCAG(KC_G),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, PTPASTE, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MPLY, KC_MRWD, KC_MFFD,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_TRNS, LCAG(KC_U), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_HOME, KC_END,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
};

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
}

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case SYMB:
        ergodox_right_led_1_on();
        break;
      default:
        break;
    }

  return state;
};
