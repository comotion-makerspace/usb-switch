int relayPin = 5;
int ledPin = 6;
int button = 7; 

int relay = 0;

void setup() {
  pinMode(ledPin, INPUT); 
  pinMode(button, OUTPUT);
  Serial.begin(9600);
}

/*
 * LED = 0 -> Computer ON
 * LED = 1 -> Computer OFF
 */

void loop() {
  // put your main code here, to run repeatedly:
  //int relay = digitalRead(relayPin);

  delay(500);
  int led = digitalRead(ledPin);
  if ( (relay && led ) || (!relay && !led) ) {
    pressButton();
  }
  Serial.println("RELAY: " + (String)relay + " LED: " + (String)led );
//  Serial.println("BUTTON: " + (String)button + " LED: " + (String)led );
}

void pressButton(){
  Serial.println("Button pressed!");
  digitalWrite(button, HIGH);
  delay(100);
  digitalWrite(button, LOW);
}
