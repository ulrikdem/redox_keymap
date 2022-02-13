#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SFT,
    NUM,
    KP,
    KP_SFT,
    FN,
    NAV,
    MOU,
    MIR,
};

enum custom_keycodes {
    REPEAT = SAFE_RANGE,
    ID_CAPS,
    LOCK,
};

#define LT_ENT LT(NUM, KC_ENT)
#define LT_SPC LT(NAV, KC_SPC)

#define MT_A LGUI_T(KC_A)
#define MT_R LALT_T(KC_R)
#define MT_S LSFT_T(KC_S)
#define MT_T LCTL_T(KC_T)
#define MT_N RCTL_T(KC_N)
#define MT_E RSFT_T(KC_E)
#define MT_I LALT_T(KC_I)
#define MT_O RGUI_T(KC_O)
#define MT_X RALT_T(KC_X)
#define MT_DOT RALT_T(KC_DOT)
#define MT_GT RALT_T(ENCODE_SYM(KC_GT))

#define MT_COMM LGUI_T(KC_COMM)
#define MT_LPRN LALT_T(ENCODE_SYM(KC_LPRN))
#define MT_RPRN LSFT_T(ENCODE_SYM(KC_RPRN))
#define MT_NDOT LCTL_T(KC_DOT)
#define MT_PDOT LCTL_T(KC_PDOT)
#define MT_4 RCTL_T(KC_4)
#define MT_5 RSFT_T(KC_5)
#define MT_6 LALT_T(KC_6)
#define MT_0 RGUI_T(KC_0)
#define MT_LCBR RALT_T(ENCODE_SYM(KC_LCBR))
#define MT_3 RALT_T(KC_3)

#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALG OSM(MOD_RALT)

#define LAYOUT_ulrikdem( \
    k00, k01, k02, k03,                     k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
                        k44, k45, k46, k47 \
) LAYOUT( \
    k00,   k01,   k02,   k03,   KC_NO, KC_NO,                             KC_NO, KC_NO, k08,   k09,   k0a,   k0b, \
    k10,   k11,   k12,   k13,   k14,   k15,   KC_NO,               KC_NO, k16,   k17,   k18,   k19,   k1a,   k1b, \
    k20,   k21,   k22,   k23,   k24,   k25,   KC_NO,               KC_NO, k26,   k27,   k28,   k29,   k2a,   k2b, \
    k30,   k31,   k32,   k33,   k34,   k35,   KC_NO, KC_NO, KC_NO, KC_NO, k36,   k37,   k38,   k39,   k3a,   k3b, \
    KC_NO, KC_NO, KC_NO, KC_NO,        k44,   k45,   KC_NO, KC_NO, k46,   k47,          KC_NO, KC_NO, KC_NO, KC_NO \
)

#define LAYER(layer, \
    k00, k01, k02, k03,                     k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
                        k44, k45, k46, k47 \
) \
    [layer] = LAYOUT_ulrikdem( \
        k00, k01, k02, k03,                     k08, k09, k0a, k0b, \
        k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
        k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
                            k44, k45, k46, k47 \
    ), \
    [layer + MIR] = LAYOUT_ulrikdem( \
        M(k0b), M(k0a), M(k09), M(k08),                                 M(k03), M(k02), M(k01), M(k00), \
        M(k1b), M(k1a), M(k19), M(k18), M(k17), M(k16), M(k15), M(k14), M(k13), M(k12), M(k11), M(k10), \
        M(k2b), M(k2a), M(k29), M(k28), M(k27), M(k26), M(k25), M(k24), M(k23), M(k22), M(k21), M(k20), \
        M(k3b), M(k3a), M(k39), M(k38), M(k37), M(k36), M(k35), M(k34), M(k33), M(k32), M(k31), M(k30), \
                                        k44,    k45,    k46,    k47 \
    )

#undef M
#define M(kc) ( \
    MIRROR_KEY(kc, KC_LPRN, KC_RPRN) \
    MIRROR_KEY(kc, KC_LBRC, KC_RBRC) \
    MIRROR_KEY(kc, KC_LCBR, KC_RCBR) \
    MIRROR_KEY(kc, KC_LT, KC_GT) \
    MIRROR_KEY(kc, KC_LEFT, KC_RGHT) \
    MIRROR_KEY(kc, KC_HOME, KC_END) \
    MIRROR_KEY(kc, KC_MS_L, KC_MS_R) \
    MIRROR_KEY(kc, KC_WH_L, KC_WH_R) \
    (kc) \
)

#define MIRROR_KEY(kc, left, right) REPLACE_KEY(kc, left, right) REPLACE_KEY(kc, right, left)
#define REPLACE_KEY(kc, left, right) \
    (uint16_t)(kc) == (left) ? (right) : \
    (IN_RANGE(kc, QK_LAYER_TAP) || IN_RANGE(kc, QK_MOD_TAP)) \
        && ((kc) & 0xFF) == ENCODE_SYM(left) ? ((kc) & 0xFF00) | ENCODE_SYM(right) :

#define IN_RANGE(kc, range) ((uint16_t)(kc) >= range && (uint16_t)(kc) <= range##_MAX)

