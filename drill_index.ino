const int soundPin = 10 ;
const int ledPin = 11;
const int inputPin = 12;

unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
  setupSound(soundPin);

  delayStart = millis();   // start delay
  delayRunning = true; // not finished yet
}

void loop() {

  digitalRead(inputPin);
  int bitState = digitalRead(inputPin);

  if (bitState == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    if (delayRunning && ((millis() - delayStart) >= 600000)) {
      activateSound(soundPin);
      delayStart = millis();
      delayRunning = false;
      delay(500);
      delayRunning = true;
    }
  }

  if (bitState == LOW)
  {
    digitalWrite(ledPin, LOW);
     delayStart = millis();
     delayRunning = true;
  }
}

void setupSound(int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

void activateSound(int pin) {
  digitalWrite(pin, LOW);

  delay(500);
  digitalWrite(pin, HIGH);
}
