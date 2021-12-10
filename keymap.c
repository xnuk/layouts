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

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// float my_song[][2] = SONG(QWERTY_SOUND);

__attribute__ ((weak))
enum preonic_layers
{ Layer_default
, Layer_qwerty
, Layer_left_mod
, Layer_right_mod
, Layer_adjust
, Layer_danger
, Layer_mouse
, Layer_wheel
, Layer_music
};

// enum preonic_keycodes
// { Key_nothing = SAFE_RANGE
// , Key_to_left_mod
// , Key_to_right_mod
// };

#define _ KC_TRANSPARENT
#define KC_CARET KC_CIRCUMFLEX
#define KC_L_CURLY KC_LEFT_CURLY_BRACE
#define KC_R_CURLY KC_RIGHT_CURLY_BRACE
#define KC_R_PAREN KC_RIGHT_PAREN
#define KC_DQUOTE KC_DOUBLE_QUOTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{ [Layer_default] = LAYOUT_ortho_5x12
( KC_AUDIO_MUTE    , KC_1      , KC_2      , KC_3      , KC_4                          , KC_5     , KC_6     , KC_7                           , KC_8                      , KC_9      , KC_0      , KC_BSPACE
, LALT_T(KC_TAB)   , KC_Q      , KC_W      , KC_F      , KC_P                          , KC_B     , KC_J     , KC_L                           , KC_U                      , KC_Y      , KC_SCLN   , KC_BSPACE
, LCTL_T(KC_ESC)   , KC_A      , KC_R      , KC_S      , KC_T                          , KC_G     , KC_M     , KC_N                           , KC_E                      , KC_I      , KC_O      , KC_MINS
, KC_LSPO          , KC_Z      , KC_X      , KC_C      , KC_D                          , KC_V     , KC_K     , KC_H                           , KC_COMMA                  , KC_DOT    , KC_SLASH  , KC_ENTER
, ALL_T(KC_BSLS)   , KC_LALT   , KC_LCTRL  , KC_LGUI   , LT(Layer_left_mod,KC_RIGHT)   , KC_SPC   , KC_SPC   , LT(Layer_right_mod,KC_HAEN)    , LT(Layer_mouse,KC_LEFT)   , KC_DOWN   , KC_UP     , KC_RIGHT
)

, [Layer_qwerty] = LAYOUT_ortho_5x12
( KC_AUDIO_MUTE    , KC_1      , KC_2      , KC_3      , KC_4                          , KC_5     , KC_6     , KC_7                           , KC_8                      , KC_9      , KC_0      , KC_BSPACE
, LALT_T(KC_TAB)   , KC_Q      , KC_W      , KC_E      , KC_R                          , KC_T     , KC_Y     , KC_U                           , KC_I                      , KC_O      , KC_P      , KC_BSPACE
, LCTL_T(KC_ESC)   , KC_A      , KC_S      , KC_D      , KC_F                          , KC_G     , KC_H     , KC_J                           , KC_K                      , KC_L      , KC_SCLN   , KC_MINS
, _                , KC_Z      , KC_X      , KC_C      , KC_V                          , KC_B     , KC_N     , KC_M                           , KC_COMMA                  , KC_DOT    , KC_SLASH  , KC_ENTER
, ALL_T(KC_BSLS)   , _         , _         , _         , _                             , KC_SPC   , KC_SPC   , _                              , _                         , _         , _         , _
)

, [Layer_left_mod] = LAYOUT_ortho_5x12
( _  , KC_EXLM    , KC_AT      , KC_HASH    , KC_DOLLAR  , KC_PERCENT , KC_CARET   , KC_AMPERSAND , KC_ASTERISK    , KC_DQUOTE  , KC_COLN        , KC_DEL
, _  , KC_EXLM    , KC_AT      , KC_HASH    , KC_DOLLAR  , KC_PERCENT , KC_CARET   , KC_AMPERSAND , KC_ASTERISK    , KC_DQUOTE  , KC_COLN        , KC_DEL
, _  , KC_PIPE    , KC_GRV     , KC_QUOT    , KC_EQUAL   , KC_PLUS    , KC_LBRC    , KC_LCBR      , KC_R_PAREN     , KC_RCBR    , KC_RBRC        , KC_UNDERSCORE
, _  , _          , _          , KC_LT      , KC_GT      , KC_TILDE   , _          , KC_L_CURLY   , KC_RBRC        , _          , KC_QUESTION    , _
, _  , _          , _          , _          , _          , _          , _          , _            , _              , _          , _              , _
)

