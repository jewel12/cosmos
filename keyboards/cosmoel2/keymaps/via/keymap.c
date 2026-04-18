#include QMK_KEYBOARD_H
#include "i2c_master.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_SPACE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_SPACE, KC_SPACE, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SPACE, KC_SPACE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_SPACE, KC_SPACE, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_SPACE, KC_SPACE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_SPACE, KC_SPACE, KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_SPACE, KC_SPACE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPACE, KC_SPACE, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_SPACE, KC_RIGHT_BRACKET, KC_RIGHT_BRACKET, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE),
};


void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    debug_mouse=true;

    // I2C scan to check if azoteq is detected
    i2c_init();
    uprintf("I2C scan starting...\n");
    for (uint8_t addr = 0x08; addr < 0x78; addr++) {
        uint8_t dummy;
        i2c_status_t status = i2c_read_register(addr << 1, 0x00, &dummy, 1, 100);
        if (status == I2C_STATUS_SUCCESS) {
            uprintf("I2C device found at 0x%02X\n", addr);
        }
    }
    uprintf("I2C scan done.\n");
}
