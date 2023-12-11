//There are several syntax errors and typos in the provided Arduino code. Here's a corrected version:

#include <Servo.h>

Servo horizontal; // horizontal servo
Servo vertical; // vertical servo

int servoh = 180;
int servohLimitHigh = 175;
int servohLimitLow = 5;

int servov = 45;
int servovLimitHigh = 60;
int servovLimitLow = 1;

// LDR pin connections
int Idrit = A0; // LDR top left - BOTTOM LEFT <--- BDG
int Idrrt = A3; // LDR top right - BOTTOM RIGHT
int Idrid = A1; // LDR down left - TOP LEFT
int Idrrd = A3; // LDR down right - TOP RIGHT

void setup() {
  horizontal.attach(9);
  vertical.attach(10);

  horizontal.write(180);
  vertical.write(45);

  delay(2500);
}

void loop() {
  int it = analogRead(Idrit); // top left
  int rt = analogRead(Idrrt); // top right
  int Id = analogRead(Idrid); // down left
  int rd = analogRead(Idrrd); // down right

  int dtime = 10;
  int tol = 90; // dtime=diffirence time, tol-tolerance

  int avt = (it + rt) / 2; // average value top
  int avd = (Id + rd) / 2; // average value down
  int avl = (it + Id) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the difference of up and down
  int dhoriz = avl - avr; // check the difference of left and right

  if (-1 * tol > dvert || dvert > tol) {
    if (avt > avd)
      servov = ++servov;

    if (servov > servovLimitHigh)
      servov = servovLimitHigh;
    else if (avt < avd)
      servov = --servov;

    if (servov < servovLimitLow)
      servov = servovLimitLow;
  }

  vertical.write(servov);

  if (-1 * tol > dhoriz || dhoriz > tol) { // check if the difference is in the tolerance else change horizontal angle
    if (avl > avr) {
      servoh = --servoh;

      if (servoh < servohLimitLow)
        servoh = servohLimitLow;
    } else if (avl < avr) {
      servoh = ++servoh;

      if (servoh > servohLimitHigh)
        servoh = servohLimitHigh;
    }
  }

  horizontal.write(servoh);

  delay(dtime);
}


//Please note that I've corrected variable names, syntax errors, and adjusted some conditions. It's advisable to thoroughly test the code and fine-tune the parameters based on your specific setup.