, [Layer_right_mod] = LAYOUT_ortho_5x12
( _        , _        , _        , _        , _          , _        , _          , _          , _          , _         , _          , _
, _        , KC_1     , KC_2     , KC_3     , KC_4       , KC_5     , KC_6       , KC_7       , KC_8       , KC_9      , KC_0       , KC_DEL
, _        , KC_4     , KC_5     , KC_6     , KC_CIRC    , _        , KC_HOME    , KC_LEFT    , KC_DOWN    , KC_UP     , KC_RGHT    , KC_END
, _        , KC_7     , KC_8     , KC_9     , KC_0       , _        , _          , KC_PGUP    , _          , _         , KC_PGDN    , _
, _        , _        , _        , _        , _          , _        , _          , _          , _          , _         , _          , _
)

, [Layer_adjust] = LAYOUT_ortho_5x12
( _                     , _                   , _                     , _                 , _                    , _        , _          , _                    , _           , _           , _          , _
, KC_F1                 , KC_F2               , KC_F3                 , KC_F4             , KC_F5                , KC_F6    , KC_F7      , KC_F8                , KC_F9       , KC_F10      , KC_F11     , KC_F12
, _                     , KC_MEDIA_PLAY_PAUSE , KC_AUDIO_VOL_DOWN     , KC_AUDIO_VOL_UP   , MO(Layer_danger)     , _        , MU_ON      , MO(Layer_danger)     , _           , _           , _          , _
, _                     , _                   , _                     , _                 , _                    , _        , _          , _                    , _           , _           , _          , _
, TO(Layer_default)     , _                   , _                     , _                 , _                    , _        , _          , _                    , _           , _           , _          , _
)

, [Layer_danger] = LAYOUT_ortho_5x12
( MAGIC_TOGGLE_NKRO   , DEBUG                 , _     , _                   , _    , _      , _                    , KC_SYSTEM_SLEEP  , _     , _      , _      , RESET
, _                   , TO(Layer_qwerty)      , _     , _                   , _    , _      , _                    , _                , _     , _      , _      , _
, _                   , _                     , _     , _                   , _    , _      , MU_ON                , _                , _     , _      , _      , _
, _                   , _                     , _     , TO(Layer_default)   , _    , _      , _                    , _                , _     , _      , _      , _
, TO(Layer_default)   , _                     , _     , _                   , _    , _      , _                    , _                , _     , _      , _      , _
)

, [Layer_mouse] = LAYOUT_ortho_5x12
( _                   , _                , _                , _                 , _               , _               , _               , _                , _              , _                , _      , _
, _                   , _                , KC_MS_BTN2       , KC_MS_BTN3        , KC_MS_BTN1      , _               , _               , _                , KC_MS_UP       , _                , _      , _
, _                   , KC_MS_ACCEL2     , KC_MS_ACCEL1     , KC_MS_ACCEL0      , MO(Layer_wheel) , KC_MS_BTN3      , KC_MS_BTN3      , KC_MS_LEFT       , KC_MS_DOWN     , KC_MS_RIGHT      , _      , KC_MS_BTN2
, _                   , _                , _                , _                 , _               , _               , _               , _                , _              , _                , _      , _
, _                   , _                , _                , _                 , _               , KC_MS_BTN1      , _               , _                , _              , _                , _      , _
)

, [Layer_wheel] = LAYOUT_ortho_5x12
( _                   , _                , _                , _                 , _             , _               , _               , _                   , _                 , _                   , _      , _
, _                   , _                , KC_MS_BTN2       , KC_MS_BTN3        , KC_MS_BTN1    , _               , _               , _                   , KC_MS_WH_UP       , _                   , _      , _
, _                   , KC_MS_ACCEL2     , KC_MS_ACCEL1     , KC_MS_ACCEL0      , _             , KC_MS_BTN3      , KC_MS_BTN3      , KC_MS_WH_LEFT       , KC_MS_WH_DOWN     , KC_MS_WH_RIGHT      , _      , KC_MS_BTN2
, _                   , _                , _                , _                 , _             , _               , _               , _                   , _                 , _                   , _      , _
, _                   , _                , _                , _                 , _             , KC_MS_BTN1      , _               , _                   , _                 , _                   , _      , _
)


#undef _
#define _ KC_NO

, [Layer_music] = LAYOUT_ortho_5x12
( _  , _   , _  , _  , _  , _  , _  , _  , _  , _  , MU_MOD , MU_OFF
, _  , _   , _  , _  , _  , _  , _  , _  , _  , _  , _      , _
, _  , _   , _  , _  , _  , _  , _  , _  , _  , _  , _      , _
, _  , _   , _  , _  , _  , _  , _  , _  , _  , _  , _      , _
, _  , _   , _  , _  , _  , _  , _  , _  , _  , _  , _      , _
)

};

