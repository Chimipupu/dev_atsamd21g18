/**
 * @file dev_atsamd21g18.ino
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief ATSAMD21G18のF/W開発 Arduinoファイル
 * @version 0.1
 * @date 2026-05-1
 * @copyright Copyright (c) 2026 Chimipupu All Rights Reserved.
 */

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

// ---------------------------------------------------------
static void _led_blink(void);
static void _iPrintf(const char *p_fmt, ...);
// ---------------------------------------------------------
// [Static関数]

static void _led_blink(void)
{
    static uint8_t led_val = 0;
    led_val = !led_val;
    digitalWrite(LED_BUILTIN, led_val);
}

static void _iPrintf(const char *p_fmt, ...)
{
    char buf[128];
    va_list args;
    
    va_start(args, p_fmt);
    vsnprintf(buf, sizeof(buf), p_fmt, args);
    va_end(args);
    
    SerialUSB.print(buf);
}
// ---------------------------------------------------------
void setup()
{
    // GPIO初期化
    pinMode(LED_BUILTIN, OUTPUT);

    // シリアル/UART初期化
    SerialUSB.begin(9600);
    while(!SerialUSB){
        ;
    }
    _iPrintf("ATSAMD21G18 F/W Development\r\n");
    _iPrintf("PCB: Arduino M0\r\n");
    _iPrintf("Clock: 48MHz\r\n");
    _iPrintf("ROM: 256KB\r\n");
    _iPrintf("RAM: 32KB\r\n");

    // アプリ初期化
    // NOP
}

void loop()
{
    static uint32_t s_val = 0;
    _iPrintf("printf() Test: val = %d\r\n", s_val);
    s_val++;

    _led_blink();

    delay(500);
}