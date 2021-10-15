#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SFT,
    NUM,
    KP,
    KP_SFT,
    NAV,
    MOU,
    MIR,
};

enum custom_keycodes {
    ID_CAPS = SAFE_RANGE,
    LOCK,
};

#define LT_ESC LT(NAV, KC_ESC)
#define LT_TAB LT(NUM, KC_TAB)
#define LT_SPC LT(NAV, KC_SPC)
#define LT_ENT LT(NUM, KC_ENT)
#define LT_MINS LT(MIR, KC_MINS)
#define LT_QUOT LT(MIR, KC_QUOT)
#define LT_PMNS LT(MIR, KC_PMNS)
#define LT_UNDS LT(MIR, KC_UNDS)

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

#define MT_F11 LGUI_T(KC_F11)
#define MT_F6 LALT_T(KC_F6)
#define MT_F5 LSFT_T(KC_F5)
#define MT_F4 LCTL_T(KC_F4)
#define MT_4 RCTL_T(KC_4)
#define MT_5 RSFT_T(KC_5)
#define MT_6 LALT_T(KC_6)
#define MT_0 RGUI_T(KC_0)
#define MT_F3 RALT_T(KC_F3)
#define MT_3 RALT_T(KC_3)

#define OSL_MIR OSL(MIR)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALG OSM(MOD_RALT)

#define LAYOUT_ulrikdem( \
    k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, \
    k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, \
         k34, k35, k36, k37, k38, k39, k40, k41, k42, k43, \
                   k44, k45, k46, k47, k48, k49 \
) LAYOUT( \
    k00,   k01,   k02,   k03,   k04,   KC_NO,                             KC_NO, k05,   k06,   k07,   k08,   k09, \
    k10,   k11,   k12,   k13,   k14,   k15,   KC_NO,               KC_NO, k16,   k17,   k18,   k19,   k20,   k21, \
    k22,   k23,   k24,   k25,   k26,   k27,   KC_NO,               KC_NO, k28,   k29,   k30,   k31,   k32,   k33, \
    KC_NO, k34,   k35,   k36,   k37,   k38,   KC_NO, KC_NO, KC_NO, KC_NO, k39,   k40,   k41,   k42,   k43,   KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO,        k44,   k45,   k46,   k47,   k48,   k49,          KC_NO, KC_NO, KC_NO, KC_NO \
)

#define LAYER(layer, \
    k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, \
    k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, \
         k34, k35, k36, k37, k38, k39, k40, k41, k42, k43, \
                   k44, k45, k46, k47, k48, k49 \
) \
    [layer] = LAYOUT_ulrikdem( \
        k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
        k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, \
        k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, \
             k34, k35, k36, k37, k38, k39, k40, k41, k42, k43, \
                       k44, k45, k46, k47, k48, k49 \
    ), \
    [layer + MIR] = LAYOUT_ulrikdem( \
        M(k09), M(k08), M(k07), M(k06), M(k05),                 M(k04), M(k03), M(k02), M(k01), M(k00), \
        M(k21), M(k20), M(k19), M(k18), M(k17), M(k16), M(k15), M(k14), M(k13), M(k12), M(k11), M(k10), \
        M(k33), M(k32), M(k31), M(k30), M(k29), M(k28), M(k27), M(k26), M(k25), M(k24), M(k23), M(k22), \
                M(k43), M(k42), M(k41), M(k40), M(k39), M(k38), M(k37), M(k36), M(k35), M(k34), \
                                M(k49), M(k48), M(k47), M(k46), M(k45), M(k44) \
    )

#undef M
#define M(kc) ( \
    MIRROR_KEY(kc, KC_LEFT, KC_RGHT) \
    MIRROR_KEY(kc, KC_HOME, KC_END) \
    MIRROR_KEY(kc, KC_MS_L, KC_MS_R) \
    MIRROR_KEY(kc, KC_WH_L, KC_WH_R) \
    REPLACE_LAYER(kc, NUM, NAV) REPLACE_LAYER(kc, NAV, NUM) \
    (kc) \
)

#define MIRROR_KEY(kc, left, right) (uint16_t)(kc) == (left) ? (right) : (uint16_t)(kc) == (right) ? (left) :

