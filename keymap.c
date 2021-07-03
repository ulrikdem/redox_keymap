#include QMK_KEYBOARD_H

enum layer {
    BASE,
    NUM,
    KP,
    SYM,
    NAV,
    MOU,
    GAM,
    GNUM,
};

enum custom_keycode {
    LOCK = SAFE_RANGE,
};

#define LT_ESC LT(NUM, KC_ESC)
#define LT_TAB LT(SYM, KC_TAB)
#define LT_DEL LT(NAV, KC_DEL)
#define LT_BSPC LT(NAV, KC_BSPC)
#define LT_SPC LT(SYM, KC_SPC)
#define LT_ENT LT(NUM, KC_ENT)
#define LT_GESC LT(GNUM, KC_ESC)

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

#define MT_F5 LALT_T(KC_F5)
#define MT_F6 LGUI_T(KC_F6)
#define MT_F7 LSFT_T(KC_F7)
#define MT_F8 LCTL_T(KC_F8)
#define MT_4 RCTL_T(KC_4)
#define MT_5 RSFT_T(KC_5)
#define MT_6 RGUI_T(KC_6)
#define MT_0 LALT_T(KC_0)

#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                      KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   LT_ESC,  LT_TAB,  LT_DEL,  LT_BSPC, LT_SPC,  LT_ENT
    ),

    [NUM] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR,                   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
        MT_F5,   MT_F6,   MT_F7,   MT_F8,   KC_SLCK,                   TG(KP),  MT_4,    MT_5,    MT_6,    MT_0,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS,                   XXXXXXX, KC_1,    KC_2,    KC_3,    OSM_GUI,
                                   KC_ESC,  _______, _______, _______, _______, KC_ENT
    ),

    [KP] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                   KC_PAST, KC_P7,   KC_P8,   KC_P9,   KC_PDOT,
        _______, _______, _______, _______, KC_NLCK,                   KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_P0,
        _______, _______, _______, _______, _______,                   KC_PPLS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS,
                                   _______, _______, _______, _______, _______, KC_PENT
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_HASH, KC_AT,   KC_LBRC, KC_RBRC, KC_CIRC,                   KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR,
        MT_BSLS, MT_UNDS, MT_LCBR, MT_RCBR, KC_ASTR,                   KC_QUES, MT_LPRN, MT_RPRN, MT_MINS, MT_COLN,
        KC_RALT, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,                    KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_RALT,
                                   _______, KC_TAB,  _______, _______, KC_SPC,  _______
    ),

    [NAV] = LAYOUT_split_3x5_3(
        DM_REC1, DM_PLY1, TG(GAM), XXXXXXX, XXXXXXX,                   KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP,
        OSM_ALT, OSM_GUI, OSM_SFT, OSM_CTL, XXXXXXX,                   KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        RESET,   XXXXXXX, LOCK,    TG(MOU), XXXXXXX,                   KC_MUTE, KC_INS,  KC_CAPS, KC_APP,  RESET,
                                   _______, _______, KC_DEL,  KC_BSPC, _______, _______
    ),

    [MOU] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                   _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,
        _______, _______, _______, _______, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
        _______, _______, _______, _______, _______,                   _______, KC_BTN4, KC_BTN5, _______, _______,
                                   _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2
    ),

    [GAM] = LAYOUT_split_3x5_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PGUP,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                      KC_MUTE, KC_BTN1, KC_BTN3, KC_BTN2, DM_PLY1,
                                   LT_GESC, KC_SPC,  LOCK,    KC_BSPC, TG(GAM), KC_ENT
    ),

    [GNUM] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, _______, _______, _______, KC_F12,
                                   _______, _______, _______, _______, _______, _______
    ),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX;
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

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_OFF_STATE(state, NUM))
        state &= ~(1UL << KP);
    if (IS_LAYER_OFF_STATE(state, NAV))
        state &= ~(1UL << MOU);
    if (IS_LAYER_OFF_STATE(state, GAM))
        state &= ~(1UL << GNUM);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    uint8_t tap = record->tap.count;
    bool layer_tap = keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX;

    static bool lock_next = false;
    static layer_state_t locked_layers = 0;
    if (lock_next && !pressed) {
        lock_next = false;
        if (layer_tap && !tap)
            locked_layers |= 1UL << ((keycode >> 8) & 0xF);
        return false;
    } else if (keycode == LOCK) {
        if (!pressed)
            lock_next = true;
        return false;
    } else if (locked_layers && (layer_tap && tap ? keycode & 0xFF : keycode) == KC_ESC && pressed) {
        layer_off(get_highest_layer(locked_layers));
        locked_layers &= layer_state;
        return false;
    }

    return true;
}