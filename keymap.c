#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYM,
    NUM,
    KP,
    NAV,
    MOU,
    GAM,
    GNUM,
    MIR,
};

enum custom_keycodes {
    REC1 = KC_FN0,
    ID_CAPS,
    LOCK,
    SFT_SYM,
    SFT_SYM_MAX = SFT_SYM + (KC_QUES - KC_EXLM),
};
_Static_assert(SFT_SYM_MAX <= (uint16_t)KC_FN31);

#define LT_ESC LT(NAV, KC_ESC)
#define LT_TAB LT(NUM, KC_TAB)
#define LT_SPC LT(NAV, KC_SPC)
#define LT_ENT LT(NUM, KC_ENT)
#define LT_GESC LT(GNUM, KC_ESC)
#define LT_GENT LT(GNUM, KC_ENT)

#define MT_Q RALT_T(KC_Q)
#define MT_SCLN RALT_T(KC_SCLN)
#define MT_A LGUI_T(KC_A)
#define LT_R LT(SYM, KC_R)
#define MT_S LSFT_T(KC_S)
#define MT_T LCTL_T(KC_T)
#define MT_G LALT_T(KC_G)
#define MT_M LALT_T(KC_M)
#define MT_N RCTL_T(KC_N)
#define MT_E RSFT_T(KC_E)
#define LT_I LT(SYM, KC_I)
#define MT_O RGUI_T(KC_O)
#define LT_Z LT(MIR, KC_Z)
#define LT_SLSH LT(MIR, KC_SLSH)

#define MT_HASH RALT_T(ENCODE_SYM(KC_HASH))
#define MT_AMPR RALT_T(ENCODE_SYM(KC_AMPR))
#define MT_BSLS LGUI_T(ENCODE_SYM(KC_BSLS))
#define MT_LCBR LSFT_T(ENCODE_SYM(KC_LCBR))
#define MT_RCBR LCTL_T(ENCODE_SYM(KC_RCBR))
#define MT_ASTR LALT_T(ENCODE_SYM(KC_ASTR))
#define MT_QUES LALT_T(ENCODE_SYM(KC_QUES))
#define MT_LPRN RCTL_T(ENCODE_SYM(KC_LPRN))
#define MT_RPRN RSFT_T(ENCODE_SYM(KC_RPRN))
#define MT_COLN RGUI_T(ENCODE_SYM(KC_COLN))
#define LT_NUBS LT(MIR, ENCODE_SYM(KC_NUBS))

#define MT_F12 RALT_T(KC_F12)
#define OSM_ALG OSM(MOD_RALT)
#define MT_F11 LGUI_T(KC_F11)
#define LT_F6 LT(SYM, KC_F6)
#define MT_F5 LSFT_T(KC_F5)
#define MT_F4 LCTL_T(KC_F4)
#define MT_SLCK LALT_T(KC_SLCK)
#define MT_NLCK LALT_T(KC_NLCK)
#define MT_4 RCTL_T(KC_4)
#define MT_5 RSFT_T(KC_5)
#define LT_6 LT(SYM, KC_6)
#define MT_0 RGUI_T(KC_0)
#define LT_F10 LT(MIR, KC_F10)
#define LT_PSLS LT(MIR, KC_PSLS)

#define MT_REC1 RALT_T(REC1)
#define OSM_GUI OSM(MOD_LGUI)
#define OSL_SYM OSL(SYM)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSL_MIR OSL(MIR)

#define LAYOUT_split_3x5_3( \
    k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29, \
                   k30, k31, k32, k33, k34, k35 \
) \
    LAYOUT( \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, k00,   k01,   k02,   k03,   k04,   KC_NO,               KC_NO, k05,   k06,   k07,   k08,   k09,   KC_NO, \
        KC_NO, k10,   k11,   k12,   k13,   k14,   KC_NO,               KC_NO, k15,   k16,   k17,   k18,   k19,   KC_NO, \
        KC_NO, k20,   k21,   k22,   k23,   k24,   KC_NO, KC_NO, KC_NO, KC_NO, k25,   k26,   k27,   k28,   k29,   KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO,        k30,   k31,   k32,   k33,   k34,   k35,          KC_NO, KC_NO, KC_NO, KC_NO \
    )

