char cha_val = 65;
int int_val = 65;
float float_val = 65.0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello Arduino DUE");

  pinMode(LED_BUILTIN, OUTPUT);
 

}
void loop() {
  Serial.println("char val");
  Serial.println(cha_val);
  Serial.println(cha_val, BIN);
  Serial.println(cha_val, DEC);

  Serial.println("int val");
  Serial.println(int_val);
  Serial.println(int_val, BIN);
  Serial.println(int_val, DEC);

  Serial.println("float val");
  Serial.println(float_val);
  Serial.println(float_val, BIN);
  Serial.println(float_val, DEC);

  delay(1000);
  cha_val++;
  int_val++;

}
