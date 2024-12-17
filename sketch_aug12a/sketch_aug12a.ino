#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // Include the I2C LCD library

// I2C LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD address 0x27, 16 columns, 2 rows

// Ultrasonic sensor pins
const int trigPin = 12;
const int echoPin = 11;

// LED pins
const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

// Motor control pins
const int motor1pin1 = 2;
const int motor1pin2 = 3;
const int motor2pin1 = 4;
const int motor2pin2 = 5;

long duration;
int distanceCm;

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Set up pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  // Initial LCD display
  lcd.setCursor(0, 0);
  lcd.print(" Distance Meas. ");
  lcd.setCursor(0, 1);
  lcd.print("    System      ");
  delay(2000);
  lcd.clear();

  // Serial monitor
  Serial.begin(9600);
  Serial.println("Distance Measurement System");
}

void loop() {
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;  // Calculate distance in cm

  // Display distance on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceCm);
  lcd.print(" cm  ");

  // Control LEDs and motors based on distance
  if (distanceCm < 50) {
    // Red LED on, motors stop
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    stopMotors();

    lcd.setCursor(0, 1);
    lcd.print("DANGER!!!       ");
    Serial.println("DANGER!!!");

  } else if (distanceCm == 50) {
    // Yellow LED on, motors stop
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    stopMotors();

    lcd.setCursor(0, 1);
    lcd.print("Maintain Dist.  ");
    Serial.println("Maintain Distance");

  } else {
    // Green LED on, motors run
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    runMotors();

    lcd.setCursor(0, 1);
    lcd.print("Safe to Move    ");
    Serial.println("Safe to Move");
  }

  delay(500);  // Delay for stability
}

// Function to stop motors
void stopMotors() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

// Function to run motors
void runMotors() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}
