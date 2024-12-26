#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

bool dispenserReady[4] = {true, true, true, true}; // Track readiness for each dispenser
String command;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  Serial.println("System Ready");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');

    if (command.startsWith("check_ready")) {
      checkDispenserStatus();
    } else if (command.startsWith("assign_order")) {
      int dispenser = command.substring(13).toInt(); // Extract dispenser number
      if (dispenser >= 1 && dispenser <= 4) {
        assignOrder(dispenser);
      } else {
        Serial.println("Error: Invalid dispenser ID");
      }
    }
  }
}

void checkDispenserStatus() {
  for (int i = 0; i < 4; i++) {
    if (dispenserReady[i]) {
      Serial.print("Dispenser ");
      Serial.print(i + 1);
      Serial.println(" is ready.");
      return; // Stop as soon as one dispenser is ready
    }
  }
  Serial.println("No dispensers are ready.");
}

void assignOrder(int dispenser) {
  if (dispenserReady[dispenser - 1]) {
    Serial.print("Order assigned to dispenser ");
    Serial.println(dispenser);
    operateDispenser(dispenser);
    dispenserReady[dispenser - 1] = false; // Mark as busy
  } else {
    Serial.print("Dispenser ");
    Serial.print(dispenser);
    Serial.println(" is busy.");
  }
}

void operateDispenser(int dispenser) {
  AF_DCMotor *motor;

  switch (dispenser) {
    case 1: motor = &motor1; break;
    case 2: motor = &motor2; break;
    case 3: motor = &motor3; break;
    case 4: motor = &motor4; break;
    default: return;
  }

  motor->run(FORWARD);
  delay(5000);
  motor->run(RELEASE);
  Serial.print("Dispenser ");
  Serial.print(dispenser);
  Serial.println(" completed order.");
  dispenserReady[dispenser - 1] = true; // Mark as ready again
}
