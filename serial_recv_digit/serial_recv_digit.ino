
/**
 * Receive blink rate from the serial
 */

int blink_rate = 0;

int value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  if(Serial.available()) {
    char ch = Serial.read();
    if( ch >= '0' && ch <= '9') {
      /* digit between 0 and 9 */
      //blink_rate = (ch - '0');
      //blink_rate = blink_rate * 100; // in ms

      value = (value * 10) + (ch - '0'); // accumulate the value 
      
    } else if(ch == 10) {
      blink_rate = value;
      Serial.println(blink_rate);
      value = 0; // reset for the next sycle
    }
  }

  blink();
 
}

void blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blink_rate);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blink_rate);
  
}
