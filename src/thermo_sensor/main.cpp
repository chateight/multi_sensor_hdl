#include "module.h"
#include <Wire.h>
#include "Adafruit_MLX90614.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int setup_thermo() {
    M5.begin();
    M5.Power.begin();
    Wire.begin();

    M5.Lcd.setRotation(3);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.clear(BLACK);

    mlx.begin();
    int ret = mlx.begin();
    return ret;
}


void loop_thermo() {
    // surface temp
    Serial.print("Temperature : ");  Serial.println(mlx.readObjectTempC());
    // ambient temp
    Serial.print("Ambient : ");  Serial.println(mlx.readAmbientTempC());
    Serial.print("emmisivity : ");  Serial.println(mlx.readEmissivity());
    Serial.println();

    M5.Lcd.fillRect(0, 40, 120, 100, BLACK);
    M5.Lcd.setCursor(50, 100);

    M5.Lcd.print(mlx.readObjectTempC());
    M5.Lcd.print(" degree");

    read_batt();
    delay(500);
    M5.Lcd.clear(BLACK);
}

