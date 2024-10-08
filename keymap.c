// Includes and Macros {{{1

// vim: foldmethod=marker

#include QMK_KEYBOARD_H
#include "process_caps_word.h"

#define LAYER_BIT(layer) ((layer_state_t)1 << (layer))

#define IN_RANGE(kc, range) ((uint16_t)(kc) >= range && (uint16_t)(kc) <= range##_MAX)

// Custom Keycodes {{{1

enum custom_keycodes {
    LOCK = KC_APP + 1,
    CLEAR,
    PLY2,
    SFT_SYM,
    SFT_SYM_MAX = SFT_SYM + (KC_QUES - KC_EXLM),
};
_Static_assert((uint16_t)SFT_SYM_MAX < KC_MUTE);

#define ENCODE_SYM(kc) ((kc) >= KC_EXLM && (kc) <= KC_QUES ? SFT_SYM + ((kc) - KC_EXLM) : (kc))

// Layout Macros {{{1

#define LAYOUT_ulrikdem( \
    k00, k01, k02, k03,                     k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
                   k43, k44, k45, k46, k47, k48 \
) LAYOUT( \
    k00,   k01,   k02,   k03,   KC_NO, KC_NO,                             KC_NO, KC_NO, k08,   k09,   k0a,   k0b, \
    k10,   k11,   k12,   k13,   k14,   k15,   KC_NO,               KC_NO, k16,   k17,   k18,   k19,   k1a,   k1b, \
    k20,   k21,   k22,   k23,   k24,   k25,   KC_NO,               KC_NO, k26,   k27,   k28,   k29,   k2a,   k2b, \
    k30,   k31,   k32,   k33,   k34,   k35,   KC_NO, KC_NO, KC_NO, KC_NO, k36,   k37,   k38,   k39,   k3a,   k3b, \
    k30,   KC_NO, KC_NO, KC_NO,        k43,   k44,   k45,   k46,   k47,   k48,          KC_NO, KC_NO, KC_NO, k3b \
)

#define LAYER(layer, \
    k00, k01, k02, k03,                     k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
                   k43, k44, k45, k46, k47, k48 \
) \
    [layer] = LAYOUT_ulrikdem( \
        k00, k01, k02, k03,                     k08, k09, k0a, k0b, \
        k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
        k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
                       k43, k44, k45, k46, k47, k48 \
    ), \
    [layer + MIRROR] = LAYOUT_ulrikdem( \
        M(k0b), M(k0a), M(k09), M(k08),                                 M(k03), M(k02), M(k01), M(k00), \
        M(k1b), M(k1a), M(k19), M(k18), M(k17), M(k16), M(k15), M(k14), M(k13), M(k12), M(k11), M(k10), \
        M(k2b), M(k2a), M(k29), M(k28), M(k27), M(k26), M(k25), M(k24), M(k23), M(k22), M(k21), M(k20), \
        M(k3b), M(k3a), M(k39), M(k38), M(k37), M(k36), M(k35), M(k34), M(k33), M(k32), M(k31), M(k30), \
                                k43,    k44,    k45,    k46,    k47,    k48 \
    )

#define M(kc) ( \
    MIRROR_KEY(kc, KC_LPRN, KC_RPRN) \
    MIRROR_KEY(kc, KC_LBRC, KC_RBRC) \
    MIRROR_KEY(kc, KC_LCBR, KC_RCBR) \
    MIRROR_KEY(kc, KC_LT, KC_GT) \
    MIRROR_KEY(kc, KC_LEFT, KC_RGHT) \
    MIRROR_KEY(kc, KC_HOME, KC_END) \
    MIRROR_KEY(kc, MS_LEFT, MS_RGHT) \
    MIRROR_KEY(kc, MS_WHLL, MS_WHLR) \
    (kc) \
)

#define MIRROR_KEY(kc, left, right) REPLACE_KEY(kc, left, right) REPLACE_KEY(kc, right, left)

#define REPLACE_KEY(kc, left, right) \
    (uint16_t)(kc) == (left) ? (right) : \
    (IN_RANGE(kc, QK_LAYER_TAP) || IN_RANGE(kc, QK_MOD_TAP)) \
        && ((kc) & 0xFF) == ENCODE_SYM(left) ? ((kc) & 0xFF00) | ENCODE_SYM(right) :

// Layers {{{1

