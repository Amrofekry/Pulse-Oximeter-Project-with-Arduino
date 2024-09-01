#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <LiquidCrystal_I2C.h>

#define REPORTING_PERIOD_MS     1000

LiquidCrystal_I2C lcd(0x27, 16, 2);
PulseOximeter pox;

uint32_t tsLastReport = 0;
int sp = 0;
int hr = 0;

byte Heart[] = {
    B00000,
    B01010,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000,
    B00000
};

void onBeatDetected() {
    Serial.println("A heartbeat is detected.");
}

void setup() {
    Serial.begin(9600);

    lcd.init();
    lcd.backlight();
    lcd.createChar(0, Heart);

    lcd.setCursor(0, 0);
    lcd.print("TEAM 7");
    delay(2000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Presents");
    lcd.setCursor(0, 1);
    lcd.print("Pulse Oximeter");
    delay(2000);
    lcd.clear();

    if (!pox.begin()) {
        Serial.println("Pulse oximeter initialization FAILED");
        while (1); // Halt execution
    } else {
        Serial.println("Pulse oximeter initialization SUCCESS");
    }

    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
    pox.update();

    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        hr = pox.getHeartRate();
        sp = pox.getSpO2();

        lcd.setCursor(0, 0);
        lcd.print("HEART RATE: ");
        lcd.print(hr);
        lcd.write(0); // Display custom character (Heart)
        lcd.print(" ");

        lcd.setCursor(0, 1);
        lcd.print("SpO2 LEVELS: ");
        lcd.print(sp);
        lcd.print("%");

        Serial.print("HEART RATE: ");
        Serial.print(hr);
        Serial.print(" bpm, SpO2: ");
        Serial.print(sp);
        Serial.println("%");

        tsLastReport = millis();
    }
}
