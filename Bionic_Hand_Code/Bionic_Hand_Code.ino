// Bionic Hand Arduino Code

/** Code written by Kevin Tran 4/2/2024, Bionic hand simulation of flexion and extension of the bionic hand
utilizing 5 servo motors and MyoWare EMG sensors. Amplification of 100x using a non-inverting amplifier and 
a low pass filter with a cutoff frequency of 20 Hz.
**/

/***********************************************************************************************************/
// Servo Library
#include <Servo.h>

// Initializing Servo variable
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
/***********************************************************************************************************/
// OLED Library
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Display
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
/***********************************************************************************************************/
// Baseline for the pulse/spikes
// Change value based on baseline reading in Arduino
const int x = 150;
/***********************************************************************************************************/

void setup() { 
  Serial.begin(9600); 

  // Configuring servo pins
  servo2.attach(10);  // pinky
  servo3.attach(11);  // ring
  servo4.attach(3);   // middle
  servo5.attach(6);   // index
  servo6.attach(5);   // thumb
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize with the I2C addr 0x3C
  display.clearDisplay(); // Clear the buffer
} 

/***********************************************************************************************************/

void loop() { 
  // Initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();

  // Reading the EMG signal from pin 3
  int emg = analogRead(A3);
  // Printing the EMG data
  Serial.println(emg);

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 32);
  display.print("State: ");
  display.print(emg);
  display.display();

  // Restricting serial plotter using lower and upper bound
  Serial.print(100);
  Serial.print(", ");
  
  Serial.print(700);
  Serial.print(", ");

  // If the EMG data is greater than x, the hand closes
  if(emg > x) {
    servo2.write(90);
    servo3.write(100);
    servo4.write(105);
    servo5.write(108);
    servo6.write(103);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Closed");
    display.display();
  }

  // If the EMG data is lower than x, the hand opens
  else if (emg < x) {
    servo2.write(10);
    servo3.write(0);
    servo4.write(12);
    servo5.write(10);
    servo6.write(14);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Open");
    display.display();
  }
  delay(50);
} 
