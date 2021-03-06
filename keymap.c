/* Copyright 2015-2017 Jack Humbert
 * Modified by 2021 Xnuk Shuman
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
#include "muse.h"

enum preonic_layers
{ Layer_default
, Layer_left_mod
, Layer_right_mod
, Layer_adjust
};

enum preonic_keycodes
{ Key_nothing = SAFE_RANGE
, Key_to_left_mod
, Key_to_right_mod
};

#define _ KC_TRANSPARENT
#define KC_CARET KC_CIRCUMFLEX
#define KC_L_CURLY KC_LEFT_CURLY_BRACE
#define KC_R_CURLY KC_RIGHT_CURLY_BRACE
#define KC_R_PAREN KC_RIGHT_PAREN
#define KC_DQUOTE KC_DOUBLE_QUOTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[Layer_default] = LAYOUT_ortho_5x12(
KC_GRAVE         , KC_1      , KC_2      , KC_3      , KC_4                          , KC_5     , KC_6     , KC_7                           , KC_8      , KC_9      , KC_0      , KC_BSPACE    ,
LALT_T(KC_TAB)   , KC_Q      , KC_W      , KC_F      , KC_P                          , KC_B     , KC_J     , KC_L                           , KC_U      , KC_Y      , KC_SCLN   , KC_BSPACE    ,
LCTL_T(KC_ESC)   , KC_A      , KC_R      , KC_S      , KC_T                          , KC_G     , KC_M     , KC_N                           , KC_E      , KC_I      , KC_O      , KC_MINS      ,
KC_LSPO /* ( */  , KC_Z      , KC_X      , KC_C      , KC_D                          , KC_V     , KC_K     , KC_H                           , KC_COMMA  , KC_DOT    , KC_SLASH  , KC_ENTER     ,
ALL_T(KC_BSLS)   , KC_LALT   , KC_LCTRL  , KC_LGUI   , LT(Key_to_left_mod,KC_RIGHT)  , KC_SPC   , KC_SPC   , LT(Key_to_right_mod,KC_HAEN)   , KC_LEFT   , KC_DOWN   , KC_UP     , KC_RIGHT     
),


[Layer_left_mod] = LAYOUT_ortho_5x12(
_  , KC_EXLM    , KC_AT      , KC_HASH    , KC_DOLLAR  , KC_PERCENT , KC_CARET   , KC_AMPERSAND , KC_ASTERISK    , KC_DQUOTE  , KC_COLN        , KC_DEL         ,
_  , KC_EXLM    , KC_AT      , KC_HASH    , KC_DOLLAR  , KC_PERCENT , KC_CARET   , KC_AMPERSAND , KC_ASTERISK    , KC_DQUOTE  , KC_COLN        , KC_DEL         ,
_  , KC_PIPE    , KC_GRV     , KC_QUOT    , KC_EQUAL   , KC_PLUS    , KC_LBRC    , KC_LCBR      , KC_R_PAREN     , KC_RCBR    , KC_RBRC        , KC_UNDERSCORE  ,
_  , _          , _          , KC_LT      , KC_GT      , KC_TILDE   , _          , KC_L_CURLY   , KC_RBRC        , KC_DOT     , KC_QUESTION    , _              ,
_  , _          , _          , _          , _          , _          , _          , MO(3)        , _              , _          , _              , _              
),

[Layer_right_mod] = LAYOUT_ortho_5x12(
KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5      , KC_F6    , KC_F7      , KC_F8      , KC_F9      , KC_F10    , KC_F11     , KC_F12    ,
_        , KC_1     , KC_2     , KC_3     , KC_4       , KC_5     , KC_6       , KC_7       , KC_8       , KC_9      , KC_0       , KC_DEL    ,
_        , KC_4     , KC_5     , KC_6     , KC_CIRC    , _        , KC_HOME    , KC_LEFT    , KC_DOWN    , KC_UP     , KC_RGHT    , KC_END    ,
_        , KC_7     , KC_8     , KC_9     , KC_0       , _        , _          , KC_PGUP    , _          , _         , KC_PGDN    , _         ,
_        , _        , _        , _        , MO(3)      , _        , _          , _          , _          , _         , _          , _         
),


[Layer_adjust] = LAYOUT_ortho_5x12(
MAGIC_TOGGLE_NKRO     , _          , _           , _           , _            , _     , _     , _           , _           , _           , _          , RESET     ,
_                     , _          , _           , _           , RGB_SPI      , _     , _     , RGB_SPD     , _           , _           , _          , _         ,
_                     , BL_INC     , RGB_SAI     , RGB_HUI     , RGB_RMOD     , _     , _     , RGB_MOD     , RGB_HUD     , RGB_SAD     , BL_DEC     , _         ,
_                     , _          , _           , _           , _            , _     , _     , _           , _           , _           , _          , _         ,
_                     , _          , _           , _           , _            , _     , _     , _           , _           , _           , _          , _         
)

};

#undef _
#undef KC_CARET
#undef KC_L_CURLY
#undef KC_R_CURLY
#undef KC_R_PAREN
#undef KC_DQUOTE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	#define check_adjust update_tri_layer(Layer_left_mod, Layer_right_mod, Layer_adjust)

	switch (keycode) {
		// case Key_to_default:
		//   if (record->event.pressed) {
		//     set_single_persistent_default_layer(Layer_default);
		//   }
		//   return false;
		//   break;

	case Key_to_left_mod:
	if (record->event.pressed) {
		layer_on(Layer_left_mod);
		check_adjust;
	} else {
		layer_off(Layer_left_mod);
		check_adjust;
	}
	return false;
	break;

	case Key_to_right_mod:
	if (record->event.pressed) {
		layer_on(Layer_right_mod);
		check_adjust;
	} else {
		layer_off(Layer_right_mod);
		check_adjust;
	}
	return false;
	break;

        // case BACKLIT:
        //   if (record->event.pressed) {
        //     register_code(KC_RSFT);
        //     #ifdef BACKLIGHT_ENABLE
        //       backlight_step();
        //     #endif
        //     #ifdef __AVR__
        //     writePinLow(E6);
        //     #endif
        //   } else {
        //     unregister_code(KC_RSFT);
        //     #ifdef __AVR__
        //     writePinHigh(E6);
        //     #endif
        //   }
        //   return false;
        //   break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

// void encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(Layer_right_mod)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
// }

// void dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0:
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
// }


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case Layer_left_mod:
    case Layer_right_mod:
      return false;
    default:
      return true;
  }
}
