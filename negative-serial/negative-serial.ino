
/**
 * Receive blink rate from the serial
 */

int blink_rate = 0;

int value;
int sign = 1;

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
      value = (value * 10) + (ch - '0'); // accumulate the value 
      
    } else if(ch == '-') {
      sign = -1;      
    }else { // any other char not a digit or minus sign
      value = sign * value;
      Serial.println(value);
      value = 0;
      sign = 1;
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
