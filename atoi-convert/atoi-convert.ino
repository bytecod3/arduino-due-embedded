/**
 * demonstrate atoi
 */


int indx = 0;
int max_chars = 5;
char str[6]; // one extra for storing the nul termination character

int blink_rate;

void setup() {
  
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  if(Serial.available()){
    char c = Serial.read();
    if(indx < max_chars && c >= '0' && c <= '9') {
      str[indx++] = c;
    } else {
      // process the received str
      str[indx] = 0;
      blink_rate = atoi(str);
      indx = 0;
    }
  }

  blink();
  Serial.println(blink_rate);
  
}

void blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blink_rate);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blink_rate);
}