#define LAYER(layer, \
    k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29, \
                   k30, k31, k32, k33, k34, k35 \
) \
    [layer] = LAYOUT_split_3x5_3( \
        k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
        k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
        k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29, \
                       k30, k31, k32, k33, k34, k35 \
    ), \
    [layer + MIR] = LAYOUT_split_3x5_3( \
        M(k09), M(k08), M(k07), M(k06), M(k05),                 M(k04), M(k03), M(k02), M(k01), M(k00), \
        M(k19), M(k18), M(k17), M(k16), M(k15),                 M(k14), M(k13), M(k12), M(k11), M(k10), \
        M(k29), M(k28), M(k27), M(k26), M(k25),                 M(k24), M(k23), M(k22), M(k21), M(k20), \
                                M(k35), M(k34), M(k33), M(k32), M(k31), M(k30) \
    )

#undef M
#define M(kc) \
    ( \
        MIRROR_KEY(kc, KC_LCBR, KC_RCBR) MIRROR_KEY(kc, KC_LBRC, KC_RBRC) \
        MIRROR_KEY(kc, KC_LPRN, KC_RPRN) MIRROR_KEY(kc, KC_LT, KC_GT) \
        MIRROR_KEY(kc, KC_LEFT, KC_RGHT) MIRROR_KEY(kc, KC_HOME, KC_END) \
        MIRROR_KEY(kc, KC_MS_L, KC_MS_R) MIRROR_KEY(kc, KC_WH_L, KC_WH_R) \
        REPLACE_LAYER(kc, NUM, NAV) REPLACE_LAYER(kc, NAV, NUM) \
        (kc) \
    )

#define MIRROR_KEY(kc, left, right) REPLACE_KEY(kc, left, right) REPLACE_KEY(kc, right, left)
#define REPLACE_KEY(kc, left, right) \
    (uint16_t)(kc) == (left) ? (right) : \
    (IN_RANGE(kc, QK_LAYER_TAP) || IN_RANGE(kc, QK_MOD_TAP)) \
        && ((kc) & 0xFF) == ENCODE_SYM(left) ? ((kc) & 0xFF00) | ENCODE_SYM(right) :

#define REPLACE_LAYER(kc, left, right) \
    IN_RANGE(kc, QK_LAYER_TAP) && GET_LT_LAYER(kc) == (left) ? LT(right, (kc) & 0xFF) :

#define IN_RANGE(kc, range) ((uint16_t)(kc) >= range && (uint16_t)(kc) <= range##_MAX)

#define GET_LT_LAYER(kc) (((kc) >> 8) & 0xF)

