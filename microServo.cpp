#include <Servo.h>

#define pot_pin A3  // Pin potensiometer
#define servo_pin 9 // Pin servo

Servo myservo;  // Membuat objek servo

void setup() {
  Serial.begin(9600);         // Inisialisasi komunikasi serial
  myservo.attach(servo_pin);  // Menghubungkan servo ke pin 6
}

void loop() {
  int nilai_pot = analogRead(pot_pin); // Membaca nilai potensiometer (0-1023)
  
  // Konversi nilai potensiometer ke rentang pulse width (500 - 2500 microseconds)
  int nilai_pulse = map(nilai_pot, 0, 1023, 2500, 500);

  // Konversi ke sudut servo dalam rentang 1 - 120 derajat
  int nilai_servo = map(nilai_pot, 0, 1023, 1, 120);

  myservo.writeMicroseconds(nilai_pulse); // Menggerakkan servo dengan pulse width
  delay(10); // Delay kecil untuk respons yang halus

  // Menampilkan data ke Serial Monitor
  Serial.print("Potensiometer: ");
  Serial.print(nilai_pot);
  Serial.print(" | Pulse Width: ");
  Serial.print(nilai_pulse);
  Serial.print(" µs | Servo Angle: ");
  Serial.println(nilai_servo);
}
