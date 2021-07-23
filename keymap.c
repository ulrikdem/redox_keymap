#include QMK_KEYBOARD_H

enum layers {
    BASE,
    NUM,
    KP,
    SYM,
    NAVBASE,
    NAV,
    MOU,
    GAM,
    GAN,
    MIRROR,
};

enum custom_keycodes {
    LOCK = SAFE_RANGE,
};

#define OSL_NUM OSL(NUM)
#define OSL_SYM OSL(SYM)
#define OSL_NAV OSL(NAV)
#define OSL_MOU OSL(MOU)
#define OSL_GAN OSL(GAN)
#define OSL_MIR OSL(MIRROR)

#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)

#define MT_A LALT_T(KC_A)
#define MT_R LGUI_T(KC_R)
#define MT_S LSFT_T(KC_S)
#define MT_T LCTL_T(KC_T)
#define MT_N RCTL_T(KC_N)
#define MT_E RSFT_T(KC_E)
#define MT_I RGUI_T(KC_I)
#define MT_O LALT_T(KC_O)

#define MT_SHIFTED(mod, kc) F((MOD_INDEX(mod) << 8) | ((kc) & 0xFF))
#define MT_BSLS LALT_T(KC_BSLS)
#define MT_SCLN LGUI_T(KC_SCLN)
#define MT_LCBR MT_SHIFTED(KC_LSFT, KC_LCBR)
#define MT_RCBR MT_SHIFTED(KC_LCTL, KC_RCBR)
#define MT_LPRN MT_SHIFTED(KC_RCTL, KC_LPRN)
#define MT_RPRN MT_SHIFTED(KC_RSFT, KC_RPRN)
#define MT_MINS RGUI_T(KC_MINS)
#define MT_COLN MT_SHIFTED(KC_LALT, KC_COLN)

#define MT_F11 LALT_T(KC_F11)
#define MT_F6 LGUI_T(KC_F6)
#define MT_F5 LSFT_T(KC_F5)
#define MT_F4 LCTL_T(KC_F4)
#define MT_4 RCTL_T(KC_4)
#define MT_5 RSFT_T(KC_5)
#define MT_6 RGUI_T(KC_6)
#define MT_0 LALT_T(KC_0)

#define LAYOUT_split_3x6_4( \
    k00, k01, k02, k03, k04, k05,           k06, k07, k08, k09, k10, k11, \
    k12, k13, k14, k15, k16, k17,           k18, k19, k20, k21, k22, k23, \
    k24, k25, k26, k27, k28, k29,           k30, k31, k32, k33, k34, k35, \
                   k36, k37, k38, k39, k40, k41, k42, k43 \
) \
    LAYOUT( \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        k00,   k01,   k02,   k03,   k04,   k05,   KC_NO,               KC_NO, k06,   k07,   k08,   k09,   k10,   k11, \
        k12,   k13,   k14,   k15,   k16,   k17,   KC_NO,               KC_NO, k18,   k19,   k20,   k21,   k22,   k23, \
        k24,   k25,   k26,   k27,   k28,   k29,   KC_NO, KC_NO, KC_NO, KC_NO, k30,   k31,   k32,   k33,   k34,   k35, \
        KC_NO, KC_NO, KC_NO, k36,          k37,   k38,   k39,   k40,   k41,   k42,          k43,   KC_NO, KC_NO, KC_NO \
    )

#define LAYER(layer, \
    k00, k01, k02, k03, k04, k05,           k06, k07, k08, k09, k10, k11, \
    k12, k13, k14, k15, k16, k17,           k18, k19, k20, k21, k22, k23, \
    k24, k25, k26, k27, k28, k29,           k30, k31, k32, k33, k34, k35, \
                   k36, k37, k38, k39, k40, k41, k42, k43 \
) \
    [layer] = LAYOUT_split_3x6_4( \
        k00, k01, k02, k03, k04, k05,           k06, k07, k08, k09, k10, k11, \
        k12, k13, k14, k15, k16, k17,           k18, k19, k20, k21, k22, k23, \
        k24, k25, k26, k27, k28, k29,           k30, k31, k32, k33, k34, k35, \
                       k36, k37, k38, k39, k40, k41, k42, k43 \
    ), \
    [layer + MIRROR] = LAYOUT_split_3x6_4( \
        M(k11), M(k10), M(k09), M(k08), M(k07), M(k06),                 M(k05), M(k04), M(k03), M(k02), M(k01), M(k00), \
        M(k23), M(k22), M(k21), M(k20), M(k19), M(k18),                 M(k17), M(k16), M(k15), M(k14), M(k13), M(k12), \
        M(k35), M(k34), M(k33), M(k32), M(k31), M(k30),                 M(k29), M(k28), M(k27), M(k26), M(k25), M(k24), \
                                M(k43), M(k42), M(k41), M(k40), M(k39), M(k38), M(k37), M(k36) \
    )

#undef M
#define M(kc) \
    ( \
        (kc) == OSL(MIRROR) ? MO(MIRROR) : \
        MIRROR_KEY(kc, KC_LCBR, KC_RCBR) MIRROR_KEY(kc, KC_LBRC, KC_RBRC) \
        MIRROR_KEY(kc, KC_LPRN, KC_RPRN) MIRROR_KEY(kc, KC_LT, KC_GT) \
        MIRROR_KEY(kc, KC_LEFT, KC_RGHT) MIRROR_KEY(kc, KC_HOME, KC_END) \
        MIRROR_KEY(kc, KC_MS_L, KC_MS_R) MIRROR_KEY(kc, KC_WH_L, KC_WH_R) \
        (kc) \
    )

