#include QMK_KEYBOARD_H

enum layers {
    BASE,
    NUM,
    KP,
    SYM,
    NAV,
    MOU,
    GAM,
    GNUM,
    MIRROR,
};

enum custom_keycodes {
    ID_CAPS = SAFE_RANGE,
    LOCK,
};

#define LT_ESC LT(NUM, KC_ESC)
#define LT_TAB LT(SYM, KC_TAB)
#define LT_DEL LT(NAV, KC_DEL)
#define LT_BSPC LT(NAV, KC_BSPC)
#define LT_SPC LT(SYM, KC_SPC)
#define LT_ENT LT(NUM, KC_ENT)
#define LT_GESC LT(GNUM, KC_ESC)
#define LT_GENT LT(GNUM, KC_ENT)

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
#define MT_UNDS MT_SHIFTED(KC_LGUI, KC_UNDS)
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

#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)

#define LAYOUT_split_3x6_3( \
    k00, k01, k02, k03, k04, k05,           k06, k07, k08, k09, k10, k11, \
    k12, k13, k14, k15, k16, k17,           k18, k19, k20, k21, k22, k23, \
    k24, k25, k26, k27, k28, k29,           k30, k31, k32, k33, k34, k35, \
                        k36, k37, k38, k39, k40, k41 \
) \
    LAYOUT( \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        k00,   k01,   k02,   k03,   k04,   k05,   KC_NO,               KC_NO, k06,   k07,   k08,   k09,   k10,   k11, \
        k12,   k13,   k14,   k15,   k16,   k17,   KC_NO,               KC_NO, k18,   k19,   k20,   k21,   k22,   k23, \
        k24,   k25,   k26,   k27,   k28,   k29,   KC_NO, KC_NO, KC_NO, KC_NO, k30,   k31,   k32,   k33,   k34,   k35, \
        KC_NO, KC_NO, KC_NO, KC_NO,        k36,   k37,   k38,   k39,   k40,   k41,          KC_NO, KC_NO, KC_NO, KC_NO \
    )

#define LAYER(layer, \
    k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29, \
                   k30, k31, k32, k33, k34, k35 \
) \
    [layer] = LAYOUT_split_3x6_3( \
        KC_NO,       k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, KC_NO, \
        OSL(MIRROR), k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, OSL(MIRROR), \
        KC_NO,       k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29, KC_NO, \
                                    k30, k31, k32, k33, k34, k35 \
    ), \
    [layer + MIRROR] = LAYOUT_split_3x6_3( \
        KC_NO,      M(k09), M(k08), M(k07), M(k06), M(k05),                 M(k04), M(k03), M(k02), M(k01), M(k00), KC_NO, \
        MO(MIRROR), M(k19), M(k18), M(k17), M(k16), M(k15),                 M(k14), M(k13), M(k12), M(k11), M(k10), MO(MIRROR), \
        KC_NO,      M(k29), M(k28), M(k27), M(k26), M(k25),                 M(k24), M(k23), M(k22), M(k21), M(k20), KC_NO, \
                                            M(k35), M(k34), M(k33), M(k32), M(k31), M(k30) \
    )

#undef M
#define M(kc) \
    ( \
        MIRROR_KEY(kc, KC_LCBR, KC_RCBR) MIRROR_KEY(kc, KC_LBRC, KC_RBRC) \
        MIRROR_KEY(kc, KC_LPRN, KC_RPRN) MIRROR_KEY(kc, KC_LT, KC_GT) \
        MIRROR_KEY(kc, KC_LEFT, KC_RGHT) MIRROR_KEY(kc, KC_HOME, KC_END) \
        MIRROR_KEY(kc, KC_MS_L, KC_MS_R) MIRROR_KEY(kc, KC_WH_L, KC_WH_R) \
        (kc) \
    )

#define MIRROR_KEY(kc, left, right) REPLACE_KEY(kc, left, right) REPLACE_KEY(kc, right, left)
#define REPLACE_KEY(kc, left, right) \
    ( \
        IN_RANGE(kc, QK_LAYER_TAP) || IN_RANGE(kc, QK_MOD_TAP) ? (kc) & 0xFF : \
        IN_RANGE(kc, QK_FUNCTION) ? LSFT((kc) & 0xFF) : \
        (kc) \
    ) == (left) ? ((kc) & 0xFF00) | ((right) & 0xFF) :

