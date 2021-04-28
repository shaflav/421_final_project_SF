
#include <Adafruit_CircuitPlayground.h>

int value;
int songchoice;
const int ledPin =  13; // the number of the LED pin
int ledState = LOW;

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
#define REST 0

// Define note durations.  You only need to adjust the whole note
// time and other notes will be subdivided from it directly.
#define WHOLE         2200       // Length of time in milliseconds of a whole note (i.e. a full bar).
#define HALF          WHOLE/2
#define QUARTER       HALF/2
#define EIGHTH        QUARTER/2
#define EIGHTH_TRIPLE QUARTER/3
#define SIXTEENTH     EIGHTH/2
#define DOT_HALF          HALF + QUARTER
#define DOT_QUARTER       QUARTER + EIGHTH
#define DOT_EIGHTH        EIGHTH + SIXTEENTH
#define DOT_SIXTEENTH     SIXTEENTH + (SIXTEENTH/2)


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
}

void loop() {

  value = CircuitPlayground.lightSensor();
  Serial.print("Raw:");
  Serial.println(value);
  value = map(value, 0, 255, 0, 255);
  songchoice = random(0,2);
  if (value <= 10) {
    // line here would initiate solenoid (water valve)
    digitalWrite(ledPin, HIGH);
    if (songchoice == 0) {

      pinkpanther();
      pinkpanther();
    }
    
    if (songchoice == 1) {
      birthdaysong();
      //birthdaysong();
    }

    if (songchoice == 2) {
      harrypotter();
    }


    delay(500);
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
    delay(500);
    CircuitPlayground.clearPixels();
    delay(500);
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
    delay(500);
    CircuitPlayground.clearPixels();
    delay(500);
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
    delay(500);
    CircuitPlayground.clearPixels();
    delay(500);
  }
  else {
    CircuitPlayground.clearPixels();
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}


void playNote(int frequency, int duration) {
  CircuitPlayground.playTone(frequency, duration, false);
}


// plays the birthday song
void birthdaysong() {

  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_E4, QUARTER);        // Bar 1
  CircuitPlayground.setPixelColor(0, 255, 255, 255);
  playNote(NOTE_D4, QUARTER);
  playNote(NOTE_G4, QUARTER);
  CircuitPlayground.setPixelColor(1, 255, 255, 255);
  playNote(NOTE_FS4, HALF);         // Bar 2
  CircuitPlayground.setPixelColor(2, 255, 255, 255);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_E4, QUARTER);       // Bar 3
  CircuitPlayground.setPixelColor(3, 255, 255, 255);
  playNote(NOTE_D4, QUARTER);
  playNote(NOTE_A4, QUARTER);
  CircuitPlayground.setPixelColor(4, 255, 255, 255);
  playNote(NOTE_G4, HALF);          // Bar 4
  CircuitPlayground.setPixelColor(5, 255, 255, 255);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_D5, QUARTER);       // Bar 5
  CircuitPlayground.setPixelColor(6, 255, 255, 255);
  playNote(NOTE_B4, QUARTER);
  playNote(NOTE_G4, QUARTER);
  CircuitPlayground.setPixelColor(7, 255, 255, 255);
  playNote(NOTE_FS4, QUARTER);      // Bar 6
  playNote(NOTE_E4, QUARTER);
  CircuitPlayground.setPixelColor(8, 255, 255, 255);
  playNote(NOTE_C5, EIGHTH);
  playNote(NOTE_C5, EIGHTH);
  playNote(NOTE_B4, QUARTER);       // Bar 7
  CircuitPlayground.setPixelColor(9, 255, 255, 255);
  playNote(NOTE_G4, QUARTER);
  playNote(NOTE_A4, QUARTER);
  CircuitPlayground.setPixelColor(0, 255, 255, 255);
  playNote(NOTE_G4, HALF);          // Bar 8
  CircuitPlayground.clearPixels();

void pinkpanther() {
  playNote(REST, HALF);
  playNote(REST, QUARTER);
  playNote(REST, EIGHTH);
  CircuitPlayground.setPixelColor(0, 255, 255, 255);
  playNote(NOTE_DS4, EIGHTH);
  playNote(NOTE_E4, DOT_QUARTER);
  CircuitPlayground.setPixelColor(1, 255, 255, 255);
  playNote(REST, EIGHTH);
  playNote(NOTE_FS4, EIGHTH);
  CircuitPlayground.setPixelColor(2, 255, 255, 255);
  playNote(NOTE_G4, DOT_QUARTER);
  playNote(REST, EIGHTH);
  playNote(NOTE_DS4, EIGHTH);
  CircuitPlayground.setPixelColor(3, 255, 255, 255);
  playNote(NOTE_E4, DOT_EIGHTH);
  playNote(NOTE_FS4, EIGHTH);
  CircuitPlayground.setPixelColor(4, 255, 255, 255);
  playNote(NOTE_G4, DOT_EIGHTH);
  playNote(NOTE_C5, EIGHTH);
  playNote(NOTE_B4, DOT_EIGHTH);
  CircuitPlayground.setPixelColor(5, 255, 255, 255);
  playNote(NOTE_E4, EIGHTH);
  playNote(NOTE_G4, DOT_EIGHTH);
  playNote(NOTE_B4, EIGHTH);
  CircuitPlayground.setPixelColor(6, 255, 255, 255);
  playNote(NOTE_AS4, HALF);
  CircuitPlayground.setPixelColor(7, 255, 255, 255);
  playNote(NOTE_A4, SIXTEENTH);
  playNote(NOTE_G4, SIXTEENTH);
  playNote(NOTE_E4, SIXTEENTH);
  playNote(NOTE_D4, SIXTEENTH );
  CircuitPlayground.setPixelColor(8, 255, 255, 255);
  playNote(NOTE_E4, HALF);
  CircuitPlayground.setPixelColor(9, 255, 255, 255);
  playNote(REST, QUARTER);
  playNote( REST, HALF);
  CircuitPlayground.clearPixels();
}

void harrypotter() {
  playNote(REST, HALF);
  playNote(NOTE_D4, QUARTER);
  playNote(NOTE_G4, DOT_QUARTER);
  playNote(NOTE_AS4, EIGHTH);
  playNote(NOTE_A4, QUARTER);
  playNote(NOTE_G4, HALF);
  playNote(NOTE_D5, QUARTER);
  playNote(NOTE_C5, DOT_HALF);

  playNote(NOTE_A4, DOT_HALF);
  playNote(NOTE_G4, DOT_QUARTER);
  playNote(NOTE_AS4, EIGHTH);
  playNote(NOTE_A4, QUARTER);

  playNote(NOTE_F4, HALF);
  playNote(NOTE_GS4, QUARTER);
  playNote(NOTE_D4, DOT_HALF);
  playNote(NOTE_D4, QUARTER);

  playNote(NOTE_G4, DOT_QUARTER);
  playNote(NOTE_AS4, EIGHTH);
  playNote(NOTE_A4, QUARTER);
  playNote(NOTE_G4, HALF);
  playNote(NOTE_D5, QUARTER);
  playNote(NOTE_F5, HALF);
  playNote(NOTE_E5, QUARTER);
  playNote(NOTE_DS5, HALF);
  playNote(NOTE_B4, QUARTER);
  playNote(NOTE_DS5, DOT_QUARTER);
  playNote(NOTE_D5, EIGHTH);
  playNote(NOTE_CS5, QUARTER);


  playNote(NOTE_CS4, HALF);
  playNote(NOTE_DS5, HALF);
  playNote(NOTE_B4, QUARTER);
}






