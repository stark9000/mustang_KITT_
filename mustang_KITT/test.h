void leftSideSetup() {//D2 to D10
  for (int a = 2; a < 13; a++) {
    pinMode(a, OUTPUT);
  }
  for (int a = 2; a < 13; a++) {
    digitalWrite(a, LOW);
  }
}

void rightSideSetup() {//D11 to D13 and A0 to A3
  for (int a = 10; a < 14; a++) {
    pinMode(a, OUTPUT);
  }

  for (int a = 14; a < 18; a++) {
    pinMode(a, OUTPUT);
  }

  for (int a = 14; a < 18; a++) {
    digitalWrite(a, LOW);
  }

}

void setupPins() {
  leftSideSetup();
  rightSideSetup();
}

void leftSideTest(bool X) {
  for (int a = 2; a < 10; a++) {
    digitalWrite(a, X);
  }
}

void righSideTest(bool X) {
  for (int a = 10; a < 14; a++) {
    digitalWrite(a, X);
  }

  for (int a = 14; a < 18; a++) {
    digitalWrite(a, X);
  }
}

void testPins() {
  leftSideTest(HIGH);
  righSideTest(LOW);
  delay(300);
  leftSideTest(LOW);
  righSideTest(HIGH);
  delay(300);
}
