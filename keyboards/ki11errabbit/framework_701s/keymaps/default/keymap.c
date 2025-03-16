
#include QMK_KEYBOARD_H

#undef LED_PIN_ON_STATE
#define LED_PIN_ON_STATE 0

/* Use remote mode instead of the default stream mode (see link) */
#define PS2_MOUSE_USE_REMOTE_MODE

/* Enable the scrollwheel or scroll gesture on your mouse or touchpad */
#define PS2_MOUSE_ENABLE_SCROLLING

/* Some mice will need a scroll mask to be configured. The default is 0xFF. */
#define PS2_MOUSE_SCROLL_MASK 0x0F

/* Applies a transformation to the movement before sending to the host (see link) */
#define PS2_MOUSE_USE_2_1_SCALING

/* The time to wait after initializing the ps2 host */
#define PS2_MOUSE_INIT_DELAY 1000 /* Default */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_GRV,  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_HOME, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_END,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSPC,
        KC_PGUP, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, _______,
        KC_PGDN, KC_LCTL, KC_LALT, _______, KC_INS,  KC_BSLS, KC_LGUI, KC_RGUI, KC_PSCR, KC_PAUS, _______, KC_RALT, KC_RCTL, KC_DEL,
                                            MS_BTN1, MS_BTN2, KC_SPC,  KC_ENT,  _______, KC_DEL
    ),

};
