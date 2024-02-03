#include "color.h"

#ifdef RGB_MATRIX_ENABLE

/* Number Row */
#define LED_ESC      13
#define LED_1        12
#define LED_2        11
#define LED_3        10
#define LED_4        9
#define LED_5        8
#define LED_6        7
#define LED_7        6
#define LED_8        5
#define LED_9        4
#define LED_0        3
#define LED_MINUS    2
#define LED_EQUAL    1
#define LED_BSPACE   0

/* qwer Row */
#define LED_TAB      27
#define LED_Q        26
#define LED_W        25
#define LED_E        24
#define LED_R        23
#define LED_T        22
#define LED_Y        21
#define LED_U        20
#define LED_I        19
#define LED_O        18
#define LED_P        17
#define LED_LBRACKET 16
#define LED_RBRACKET 15
#define LED_BSLASH   14

/* asdf Row */
#define LED_CAPS     40
#define LED_A        39
#define LED_S        38
#define LED_D        37
#define LED_F        36
#define LED_G        35
#define LED_H        34
#define LED_J        33
#define LED_K        32
#define LED_L        31
#define LED_SCOLON   30
#define LED_QUOTE    29
#define LED_ENTER    28

/* zxcv Row */
#define LED_LSHIFT   52
#define LED_Z        51
#define LED_X        50
#define LED_C        49
#define LED_V        48
#define LED_B        47
#define LED_N        46
#define LED_M        45
#define LED_COMMA    44
#define LED_DOT      43
#define LED_SLASH    42
#define LED_RSHIFT   41

/* Last Row */
#define LED_LCTRL    60
#define LED_LGUI     59
#define LED_LALT     58
#define LED_SPACE    57
#define LED_RALT     56
#define LED_RGUI     55
#define LED_RCTRL    54
#define LED_FN       53


const uint8_t LED_LIST_NUMROW_1[] = { LED_1, LED_2,  LED_3,  LED_4  };
const uint8_t LED_LIST_NUMROW_2[] = { LED_5, LED_6,  LED_7,  LED_8  };
const uint8_t LED_LIST_NUMROW_3[] = { LED_9, LED_0, LED_MINUS, LED_EQUAL };
const uint8_t LED_LIST_NUMROW[] = { LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_0 };

    

// Layer Sequence
#define hsv_LAYER_BL       (HSV){  20, 255, 255 }
#define hsv_LAYER_GL       (HSV){ 172, 255, 255 }
#define hsv_IDR_CAPS       (HSV){   0, 255, 255 }
    
// Layer Order
#define hsv_CurLAYER       (HSV){ 255, 255, 255 }

    
#endif
