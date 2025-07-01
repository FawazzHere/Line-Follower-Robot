// IR sensor pins
const int leftSensor = 2;
const int rightSensor = 3;

// Motor pins
const int motorLeft1 = 4;
const int motorLeft2 = 5;
const int motorRight1 = 6;
const int motorRight2 = 7;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" | Right: ");
  Serial.println(rightValue);

  // Both sensors on black line — move forward
  if (leftValue == LOW && rightValue == LOW) {
    forward();
  }
  // Left sensor off the line — turn right
  else if (leftValue == HIGH && rightValue == LOW) {
    turnRight();
  }
  // Right sensor off the line — turn left
  else if (leftValue == LOW && rightValue == HIGH) {
    turnLeft();
  }
  // Both sensors off the line — stop
  else {
    stopMotors();
  }
}

void forward() {
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void turnLeft() {
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, HIGH);
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void turnRight() {
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, HIGH);
}

void stopMotors() {
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, LOW);
}
