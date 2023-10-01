# Digital-Measurer

### Digital Measurer firmware Code Description - VL53L0X Distance Display on OLED

#### Purpose:
The purpose of this Arduino code is to read distance values from the VL53L0X Time-of-Flight sensor and display them on a 128x64 OLED screen. The displayed values represent the distance in centimeters.

#### Components Used:
1. **VL53L0X Sensor:**
   - The code uses the `Adafruit_VL53L0X` library to interface with the VL53L0X Time-of-Flight sensor.

2. **OLED Display:**
   - The code utilizes the `Adafruit_SSD1306` library to communicate with a 128x64 OLED display.

#### Setup:
- The Arduino sketch initializes serial communication for debugging purposes.
- The OLED display and VL53L0X sensor are initialized in the `setup()` function.

#### Main Loop:
1. **Read Distance:**
   - The `loop()` function continuously reads distance values from the VL53L0X sensor in millimeters.

2. **Convert to Centimeters:**
   - The distance value is converted from millimeters to centimeters by dividing it by 10.

3. **Display on OLED:**
   - The OLED screen is cleared, and the distance in centimeters is displayed at the center of the screen.
   - The text size for the distance is set to 3, making it larger, while the "cm" text is set to size 2.
   - The x-position of the text is dynamically calculated to ensure it is centered on the display.
   - The OLED display is updated, and a delay is introduced to control the refresh rate.

#### Customization:
- The code allows for customization of text sizes, positioning, and delay based on user preferences.
- Users can modify the font size and coordinates to achieve the desired visual appearance on the OLED display.

#### Notes:
- Ensure that the necessary libraries (`Adafruit_VL53L0X` and `Adafruit_SSD1306`) are installed using the Arduino Library Manager.
- The code assumes a millimeter-to-centimeter conversion by dividing by 10.
- Adjustments to text size, positioning, and delay can be made for personalized display preferences.
