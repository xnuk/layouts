// Copyright 2024 Xnuk Shuman
// SPDX-License-Identifier: AGPL-3.0-or-later

#include QMK_KEYBOARD_H

__attribute__ ((weak))
enum layers
{ Layer_default
, Layer_left_mod
, Layer_right_mod
, Layer_adjust
, Layer_danger
, Layer_mouse
, Layer_wheel
};

#define _ KC_TRANSPARENT
#define KC_CARET KC_CIRCUMFLEX
#define KC_L_CURLY KC_LEFT_CURLY_BRACE
#define KC_R_CURLY KC_RIGHT_CURLY_BRACE
#define KC_R_PAREN KC_RIGHT_PAREN
#define KC_DQUOTE KC_DOUBLE_QUOTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{ [Layer_default] = LAYOUT_planck_mit
( LALT_T(KC_TAB)   , KC_Q      , KC_W      , KC_F      , KC_P                  , KC_B     , KC_J     , KC_L                           , KC_U                      , KC_Y      , KC_SCLN   , KC_BSPC
, LCTL_T(KC_ESC)   , KC_A      , KC_R      , KC_S      , KC_T                  , KC_G     , KC_M     , KC_N                           , KC_E                      , KC_I      , KC_O      , KC_MINS
, SC_LSPO          , KC_Z      , KC_X      , KC_C      , KC_D                  , KC_V     , KC_K     , KC_H                           , KC_COMMA                  , KC_DOT    , KC_SLASH  , KC_ENTER
, ALL_T(KC_BSLS)   , KC_LALT   , KC_LCTL   , KC_LGUI   , MO(Layer_left_mod)        , KC_SPC          , LT(Layer_right_mod,KC_LNG1)    , LT(Layer_mouse,KC_LEFT)   , KC_DOWN   , KC_UP     , KC_RIGHT
)

, [Layer_left_mod] = LAYOUT_planck_mit
( _  , KC_EXLM    , KC_AT      , KC_HASH    , KC_DOLLAR  , KC_PERCENT , KC_CARET   , KC_AMPERSAND , KC_ASTERISK    , KC_DQUOTE  , KC_COLN        , KC_DEL
, _  , KC_PIPE    , KC_GRV     , KC_QUOT    , KC_EQUAL   , KC_PLUS    , KC_LBRC    , KC_LCBR      , KC_R_PAREN     , KC_RCBR    , KC_RBRC        , KC_UNDERSCORE
, _  , _          , _          , KC_LT      , KC_GT      , KC_TILDE   , _          , KC_L_CURLY   , KC_RBRC        , _          , KC_QUESTION    , _
, _  , _          , _          , _          , _          , _                  , _                 , _              , _          , _              , _
)

, [Layer_right_mod] = LAYOUT_planck_mit
( _        , KC_1     , KC_2     , KC_3     , KC_4       , KC_5     , KC_6       , KC_7       , KC_8       , KC_9      , KC_0       , KC_DEL
, _        , KC_4     , KC_5     , KC_6     , KC_CIRC    , _        , KC_HOME    , KC_LEFT    , KC_DOWN    , KC_UP     , KC_RGHT    , KC_END
, _        , KC_7     , KC_8     , KC_9     , KC_0       , _        , _          , KC_PGUP    , _          , _         , KC_PGDN    , _
, _        , _        , _        , _        , _                , _               , _          , _          , _         , _          , _
)

, [Layer_adjust] = LAYOUT_planck_mit
( KC_F1                 , KC_F2               , KC_F3                 , KC_F4             , KC_F5                , KC_F6     , KC_F7      , KC_F8                , KC_F9       , KC_F10      , KC_F11     , KC_F12
, _                     , KC_MEDIA_PLAY_PAUSE , KC_AUDIO_VOL_DOWN     , KC_AUDIO_VOL_UP   , MO(Layer_danger)     , _         , _          , MO(Layer_danger)     , _           , _           , _          , _
, _                     , _                   , _                     , _                 , _                    , _         , _          , _                    , _           , _           , _          , _
, TO(Layer_default)     , _                   , _                     , _                 , _                          , _                , _                    , _           , _           , _          , _
)

, [Layer_danger] = LAYOUT_planck_mit
( QK_MAGIC_TOGGLE_NKRO   , _  , _     , _                   , _    , _    , _   , _    , _     , _      , _      , QK_BOOTLOADER
, _                      , _  , _     , _                   , _    , _    , _   , _    , _     , _      , _      , _
, _                      , _  , _     , TO(Layer_default)   , _    , _    , _   , _    , _     , _      , _      , _
, TO(Layer_default)      , _  , _     , _                   , _       , _       , _    , _     , _      , _      , _
)

, [Layer_mouse] = LAYOUT_planck_mit
( _   , _         , MS_BTN2   , MS_BTN3  , MS_BTN1         , _          , _        , _          , MS_UP     , _       , _    , _
, _   , MS_ACL2   , MS_ACL1   , MS_ACL0  , MO(Layer_wheel) , MS_BTN3    , MS_BTN3  , MS_LEFT    , MS_DOWN   , MS_RGHT , _    , MS_BTN2
, _   , _         , _         , _        , _               , _          , _        , _          , _         , _       , _    , _
, _   , _         , _         , _        , _                    , MS_BTN1            , _          , _         , _       , _    , _
)

, [Layer_wheel] = LAYOUT_planck_mit
( _   , _         , MS_BTN2   , MS_BTN3  , MS_BTN1    , _            , _         , _         , MS_WHLU     , _         , _      , _
, _   , MS_ACL2   , MS_ACL1   , MS_ACL0  , _          , MS_BTN3      , MS_BTN3   , MS_WHLL   , MS_WHLD     , MS_WHLR   , _      , MS_BTN2
, _   , _         , _         , _        , _          , _            , _         , _         , _           , _         , _      , _
, _   , _         , _         , _        , _                   , MS_BTN1         , _         , _           , _         , _      , _
)

};

#undef _
#undef KC_CARET
#undef KC_L_CURLY
#undef KC_R_CURLY
#undef KC_R_PAREN
#undef KC_DQUOTE

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, Layer_left_mod, Layer_right_mod, Layer_adjust);
}