#define MIRROR_KEY(kc, left, right) REPLACE_KEY((uint16_t)(kc), left, right) REPLACE_KEY((uint16_t)(kc), right, left)
#define REPLACE_KEY(kc, left, right) \
    ( \
        (kc) >= QK_MOD_TAP && (kc) <= QK_MOD_TAP_MAX ? (kc) & 0xFF : \
        (kc) >= QK_FUNCTION && (kc) <= QK_FUNCTION_MAX ? LSFT((kc) & 0xFF) : \
        (kc) \
    ) == (left) ? ((kc) & 0xFF00) | ((right) & 0xFF) :

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYER(BASE,
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
        KC_TAB,  MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                      KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    KC_ENT,
        OSL_MIR, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSL_MIR,
                                   OSL_MOU, OSL_NUM, OSM_SFT, OSL_SYM, OSL_SYM, KC_SPC,  OSL_NAV, OSL_NUM
    ),

    LAYER(NUM,
        _______, KC_F12,  KC_F9,   KC_F8,   KC_F7,   KC_PSCR,                   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, _______,
        _______, MT_F11,  MT_F6,   MT_F5,   MT_F4,   KC_SLCK,                   TG(KP),  MT_4,    MT_5,    MT_6,    MT_0,    _______,
        _______, KC_F10,  KC_F3,   KC_F2,   KC_F1,   KC_PAUS,                   XXXXXXX, KC_1,    KC_2,    KC_3,    OSM_GUI, _______,
                                   _______, MO(NUM), _______, _______, _______, _______, _______, MO(NUM)
    ),

    LAYER(KP,
        _______, _______, _______, _______, _______, _______,                   KC_PAST, KC_P7,   KC_P8,   KC_P9,   KC_PDOT, _______,
        _______, _______, _______, _______, _______, KC_NLCK,                   KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_P0,   KC_PENT,
        _______, _______, _______, _______, _______, _______,                   KC_PPLS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    LAYER(SYM,
        _______, KC_AT,   KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                   KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, _______,
        _______, MT_BSLS, MT_SCLN, MT_LCBR, MT_RCBR, KC_ASTR,                   KC_QUES, MT_LPRN, MT_RPRN, MT_MINS, MT_COLN, _______,
        _______, KC_RALT, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,                    KC_PLUS, KC_PERC, KC_DQUO, KC_HASH, KC_RALT, _______,
                                   _______, _______, _______, MO(SYM), MO(SYM), _______, _______, _______
    ),

    LAYER(NAVBASE,
        _______, DM_REC1, DM_PLY1, TG(GAM), XXXXXXX, RESET,                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______,
        _______, OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, XXXXXXX,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, _______,
        _______, XXXXXXX, XXXXXXX, KC_CAPS, LOCK,    XXXXXXX,                   XXXXXXX, KC_DEL,  KC_INS,  KC_APP,  KC_MUTE, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    LAYER(NAV,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, MO(NAV), _______
    ),

    LAYER(MOU,
        _______, _______, _______, _______, _______, _______,                   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, _______, _______,
                                   MO(MOU), _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______
    ),

    LAYER(GAM,
        _______, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,                      _______, _______, _______, _______, _______, _______,
        _______, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      _______, _______, _______, _______, _______, _______,
        _______, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                      _______, _______, _______, _______, _______, _______,
                                   DM_PLY1, OSL_GAN, KC_SPC,  LOCK,    KC_BTN3, KC_BTN1, KC_BTN2, TG(GAM)
    ),

    LAYER(GAN,
        _______, _______, KC_9,    KC_8,    KC_7,    KC_T,                      XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
        _______, KC_0,    KC_6,    KC_5,    KC_4,    KC_G,                      XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
        _______, _______, KC_3,    KC_2,    KC_1,    KC_B,                      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                                   _______, MO(GAN), _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, NUM))
        state &= ~(1UL << KP);

    if (IS_LAYER_ON_STATE(state, NAV) || IS_LAYER_ON_STATE(state, MOU) || IS_LAYER_ON_STATE(state, GAM))
        state |= 1UL << NAVBASE;
    else
        state &= ~(1UL << NAVBASE);

    bool mirror = IS_LAYER_ON_STATE(state, MIRROR);
    state &= (1UL << MIRROR) - 1;
    if (mirror)
        state |= (state | 1) << MIRROR;

    return state;
}

uint16_t keymap_function_id_to_action(uint16_t id) {
    return ACTION_FUNCTION_TAP(id);
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->tap.count)
        (record->event.pressed ? register_code16 : unregister_code16)(LSFT(id));
    else
        (record->event.pressed ? register_mods : unregister_mods)(1 << (opt & ~FUNC_TAP));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool lock_next = false;
    if (lock_next && !record->event.pressed) {
        lock_next = false;
        return false;
    } else if (keycode == LOCK && !record->event.pressed) {
        lock_next = true;
    }
    return true;
}
