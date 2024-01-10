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
    _EL = 0,  // _BL       = 0
    _GL,      // _GAME     = 1
    _FL       // _FL       = 2
};

#define DF_UNDO C(KC_Z)
#define DF_REDO S(C(KC_Z))
#define DF_ZMI C(KC_EQL)
#define DF_ZMO C(KC_MINS)

#define DF_ETHG A(KC_F)

#define DF_PWD C(KC_LEFT)
#define DF_NWD C(KC_RGHT)
#define DF_LCOM C(KC_SLSH)
#define DF_BCOM C(S(KC_SLSH))
#define DF_PTAB C(KC_PGUP)
#define DF_NTAB C(KC_PGDN)
#define DF_FIND C(KC_F)
#define DF_CAPS LT(_FL, KC_CAPS)


// Macros Part
typedef struct {
    uint8_t num;
} count_user_t;

static count_user_t rf = {
    .num = 0,
};

bool rotary_hold = false;
uint16_t rotary_timer = 0;


enum custom_keycodes {
    ROTARY = SAFE_RANGE,  // ROTARY    : Special Keycode that defined for Rotary
};


// Macro Implementations
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        // ROTARY
        case ROTARY:
            /*
            +-----------------------+------------------------+
            |                    Rotary                      |
            +-----------------------+------------------------+
            |         Tap           |         Hold           |
            +----+------------------+------------------------+
            |  # |  Cycle Function  |         Layer          |
            +----+------------------+------------------------+
            |  0 |      Redo        |                        |
            |    |      Undo        |                        |
            +----+------------------+       Layer _GL        |
            |  1 |    Zoom In       |                        |
            |    |    Zoom Out      |                        |
            +----+------------------+------------------------+
            */
            // Different Function Between Tap and Hold
            // Tap within 500ms                    : Switch Functions of Rotary
            // Hold equals or longer than 500ms    : Enable Layer _GL
            if (record -> event.pressed) {
                if (!rotary_hold) {
                    rotary_hold = true;
                    rotary_timer = timer_read();
                }
            } else {
                if (rotary_hold) {
                    // Switch Functions of Rotary
                    rf.num = (rf.num == 1) ? 0 : rf.num + 1;

                    // Reset
                    rotary_hold = false;
                }
            }
            break;

        default: break;
    }


    return true;
};

void matrix_scan_user(void) {
    if (rotary_hold) {
        if (timer_elapsed(rotary_timer) >= 500) {
            // Reset Rotary State & Rotary Function Sequence
            rotary_hold = false;
            rf.num = 0;

            // Enable Layer _GL
            layer_on(_GL);
        }

    }
}


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
    [_EL] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_INS,                  ROTARY,
        KC_GRV,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,             KC_BSPC,                 KC_HOME,
        KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,            KC_BSLS,                 KC_END,
        DF_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                     KC_ENT,                  KC_PGUP,
        KC_LSFT,           KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                     KC_RSFT,     KC_UP,      KC_PGDN,
        KC_LCTL,  KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, KC_RCTL, MO(2),              KC_LEFT,     KC_DOWN,    KC_RGHT
    ),

    [_GL] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_INS,                  TG(1),
        KC_GRV,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,             KC_BSPC,                 KC_HOME,
        KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,            _______,                 KC_END,
        KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                     KC_ENT,                  KC_PGUP,
        KC_LSFT,           KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                     KC_RSFT,     _______,    KC_PGDN,
        KC_LCTL,  KC_NO,   KC_LALT,                           KC_SPC,                             KC_RALT, KC_RCTL, MO(2),              _______,     _______,    _______
    ),

    [_FL] = LAYOUT(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_INS,                   _______,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              _______,                  RGB_TOG,
        KC_NO,   DF_PWD,  KC_NO,   DF_NWD,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGUP, KC_PGDN,            QK_BOOT,                  RGB_VAI,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,                      KC_ENT,                   RGB_VAD,
        KC_LSFT,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   NK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,                       _______,     RGB_MOD,     RGB_HUI,
        KC_NO,   KC_NO,   KC_NO,                              KC_NO,                              KC_NO,   KC_NO,   KC_NO,              RGB_SPD,     RGB_RMOD,    RGB_SPI
    )

};
// clang-format on

// Rotary Encoder Part

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(_GL)) {
        
    }
    switch(get_highest_layer(layer_state)) {
        // _FL
        case _FL:

            break;

        // _GL
        case _GL:

            break;

        default:
            /*
            +------------+----------+
            |   rf.num   | Function |
            +------------+----------+
            |     0      |   Undo   |
            |            |   Redo   |
            +------------+----------+
            |     1      | Zoom In  |
            |            | Zoom Out |
            +------------+----------+
            */

            if (rf.num == 0) {
                if (clockwise) {
                    tap_code16(DF_REDO);
                } else {
                    tap_code16(DF_UNDO);
                }
            } else if (rf.num == 1) {
                if (clockwise) {
                    tap_code16(DF_ZMI);
                } else {
                    tap_code16(DF_ZMO);
                }
            }
            break;
        }

    return false;
}
#endif // ENCODER_ENABLE



// RGB Part

// RGB Layout
//        LED_ESC,   LED_F1,   LED_F2,   LED_F3,   LED_F4,   LED_F5,   LED_F6,   LED_F7,   LED_F8,   LED_F9,   LED_F10,     LED_F11,     LED_F12,     LED_HOME,            NO_LED(Rotary),
//        LED_GRV,   LED_1,    LED_2,    LED_3,    LED_4,    LED_5,    LED_6,    LED_7,    LED_8,    LED_9,    LED_0,       LED_MINS,    LED_EQL,     LED_BSPC,            LED_DEL,
//        LED_TAB,   LED_Q,    LED_W,    LED_E,    LED_R,    LED_T,    LED_Y,    LED_U,    LED_I,    LED_O,    LED_P,       LED_LBRC,    LED_RBRC,    LED_BSLS,            LED_PGUP,
//        LED_CAPS,  LED_A,    LED_S,    LED_D,    LED_F,    LED_G,    LED_H,    LED_J,    LED_K,    LED_L,    LED_SCLN,    LED_QUOT,                 LED_ENT,             LED_PGDN,
//        LED_LSFT,  LED_Z,    LED_X,    LED_C,    LED_V,    LED_B,    LED_N,    LED_M,    LED_COMM, LED_DOT,  LED_SLSH,                         LED_RSFT,      LED_UP,    LED_END,
//        LED_LCTL,  LED_LGUI, LED_LALT,                            LED_SPC,                                   LED_RALT,    LED_MO(_FL), LED_RCTL,    LED_LEFT, LED_DOWN,  LED_RGHT


bool caps_active = false;
bool caps_flash_on = false;

uint16_t caps_flasher = 0;

bool rgb_matrix_indicators_user() {
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
			for (uint8_t i = 0; i < sizeof(LED_LIST_FCTROW_2) / sizeof(LED_LIST_FCTROW_2[0]); i++) {
				rgb_matrix_set_color(LED_LIST_FCTROW_2[i], rgb_IDR_CAPS.r, rgb_IDR_CAPS.g, rgb_IDR_CAPS.b);
			}
		} else {
//			for (uint8_t i = 0; i < sizeof(LED_LIST_FCTROW_2) / sizeof(LED_LIST_FCTROW_2[0]); i++) {
//				rgb_matrix_set_color(LED_LIST_FCTROW_2[i], rgb_CurLAYER.r, rgb_CurLAYER.g, rgb_CurLAYER.b);
//			}
		}
    } else {
		caps_active = false;
        caps_flash_on = false;
	}

    return false;
}
