#include "test.h"

//#define TEST_MODE // un-comment this test all output pins
//#define DEBUG_MODE // un-comment this to see serial data

const int left_ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int right_ledPins[] = {10, 11, 12, 13, A0, A1, A2, A3};

const int lnumLeds = sizeof(left_ledPins) / sizeof(left_ledPins[0]);
const int rnumLeds = sizeof(right_ledPins) / sizeof(right_ledPins[0]);

int DELAY = 0;

void setup() {

#ifdef DEBUG_MODE
  Serial.begin(9600);
  Serial.println("Debug mode enabled.");
#endif

  setupPins();
  pinMode(A5, INPUT);
}


void loop() {
  
DELAY = map(analogRead(A5), 120, 1023, 0, 500);

#ifdef DEBUG_MODE
  Serial.println(analogRead(A5));
  Serial.println(DELAY);
#endif


#ifdef TEST_MODE
  testPins();
#else
  KITT();
#endif

}

void KITT() {
  for (int i = lnumLeds - 1; i >= 0; i--) {
    digitalWrite(left_ledPins[i], HIGH);
    digitalWrite(right_ledPins[lnumLeds - 1 - i], HIGH);
    delay(DELAY);
  }

  delay(200);

  for (int i = lnumLeds - 1; i >= 0; i--) {
    digitalWrite(left_ledPins[i], LOW);
    digitalWrite(right_ledPins[lnumLeds - 1 - i], LOW);
    delay(DELAY);
  }


  for (int i = 0; i < rnumLeds; i++) {
    digitalWrite(left_ledPins[i], HIGH);
    digitalWrite(right_ledPins[rnumLeds - 1 - i], HIGH);
    delay(DELAY);
  }

  delay(200);
  for (int i = 0; i < rnumLeds; i++) {
    digitalWrite(left_ledPins[i], LOW);
    digitalWrite(right_ledPins[rnumLeds - 1 - i], LOW);
    delay(DELAY);
  }
  delay(500);
}
