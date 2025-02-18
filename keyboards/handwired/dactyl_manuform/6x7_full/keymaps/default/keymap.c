// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE
#define EE_HANDS

enum custom_layer {
    _COLEMAK_DH,
    _GAMING,
    _NAVI,
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define TONAV TO(_NAVI)
#define TOCM TO(_COLEMAK_DH)
#define TOGM TO(_GAMING)
#define VOLUP KC_KB_VOLUME_UP
#define VOLDN KC_KB_VOLUME_DOWN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
        KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , TONAV  ,
        _______, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC,
        VOLUP  , KC_TAB  , KC_Q   , KC_W  , KC_F  , KC_P  , KC_B  ,                         KC_J  , KC_L   , KC_U   , KC_Y  ,KC_SCLN, KC_MINS  , KC_EQL ,
        VOLDN  , KC_BSPC , KC_A   , KC_R  , KC_S  , KC_T  , KC_G  ,                         KC_M  , KC_N   , KC_E   , KC_I  , KC_O  , KC_QUOT  , KC_BSLS,
        _______, KC_LSFT , KC_Z   , KC_X  , KC_C  , KC_D  , KC_V  ,                         KC_K  , KC_H   , KC_COMM, KC_DOT,KC_SLSH, KC_RSFT  , _______,
        _______, KC_LCTL , KC_LALT,_______,KC_BSLS,KC_SPC ,KC_ESC ,                         LOWER , KC_ENT ,KC_LBRC,KC_RBRC, KC_RALT, KC_LCTL  , _______,
                                    KC_DEL,KC_GRV ,KC_LGUI,KC_TAB ,                         KC_DEL,  KC_RGUI, KC_F20,  KC_LALT
    ),
    [_GAMING] = LAYOUT(
        KC_ESC , KC_F6   , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , TONAV  ,
        _______, KC_ESC  , KC_5   , KC_1  , KC_2  , KC_3  , KC_4  ,                         KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC,
        _______, KC_TAB  , KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  ,                         KC_J  , KC_L   , KC_UP  , KC_Y  ,KC_SCLN, KC_MINS  , KC_EQL ,
        _______, KC_BSPC , KC_TAB , KC_A  , KC_S  , KC_D  , KC_F  ,                         KC_M  , KC_LEFT, KC_DOWN,KC_RGHT, KC_O  , KC_QUOT  , _______,
        _______, KC_LSFT , KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  ,                         KC_K  , KC_H   , KC_COMM, KC_DOT,KC_SLSH, KC_RSFT  , _______,
        _______, KC_LCTL , KC_LCTL,KC_LALT, KC_H  ,KC_SPC , KC_G  ,                         KC_ENT, KC_SPC ,KC_LBRC,KC_RBRC, KC_RALT, KC_LCTL  , _______,
                                    KC_T  ,KC_GRV , KC_B  ,KC_TAB ,                         KC_DEL, KC_RGUI, KC_F20,  KC_LALT
    ),
    [_QWERTY] = LAYOUT(
        KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , _______,
        _______, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC,
        _______, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U   , KC_I   , KC_O  , KC_P  , KC_QUOT  , KC_BSLS,
        _______, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J   , KC_K   , KC_L  ,KC_SCLN, KC_LSFT  , _______,
        _______, KC_LSFT , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M   , KC_COMM, KC_DOT,KC_SLSH, KC_LCTL  , _______,
        _______, KC_LCTL , KC_Z   , KC_LBRC,KC_RBRC,RAISE ,KC_SPC ,                         KC_ENT,  LOWER , KC_PLUS, KC_EQL,KC_SLSH, KC_LCTL  , _______,
                                    KC_TAB,KC_HOME ,KC_BSPC,KC_GRV,                         KC_END,  KC_DEL, KC_LGUI, KC_LALT
    ),

    [_LOWER] = LAYOUT(
        KC_ESC , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,                          KC_F7 , KC_F8  , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 , _______,
        _______, KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                           KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL , _______,
        _______, _______,_______,_______,_______,_______,KC_LBRC,                           KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS, _______,
        _______, _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                           KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_MINS,KC_PIPE, _______,
        _______, _______,_______,_______,_______,_______,_______,                           _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS, _______,
        QK_BOOT, _______,_______,_______,KC_PSCR,_______,_______,                           _______,_______,_______, KC_P0, KC_EQL ,KC_UNDS, _______,
                                _______,_______,_______,_______,                            _______,_______,_______,_______
    ),

    [_RAISE] = LAYOUT(
        _______,KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                            KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 , _______,
        _______,_______,_______,_______,_______,_______,KC_LBRC,                            KC_RBRC,_______,KC_NUM ,KC_INS ,KC_SCRL,KC_MUTE, _______,
        _______,_______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                            KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU, _______,
        _______,_______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,KC_VOLD, _______,
        _______,_______,_______,_______,_______,_______,_______,                            _______,_______,_______,_______,_______,_______, _______,
        _______,_______,_______,_______,_______,_______,_______,                            _______,_______,KC_EQL ,_______,_______,_______, _______,
                                _______,_______,_______,_______,                            _______,_______,_______,_______
    ),
    [_NAVI] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,                            KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 , _______,
        _______,_______,_______,_______,_______,_______,KC_LBRC,                            KC_RBRC,_______,KC_NUM ,KC_INS ,KC_SCRL,KC_MUTE, _______,
        _______,_______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                            KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU, _______,
        _______,_______,_______,_______,_______,_______, TOGM  ,                            _______,_______,_______,_______,_______,KC_VOLD, _______,
        _______,_______,_______,_______, TOCM  ,_______,_______,                            _______,_______,_______,_______,_______,_______, _______,
        _______,_______,_______,_______,_______,_______,_______,                            _______,_______,KC_EQL ,_______,_______,_______, _______,
                                _______,_______,_______,_______,                            _______,_______,_______,_______
    )
};
