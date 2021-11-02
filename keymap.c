#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYM,
    KP,
    NAV,
    MOU,
    FN,
    MIR,
};

enum custom_keycodes {
    ID_CAPS = SAFE_RANGE,
    LOCK,
};

#define LT_ESC LT(NAV, KC_ESC)
#define LT_TAB LT(SYM, KC_TAB)
#define LT_SPC LT(NAV, KC_SPC)
#define LT_UNDS LT(SYM, ENCODE_SYM(KC_UNDS))

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
#define LT_HASH LT(MIR, ENCODE_SYM(KC_HASH))
#define LT_QUOT LT(MIR, KC_QUOT)

#define MT_LT LGUI_T(ENCODE_SYM(KC_LT))
#define MT_LCBR LALT_T(ENCODE_SYM(KC_LCBR))
#define MT_LBRC LSFT_T(KC_LBRC)
#define MT_LPRN LCTL_T(ENCODE_SYM(KC_LPRN))
#define MT_4 RCTL_T(KC_4)
#define MT_5 RSFT_T(KC_5)
#define MT_6 LALT_T(KC_6)
#define MT_MINS RGUI_T(KC_MINS)
#define MT_RCBR RALT_T(ENCODE_SYM(KC_RCBR))
#define MT_3 RALT_T(KC_3)
#define LT_COLN LT(MIR, ENCODE_SYM(KC_COLN))
#define LT_DOT LT(MIR, KC_DOT)
#define LT_PDOT LT(MIR, KC_PDOT)

#define OSL_MIR OSL(MIR)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALG OSM(MOD_RALT)

#define LAYOUT_split_3x6_3( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, \
    k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, \
    k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, \
                   k36, k37, k38, k39, k40, k41 \
) LAYOUT( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    k00,   k01,   k02,   k03,   k04,   k05,   KC_NO,               KC_NO, k06,   k07,   k08,   k09,   k10,   k11, \
    k12,   k13,   k14,   k15,   k16,   k17,   KC_NO,               KC_NO, k18,   k19,   k20,   k21,   k22,   k23, \
    k24,   k25,   k26,   k27,   k28,   k29,   KC_NO, KC_NO, KC_NO, KC_NO, k30,   k31,   k32,   k33,   k34,   k35, \
    KC_NO, KC_NO, KC_NO, KC_NO,        k36,   k37,   k38,   k39,   k40,   k41,          KC_NO, KC_NO, KC_NO, KC_NO \
)

#define LAYER(layer, \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, \
    k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, \
    k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, \
                   k36, k37, k38, k39, k40, k41 \
) \
    [layer] = LAYOUT_split_3x6_3( \
        k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, \
        k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, \
        k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, \
                       k36, k37, k38, k39, k40, k41 \
    ), \
    [layer + MIR] = LAYOUT_split_3x6_3( \
        M(k11), M(k10), M(k09), M(k08), M(k07), M(k06), M(k05), M(k04), M(k03), M(k02), M(k01), M(k00), \
        M(k23), M(k22), M(k21), M(k20), M(k19), M(k18), M(k17), M(k16), M(k15), M(k14), M(k13), M(k12), \
        M(k35), M(k34), M(k33), M(k32), M(k31), M(k30), M(k29), M(k28), M(k27), M(k26), M(k25), M(k24), \
                                M(k41), M(k40), M(k39), M(k38), M(k37), M(k36) \
    )

#undef M
#define M(kc) ( \
    MIRROR_KEY(kc, KC_LEFT, KC_RGHT) \
    MIRROR_KEY(kc, KC_HOME, KC_END) \
    MIRROR_KEY(kc, KC_MS_L, KC_MS_R) \
    MIRROR_KEY(kc, KC_WH_L, KC_WH_R) \
    REPLACE_LAYER(kc, SYM, NAV) REPLACE_LAYER(kc, NAV, SYM) \
    (kc) \
)

#define MIRROR_KEY(kc, left, right) (uint16_t)(kc) == (left) ? (right) : (uint16_t)(kc) == (right) ? (left) :

#define REPLACE_LAYER(kc, a, b) IN_RANGE(kc, QK_LAYER_TAP) && GET_LT_LAYER(kc) == (a) ? LT(b, (kc) & 0xFF) :

#define IN_RANGE(kc, range) ((uint16_t)(kc) >= range && (uint16_t)(kc) <= range##_MAX)

