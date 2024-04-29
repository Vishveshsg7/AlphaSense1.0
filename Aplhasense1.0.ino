// Define pin assignments for ultrasonic sensors and vibrational motors
const int trigPins[] = {2, 4, 6, 8};
const int echoPins[] = {3, 5, 7, 9};
const int vibrationPins[] = {10, 11, 12, 13};

// Function prototypes
void measureDistance(int trigPin, int echoPin, long& duration, long& distance);
void adjustVibration(long distance, int vibrationPin);

void setup() {
  // Initialize ultrasonic sensor pins
  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
    pinMode(vibrationPins[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  long durations[4];
  long distances[4];

  // Measure distances for all sensors
  for (int i = 0; i < 4; i++) {
    measureDistance(trigPins[i], echoPins[i], durations[i], distances[i]);
  }

  // Output distances to serial monitor
  for (int i = 0; i < 4; i++) {
    Serial.print("Distance Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(distances[i]);
  }
  Serial.println("------(^..^)------");

  // Adjust vibration intensity based on distance for each sensor
  for (int i = 0; i < 4; i++) {
    adjustVibration(distances[i], vibrationPins[i]);
  }

  delay(100); // Adjust delay as needed
}

void measureDistance(int trigPin, int echoPin, long& duration, long& distance) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

void adjustVibration(long distance, int vibrationPin) {
  if (distance >= 30 && distance <= 80) {
    digitalWrite(vibrationPin, HIGH);
  } else if (distance >= 90 && distance <= 150) {
    digitalWrite(vibrationPin, HIGH);
    delay(500);
    digitalWrite(vibrationPin, LOW);
    delay(500);
  } else {
    digitalWrite(vibrationPin, LOW); // No vibrations
  }
}