enum layers {
    GAME,
    GAME_NUM,
    GAME_NAV,
    BASE,
    SFT,
    NUM,
    KP,
    KP_SFT,
    NAV,
    MOUSE,
    FN,
    MIRROR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Base Layers {{{1

#define LT_ENT LT(NUM, KC_ENT)
#define LT_SPC LT(NAV, KC_SPC)
#define LT_LOCK LT(FN, LOCK)
#define LT_CLR LT(FN, CLEAR)

#define MT_A LGUI_T(KC_A)
#define MT_R LALT_T(KC_R)
#define MT_S LSFT_T(KC_S)
#define MT_T LCTL_T(KC_T)
#define MT_G RALT_T(KC_G)

#define MT_M RALT_T(KC_M)
#define MT_N RCTL_T(KC_N)
#define MT_E RSFT_T(KC_E)
#define MT_I LALT_T(KC_I)
#define MT_O RGUI_T(KC_O)

#define OSL_MIR OSL(MIRROR)

    LAYER(BASE,
        KC_GRV,  KC_EXLM, KC_CIRC, KC_DLR,                                      KC_UNDS, KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_ESC,  MT_A,    MT_R,    MT_S,    MT_T,    MT_G,    MT_M,    MT_N,    MT_E,    MT_I,    MT_O,    KC_QUOT,
        OSL_MIR, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSL_MIR,
                                   LT_LOCK, LT_ENT,  LT_SPC,  LT_CLR,  LT_SPC,  LT_ENT
    ),

    LAYER(SFT,
        _______, KC_AT,   KC_HASH, KC_PERC,                                     KC_AMPR, KC_ASTR, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______
    ),

// Numeric Layers {{{1

#define MT_LT LGUI_T(ENCODE_SYM(KC_LT))
#define MT_LPRN LALT_T(ENCODE_SYM(KC_LPRN))
#define MT_RPRN LSFT_T(ENCODE_SYM(KC_RPRN))
#define MT_GT LCTL_T(ENCODE_SYM(KC_GT))
#define MT_DOWN RALT_T(KC_DOWN)

#define MT_4 RCTL_T(KC_4)
#define MT_5 RSFT_T(KC_5)
#define MT_6 LALT_T(KC_6)
#define MT_0 RGUI_T(KC_0)

    LAYER(NUM,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_APP,  KC_UP,   TG(KP),  KC_7,    KC_8,    KC_9,    _______, _______,
        _______, MT_LT,   MT_LPRN, MT_RPRN, MT_GT,   MT_DOWN, KC_RALT, MT_4,    MT_5,    MT_6,    MT_0,    _______,
        _______, XXXXXXX, KC_LCBR, KC_RCBR, KC_DOT,  KC_COMM, XXXXXXX, KC_1,    KC_2,    KC_3,    _______, _______,
                                   _______, KC_ENT,  _______, _______, _______, KC_ENT
    ),

    LAYER(KP,
        _______, _______, _______, _______,                                     _______, KC_PMNS, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_NUM,  KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_P0,   _______,
        _______, _______, _______, _______, KC_PDOT, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
                                   _______, KC_PENT, _______, _______, _______, KC_PENT
    ),

    LAYER(KP_SFT,
        _______, _______, _______, _______,                                     _______, KC_PAST, KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUES, _______,
                                   _______, _______, _______, _______, _______, _______
    ),

// Navigation Layers {{{1

#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALG OSM(MOD_RALT)

#define TG_MOUS TG(MOUSE)
#define DF_GAME DF(GAME)
#define DF_GNUM DF(GAME_NUM)

    LAYER(NAV,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, DM_REC1, DM_PLY1, DF_GAME, DF_GNUM, KC_BRIU, KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, OSM_GUI, OSM_ALT, OSM_SFT, OSM_CTL, OSM_ALG, KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, XXXXXXX, XXXXXXX, CW_TOGG, TG_MOUS, KC_BRID, KC_VOLD, KC_INS,  XXXXXXX, QK_REP,  KC_DEL,  _______,
                                   _______, _______, KC_SPC,  _______, KC_SPC,  _______
    ),

    LAYER(MOUSE,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, MS_WHLL, MS_UP,   MS_WHLR, MS_WHLU, _______,
        _______, _______, _______, _______, _______, _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, _______,
        _______, _______, _______, _______, _______, _______, _______, MS_BTN4, XXXXXXX, MS_BTN5, MS_BTN3, _______,
                                   _______, _______, _______, _______, MS_BTN1, MS_BTN2
    ),

// Function Layer {{{1

    LAYER(FN,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_PAUS, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_RALT, KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
        _______, XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                                   LOCK,    _______, _______, CLEAR,   _______, _______
    ),

// Gaming Layers {{{1

#define G_LOCK LT(GAME_NUM, LOCK)
#define G_ESC LT(GAME_NAV, KC_ESC)
#define G_PLY2 LT(BASE, PLY2)

    LAYER(GAME,
        KC_1,    KC_2,    KC_3,    KC_4,                                        MS_BTN1, MS_BTN3, MS_BTN2, KC_BSPC,
        KC_TAB,  KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_VOLU, KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_BSLS,
        G_ESC,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_MUTE, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_QUOT,
        OSL_MIR, KC_LCTL, KC_X,    KC_C,    KC_T,    KC_G,    KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F10,  OSL_MIR,
                                   G_LOCK,  KC_SPC,  G_PLY2,  CLEAR,   KC_SPC,  KC_ENT
    ),

#define GN_SPC LT(BASE, KC_SPC)
#define GN_LOCK LT(GAME_NAV, LOCK)
#define GN_PLY2 LT(BASE + MIRROR, PLY2)

    LAYER(GAME_NUM,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,                                       _______, _______, _______, _______,
        _______, _______, KC_7,    KC_8,    KC_9,    DM_REC2, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_4,    KC_5,    KC_6,    KC_0,    _______, _______, _______, _______, _______, _______,
        _______, _______, KC_1,    KC_2,    KC_3,    KC_A,    _______, _______, _______, _______, _______, _______,
                                   GN_LOCK, GN_SPC,  GN_PLY2, _______, _______, _______
    ),

    LAYER(GAME_NAV,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,                                       _______, _______, _______, _______,
        _______, _______, KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE, _______, _______, _______, _______, _______, _______,
        _______, _______, QK_REP,  KC_BSPC, KC_DEL,  KC_VOLD, _______, _______, _______, _______, _______, _______,
                                   _______, KC_ENT,  _______, _______, _______, _______
    ),

};

// Layer Changes {{{1

void keyboard_post_init_user(void) {
    default_layer_set(LAYER_BIT(BASE));
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, GAME_NUM))
        state |= LAYER_BIT(GAME);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, NUM))
        state &= ~LAYER_BIT(KP);
    if (IS_LAYER_OFF_STATE(state, NAV))
        state &= ~LAYER_BIT(MOUSE);

    state = update_tri_layer_state(state, KP, SFT, KP_SFT);

    bool mirror = IS_LAYER_ON_STATE(state, MIRROR);
    state &= LAYER_BIT(MIRROR) - 1;
    if (mirror)
        state |= (state | default_layer_state | 1) << MIRROR;

    return state;
}

