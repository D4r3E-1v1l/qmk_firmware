/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

//Layer Define

enum layers {
    _EL = 0,  // _EL       = 0
    _GL,      // _GAME     = 1
    _FL,      // _FL       = 2
};

// Macros Part
#define DF_CAPS       LT(_FL, KC_CAPS)

#define DF_UNDO       C(KC_Z)
#define DF_REDO       S(C(KC_Z))

#define DF_ETHG       A(KC_F)

#define DF_PWD        C(KC_LEFT)
#define DF_NWD        C(KC_RGHT)

const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, (layer_state_t) 1 << _EL);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	                Home                     Rotary(MUTED)
//      ~        1        2        3        4        5        6        7        8        9        0         -       =	                BackSpc                  Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                   \                        PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                            Enter                    PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                            Sh_R         Up          End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R                Left         Down        Right


/*  EMPTY LAYER
    [_EMPTY] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,                 _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,                 _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,                 _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                     _______,                 _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                     _______,     _______,    _______,
        _______, _______, _______,                            _______,                            _______, _______, _______,            _______,     _______,    _______
    ),
*/
    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_EL] = LAYOUT_60_ansi(
        KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,             KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,            KC_BSLS,
        DF_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                     KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                     KC_RSFT,
        KC_LCTL,  KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL,            MO(2)
    ),

    [_GL] = LAYOUT_60_ansi(
        KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,             KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,            KC_BSLS,
        KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                     KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                     KC_RSFT,
        KC_LCTL,  KC_NO,   KC_LALT,                           KC_SPC,                             KC_RALT, KC_NO,   KC_RCTL,            MO(2)
    ),

    [_FL] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_NO,
        KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,   KC_NO,   DF_PWD,  DF_NWD,  KC_NO,   KC_NO,   KC_NO,   KC_NO,              QK_BOOT,
        KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,                      KC_NO,
        KC_NO,            KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,   NK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,                       TG(1),
        KC_NO,   KC_NO,   KC_0,                               KC_NO,                              KC_NO,   KC_NO,   KC_NO,              KC_NO
    ),

};
// clang-format on

const key_override_t **key_overrides = (const key_override_t *[]){
   &delete_key_override,
   NULL // Null terminate the array of overrides!
};

// RGB Part
static bool caps_active = false;
static bool caps_flash_on = false;
static uint16_t caps_flasher = 0;

bool rgb_matrix_indicators_user(void) {
    RGB rgb_IDR_CAPS = hsv_to_rgb(hsv_IDR_CAPS);

    if (layer_state_is(_GL)) {
        rgb_matrix_set_color(LED_LGUI, RGB_OFF);
    }

    if (host_keyboard_led_state().caps_lock) {
        if (!caps_active) {
			caps_active = true;
			caps_flash_on = true;
			caps_flasher = timer_read();
		}
		if (timer_elapsed(caps_flasher) >= 500) {
			caps_flasher = timer_read();
			caps_flash_on = !caps_flash_on;
		}

        if (caps_flash_on) {
			for (uint8_t i = 0; i < sizeof(LED_LIST_NUMROW_2); i++) {
				rgb_matrix_set_color(LED_LIST_NUMROW_2[i], rgb_IDR_CAPS.r, rgb_IDR_CAPS.g, rgb_IDR_CAPS.b);
			}
		}
    } else {
		caps_active = false;
        caps_flash_on = false;
	}

    return false;
}