#define GET_LT_LAYER(kc) (((kc) >> 8) & 0xF)

#define ENCODE_SYM(kc) ((kc) >= KC_EXLM && (kc) <= KC_QUES ? (kc) - KC_EXLM + KC_FN0 : (kc))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYER(BASE,
        KC_AT,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DQUO,
        LT_HASH, MT_A,    MT_R,    MT_S,    MT_T,    KC_G,    KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    LT_QUOT,
        XXXXXXX, KC_Z,    MT_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, MT_DOT,  KC_SLSH, KC_GRV,
                                   LT_ESC,  LT_TAB,  KC_ENT,  KC_BSPC, LT_SPC,  LT_UNDS
    ),

    LAYER(SYM,
        KC_CIRC, KC_PIPE, KC_AMPR, KC_EQL,  KC_EXLM, KC_DLR,  KC_PERC, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_QUES,
        LT_COLN, MT_LT,   MT_LCBR, MT_LBRC, MT_LPRN, KC_BSLS, KC_ASTR, MT_4,    MT_5,    MT_6,    MT_MINS, LT_DOT,
        XXXXXXX, KC_GT,   MT_RCBR, KC_RBRC, KC_RPRN, KC_TILD, KC_0,    KC_1,    KC_2,    MT_3,    KC_SLSH, TG(KP),
                                   _______, KC_TAB,  _______, _______, _______, KC_UNDS
    ),

    LAYER(KP,
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, LT_PDOT,
        _______, _______, _______, _______, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_NLCK,
                                   _______, _______, KC_PENT, _______, _______, _______
    ),

    LAYER(NAV,
        DM_PLY1, DM_REC1, TG(MOU), TG(FN),  XXXXXXX, RESET,   KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
        OSL_MIR, OSM_GUI, OSM_ALT, OSM_SFT, OSM_CTL, XXXXXXX, KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, OSL_MIR,
        XXXXXXX, XXXXXXX, OSM_ALG, ID_CAPS, LOCK,    XXXXXXX, KC_MUTE, KC_INS,  KC_CAPS, KC_APP,  KC_DEL,  XXXXXXX,
                                   KC_ESC,  _______, _______, _______, KC_SPC,  _______
    ),

    LAYER(MOU,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BTN4, _______, KC_BTN5, _______, _______,
                                   _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2
    ),

    LAYER(FN,
        _______, _______, _______, _______, _______, _______, KC_PAUS, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, KC_SLCK, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
        _______, _______, _______, _______, _______, _______, KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                                   _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, SYM))
        state &= ~(1UL << KP);
    if (IS_LAYER_OFF_STATE(state, NAV))
        state &= ~(1UL << MOU) & ~(1UL << FN);

    bool mirror = IS_LAYER_ON_STATE(state, MIR);
    state &= (1UL << MIR) - 1;
    if (mirror)
        state |= (state | 1) << MIR;

    return state;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return IN_RANGE(keycode, QK_LAYER_TAP) && GET_LT_LAYER(keycode) != MIR;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    if ((IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_MOD_TAP)) && record->tap.count)
        keycode &= 0xFF;

    static bool identifier_caps = false;
    bool is_identifier = (keycode >= KC_A && keycode <= KC_0) || ENCODE_SYM(keycode) == ENCODE_SYM(KC_UNDS)
        || keycode == KC_BSPC || IN_RANGE(keycode, QK_LAYER_TAP);
    if ((keycode == ID_CAPS || (identifier_caps && !is_identifier)) && pressed) {
        identifier_caps = !identifier_caps;
        tap_code(KC_CAPS);
    }

    static bool lock_next = false;
    static layer_state_t locked_layers = 0;
    if (lock_next && !pressed) {
        lock_next = false;
        if (IN_RANGE(keycode, QK_LAYER_TAP) && GET_LT_LAYER(keycode) != MIR)
            locked_layers |= 1UL << GET_LT_LAYER(keycode);
        return false;
    } else if (keycode == LOCK && !pressed) {
        lock_next = true;
    } else if (locked_layers && keycode == KC_ESC && pressed) {
        layer_and(~locked_layers);
        locked_layers = 0;
        return false;
    }

    if (IS_FN(keycode)) {
        (pressed ? register_code16 : unregister_code16)(FN_INDEX(keycode) + KC_EXLM);
        return false;
    }

    return true;
}
