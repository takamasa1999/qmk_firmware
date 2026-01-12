#include QMK_KEYBOARD_H

enum custom_keycodes {
    M0 = SAFE_RANGE, // GUI + TAB
    M1,              // GUI + SHIFT + TAB
    M2,              // tap(ESC + LNG2)
};

static void tap_chord(uint16_t k1, uint16_t k2) {
    register_code16(k1);
    register_code16(k2);
    unregister_code16(k2);
    unregister_code16(k1);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case M0:
            register_mods(MOD_BIT(KC_LGUI));
            tap_code(KC_TAB);
            unregister_mods(MOD_BIT(KC_LGUI));
            return false;

        case M1:
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
            tap_code(KC_TAB);
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
            return false;

        case M2:
            tap_chord(KC_ESC, KC_LNG2);
            return false;
    }
    return true;
}

bool led_update_user(led_t led_state) {
#ifdef RGB_MATRIX_ENABLE
    if (led_state.caps_lock) {
        rgb_matrix_enable_noeeprom(); // Caps ON: バックライト有効化（保存しない）
    } else {
        rgb_matrix_disable_noeeprom(); // Caps OFF: バックライト完全OFF（保存しない）
    }
#endif
    return true;
}

const uint16_t PROGMEM
    keymaps[][MATRIX_ROWS][MATRIX_COLS] =
        {
            // ---------------- Layer 0 ----------------
            [0] =
                {
                    {KC_CAPS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_VOLU},
                    {M2, LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G, KC_VOLD},
                    {M1, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_LNG2, LT(2, KC_TAB), LT(4, KC_SPC), KC_NO},

                    {KC_DEL, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_BRIU},
                    {KC_QUOT, RSFT_T(KC_SCLN), RCTL_T(KC_L), RALT_T(KC_K), RGUI_T(KC_J), KC_H, KC_BRID},
                    {M0, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_LNG1, LT(1, KC_BSPC), LT(3, KC_ENT), KC_NO},
                },

            // ---------------- Layer 1 ----------------
            [1] =
                {
                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
                    {KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS},
                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},

                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
                    {KC_BSLS, KC_RBRC, KC_LBRC, KC_EQL, KC_MINS, KC_TRNS, KC_TRNS},
                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                },

            // ---------------- Layer 2 ----------------
            [2] =
                {
                    {KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS},
                    {KC_GRV, LSFT_T(KC_1), LCTL_T(KC_2), LALT_T(KC_3), LGUI_T(KC_4), KC_5, KC_TRNS},
                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},

                    {KC_TRNS, KC_F10, KC_F9, KC_F8, KC_F7, KC_F6, KC_TRNS},
                    {KC_TRNS, RSFT_T(KC_0), RCTL_T(KC_9), RALT_T(KC_8), RGUI_T(KC_7), KC_6, KC_TRNS},
                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_F12, KC_F11, KC_TRNS, KC_NO},
                },

            // ---------------- Layer 3 ----------------
            [3] =
                {
                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
                    {KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS},
                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},

                    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
                    {KC_TRNS, KC_TRNS, KC_RGHT, KC_UP, KC_DOWN, KC_LEFT, KC_TRNS},
                    {QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
                },

            // ---------------- Layer 4 ----------------
            [4] =
                {
                    {KC_NO, KC_NO, KC_NO, KC_NO, QK_REBOOT, KC_NO, KC_NO},
                    {KC_NO, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, KC_NO, KC_NO},
                    {QK_BOOT, RM_PREV, RM_HUED, RM_SATD, RM_VALD, KC_NO, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},

                    {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                    {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
                },
};
