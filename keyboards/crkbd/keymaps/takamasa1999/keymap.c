#include QMK_KEYBOARD_H

// ============================================================
// Custom keycodes
// ============================================================
enum custom_keycodes { M2 = SAFE_RANGE, M3, M4, M5 };

// ============================================================
// Helpers
// ============================================================
void kill_caps_lock(void) {
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// ============================================================
// Key processing
// ============================================================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // M2: press=CapsLock off  / release=ESC + Eisu
        case M2:
            if (record->event.pressed) {
                kill_caps_lock();
            } else {
                tap_code(KC_ESC);
                tap_code(KC_LNG2);
            }
            break;
        // M3: press=Eisu          / release=CapsLock on
        case M3:
            if (record->event.pressed) {
                tap_code(KC_LNG2);
            } else {
                tap_code(KC_CAPS);
            }
            break;
        // M4: press=CapsLock off  / release=Kana
        case M4:
            if (record->event.pressed) {
                kill_caps_lock();
            } else {
                tap_code(KC_LNG1);
            }
            break;
        // M5: press=CapsLock off  / release=Eisu
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

// ============================================================
// LED: RGB on when CapsLock active
// ============================================================
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

// ============================================================
// Keymap  (LAYOUT_split_3x6_3_ex2)
// ============================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ----------------------------------------------------------
    // Layer 0: Base (Homerow mods: CTRL/ALT/GUI/SHIFT)
    // ----------------------------------------------------------
    [0] = LAYOUT_split_3x6_3_ex2(
        // Left Top
        M3, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_VOLU,
        // Right Top
        KC_BRIU, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
        // Left Middle
        M2, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_VOLD,
        // Right Middle
        KC_BRID, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
        // Left Bottom
        KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,
        // Right Bottom
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
        // Left Thumb
        M5, LT(1, KC_TAB), LT(3, KC_SPC),
        // Right Thumb
        LT(4, KC_ENT), LT(2, KC_BSPC), M4),

    // ----------------------------------------------------------
    // Layer 1: Left symbols (raised by TAB)
    // ----------------------------------------------------------
    [1] = LAYOUT_split_3x6_3_ex2(
        // Left Top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Left Middle
        KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS,
        // Right Middle
        KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        // Left Bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Left Thumb
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Thumb
        KC_TRNS, KC_TRNS, KC_TRNS),

    // ----------------------------------------------------------
    // Layer 2: Numbers / F-keys (raised by BSPC)
    // ----------------------------------------------------------
    [2] = LAYOUT_split_3x6_3_ex2(
        // Left Top
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        // Right Top
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
        // Left Middle
        KC_GRV, LCTL_T(KC_1), LALT_T(KC_2), LGUI_T(KC_3), LSFT_T(KC_4), KC_5, KC_TRNS,
        // Right Middle
        KC_TRNS, KC_6, RSFT_T(KC_7), RGUI_T(KC_8), RALT_T(KC_9), RCTL_T(KC_0), KC_TRNS,
        // Left Bottom
        KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Left Thumb
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Thumb
        KC_TRNS, KC_NO, KC_NO),

    // ----------------------------------------------------------
    // Layer 3: Navigation (raised by SPC)
    // ----------------------------------------------------------
    [3] = LAYOUT_split_3x6_3_ex2(
        // Left Top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Top
        KC_TRNS, KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END, KC_TRNS, KC_TRNS,
        // Left Middle
        KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS,
        // Right Middle
        KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,
        // Left Bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Left Thumb
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Right Thumb
        KC_TRNS, KC_TRNS, KC_TRNS),

    // ----------------------------------------------------------
    // Layer 4: RGB / System (raised by ENT)
    // ----------------------------------------------------------
    [4] = LAYOUT_split_3x6_3_ex2(
        // Left Top
        KC_NO, KC_NO, KC_NO, KC_NO, QK_REBOOT, KC_NO, KC_NO,
        // Right Top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // Left Middle
        KC_NO, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, KC_NO, KC_NO,
        // Right Middle
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // Left Bottom
        KC_NO, RM_PREV, RM_HUED, RM_SATD, RM_VALD, QK_BOOT,
        // Right Bottom
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // Left Thumb
        KC_NO, KC_NO, KC_NO,
        // Right Thumb
        KC_NO, KC_NO, KC_NO),
};