#define ENCODE_SYM(kc) ((kc) >= KC_EXLM && (kc) <= KC_QUES ? SFT_SYM + ((kc) - KC_EXLM) : (kc))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYER(BASE,
        MT_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    MT_SCLN,
        MT_A,    LT_R,    MT_S,    MT_T,    MT_G,                      MT_M,    MT_N,    MT_E,    LT_I,    MT_O,
        LT_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  LT_SLSH,
                                   LT_ESC,  LT_TAB,  KC_DEL,  KC_BSPC, LT_SPC,  LT_ENT
    ),

    LAYER(SYM,
        MT_HASH, KC_AT,   KC_LBRC, KC_RBRC, KC_CIRC,                   KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  MT_AMPR,
        MT_BSLS, KC_UNDS, MT_LCBR, MT_RCBR, MT_ASTR,                   MT_QUES, MT_LPRN, MT_RPRN, KC_MINS, MT_COLN,
        LT_NUBS, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,                    KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, LT_NUBS,
                                   _______, _______, _______, _______, _______, _______
    ),

    LAYER(NUM,
        MT_F12,  KC_F9,   KC_F8,   KC_F7,   KC_PSCR,                   XXXXXXX, KC_7,    KC_8,    KC_9,    OSM_ALG,
        MT_F11,  LT_F6,   MT_F5,   MT_F4,   MT_SLCK,                   OSM_ALT, MT_4,    MT_5,    LT_6,    MT_0,
        LT_F10,  KC_F3,   KC_F2,   KC_F1,   KC_PAUS,                   TG(KP),  KC_1,    KC_2,    KC_3,    OSL_MIR,
                                   _______, KC_TAB,  _______, _______, _______, KC_ENT
    ),

    LAYER(KP,
        _______, _______, _______, _______, _______,                   KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_PDOT,
        _______, _______, _______, _______, MT_NLCK,                   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_P0,
        _______, _______, _______, _______, _______,                   KC_PPLS, KC_P1,   KC_P2,   KC_P3,   LT_PSLS,
                                   _______, _______, _______, _______, _______, KC_PENT
    ),

    LAYER(NAV,
        MT_REC1, DM_PLY1, TG(GAM), XXXXXXX, RESET,                     KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP,
        OSM_GUI, OSL_SYM, OSM_SFT, OSM_CTL, OSM_ALT,                   KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        OSL_MIR, LOCK,    ID_CAPS, TG(MOU), XXXXXXX,                   KC_MUTE, KC_INS,  KC_CAPS, KC_APP,  OSL_MIR,
                                   KC_ESC,  _______, _______, _______, KC_SPC,  _______
    ),

    LAYER(MOU,
        _______, _______, _______, _______, _______,                   _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,
        _______, _______, _______, _______, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
        _______, _______, _______, _______, _______,                   _______, KC_BTN4, KC_BTN5, _______, _______,
                                   _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2
    ),

    LAYER(GAM,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                      KC_MUTE, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,
                                   LT_GESC, KC_SPC,  LOCK,    KC_BSPC, TG(GAM), LT_GENT
    ),

    LAYER(GNUM,
        DM_PLY1, KC_9,    KC_8,    KC_7,    KC_T,                      KC_Y,    KC_F7,   KC_F8,   KC_F9,   KC_F12,
        KC_0,    KC_6,    KC_5,    KC_4,    KC_G,                      KC_H,    KC_F4,   KC_F5,   KC_F6,   KC_F11,
        OSL_MIR, KC_3,    KC_2,    KC_1,    KC_B,                      KC_N,    KC_F1,   KC_F2,   KC_F3,   LT_F10,
                                   KC_ESC,  _______, _______, _______, _______, KC_ENT
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, NUM))
        state &= ~(1UL << KP);
    if (IS_LAYER_OFF_STATE(state, NAV))
        state &= ~(1UL << MOU);

    bool mirror = IS_LAYER_ON_STATE(state, MIR);
    state &= (1UL << MIR) - 1;
    if (mirror)
        state |= (state | 1) << MIR;

    return state;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return IN_RANGE(keycode, QK_LAYER_TAP) && GET_LT_LAYER(keycode) != SYM && GET_LT_LAYER(keycode) != MIR;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    if ((IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_MOD_TAP)) && record->tap.count)
        keycode &= 0xFF;

    if (!process_dynamic_macro(keycode == REC1 ? DM_REC1 : keycode, record))
        return false;

    static bool identifier_caps = false;
    bool is_identifier = (keycode >= KC_A && keycode <= KC_0) || ENCODE_SYM(keycode) == ENCODE_SYM(KC_UNDS)
        || keycode == KC_BSPC || IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_ONE_SHOT_LAYER);
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
        layer_off(get_highest_layer(locked_layers));
        locked_layers &= layer_state;
        return false;
    }

    if (IN_RANGE(keycode, SFT_SYM))
        (pressed ? register_code16 : unregister_code16)(KC_EXLM + (keycode - SFT_SYM));

    return !IS_FN(keycode);
}
