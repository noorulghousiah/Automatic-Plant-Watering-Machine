//ultrasonic sensor
unsigned int ADCValue;

//relay
const int RELAY_PIN = 12;

//time delay
const int timewater=5000;
const int timewait=5000;

//time millis
unsigned long previousMillis=0;
long OnTime=4000;
long OffTime=5000;
int pumpState= LOW;

//for ultrasonic distance if else statement
const int DISTANCE_THRESHOLD = 40; //mm

void setup() {
  //begin serial port
  Serial.begin (9600);

  //relay
  pinMode(RELAY_PIN, OUTPUT);


}

void loop() {
  
 ultrasonic();
 int run=LOW;
 int stop= HIGH;
/////////////////////////////////////////////////////////////////////////////
  unsigned long currentMillis = millis();

  if(ADCValue < DISTANCE_THRESHOLD){
    if((pumpState == run) && (currentMillis - previousMillis >= OnTime))
    {
      pumpState = stop;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(RELAY_PIN, pumpState);  // Update the actual LED
      Serial.println("s");
    }
    else if ((pumpState == stop) && (currentMillis - previousMillis >= OffTime))
    {
      pumpState = run;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(RELAY_PIN, pumpState);    // Update the actual LED
      Serial.println("r");
    }
  }
  else{
      digitalWrite(RELAY_PIN, stop);
      Serial.println("s");
  }
}


    
//ultrasonic
void ultrasonic(){
  ADCValue = analogRead(0);
   // ADCValue *=3;   //uncomment if want range 3meter
    Serial.print("Present Length is: ");
    Serial.print(ADCValue, DEC);
    Serial.println("mm");
    delay(1000); //delay 1S
  }


























  ///////////////////////////////////////////////////////////////////////

//  if (ADCValue < DISTANCE_THRESHOLD){
//    delay(5000); //precaution so water dont flow suddenly
//    digitalWrite(RELAY_PIN, run);
//    Serial.println("r");
//    delay(5000);
//    digitalWrite(RELAY_PIN, stop);
//    Serial.println("s");
//    delay(10000);
//    }
//    else{
//      digitalWrite(RELAY_PIN, stop);
//      Serial.println("s");
//    }
    
