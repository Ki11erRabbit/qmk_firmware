
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

#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE) /* Default */



enum numlock_keycodes {
    NUMLOCK_OFF = SAFE_RANGE,
    NUMLOCK_ON,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUMLOCK_OFF:
            if (record->event.pressed) {
                // Check if numlock is on first
                if (host_keyboard_led_state().num_lock == true) {
                    // Turn off numlock
                    SEND_STRING(SS_TAP(X_NUM));
                }
                layer_off(0);
            }
            return false;
        case NUMLOCK_ON:
            if (record->event.pressed) {
                if (host_keyboard_led_state().num_lock == false) {
                    // Turn on numlock
                    SEND_STRING(SS_TAP(X_NUM));
                }
                layer_on(2);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_GRV,  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_HOME, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_END,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSPC,
        KC_PGUP, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_SCRL,
        KC_PGDN, KC_LCTL, KC_LALT, MO(1),   KC_INS,  KC_BSLS, KC_LGUI, KC_RGUI, KC_PSCR, KC_PAUS, MO(1),   KC_RALT, KC_RCTL, KC_DEL,
                                            MS_BTN1, MS_BTN2, KC_SPC,  KC_ENT,  MS_BTN3, KC_DEL
    ),

    [1] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_EQL,
        KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_BRID, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, _______,
        KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NUMLOCK_ON,
        KC_VOLD, _______, _______, _______, _______, _______, _______, _______, KC_SYRQ, _______, _______, _______, _______, KC_MUTE,
                                            _______, _______, KC_SLEP, _______, _______, KC_KB_MUTE
    ),

    [2] = LAYOUT(
        XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, XXXXXXX, XXXXXXX,
        KC_HOME, KC_TAB,  XXXXXXX, KC_W,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PAST, XXXXXXX, XXXXXXX,
        KC_END,  XXXXXXX, KC_A,    KC_S,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, KC_BSPC,
        KC_PGUP, KC_LSFT, KC_Z,    KC_X,    KC_C,    XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   XXXXXXX, KC_PDOT, KC_PPLS, KC_RSFT, XXXXXXX,
        KC_PGDN, KC_LCTL, KC_LALT, MO(3),   KC_INS,  KC_BSLS, KC_LGUI, KC_RGUI, KC_PSCR, KC_PAUS, MO(3),   KC_RALT, KC_RCTL, XXXXXXX,
                                            MS_BTN1, MS_BTN2, KC_SPC,  KC_ENT,  MS_BTN3, KC_DEL
    ),

    [3] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_EQL,
        KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_BRID, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, _______,
        KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NUMLOCK_OFF,
        KC_VOLD, _______, _______, _______, _______, _______, _______, _______, KC_SYRQ, _______, _______, _______, _______, KC_MUTE,
                                            _______, _______, KC_SLEP, _______, _______, KC_KB_MUTE
    ),

};
