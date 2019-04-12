#define rotEncoderA 2
#define rotEncoderB 3
#define button 4
volatile bool change = false;
volatile int counter = 0;
long lastMillis = 0;
long debounceMillis = 250;

void rotationISR(){
  bool statB = digitalRead(rotEncoderB);
  if(digitalRead(rotEncoderA)!=statB)counter++;
  else counter--;
  change = true;
}

void setup() {
  pinMode(rotEncoderA, INPUT_PULLUP);
  pinMode(rotEncoderB, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(rotEncoderA),rotationISR,FALLING);
  
}

void loop() {
  if(change){
    Serial.println(counter);
    change = false;
    }
   
  if(digitalRead(button) == false){
    if(millis() - lastMillis >debounceMillis){
      lastMillis = millis();
      counter = 0;
      Serial.println(counter);
    }
  }
   
  

}
