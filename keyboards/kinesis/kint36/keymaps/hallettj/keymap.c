/* Copyright 2021 Dave Vandyke <kzar@kzar.co.uk>,
 *   Based upon Xyverz's Kinesis keymap Copyright 2017-2020.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "version.h"

enum layer_names {_QWERTY, _DVORAK, _MAC, _PC, _KEYPAD, _PROGRAM};
enum my_keycodes {QWERTY = SAFE_RANGE, DVORAK, WIN, MAC, PC, STATUS, PROGRAM};

#define LED_KEYPAD E26

// clang-format off

/*
        QWERTY layer:
        ,---------------------------------------------------------------------------.
        |    ESC   |  F1  |  F2  |  F3  |  F4  |    F5    |   F6   |   F7   |  F8   |
        `---------------------------------------------------------------------------'
        ,---------------------------------------------------------------------------.
        |    F9    |  F10 |  F11 |  F12 | PScr |   SLck   |  Pause | Keypad | Prgrm |
        `---------------------------------------------------------------------------'
        ,-------------------------------------------.,-------------------------------------------.
        |   =    |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  |   -    |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        | Tab    |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  |   \    |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        | CapsLk |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |   '    |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        | LShift |   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  | RShift |
        `--------+------+------+------+------+------'`------+------+------+------+------+--------'
                 |   `  |   \  | Left | Rght |              |  Up  |  Dn  |   [  |   ]  |
                 `---------------------------'              `---------------------------'
                                     ,--------------.,--------------.
                                     | LCtl  | LAlt || LGUI | RCtl  |
                              ,------|-------|------||------+-------+-------.
                              |      |       | Home || PgUp | Enter |       |
                              | BkSp |  Del  |------||------|   /   | Space |
                              |      |       | End  || PgDn | KeyPd |       |
                              `---------------------'`----------------------'

        Dvorak layer:
        ,---------------------------------------------------------------------------.
        |          |      |      |      |      |          |        |        |       |
        `---------------------------------------------------------------------------'
        ,---------------------------------------------------------------------------.
        |          |      |      |      |      |          |        |        |       |
        `---------------------------------------------------------------------------'
        ,-------------------------------------------.,-------------------------------------------.
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |   '  |   ,  |   .  |   P  |   Y  ||   F  |   G  |   C  |   R  |   L  |   /    |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |   A  |   O  |   E  |   U  |   I  ||   D  |   H  |   T  |   N  |   S  |   \    |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |   ;  |   Q  |   J  |   K  |   X  ||   B  |   M  |   W  |   V  |   Z  |        |
        `--------+------+------+------+------+------'`------+------+------+------+------+--------'
                 |      |      |      |      |              |      |      |      |      |
                 `---------------------------'              `---------------------------'
                                     ,--------------.,--------------.
                                     |       |      ||      |       |
                              ,------|-------|------||------+-------+-------.
                              |      |       |      ||      |       |       |
                              |      |       |------||------|       |       |
                              |      |       |      ||      |       |       |
                              `---------------------'`----------------------'

        Mac layer:
        ,-------------------------------------------------------------------------------.
        |          |      |      |        |        |          |        |        |       |
        `-------------------------------------------------------------------------------'
        ,-------------------------------------------------------------------------------.
        |          |      |      |        |        |   Power  |        |        |       |
        `-------------------------------------------------------------------------------'
        ,-------------------------------------------.,-------------------------------------------.
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        `--------+------+------+------+------+------'`------+------+------+------+------+--------'
                 |      |      |      |      |              |      |      |      |      |
                 `---------------------------'              `---------------------------'
                                      ,-------------.,-------------.
                                      | LGUI | LAlt || RCtl | RGUI |
                               ,------|------|------||------+------+------.
                               |      |      |      ||      |      |      |
                               |      |      |------||------|      |      |
                               |      |      |      ||      |      |      |
                               `--------------------'`--------------------'

        PC layer:
        ,-------------------------------------------------------------------------------.
        |          |      |      |        |        |          |        |        |       |
        `-------------------------------------------------------------------------------'
        ,-------------------------------------------------------------------------------.
        |          |      |      |        |        |          |        |        |       |
        `-------------------------------------------------------------------------------'
        ,-------------------------------------------.,-------------------------------------------.
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        `--------+------+------+------+------+------'`------+------+------+------+------+--------'
                 |      |      |      |      |              |      |      |      |      |
                 `---------------------------'              `---------------------------'
                                      ,-------------.,-------------.
                                      |      |      || RAlt |      |
                               ,------|------|------||------+------+------.
                               |      |      |      ||      |      |      |
                               |      |      |------||------|      |      |
                               |      |      |      ||      |      |      |
                               `--------------------'`--------------------'

        Keypad layer:
        ,---------------------------------------------------------------------------.
        |          |      |      |      |      |          |        |        |       |
        `---------------------------------------------------------------------------'
        ,---------------------------------------------------------------------------.
        |          |      |      |      | Mute | Vol Down | Vol Up | Keypad |       |
        `---------------------------------------------------------------------------'
        ,-------------------------------------------.,-------------------------------------------.
        |        |      |      |      |      |      ||      | NmLk | KP = | KP / | KP * |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      | KP 7 | KP 8 | KP 9 | KP - |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      | KP 4 | KP 5 | KP 6 | KP + |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      | KP 1 | KP 2 | KP 3 |KP Ent|        |
        `--------+------+------+------+------+------'`------+------+------+------+------+--------'
                 |      |  INS |      |      |              |      |      | KP . |KP Ent|
                 `---------------------------'              `---------------------------'
                                      ,-------------.,-------------.
                                      |      |      ||      |      |
                               ,------|------|------||------+------+------.
                               |      |      |      ||      |      |      |
                               |      |      |------||------|      | KP 0 |
                               |      |      |      ||      |      |      |
                               `--------------------'`--------------------'

        Program layer:
        ,-------------------------------------------------------------------------------.
        |  STATUS  |      |      | QWERTY | DVORAK |          |        |        |       |
        `-------------------------------------------------------------------------------'
        ,-------------------------------------------------------------------------------.
        |   RESET  |      |      |        |        |          |        |        |       |
        `-------------------------------------------------------------------------------'
        ,-------------------------------------------.,-------------------------------------------.
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        |--------+------+------+------+------+------||------+------+------+------+------+--------|
        |        |      |      |      |      |      ||      |      |      |      |      |        |
        `--------+------+------+------+------+------'`------+------+------+------+------+--------'
                 |      |      |      |      |              |      |      |      |      |
                 `---------------------------'              `---------------------------'
                                      ,-------------.,-------------.
                                      |      |      ||      |      |
                               ,------|------|------||------+------+------.
                               |      |      |      ||      |      |      |
                               |      |      |------||------|      |      |
                               |      |      |      ||      |      |      |
                               `--------------------'`--------------------'

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Keys here are scrambled a little so that they map the way I want them when
// the OS is in Dvorak mode
[_QWERTY] = LAYOUT (
           // Left Hand
           KC_ESC,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,        KC_F8,
           KC_RBRC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
           MO(_KEYPAD), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
           KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                        KC_GRV,  KC_BSLS, KC_LEFT, KC_RGHT,
           // Left Thumb
                        KC_LGUI, KC_LALT,
                                 KC_HOME,
           KC_SPACE,    KC_LCTL, KC_END,

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TG(_KEYPAD),  MO(_PROGRAM),
           KC_6,    KC_8,    KC_9,    KC_0,    KC_7,    KC_MINS,
           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_UP,   KC_DOWN, KC_MINS, KC_EQL,
           // Right Thumb
           KC_RGUI, KC_BSPC,
           KC_PGUP,
           KC_PGDN, KC_RCTL, KC_ENT
    ),

[_DVORAK] = LAYOUT (
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           KC_EQL,  _______, _______, _______, _______, _______,
           _______, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,
           _______,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
           _______, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,
                    _______, _______, _______, _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           KC_F,       KC_G,    KC_C,    KC_R,    KC_L, KC_SLSH,
           KC_D,       KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
           KC_B,       KC_M,    KC_W,    KC_V,    KC_Z, _______,
                    _______, _______, KC_LBRC, KC_RBRC,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, _______
    ),

[_MAC] = LAYOUT (
           // Left Hand
           _______,       _______, _______, _______, _______, _______, _______, _______, _______,
           _______,       KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT,
           _______,       _______, _______, _______, _______, _______,
           _______,  _______, _______, _______, _______, _______,
           OSM(MOD_LSFT), _______, _______, _______, _______, _______,
                          _______, _______, _______, _______,
           // Left Thumb
                          _______, _______,
                                   _______,
           _______,       LCTL_T(KC_ESC), _______,

           // Right Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           KC_CIRCUMFLEX, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_AMPERSAND, KC_APP,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, OSM(MOD_RSFT),
                    _______, _______, _______, _______,
           // Right Thumb
           _______, _______,
           _______,
           _______, RCTL_T(KC_ESC), _______
    ),

[_PC] = LAYOUT (
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           KC_CAPS, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, _______
    ),

[_KEYPAD] = LAYOUT (
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
                    _______, KC_INS,  _______, _______,
           // Left Thumb
                                _______, _______,
                                         KC_MEDIA_PREV_TRACK,
           KC_MEDIA_PLAY_PAUSE, _______, KC_MEDIA_NEXT_TRACK,

           // Right Hand
           _______, _______, _______, _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP, _______, _______,
           _______, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST,  _______,
           _______, KC_7,    KC_8,    KC_9,    KC_PMNS,  _______,
           _______, KC_4,    KC_5,    KC_6,    KC_PPLS,  _______,
           _______, KC_1,    KC_2,    KC_3,    KC_PEQL,  _______,
                    _______, _______, KC_PDOT, KC_PENT,
           // Right Thumb
           _______, KC_DEL,
           _______,
           _______, _______, KC_0
    ),

[_PROGRAM] = LAYOUT (
           // Left Hand
           STATUS,  _______, _______, QWERTY,   DVORAK,  MAC,     PC,     WIN,     _______,
           _______, _______, _______, _______ , _______, _______,
           _______, _______, _______, _______ , _______, _______,
           _______, _______, _______, _______ , _______, _______,
           _______, _______, _______, _______ , _______, _______,
                    _______, _______, _______ , _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand
           RESET,   _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, _______
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(LED_KEYPAD, !layer_state_cmp(state, _KEYPAD));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case QWERTY:
                set_single_persistent_default_layer(_QWERTY);
                return false;
            case DVORAK:
                set_single_persistent_default_layer(_DVORAK);
                return false;
            case MAC:
                layer_on(_MAC);
                layer_off(_PC);
                return false;
            case PC:
                layer_off(_MAC);
                layer_on(_PC);
                return false;
            case WIN:
                layer_off(_MAC);
                layer_off(_PC);
                return false;
            case STATUS:
                SEND_STRING("Firmware> QMK " QMK_VERSION ", " QMK_BUILDDATE "\n");
                SEND_STRING("Keyboard> " QMK_KEYBOARD "\n");
                SEND_STRING("Keymap> " QMK_KEYMAP "\n");

                if (layer_state_is(_QWERTY))
                    SEND_STRING("Layout> QWERTY\n");
                else
                    SEND_STRING("Layout> DVORAK\n");

                if (layer_state_is(_MAC))
                    SEND_STRING("Thumb keys mode> MAC\n");
                else if (layer_state_is(_PC))
                    SEND_STRING("Thumb keys mode> PC\n");
                else
                    SEND_STRING("Thumb keys mode> WIN\n");

                if (keymap_config.nkro)
                    SEND_STRING("NKRO> Enabled\n");
                else
                    SEND_STRING("NKRO> Disabled\n");

                if (debug_enable)
                    SEND_STRING("Debug> Enabled\n");
                else
                    SEND_STRING("Debug> Disabled\n");

                return false;
        }
    }

    return true;
}
