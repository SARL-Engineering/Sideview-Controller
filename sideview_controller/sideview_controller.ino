enum HARDWARE {
  LIGHT_ENABLE = 4,
  TAP_ENABLE = 5
};

const char start_light_char = 's';
const char tap_char = 't';

const int start_light_on_time = 300; // milliseconds
const int tap_time = 300; // milliseconds

void setup() {
  Serial.begin(9600);

  pinMode(HARDWARE::LIGHT_ENABLE, OUTPUT);
  pinMode(HARDWARE::TAP_ENABLE, OUTPUT);

  digitalWrite(HARDWARE::LIGHT_ENABLE, LOW);
  digitalWrite(HARDWARE::TAP_ENABLE, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char in_byte = Serial.read();

    if (in_byte ==  start_light_char) {
      digitalWrite(HARDWARE::LIGHT_ENABLE, HIGH);
      delay(start_light_on_time);
      digitalWrite(HARDWARE::LIGHT_ENABLE, LOW);

    } else if (in_byte ==  tap_char) {
      digitalWrite(HARDWARE::TAP_ENABLE, HIGH);
      delay(tap_time);
      digitalWrite(HARDWARE::TAP_ENABLE, LOW);
    }
  }
}
