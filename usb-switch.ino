int ledPin = 6;
int buttonPin = 7;
int relayPin = 8;

void setup() {
  pinMode(relayPin, INPUT);
  pinMode(ledPin, INPUT); 
  pinMode(buttonPin, OUTPUT);
//pinMode(buttonPin, INPUT); // used for debugging button
  Serial.begin(9600);
}

/*
 * RELAY = 0 -> Fabman ON
 * RELAY = 1 -> Fabman OFF
 * 
 * LED = 0 -> Computer ON
 * LED = 1 -> Computer OFF
 */

void loop() {
  int relay = digitalRead(relayPin);
  int led = digitalRead(ledPin);
  Serial.println("RELAY: " + (String)relay + " LED: " + (String)led );
  if ( (relay && !led ) || (!relay && led) ) {
    pressButton();
  }
  delay(500);
//  Serial.println("button: " + (String)digitalRead(buttonPin) + " LED: " + (String)led ); // used for debugging button
}
void pressButton(){
  Serial.println("button pressed!");
  digitalWrite(buttonPin, HIGH);
  delay(100);
  digitalWrite(buttonPin, LOW);
}
