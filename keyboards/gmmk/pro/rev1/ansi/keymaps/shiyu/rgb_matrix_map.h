#include "color.h"

#ifdef RGB_MATRIX_ENABLE

	/* Function Row */
    #define LED_ESC      0
    #define LED_F1       6
    #define LED_F2       12
    #define LED_F3       18
    #define LED_F4       23
    #define LED_F5       28
    #define LED_F6       34
    #define LED_F7       39
    #define LED_F8       44
    #define LED_F9       50
    #define LED_F10      56
    #define LED_F11      61
    #define LED_F12      66
    #define LED_HOME     69

    /* Number Row */
    #define LED_0        57
    #define LED_1        7
    #define LED_2        13
    #define LED_3        19
    #define LED_4        24
    #define LED_5        29
    #define LED_6        35
    #define LED_7        40
    #define LED_8        45
    #define LED_9        51

    /* QWERTY */
    #define LED_A        9
    #define LED_B        32
    #define LED_C        22
    #define LED_D        21
    #define LED_E        20
    #define LED_F        26
    #define LED_G        31
    #define LED_H        37
    #define LED_I        46
    #define LED_J        42
    #define LED_K        47
    #define LED_L        53
    #define LED_M        43
    #define LED_N        38
    #define LED_O        52
    #define LED_P        58
    #define LED_Q        8
    #define LED_R        25
    #define LED_S        15
    #define LED_T        30
    #define LED_U        41
    #define LED_V        27
    #define LED_W        14
    #define LED_X        16
    #define LED_Y        36
    #define LED_Z        10

    /* Symbols */
    #define LED_MINUS    62
    #define LED_EQUAL    78
    #define LED_RBRACKET 89
    #define LED_LBRACKET 63
    #define LED_BSLASH   93
    #define LED_SLASH    60
    #define LED_SCOLON   59
    #define LED_QUOTE    64
    #define LED_COMMA    48
    #define LED_DOT      54
    #define LED_GRAVE    1

    /* Indentation */
    #define LED_TAB      2
    #define LED_SPACE    33

    /* Line Control */
    #define LED_BSPACE   85
    #define LED_ENTER    96

    /* Indicator */
    #define LED_CAPS     3

    /* Left Modifiers */
    #define LED_LSHIFT   4
    #define LED_LCTRL    5
    #define LED_LALT     17
    #define LED_LGUI     11

    /* Right Modifiers */
    #define LED_RSHIFT   90
    #define LED_RCTRL    65
    #define LED_RALT     49
    #define LED_FN       55

    /* Arrow Keys */
    #define LED_UP       94
    #define LED_DOWN     97
    #define LED_LEFT     95
    #define LED_RIGHT    79

    /* Fn Column */
    #define LED_DEL      72
    #define LED_PGUP     75
    #define LED_PGDN     86
    #define LED_END      82

    /* Left Side Underglow */
    #define LED_LT_L01   67 //TOP
    #define LED_LT_L02   70
    #define LED_LT_L03   73
    #define LED_LT_L04   76
    #define LED_LT_L05   80
    #define LED_LT_L06   83
    #define LED_LT_L07   87
    #define LED_LT_L08   91 //BOTTOM

    /* Right Side Underglow */
    #define LED_RT_R01   68 //TOP
    #define LED_RT_R02   71
    #define LED_RT_R03   74
    #define LED_RT_R04   77
    #define LED_RT_R05   81
    #define LED_RT_R06   84
    #define LED_RT_R07   88
    #define LED_RT_R08   92 //BOTTOM


    const uint8_t LED_LIST_FCTROW_1[] = { LED_F1, LED_F2,  LED_F3,  LED_F4  };
    const uint8_t LED_LIST_FCTROW_2[] = { LED_F5, LED_F6,  LED_F7,  LED_F8  };
    const uint8_t LED_LIST_FCTROW_3[] = { LED_F9, LED_F10, LED_F11, LED_F12 };
    const uint8_t LED_LIST_NUMROW[] = { LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_0 };
    const uint8_t LED_LIST_ARROWS[] = { LED_LEFT, LED_RIGHT, LED_UP, LED_DOWN };
    const uint8_t LED_SIDE_LTLight[] = { LED_LT_L01, LED_LT_L02, LED_LT_L03, LED_LT_L04, LED_LT_L05, LED_LT_L06, LED_LT_L07, LED_LT_L08 };
    const uint8_t LED_SIDE_RTLight[] = { LED_RT_R01, LED_RT_R02, LED_RT_R03, LED_RT_R04, LED_RT_R05, LED_RT_R06, LED_RT_R07, LED_RT_R08 };

    

    // Layer Sequence
    #define hsv_LAYER_BL       (HSV){  20, 255, 255 }
    #define hsv_LAYER_GL       (HSV){ 172, 255, 255 }
    #define hsv_IDR_CAPS       (HSV){   0, 255, 255 }
    
    // Layer Order
    #define hsv_CurLAYER       (HSV){ 255, 255, 255 }

    
#endif
