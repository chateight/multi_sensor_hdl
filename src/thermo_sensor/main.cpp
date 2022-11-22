#include "module.h"
#include <Wire.h>
#include "Adafruit_MLX90614.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int setup_thermo() {
    M5.begin();
    M5.Power.begin();
    Wire.begin();
    Serial.begin(115200);

    M5.Lcd.setRotation(3);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(3);
    M5.Lcd.clear(BLACK);
    M5.Lcd.setCursor(0, 40);

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

  /*
    uint16_t result;
    float temperature;
    Wire.beginTransmission(0x5A);  // Send Initial Signal and I2C Bus Address
    Wire.write(0x07);  // Send data only once and add one address automatically.
    Wire.endTransmission(false);  // Stop signal
    Wire.requestFrom(
        0x5A,
        2);  // Get 2 consecutive data from 0x5A, and the data is stored only.
    result = Wire.read();        // Receive DATA
    result |= Wire.read() << 8;  // Receive DATA

    temperature = result * 0.02 - 273.15;
*/
    M5.Lcd.fillRect(0, 40, 120, 100, BLACK);
    M5.Lcd.setCursor(20, 100);

    M5.Lcd.print(mlx.readObjectTempC());
    M5.Lcd.print(" degree");

    read_batt();
    delay(500);
    M5.Lcd.clear(BLACK);
}

