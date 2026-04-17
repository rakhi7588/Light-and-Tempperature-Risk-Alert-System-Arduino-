// RGB LED pins (use PWM pins)
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Sensor pins
int tempPin = A0;   // LM35
int potPin  = A1;   // Potentiometer
int ldrPin  = A2;   // Photoresistor (LDR)

// Function for averaging analog readings
int readAvg(int pin) {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(pin);
    delay(5);
  }
  return sum / 10;
}

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  // -------- Temperature (LM35) ----------
  int tempRaw = readAvg(tempPin);
  float voltage = tempRaw * (5.0 / 1023.0);
  float temperature = voltage * 100.0;

  // -------- Potentiometer threshold ----------
  int potValue = analogRead(potPin);
  Serial.print(" | adc potValue: ");
  Serial.println(potValue);
  float threshold = 25 + (potValue / 1023.0) * 10;

  // -------- Light sensor (LDR) ----------
  int ldrValue = readAvg(ldrPin);

  // -------- Serial Monitor ----------
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C | Threshold: ");
  Serial.print(threshold);

  Serial.print(" | LDR: ");
  Serial.println(ldrValue);

  // -------- CONTROL LOGIC ----------
  if (ldrValue < 300) {   // DARK environment

    if (temperature < threshold - 2) {
      // SAFE
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    }
    else if (temperature > threshold + 2) {
      // DANGER
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    }
    else {
      // WARNING
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
    }

  } else {  // BRIGHT environment (SAFE)

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }

  delay(1000);
}