#define REPLACE_LAYER(kc, a, b) IN_RANGE(kc, QK_LAYER_TAP) && GET_LT_LAYER(kc) == (a) ? LT(b, (kc) & 0xFF) :

#define IN_RANGE(kc, range) ((uint16_t)(kc) >= range && (uint16_t)(kc) <= range##_MAX)

#define GET_LT_LAYER(kc) (((kc) >> 8) & 0xF)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYER(BASE,
        KC_GRV,  KC_EXLM, KC_LPRN, KC_LBRC, KC_LCBR,                   KC_RCBR, KC_RBRC, KC_RPRN, KC_EQL,  KC_BSLS,
        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
        LT_MINS, MT_A,    MT_R,    MT_S,    MT_T,    KC_G,    KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    LT_QUOT,
                 KC_Z,    MT_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, MT_DOT,  KC_SLSH,
                                   LT_ESC,  LT_TAB,  KC_DEL,  KC_BSPC, LT_SPC,  LT_ENT
    ),

    LAYER(SFT,
        _______, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_AMPR, KC_ASTR, KC_CIRC, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______
    ),

    LAYER(NUM,
        _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
        _______, KC_F12,  KC_F9,   KC_F8,   KC_F7,   KC_PAUS, TG(KP),  KC_7,    KC_8,    KC_9,    _______, _______,
        _______, MT_F11,  MT_F6,   MT_F5,   MT_F4,   KC_SLCK, KC_DOT,  MT_4,    MT_5,    MT_6,    MT_0,    _______,
                 KC_F10,  MT_F3,   KC_F2,   KC_F1,   KC_PSCR, KC_COMM, KC_1,    KC_2,    MT_3,    _______,
                                   _______, KC_TAB,  _______, _______, _______, KC_ENT
    ),

    LAYER(KP,
        _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        LT_PMNS, _______, _______, _______, _______, _______, KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_P0,   _______,
                 _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PSLS,
                                   _______, _______, _______, _______, _______, KC_PENT
    ),

    LAYER(KP_SFT,
        _______, _______, _______, _______, _______,                   _______, KC_PAST, _______, KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        LT_UNDS, _______, _______, _______, _______, _______, KC_GT,   _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUES,
                                   _______, _______, _______, _______, _______, _______
    ),

    LAYER(NAV,
        _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
        _______, DM_REC1, DM_PLY1, XXXXXXX, LOCK,    RESET,   KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        OSL_MIR, OSM_GUI, OSM_ALT, OSM_SFT, OSM_CTL, XXXXXXX, KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, OSL_MIR,
                 XXXXXXX, OSM_ALG, ID_CAPS, TG(MOU), XXXXXXX, KC_MUTE, KC_INS,  KC_CAPS, KC_APP,  XXXXXXX,
                                   KC_ESC,  _______, _______, _______, KC_SPC,  _______
    ),

    LAYER(MOU,
        _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
                 _______, _______, _______, _______, _______, _______, KC_BTN4, KC_BTN5, _______, _______,
                                   _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, NUM))
        state &= ~(1UL << KP);
    if (IS_LAYER_OFF_STATE(state, NAV))
        state &= ~(1UL << MOU);

    state = update_tri_layer_state(state, KP, SFT, KP_SFT);

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
    if ((IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_MOD_TAP)) && record->tap.count)
        keycode &= 0xFF;
    bool pressed = record->event.pressed;
    uint8_t shift = get_mods() & MOD_MASK_SHIFT;

    static bool identifier_caps = false;
    bool is_identifier = (
        (keycode >= KC_A && keycode <= KC_Z)
        || (keycode >= KC_1 && keycode <= KC_0 && !shift)
        || (keycode == KC_MINS && shift) || keycode == KC_UNDS
        || keycode == KC_BSPC
        || !(IN_RANGE(keycode, QK_BASIC) || IN_RANGE(keycode, QK_MODS))
    ) && !(get_mods() & MOD_MASK_CAG);
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
    past_override = ko_make_basic(MOD_MASK_SHIFT, KC_PAST, KC_PAST),
    ppls_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PPLS),
    **key_overrides = (const key_override_t *[]){&past_override, &ppls_override, NULL};
