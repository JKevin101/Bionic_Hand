#include <Servo.h> 
#include <LiquidCrystal.h>

// LCD pin configuration
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Baseline for the pulse/spikes
const int x = 500;

// Initializing Servo variables
Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 

void setup() { 
  Serial.begin(9600); 

  // Configuring servo pins
  servo1.attach(10);  // Pinky
  servo2.attach(11);  // Ring
  servo3.attach(3);   // Middle
  servo4.attach(6);   // Index
  servo5.attach(5);   // Thumb
  
  // Initializing LCD screen
  lcd.begin(16, 2);
  lcd.print("Initializing...");
} 

void loop() { 
  int emgValue = analogRead(5);  // Read EMG sensor value once at the start of the loop

  // Printing the EMG data for debugging purposes
  Serial.println(emgValue);
  Serial.print("100, 700, ");

  // Clear LCD and set cursor position for display updates
  lcd.clear();
  lcd.setCursor(0, 0);

  // Determine hand state based on EMG data
  if(emgValue > x) {
    // Hand closes
    servo1.write(100);
    servo2.write(100);
    servo3.write(100);
    servo4.write(100);
    servo5.write(100);
    lcd.print("Hand Closed");
  } else if (emgValue < x) {
    // Hand opens
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
    servo4.write(0);
    servo5.write(0);
    lcd.print("Hand Open");
  }

  // Display the signal value on the second line
  lcd.setCursor(0, 1);
  lcd.print("Signal: ");
  lcd.print(emgValue);

  delay(50); // Slight delay to reduce flicker
}