#define IN_RANGE(kc, range) ((uint16_t)(kc) >= range && (uint16_t)(kc) <= range##_MAX)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYER(BASE,
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                      KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   LT_ESC,  LT_TAB,  LT_DEL,  LT_BSPC, LT_SPC,  LT_ENT
    ),

    LAYER(NUM,
        KC_F12,  KC_F9,   KC_F8,   KC_F7,   KC_PSCR,                   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
        MT_F11,  MT_F6,   MT_F5,   MT_F4,   KC_SLCK,                   TG(KP),  MT_4,    MT_5,    MT_6,    MT_0,
        KC_F10,  KC_F3,   KC_F2,   KC_F1,   KC_PAUS,                   XXXXXXX, KC_1,    KC_2,    KC_3,    OSM_GUI,
                                   KC_ESC,  _______, _______, _______, _______, KC_ENT
    ),

    LAYER(KP,
        _______, _______, _______, _______, _______,                   KC_PAST, KC_P7,   KC_P8,   KC_P9,   KC_PDOT,
        _______, _______, _______, _______, KC_NLCK,                   KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_P0,
        _______, _______, _______, _______, _______,                   KC_PPLS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS,
                                   _______, _______, _______, _______, _______, KC_PENT
    ),

    LAYER(SYM,
        KC_HASH, KC_AT,   KC_LBRC, KC_RBRC, KC_CIRC,                   KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR,
        MT_BSLS, MT_UNDS, MT_LCBR, MT_RCBR, KC_ASTR,                   KC_QUES, MT_LPRN, MT_RPRN, MT_MINS, MT_COLN,
        KC_RALT, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,                    KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_RALT,
                                   _______, KC_TAB,  _______, _______, KC_SPC,  _______
    ),

    LAYER(NAV,
        DM_REC1, DM_PLY1, TG(GAM), XXXXXXX, RESET,                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU,
        OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, XXXXXXX,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
        XXXXXXX, LOCK,    ID_CAPS, TG(MOU), XXXXXXX,                   XXXXXXX, KC_INS,  KC_CAPS, KC_APP,  KC_MUTE,
                                   _______, _______, KC_DEL,  KC_BSPC, _______, _______
    ),

    LAYER(MOU,
        _______, _______, _______, _______, _______,                   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______,
        _______, _______, _______, _______, _______,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______,
        _______, _______, _______, _______, _______,                   _______, KC_BTN4, KC_BTN5, _______, _______,
                                   _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2
    ),

    LAYER(GAM,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                      XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, KC_MUTE,
                                   LT_GESC, KC_SPC,  LOCK,    KC_BSPC, TG(GAM), LT_GENT
    ),

    LAYER(GNUM,
        DM_PLY1, KC_9,    KC_8,    KC_7,    KC_T,                      XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,
        KC_0,    KC_6,    KC_5,    KC_4,    KC_G,                      XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,
        _______, KC_3,    KC_2,    KC_1,    KC_B,                      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,
                                   KC_ESC,  _______, _______, _______, _______, KC_ENT
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, NUM))
        state &= ~(1UL << KP);
    if (IS_LAYER_OFF_STATE(state, NAV))
        state &= ~(1UL << MOU);

    bool mirror = IS_LAYER_ON_STATE(state, MIRROR);
    state &= (1UL << MIRROR) - 1;
    if (mirror)
        state |= (state | 1) << MIRROR;

    return state;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return IN_RANGE(keycode, QK_LAYER_TAP);
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
    bool pressed = record->event.pressed;
    if ((IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_MOD_TAP)) && record->tap.count)
        keycode &= 0xFF;
    else if (IN_RANGE(keycode, QK_FUNCTION) && record->tap.count)
        keycode = LSFT(keycode & 0xFF);

    static bool identifier_caps = false;
    bool is_identifier = (keycode >= KC_A && keycode <= KC_0) || keycode == KC_UNDS || keycode == KC_BSPC
        || IN_RANGE(keycode, QK_LAYER_TAP) || IN_RANGE(keycode, QK_ONE_SHOT_LAYER) || IN_RANGE(keycode, QK_MOMENTARY);
    if ((keycode == ID_CAPS || (identifier_caps && !is_identifier)) && pressed) {
        identifier_caps = !identifier_caps;
        tap_code(KC_CAPS);
    }

    static bool lock_next = false;
    static layer_state_t locked_layers = 0;
    if (lock_next && !pressed) {
        lock_next = false;
        if (IN_RANGE(keycode, QK_LAYER_TAP))
            locked_layers |= 1UL << ((keycode >> 8) & 0xF);
        return false;
    } else if (keycode == LOCK && !pressed) {
        lock_next = true;
    } else if (locked_layers && keycode == KC_ESC && pressed) {
        layer_off(get_highest_layer(locked_layers));
        locked_layers &= layer_state;
        return false;
    }

    return true;
}