#define ENCODE_SYM(kc) ((kc) >= KC_EXLM && (kc) <= KC_QUES ? (kc) - KC_EXLM + KC_FN0 : (kc))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYER(BASE,
        KC_GRV,  KC_EXLM, KC_CIRC, KC_DLR,                                      KC_ASTR, KC_BSLS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
        KC_ESC,  MT_A,    MT_R,    MT_S,    MT_T,    KC_G,    KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    KC_QUOT,
        MO(MIR), KC_Z,    MT_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, MT_DOT,  KC_SLSH, MO(MIR),
                                            LT_SPC,  LT_ENT,  LT_SPC,  LT_ENT
    ),

    LAYER(SFT,
        _______, KC_AT,   KC_HASH, KC_PERC,                                     KC_AMPR, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LT,   MT_GT,   _______, _______,
                                            _______, _______, _______, _______
    ),

    LAYER(NUM,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, XXXXXXX, KC_LBRC, KC_RBRC, LOCK,    XXXXXXX, TG(KP),  KC_7,    KC_8,    KC_9,    _______, _______,
        _______, MT_COMM, MT_LPRN, MT_RPRN, MT_NDOT, XXXXXXX, TG(FN),  MT_4,    MT_5,    MT_6,    MT_0,    _______,
        _______, KC_LT,   MT_LCBR, KC_RCBR, KC_GT,   XXXXXXX, XXXXXXX, KC_1,    KC_2,    MT_3,    _______, _______,
                                            _______, KC_ENT,  _______, KC_ENT
    ),

    LAYER(KP,
        _______, _______, _______, _______,                                     KC_PAST, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_NUM,  KC_P7,   KC_P8,   KC_P9,   _______, KC_PMNS,
        _______, _______, _______, _______, MT_PDOT, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_P0,   _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
                                            _______, KC_PENT, _______, KC_PENT
    ),

    LAYER(KP_SFT,
        _______, _______, _______, _______,                                     KC_AMPR, _______, KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUES, _______,
                                            _______, _______, _______, _______
    ),

    LAYER(FN,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_PAUS, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
        _______, _______, _______, _______, _______, _______, KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                                            _______, _______, _______, _______
    ),

    LAYER(NAV,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, DM_REC1, DM_PLY1, XXXXXXX, LOCK,    RESET,   KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, OSM_GUI, OSM_ALT, OSM_SFT, OSM_CTL, TG(MOU), KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, XXXXXXX, OSM_ALG, ID_CAPS, REPEAT,  XXXXXXX, KC_MUTE, KC_INS,  KC_CAPS, KC_APP,  KC_DEL,  _______,
                                            KC_SPC,  _______, KC_SPC,  _______
    ),

    LAYER(MOU,
        _______, _______, _______, _______,                                     _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BTN4, XXXXXXX, KC_BTN5, KC_BTN3, _______,
                                            _______, _______, KC_BTN1, KC_BTN2
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, NUM))
        state &= ~(1UL << KP | 1UL << FN);
    if (IS_LAYER_OFF_STATE(state, NAV))
        state &= ~(1UL << MOU);

    state = update_tri_layer_state(state, KP, SFT, KP_SFT);

    bool mirror = IS_LAYER_ON_STATE(state, MIR);
    state &= (1UL << MIR) - 1;
    if (mirror)
        state |= (state | 1) << MIR;

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    if ((IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_MOD_TAP)) && record->tap.count)
        keycode &= 0xFF;
    uint16_t orig_keycode = keycode;
    if (IS_FN(keycode))
        keycode = FN_INDEX(keycode) + KC_EXLM;
    bool basic_or_mods = IN_RANGE(keycode, QK_BASIC) || IN_RANGE(keycode, QK_MODS);

    static uint16_t last_keycode = KC_NO, repeating_keycode = KC_NO;
    if (keycode == REPEAT) {
        keycode = pressed ? last_keycode : repeating_keycode;
        repeating_keycode = keycode;
    } else if (basic_or_mods && pressed) {
        last_keycode = keycode;
        if (get_mods() & MOD_MASK_CTRL) last_keycode |= QK_LCTL;
        if (get_mods() & MOD_MASK_SHIFT) last_keycode |= QK_LSFT;
        if (get_mods() & MOD_BIT(KC_LALT)) last_keycode |= QK_LALT;
        if (get_mods() & MOD_BIT(KC_RALT)) last_keycode |= QK_RALT;
        if (get_mods() & MOD_MASK_GUI) last_keycode |= QK_LGUI;
    }

    static bool identifier_caps = false;
    uint8_t shift = get_mods() & MOD_MASK_SHIFT;
    bool is_identifier = (
        (keycode >= KC_A && keycode <= KC_Z)
        || (keycode >= KC_1 && keycode <= KC_0 && !shift)
        || (keycode == KC_MINS && shift) || keycode == KC_UNDS
        || keycode == KC_BSPC
    ) && !(get_mods() & MOD_MASK_CAG);
    if ((keycode == ID_CAPS || (identifier_caps && basic_or_mods && !is_identifier)) && pressed) {
        identifier_caps = !identifier_caps;
        tap_code(KC_CAPS);
    }

    static bool lock_next = false;
    static layer_state_t locked_layers = 0;
    if (lock_next && !pressed) {
        lock_next = false;
        if (IN_RANGE(keycode, QK_LAYER_TAP))
            locked_layers |= 1UL << (keycode >> 8 & 0xF);
        return false;
    } else if (keycode == LOCK && !pressed) {
        lock_next = true;
    } else if (locked_layers && keycode == KC_ESC && pressed) {
        layer_and(~locked_layers);
        locked_layers = 0;
        return false;
    }

    if (keycode != orig_keycode) {
        (pressed ? register_code16 : unregister_code16)(keycode);
        return false;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_mods() & MOD_MASK_SHIFT) {
        if (IS_LAYER_OFF(SFT))
            layer_on(SFT);
    } else {
        if (IS_LAYER_ON(SFT))
            layer_off(SFT);
    }
}

const key_override_t
    ppls_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PPLS),
    **key_overrides = (const key_override_t *[]){&ppls_override, NULL};
