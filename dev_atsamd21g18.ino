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
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    Serial.println("ATSAMD21G18 F/W Development");
    Serial.println("PCB: Arduino M0");
    Serial.println("Clock: 48MHz");
    Serial.println("ROM: 256KB");
    Serial.println("RAM: 32KB");
    _led_blink();
    delay(500);
}