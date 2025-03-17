#include <AccelStepper.h>

// Define motor control pins
#define OUTPUT1  7  // Blue wire
#define OUTPUT2  6  // Pink wire
#define OUTPUT3  5  // Yellow wire
#define OUTPUT4  4  // Orange wire
#define pot_pin  A3 // Potentiometer pin

// Define steps per full rotation
const int stepsPerRotation = 2048;

// Initialize stepper motor in FULL4WIRE mode
AccelStepper stepper(AccelStepper::FULL4WIRE, OUTPUT1, OUTPUT3, OUTPUT2, OUTPUT4);

void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(3000);  // Meningkatkan kecepatan maksimum
  stepper.setAcceleration(1500); // Meningkatkan akselerasi agar lebih responsif
}

void loop() {
  int nilai_pot = analogRead(pot_pin);  // Baca nilai potensiometer (0 - 1023)

  // Konversi nilai potensiometer ke kecepatan stepper (-3000 hingga 3000 langkah/detik)
  int speed = map(nilai_pot, 0, 1023, -3000, 3000);
  stepper.setSpeed(speed);  // Atur kecepatan stepper
  
  stepper.runSpeed();  // Jalankan stepper dengan kecepatan yang diatur

  // Menampilkan nilai potensiometer dan kecepatan di Serial Monitor
  Serial.print("Potentiometer: ");
  Serial.print(nilai_pot);
  Serial.print(" | Stepper Speed: ");
  Serial.println(speed);

  delay(10);  // Delay kecil agar data terbaca dengan baik
}
