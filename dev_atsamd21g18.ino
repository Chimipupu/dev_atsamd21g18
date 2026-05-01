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

static void _led_blink()
{
    static uint8_t led_val = 0;
    led_val = !led_val;
    digitalWrite(LED_BUILTIN, led_val);
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    SerialUSB.begin(9600);
    while(!SerialUSB){
        ;
    }
}

void loop()
{
    SerialUSB.print("ATSAMD21G18 F/W Development\r\n");
    SerialUSB.print("PCB: Arduino M0\r\n");
    SerialUSB.print("Clock: 48MHz\r\n");
    SerialUSB.print("ROM: 256KB\r\n");
    SerialUSB.print("RAM: 32KBv");
    _led_blink();
    delay(500);
}