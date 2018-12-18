#include <Servo.h>

Servo ser1;
Servo ser2;
Servo ser3;
Servo ser4;

int pos = 0;

int piezo1 = A0;
int piezo2 = A1;
int piezo3 = A2;
int piezo4 = A3;

int val1;
int val2;
int val3;
int val4;

int prevTime = 0;

int bufferTime1 = 0;
int bufferTime2 = 0;
int bufferTime3 = 0;
int bufferTime4 = 0;

int BUFFER_MAX = 1000; //get timeings right
int HALF_BUFFER = BUFFER_MAX / 2;

void setup() {
  prevTime = millis();
  Serial.begin(9600);
  ser1.attach(11);
  ser2.attach(10);
  ser3.attach(6);
  ser4.attach(5);

  pinMode(piezo1, INPUT);
  pinMode(piezo2, INPUT);
  pinMode(piezo3, INPUT);
  pinMode(piezo4, INPUT);

}

void loop() {



  int currTime = millis();
  int dt = currTime - prevTime;
  prevTime = currTime;

  if (bufferTime1 > BUFFER_MAX) {
    bufferTime1 += dt;
    val1 = analogRead(piezo1);

    if (bufferTime1 < HALF_BUFFER) {
      int Pos = bufferTime1 / HALF_BUFFER * 180;
      ser1.write(Pos);
    }
    else {
      int Pos = (1 - (bufferTime1 - HALF_BUFFER) / HALF_BUFFER) * 180;
      ser1.write(Pos);
    }
  }  else if (val1 < 0) {
    bufferTime1 = 0;
  }

  if (bufferTime2 > BUFFER_MAX) {
    bufferTime2 += dt;
    val2 = analogRead(piezo2);

    if (bufferTime2 < HALF_BUFFER) {
      int Pos = bufferTime2 / HALF_BUFFER * 180;
      ser2.write(Pos);
    }
    else {
      int Pos = (1 - (bufferTime2 - HALF_BUFFER) / HALF_BUFFER) * 180;
      ser2.write(Pos);
    }
  }  else if (val2 < 0) {
    bufferTime2 = 0;
  }

  if (bufferTime3 > BUFFER_MAX) {
    bufferTime3 += dt;
    val3 = analogRead(piezo3);

    if (bufferTime3 < HALF_BUFFER) {
      int Pos = bufferTime3 / HALF_BUFFER * 180;
      ser3.write(Pos);
    }
    else {
      int Pos = (1 - (bufferTime3 - HALF_BUFFER) / HALF_BUFFER) * 180;
      ser3.write(Pos);
    }
  }  else if (val3 < 0) {
    bufferTime3 = 0;
  }

  if (bufferTime4 > BUFFER_MAX) {
    bufferTime4 += dt;
    val4 = analogRead(piezo4);

    if (bufferTime4 < HALF_BUFFER) {
      int Pos = bufferTime4 / HALF_BUFFER * 180;
      ser4.write(Pos);
    }
    else {
      int Pos = (1 - (bufferTime4 - HALF_BUFFER) / HALF_BUFFER) * 180;
      ser4.write(Pos);
    }
  } else if (val4 < 0) {
    bufferTime4 = 0;
  }
}
