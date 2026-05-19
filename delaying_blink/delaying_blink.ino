void setup() {
  Serial.begin(115200);
  Serial.println("Hello Arduino DUE");

  pinMode(LED_BUILTIN, OUTPUT);
 

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

}
