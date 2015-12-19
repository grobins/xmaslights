/*
  
 
 
 */


const byte myPins[] = {
  7, 8, 9, 10, 11, 12};
byte onPin;

int sound = 0;
int soundpin = A0;

int soundTrigger = 2;
int numLights = 0;
int onTime = 0;
int baseThreshold = 512;


void setup() {                


  for (int i = 0; i < sizeof(myPins) - 1; i++) {

    pinMode(myPins[i], OUTPUT);     

  }
  Serial.begin(19200);
  Serial.print("ready");



  pinMode(soundpin, INPUT);
}


void cycleAllLights(int onTime, int offTime){

  for (int i = 0; i < sizeof(myPins); i++) {

    digitalWrite(myPins[i], HIGH);
    delay(onTime); 
    digitalWrite(myPins[i], LOW);                


  };



}

void lightsOff(){

  for (int i = 0; i < sizeof(myPins); i++) {

    int val = digitalRead(myPins[i]);

    if (val == HIGH){
      digitalWrite(myPins[i], LOW);        
    };

  };

}

void lightsOn(){

  for (int i = 0; i < sizeof(myPins); i++) {

    int val = digitalRead(myPins[i]);

    if (val == LOW){
      digitalWrite(myPins[i], HIGH);        
    };

  };

}



void lightNLights(int num, int onTime){

  for (int i = 0; i < num; i++) {
    digitalWrite(myPins[random(0, sizeof(myPins))], HIGH);
   };

  delay(onTime);
  lightsOff();

}


void light
















// the loop routine runs over and over again forever:
void loop() {


  sound = analogRead(A0); 

  if (digitalRead(soundTrigger) == HIGH){
    Serial.println("Threshold Reached"); 
    sound = analogRead(A0);
    if( sound > baseThreshold + 5) {
      numLights = 5;
      onTime = 10;    
    } 
    else if ( sound > baseThreshold + 4 ) {
      numLights = 3; 
      onTime = 30;
    }
    else if ( sound > baseThreshold + 3 ) {
      numLights = 2; 
      onTime = 50;
    }
    else if ( sound > baseThreshold + 2 ) {
      numLights = 1; 
      onTime = 80;
    }

    lightNLights(numLights, onTime);



  } 
  else {



  }


  Serial.println(sound);  


}