#undef _
#undef KC_CARET
#undef KC_L_CURLY
#undef KC_R_CURLY
#undef KC_R_PAREN
#undef KC_DQUOTE

__attribute__ ((weak))
enum preonic_rgb_layers
{ Light_default
, Light_adjust
, Light_danger
, Light_mouse
, Light_music
, Light_qwerty
};

#define COLO_IDENT(name) my_fucked_layer_ ## name
#define COLO(name, ...) __attribute__ ((weak)) const rgblight_segment_t PROGMEM COLO_IDENT(name) [] = RGBLIGHT_LAYER_SEGMENTS(__VA_ARGS__);

/*
	6    5       4    3
	         0
	7    8       1    2
*/

COLO(Light_default, {0, 9, HSV_OFF});
COLO(Light_adjust
, {1, 1, HSV_PURPLE}
, {2, 1, HSV_CYAN}
, {3, 1, HSV_PURPLE}
, {4, 1, HSV_CYAN}
, {5, 1, HSV_PURPLE}
, {6, 1, HSV_CYAN}
, {7, 1, HSV_PURPLE}
, {8, 1, HSV_CYAN}
);
COLO(Light_danger, {0, 9, HSV_RED});
COLO(Light_mouse, {0, 9, HSV_BLUE});

COLO(Light_music
, {0, 1, HSV_WHITE}
, {1, 1, HSV_RED}
, {2, 1, HSV_BLUE}
, {3, 1, HSV_GREEN}
, {4, 1, HSV_PURPLE}
, {5, 1, HSV_CYAN}
, {6, 1, HSV_YELLOW}
, {7, 1, HSV_GREEN}
, {8, 1, HSV_PURPLE}
);

COLO(Light_qwerty, {0, 9, HSV_ORANGE});

#undef COLO

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST
( [Light_default] = COLO_IDENT(Light_default)
, [Light_adjust]  = COLO_IDENT(Light_adjust)
, [Light_danger]  = COLO_IDENT(Light_danger)
, [Light_mouse]   = COLO_IDENT(Light_mouse)
, [Light_music]   = COLO_IDENT(Light_music)
, [Light_qwerty]  = COLO_IDENT(Light_qwerty)
);

#undef COLO_IDENT

void keyboard_post_init_user(void) {
	rgblight_layers = my_rgb_layers;
	rgblight_set_layer_state(Light_default, true);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(Light_default, layer_state_cmp(state, Layer_default));
	return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, Layer_left_mod, Layer_right_mod, Layer_adjust);

    rgblight_set_layer_state(Light_adjust, layer_state_cmp(state, Layer_adjust));
    rgblight_set_layer_state(Light_danger, layer_state_cmp(state, Layer_danger));
    rgblight_set_layer_state(Light_mouse,  layer_state_cmp(state, Layer_mouse) || layer_state_cmp(state, Layer_wheel));
    rgblight_set_layer_state(Light_music,  layer_state_cmp(state, Layer_music));
	//rgblight_set_layer_state(Light_qwerty, layer_state_cmp(state, Layer_qwerty));

    return state;
}

float qwerty_song[][2] = SONG(QWERTY_SOUND);
float colemak_song[][2] = SONG(COLEMAK_SOUND);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		if (keycode == MU_ON) {
			layer_move(Layer_music);
			return true;
		}

		if (keycode == MU_OFF) {
			layer_move(Layer_default);
			return true;
		}

		if (keycode == TO(Layer_qwerty)) {
			//PLAY_SONG(qwerty_song);

#ifdef CONSOLE_ENABLE
	dprintf("layer to: qwerty\n");
#endif

			return true;
		}

		if (keycode == TO(Layer_default)) {
			PLAY_SONG(colemak_song);


#ifdef CONSOLE_ENABLE
	dprintf("layer to: default\n");
#endif

			return true;
		}
	}

	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
#ifdef CONSOLE_ENABLE
	dprintf("encoder: %d %d\n", index, clockwise);
#endif

	if (index == 0) {
		if (clockwise) {
			tap_code_delay(KC_AUDIO_VOL_UP, 50);
		} else {
			tap_code_delay(KC_AUDIO_VOL_DOWN, 50);
		}
	}

	// If you return true, this will allow the keyboard level code to run
	return false;
}
