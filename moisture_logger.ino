void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(A2, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  //determines the levels of dryness
   unsigned char green=25;
   unsigned char yellow=50;
   unsigned char red=60;
   
  //Turns off all lights at the start of the loop to ensure only 1 light can be on at a time
   digitalWrite(4, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
   
  // read the input on analog pin 0 and devides it by 10 so it can be saved in a char and outputs are more stable:
   unsigned char sensorValue = analogRead(A0)/10;
  
  // print out the value you read, together with the values for dryness levels
  //code is printed in this order so the colors match in the plotter
   Serial.print(sensorValue);
   Serial.print(",");
   Serial.print(red);
   Serial.print(",");
   Serial.print(green);
   Serial.print(",");
   Serial.println(yellow);

  //determines what happens if the sensor value reaches certain levels of dryness
    if(sensorValue>red){
      Serial.println("Ground is too dry");
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(4, LOW);
      delay(500);
    }else {
      //no standard "else if" to make sure there will always be a delay of 1 second
      if(sensorValue>yellow){
        Serial.println("the plants will need water soon");
        digitalWrite(3, HIGH);
      }else if(sensorValue<green){
        Serial.println("the plants are properly watered");
        digitalWrite(2, HIGH);
      } else {
        Serial.println("no action required");
      }    
      delay(1000);
    }
}