const key_override_t
    past_override = ko_make_basic(MOD_MASK_SHIFT, KC_PAST, KC_PAST),
    ppls_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PPLS),
    *key_overrides[] = {&past_override, &ppls_override, NULL};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT && IS_LAYER_ON_STATE(layer_state | default_layer_state, BASE)) {
        if (IS_LAYER_OFF(SFT))
            layer_on(SFT);
    } else {
        if (IS_LAYER_ON(SFT))
            layer_off(SFT);
    }
}

// Custom Processing {{{1

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    if ((IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_MOD_TAP)) && record->tap.count)
        keycode &= 0xFF;

    if (!process_dynamic_macro(keycode == PLY2 ? DM_PLY2 : keycode, record) || keycode == PLY2)
        return false;

    static bool lock_next = false;
    if (keycode == LOCK) {
        if (pressed)
            lock_next = !lock_next;
        return false;
    } else if (lock_next && !pressed) {
        lock_next = false;
        return false;
    }

    switch (keycode) {
    case SFT_SYM...SFT_SYM_MAX:
        keycode = KC_EXLM + (keycode - SFT_SYM);
        process_caps_word(keycode, record);
        (pressed ? register_code16 : unregister_code16)(keycode);
        return false;

    case CLEAR:
        if (pressed) {
            default_layer_set(LAYER_BIT(BASE));
            layer_clear();
            clear_keyboard();
            clear_oneshot_mods();
            caps_word_off();
            if (host_keyboard_led_state().caps_lock)
                tap_code(KC_CAPS);
            dynamic_macro_stop_recording();
        }
        return false;

    case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
        if (QK_LAYER_TAP_GET_LAYER(keycode) > MIRROR) {
            layer_state_t mask = LAYER_BIT(QK_LAYER_TAP_GET_LAYER(keycode) - MIRROR) | LAYER_BIT(MIRROR);
            if (pressed)
                layer_or(mask);
            else
                layer_and(~mask);
            return false;
        }
        break;

    case QK_ONE_SHOT_LAYER...QK_ONE_SHOT_LAYER_MAX:
        if (!record->tap.count && !pressed)
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        else if (record->tap.count && pressed
                && is_oneshot_layer_active() && get_oneshot_layer() == QK_ONE_SHOT_LAYER_GET_LAYER(keycode))
            return false;
        break;
    }

    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    if (keycode >= KC_A && keycode <= KC_Z)
        add_weak_mods(MOD_BIT(KC_LSFT));
    return (keycode >= KC_A && keycode <= KC_0) || keycode == KC_UNDS || keycode == KC_BSPC;
}
