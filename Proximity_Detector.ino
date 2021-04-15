#include <SPI.h>
#include <Wire.h>
#include <Adafruit_CircuitPlayground.h>

// Click the left button to start the sensor

void setup() {
  //while (!Serial);
  Serial.begin(115200);
  Serial.println("Circuitplayground color sensor test");
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(200);
}

uint32_t detectColor(void) {
  uint16_t red, green, blue; // initialized red, green, blue variables with 16 bit storage
  
  CircuitPlayground.setPixelColor(1, 255, 0, 0);  
  delay(1);
  red = CircuitPlayground.lightSensor();
  delay(20);

  CircuitPlayground.setPixelColor(1, 0, 255, 0);  
  delay(1);
  green = CircuitPlayground.lightSensor();
  delay(20);

  CircuitPlayground.setPixelColor(1, 0, 0, 255);  
  delay(1);
  blue = CircuitPlayground.lightSensor();
  delay(20);

  // normalize the colors
  Serial.print("Raw Red: "); Serial.print(red);
  Serial.print("\t Raw Green: "); Serial.print(green);
  Serial.print("\t Raw Blue: "); Serial.println(blue);
  red /= 4;
  green /= 4;
  blue /= 4;
  
  // doesn't allow value to exceed 255 for neopixel color
  red = min(255, red);
  green = min(255, green);
  blue = min(255, blue);

  Serial.print("Red: "); Serial.print(red);
  Serial.print("\tGreen: "); Serial.print(green);
  Serial.print("\tBlue: "); Serial.println(blue);
   
  uint32_t c = red;
  Serial.print("c_red: "); Serial.println(c);
  c <<= 8; // appends 8 bits (c=c+8)
  Serial.print("c:"); Serial.println(c); 

  c |= green; //
  Serial.print("c_red_green: "); Serial.println(c); 
  c <<= 8; //appends 8 bits 
  c |= blue;
  Serial.print("c_red_green_blue: "); Serial.println(c);

  return c;// c contains color ocnfiguration for rbg (32 bits)
}

uint32_t color = 0;
void loop() {
  if (CircuitPlayground.leftButton()) {
     color = detectColor(); 
     Serial.print(color);
  } else {
    CircuitPlayground.setPixelColor(1, 0);
    CircuitPlayground.setPixelColor(7, color);
  }
}
