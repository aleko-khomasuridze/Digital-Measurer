/*
  Arduino code for VL53L0X distance sensor
  displaying distance in cm on a 128x64 OLED.
  Author: Aleko Khomasuridze
*/


#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET    -1
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  // Initialize the OLED display
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);

  // Initialize the VL53L0X sensor
  if(!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    for(;;);
  }
}

void loop() {
  // Read the distance value from the VL53L0X sensor
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  int distance = measure.RangeMilliMeter;

  // Convert distance from millimeters to centimeters
  int distance_cm = distance / 10;

  // Display the distance in centimeters on the OLED screen
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);

  // Calculate the position to center the text
  int xPos = (display.width() - (distance_cm * 12)) / 2; // Adjust multiplier based on font width

  display.setCursor(xPos, 20);
  display.print(distance_cm);

  // Display "cm" in a smaller font
  display.setTextSize(2);
  display.setCursor(xPos + (distance_cm * 12), 30); // Adjust spacing based on font width
  display.print("cm");

  display.display();

  delay(500); // You can adjust the delay based on your preference
}
