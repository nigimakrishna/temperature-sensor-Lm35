const int sensorPin = A0;  // LM35 temp sensor connected to analog pin A0
const int ledPin = 13;     // LED connected to digital pin 13

int temperature = 0;       // Variable to store temp value
int blinkInterval = 250;   // Initial blink interval for temperatures below 30°C
int counter = 0;           // Counter for managing blinking intervals
int tempThreshold = 30;    // Temperature threshold

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  // Convert the sensor value to temperature in Celsius
  temperature = (sensorValue * 0.48828125); // (sensorValue * 5.0 / 1024) * 100

  // Check temperature conditions and control LED blinking
  if (temperature < tempThreshold) {
    if (counter < blinkInterval / 2) {
      digitalWrite(ledPin, HIGH); // Turn LED ON
    } else {
      digitalWrite(ledPin, LOW);  // Turn LED OFF
    }
    counter = (counter + 1) % blinkInterval;
  } else {
    blinkInterval = 500; // Change blink interval for temperatures above 30°C
    if (counter < blinkInterval / 2) {
      digitalWrite(ledPin, HIGH); // Turn LED ON
    } else {
      digitalWrite(ledPin, LOW);  // Turn LED OFF
    }
    counter = (counter + 1) % blinkInterval;
  }

  // Introduce a small delay for stability
  for (int i = 0; i < 100000; i++) {
    // A small delay loop
  }
}
