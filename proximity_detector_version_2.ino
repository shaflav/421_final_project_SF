#include <Adafruit_CircuitPlayground.h>

int value;

// A few music note frequencies as defined in this tone example:
//   https://www.arduino.cc/en/Tutorial/toneMelody
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

// Define note durations.  You only need to adjust the whole note
// time and other notes will be subdivided from it directly.
#define WHOLE         2200       // Length of time in milliseconds of a whole note (i.e. a full bar).
#define HALF          WHOLE/2
#define QUARTER       HALF/2
#define EIGHTH        QUARTER/2
#define EIGHTH_TRIPLE QUARTER/3
#define SIXTEENTH     EIGHTH/2


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
    birthdaysong();
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

void playNote(int frequency, int duration, bool hold=false, bool measure=true) {
    CircuitPlayground.playTone(frequency, duration + duration/32, false);
  }


// plays the birthday song
void birthdaysong() {
  playNote(NOTE_D4, EIGHTH, true);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_E4, QUARTER);       // Bar 1
  playNote(NOTE_D4, QUARTER);
  playNote(NOTE_G4, QUARTER);
  playNote(NOTE_FS4, HALF);         // Bar 2
  playNote(NOTE_D4, EIGHTH, true);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_E4, QUARTER);       // Bar 3
  playNote(NOTE_D4, QUARTER);
  playNote(NOTE_A4, QUARTER);
  playNote(NOTE_G4, HALF);          // Bar 4
  playNote(NOTE_D4, EIGHTH, true);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_D5, QUARTER);       // Bar 5
  playNote(NOTE_B4, QUARTER);
  playNote(NOTE_G4, QUARTER);
  playNote(NOTE_FS4, QUARTER);      // Bar 6
  playNote(NOTE_E4, QUARTER);
  playNote(NOTE_C5, EIGHTH, true);
  playNote(NOTE_C5, EIGHTH);
  playNote(NOTE_B4, QUARTER);       // Bar 7
  playNote(NOTE_G4, QUARTER);
  playNote(NOTE_A4, QUARTER);
  playNote(NOTE_G4, HALF);          // Bar 8
}

