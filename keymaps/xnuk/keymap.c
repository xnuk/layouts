#include QMK_KEYBOARD_H

__attribute__ ((weak))
enum custom_layers
{ Layer_default
, Layer_lower
, Layer_upper
, Layer_mouse
, Layer_wheel
, Layer_adjust
, Layer_danger
};

#define Q_MEH ALL_T(KC_BSLS)
#define Q_LALT LALT_T(KC_TAB)
#define Q_LCTL LCTL_T(KC_ESC)
#define Q_LSFT SC_LSPO
#define Q_LOWER LT(Layer_lower,KC_RIGHT)
#define Q_UPPER LT(Layer_upper,KC_LNG1)
#define Q_MOUSE LT(Layer_mouse,KC_LEFT)
#define Q_WHEEL MO(Layer_wheel)
#define Q_ADJST MO(Layer_adjust)
#define Q_DANGR MO(Layer_danger)

#define _ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{ [Layer_default] = LAYOUT_split_4x6_3
( Q_MEH,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _
, Q_LALT,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC
, Q_LCTL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_MINS
, Q_LSFT,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENTER
,                                     KC_LGUI, Q_LOWER, KC_SPC,  KC_SPC,  Q_UPPER, Q_MOUSE
)

, [Layer_lower] = LAYOUT_split_4x6_3
( _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
, _,       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   _,       KC_AMPR, KC_ASTR, KC_DQT,  KC_COLN, KC_DEL
, _,       KC_PIPE, KC_GRV,  KC_QUOT, KC_EQL,  KC_PLUS,                   KC_LBRC, KC_LCBR, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS
, _,       _,       _,       KC_LT,   KC_GT,   KC_TILD,                   _,       _,       _,       _,       KC_QUES, _
,                                     _,       _,       _,       _,       _,       _
)

, [Layer_upper] = LAYOUT_split_4x6_3
( _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
, _,       KC_1,    KC_2,    KC_3,    _,       _,                         _,       _,       _,       _,       _,       KC_DEL
, _,       KC_4,    KC_5,    KC_6,    KC_CIRC, _,                         KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END
, _,       KC_7,    KC_8,    KC_9,    KC_0,    _,                         KC_PGUP, _,       _,       _,       KC_PGDN, _
,                                     _,       _,       _,       _,       _,       _
)

, [Layer_mouse] = LAYOUT_split_4x6_3
( _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
, _,       _,       _,       _,       _,       _,                         _,       _,       KC_MS_U, _,       _,       _
, _,       KC_ACL2, KC_ACL1, KC_ACL0, Q_WHEEL, _,                         KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, _,       KC_BTN2
, _,       _,       _,       _,       _,       _,                         KC_PGUP, _,       _,       _,       KC_PGDN, _
,                                     _,       _,       KC_BTN1, _,       _,       _
)

, [Layer_wheel] = LAYOUT_split_4x6_3
( _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
, _,       _,       _,       _,       _,       _,                         _,       _,       KC_WH_U, _,       _,       _
, _,       KC_ACL2, KC_ACL1, KC_ACL0, Q_WHEEL, _,                         KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_R, _,       KC_BTN2
, _,       _,       _,       _,       _,       _,                         KC_PGUP, _,       _,       _,       KC_PGDN, _
,                                     _,       _,       KC_BTN1, _,       _,       _
)

, [Layer_adjust] = LAYOUT_split_4x6_3
( _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     _,       KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12
, _,       KC_MUTE, KC_VOLD, KC_VOLU, Q_DANGR, _,                         _,       Q_DANGR, _,       _,       _,       _
, _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
,                                     _,       _,       _,       _,       _,       _
)

, [Layer_danger] = LAYOUT_split_4x6_3
( _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
, _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       QK_BOOT
, _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
, _,       _,       _,       _,       _,       _,                         _,       _,       _,       _,       _,       _
,                                     _,       _,       _,       _,       _,       _
)

};

#undef _

__attribute__ ((weak))
const rgblight_segment_t PROGMEM colo_default[] = RGBLIGHT_LAYER_SEGMENTS
( {0, 54, HSV_OFF} );

__attribute__ ((weak))
const rgblight_segment_t PROGMEM colo_upper[] = RGBLIGHT_LAYER_SEGMENTS
( {7, 3, HSV_BLUE}
, {13, 1, HSV_GREEN}, {14, 3, HSV_BLUE}
, {19, 4, HSV_BLUE}

, {39, 1, HSV_ORANGE}, {40, 4, HSV_PURPLE}, {44, 1, HSV_ORANGE}
, {46, 1, HSV_ORANGE}, {50, 1, HSV_ORANGE}
);

__attribute__ ((weak))
const rgblight_segment_t PROGMEM colo_mouse[] = RGBLIGHT_LAYER_SEGMENTS
( {13, 1, HSV_GREEN}
, {14, 1, 191, 255, 80}
, {15, 1, 191, 255, 160}
, {16, 1, 191, 255, 255}

, {36, 1, HSV_BLUE}
, {39, 1, HSV_GREEN}, {40, 3, HSV_BLUE}, {44, 1, HSV_PURPLE}
, {46, 1, HSV_ORANGE}, {50, 1, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST
( colo_default
, colo_upper
, colo_mouse
);

void keyboard_post_init_user(void) {
	rgblight_layers = my_rgb_layers;
	rgblight_set_layer_state(0, true);
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    waitInputPinDelay();
    waitInputPinDelay();
    waitInputPinDelay();
}

layer_state_t layer_state_set_user(layer_state_t state) {
	state = update_tri_layer_state(state, Layer_lower, Layer_upper, Layer_adjust);

	rgblight_set_layer_state(
	    1,
	    layer_state_cmp(state, Layer_upper)
	    && !layer_state_cmp(state, Layer_adjust)
	    && !layer_state_cmp(state, Layer_lower)
	);

	rgblight_set_layer_state(
		2,
		layer_state_cmp(state, Layer_mouse)
		|| layer_state_cmp(state, Layer_wheel)
	);

	return state;
}
