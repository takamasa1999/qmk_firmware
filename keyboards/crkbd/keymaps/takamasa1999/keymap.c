#include QMK_KEYBOARD_H

enum custom_keycodes { M0 = SAFE_RANGE, M1, M2, M3, M4, M5 };

void kill_caps_lock(void) {
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M0:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LGUI));
                tap_code(KC_TAB);
                unregister_mods(MOD_BIT(KC_LGUI));
            }
            break;

        case M1:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
                tap_code(KC_TAB);
                unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
            }
            break;

        case M2:
            if (record->event.pressed) {
                kill_caps_lock();
            } else {
                tap_code(KC_ESC);
                tap_code(KC_LNG2);
            }
            break;

        case M3:
            if (record->event.pressed) {
                tap_code(KC_LNG2);
            } else {
                tap_code(KC_CAPS);
            }
            break;

        case M4:
            if (record->event.pressed) {
                kill_caps_lock();
            } else {
                tap_code(KC_LNG1);
            }
            break;

        case M5:
            if (record->event.pressed) {
                kill_caps_lock();
            } else {
                tap_code(KC_LNG2);
            }
            break;
    }
    return true;
}

bool led_update_user(led_t led_state) {
#ifdef RGB_MATRIX_ENABLE
    if (led_state.caps_lock) {
        rgb_matrix_enable_noeeprom();
    } else {
        rgb_matrix_disable_noeeprom();
    }
#endif
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] =
                                                                  {
                                                                      {M3, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_VOLU},
                                                                      {M2, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_VOLD},
                                                                      {M1, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, M5, LT(1, KC_TAB), LT(3, KC_SPC), KC_NO},

                                                                      {KC_DEL, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_BRIU},
                                                                      {KC_QUOT, RCTL_T(KC_SCLN), RALT_T(KC_L), RGUI_T(KC_K), RSFT_T(KC_J), KC_H, KC_BRID},
                                                                      {M0, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, M4, LT(2, KC_BSPC), LT(4, KC_ENT), KC_NO},
                                                                  },

                                                              [1] =
                                                                  {
                                                                      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
                                                                      {KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS},
                                                                      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},

                                                                      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
                                                                      {KC_BSLS, KC_RBRC, KC_LBRC, KC_EQL, KC_MINS, KC_TRNS, KC_TRNS},
                                                                      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                  },

                                                              [2] =
                                                                  {
                                                                      {KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS},
                                                                      {KC_GRV, LCTL_T(KC_1), LALT_T(KC_2), LGUI_T(KC_3), LSFT_T(KC_4), KC_5, KC_TRNS},
                                                                      {KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},

                                                                      {KC_TRNS, KC_F10, KC_F9, KC_F8, KC_F7, KC_F6, KC_TRNS},
                                                                      {KC_TRNS, RCTL_T(KC_0), RALT_T(KC_9), RGUI_T(KC_8), RSFT_T(KC_7), KC_6, KC_TRNS},
                                                                      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO},
                                                                  },

                                                              [3] =
                                                                  {
                                                                      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
                                                                      {KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS},
                                                                      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},

                                                                      {KC_TRNS, KC_TRNS, KC_END, KC_PAGE_UP, KC_PAGE_DOWN, KC_HOME, KC_TRNS},
                                                                      {KC_TRNS, KC_TRNS, KC_RGHT, KC_UP, KC_DOWN, KC_LEFT, KC_TRNS},
                                                                      {QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                      {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                                                                  },

                                                              [4] = {
                                                                  {KC_NO, KC_NO, KC_NO, KC_NO, QK_REBOOT, KC_NO, KC_NO},
                                                                  {KC_NO, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, KC_NO, KC_NO},
                                                                  {QK_BOOT, RM_PREV, RM_HUED, RM_SATD, RM_VALD, KC_NO, KC_NO},
                                                                  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},

                                                                  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                                                                  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                                                                  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                                                                  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                                                              }};
