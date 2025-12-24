const int motorPin = 9;   

void setup() {
  
  Serial.begin(9600);
  
  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, 0);  
  
  Serial.println("Bluetooth Motor Control Ready!");

}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();
  
    if (val == '\n' || val == '\r') return;
    
    if (val == '1') {
      analogWrite(motorPin,64);
      Serial.println("motor status:on 1st gear");
    }
    else if(val =='2') {
      analogWrite(motorPin,129);
      Serial.println("2nd gear");
    }
    else if (val == '3') {
        analogWrite(motorPin,192);
      Serial.println("3rd gear");
    }
    else if( val =='4'){
      analogWrite(motorPin,255);
      Serial.println("motor status:4th gear");
    }
    else if (val == '0') {
      analogWrite(motorPin, 0);
      Serial.println("Motor: OFF");
    }
    else {
      Serial.println("Invalid! Send only 4,3,2,1 or 0");
    }
  }
}
