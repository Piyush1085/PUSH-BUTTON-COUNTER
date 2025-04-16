const int buttonPin = 2;
int buttonState;
int lastButtonState = HIGH;
int count = 0;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) {
      count++;
      Serial.print("Button Pressed: ");
      Serial.println(count);
    }
  }

  lastButtonState = reading;
}
