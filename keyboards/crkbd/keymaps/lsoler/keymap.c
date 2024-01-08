/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/** https://jayliu50.github.io/qmk-cheatsheet/ */
#include QMK_KEYBOARD_H

enum { 
    LAYER_ALPHA = 0,
    LAYER_LOWER = 1,
    LAYER_UPPER = 2,
    LAYER_ADJUST = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_ALPHA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  KC_LCTL,  LT(LAYER_LOWER, KC_BSPC),     MO(LAYER_UPPER),    KC_SPC, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,   KC_F12,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, _______,     MO(LAYER_UPPER), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_UPPER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, MO(LAYER_UPPER),  _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

void keyboard_post_init_user(void) {
    // Clears the matrix from displaying any rgb effects at startup
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case LAYER_ALPHA:
            break;
        case LAYER_UPPER:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(42, 0, 204, 0); // key }
            rgb_matrix_set_color(47, 0, 204, 0); // key {
            rgb_matrix_set_color(46, 204, 0, 0); // key ]
            rgb_matrix_set_color(43, 204, 0, 0); // key [
            rgb_matrix_set_color(45, 0, 0, 204); // key )
            rgb_matrix_set_color(50, 0, 0, 204); // key (
            break;
        // case LAYER_3:
        //     rgb_matrix_set_color_all(0,0,0);
        //     rgb_matrix_set_color(6, 75, 255, 75);
        //     rgb_matrix_set_color(7, 75, 255, 75);
        //     break;
        // case LAYER_4: 
        //     rgb_matrix_set_color_all(0, 0, 0);
        //     rgb_matrix_set_color(6, 0, 204, 0);
        //     rgb_matrix_set_color(7, 0, 204, 0);
        //     rgb_matrix_set_color(8, 0, 204, 0);
        //     break;
        default:
            break;
    }
    return false;
}