#pragma once

#ifndef KEYBOARD_preonic_rev3
fuck this shit imma out;
#endif

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PREONIC_SOUND)

#define DEFAULT_LAYER_SONGS { \
SONG(QWERTY_SOUND), \
SONG(COLEMAK_SOUND), \
SONG(DVORAK_SOUND) \
}
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

#define RGBLIGHT_LAYERS

#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 8
#define MOUSEKEY_WHEEL_DELAY 0
#define MK_MOMENTARY_ACCEL

#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_DEFAULT 440.f
