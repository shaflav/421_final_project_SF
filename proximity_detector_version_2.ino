#include <Adafruit_CircuitPlayground.h>

int value;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
}

void loop() {

  value = CircuitPlayground.lightSensor();
  Serial.print("Raw:");
  Serial.println(value);
  value = map(value, 0,255,0,255);
  // start timer if value decreases by 50%
  if (value <= 10) {
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    delay(2000);
  }
    else{
      CircuitPlayground.clearPixels();
    }


//    // scale range to Lux units
//    value = map(value,0,1023,0,1500);
//    Serial.print("Lux:");
//    Serial.println(value);

  // light up LEDs
  //  for (int i = 0; i<10; i++) {
  //  CircuitPlayground.setPixelColor(i,255,255,255);
  //  }



  delay(100);
}
