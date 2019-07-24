int relayPin = 5;
int usbDetectPin = 6;
int button = 7; 

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, INPUT);
  pinMode(usbDetectPin, INPUT); // 
  pinMode(button, OUTPUT); // 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digital read in on pin 2 for input if it's high then toggle
  int relay = digitalRead(relayPin);
  int usbDetect = digitalRead(usbDetectPin);
  if ( (relay && !usbDetect ) || (!relay && usbDetect) ) {
    pressButton();
  }
  Serial.println("RELAY: " + (String)relay + " USB: " + (String)usbDetect);
  
}

void pressButton(){
  Serial.println("Button pressed!");
  digitalWrite(button, HIGH);
  delay(100);
  digitalWrite(button, LOW);
}
