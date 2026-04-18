#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_SPACE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_SPACE, KC_SPACE, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SPACE, KC_SPACE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_SPACE, KC_SPACE, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_SPACE, KC_SPACE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_SPACE, KC_SPACE, KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_SPACE, KC_SPACE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPACE, KC_SPACE, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_SPACE, KC_RIGHT_BRACKET, KC_RIGHT_BRACKET, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE),
};


void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_mouse=true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_report.x = mouse_report.x * 1.5;
    mouse_report.y = mouse_report.y * 1.5;
    return mouse_report;
}
