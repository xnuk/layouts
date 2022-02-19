#pragma once

#ifndef KEYBOARD_preonic_rev3
fuck this shit imma out;
#endif

#ifndef CONSOLE_ENABLE
#define NO_DEBUG
#define NO_PRINT
#endif

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PREONIC_SOUND)

// #define AUDIO_CLICKY
// #define AUDIO_CLICKY_FREQ_RANDOMNESS 0.5f
// #define AUDIO_CLICKY_FREQ_MIN 70.0f

/*
#define DEFAULT_LAYER_SONGS { \
SONG(QWERTY_SOUND), \
SONG(COLEMAK_SOUND), \
SONG(DVORAK_SOUND) \
}*/

/*
#define AUDIO_ENABLE_TONE_MULTIPLEXING
#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
*/
#endif

#define MUSIC_MASK (keycode != KC_NO)

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#ifdef RETRO_TAPPING
#undef RETRO_TAPPING
#endif

#define ONESHOT_TIMEOUT 5000

#ifdef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_ANIMATIONS
#endif

// #define RGB_MATRIX_ENABLE
#define RGBLIGHT_LAYERS
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGBLIGHT_SLEEP

#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 0
#define RGBLIGHT_DEFAULT_VAL 0

#define MK_COMBINED

#define MOUSEKEY_DELAY 60
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 8

#define MOUSEKEY_WHEEL_MAX_SPEED 10
#define MOUSEKEY_WHEEL_TIME_TO_MAX 45
#define MOUSEKEY_WHEEL_DELAY 60
#define MOUSEKEY_WHEEL_INTERVAL 100

#define DEBOUNCE 1
