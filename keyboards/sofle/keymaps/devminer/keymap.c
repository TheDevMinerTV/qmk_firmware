#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAME,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_DBGGER,
    KC_DBGGER_STEP,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    KC_GRV,
  KC_ESC,  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_TAB,  KC_A, KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,       KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,       KC_MUTE,        KC_F24, KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_LALT, KC_LCTL, MO(_LOWER), KC_SPC,         KC_ENT, MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
),

[_GAME] = LAYOUT(
  KC_ESC, KC_1,    KC_2,    KC_3,    KC_4, KC_5,                               KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    KC_GRV,
  KC_F13, KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,                               KC_J,       KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
  KC_F14, KC_LSFT, KC_A,    KC_S,    KC_D, KC_F,                               KC_H,       KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
  KC_F15, KC_LCTL, KC_Z,    KC_X,    KC_C, KC_M,       KC_MUTE,        KC_F24, KC_K,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                   KC_LGUI, KC_LALT, KC_V, MO(_LOWER), KC_SPC,         KC_ENT, MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
),

[_LOWER] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_NO,                            KC_NO,   KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_NO,   KC_NO,   KC_PIPE,
  _______, KC_UNDS, KC_EQL,  KC_MINS, KC_PLUS,  KC_NO,  _______,        _______, KC_NO,   KC_NO,   KC_SCLN, KC_COLN, KC_BSLS, _______,
                    _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
  _______, _______, _______,    _______,    _______, _______,                          _______,          _______, _______,               _______, _______, _______,
  _______, KC_INS,  SGUI(KC_S), SGUI(KC_4), KC_APP,  KC_NO,                            LT(0, KC_DBGGER), KC_F10,  LT(0, KC_DBGGER_STEP), S(KC_F8), KC_NO,   KC_DEL,
  _______, KC_NO,   KC_NO,      KC_NO,      KC_NO,   KC_NO,                            KC_LEFT,          KC_DOWN, KC_UP,                 KC_RGHT,  KC_NO,   KC_NO,
  _______, KC_NO,   KC_NO,      KC_NO,      KC_NO,   KC_NO,   _______,        _______, KC_HOME,          KC_PGDN, KC_PGUP,               KC_END,   KC_NO,   _______,
                     _______,   _______,    _______, _______, _______,        _______, _______,          _______, _______,               _______
),

[_ADJUST] = LAYOUT(
  QK_BOOT, KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO, CG_TOGG,
  KC_CAPS, KC_QWERTY, KC_GAME, KC_NO,   KC_NO,   KC_NO,                            KC_F6,   KC_NO,   KC_NO,   C(S(KC_F8)), KC_NO, KC_DLINE,
  KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU,     KC_NO, KC_NO,
  KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT,     KC_NO, KC_NO,
                      _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case LT(0, KC_DBGGER):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_F5);
            } else if (record->event.pressed) {
                tap_code16(C(KC_F5));
            }
            return false;
        case LT(0, KC_DBGGER_STEP):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_F11);
            } else if (record->event.pressed) {
                tap_code16(S(KC_F11));
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
