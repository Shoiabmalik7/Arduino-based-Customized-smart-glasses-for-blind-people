#define LDR A0
#define GAS 7
#define BUZZER 8
int ldr_val;
int gas_val;
int const trigPin = 3;
int const echoPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(GAS,INPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,LOW);
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  delay(500);
}

void loop() {

  ////////  LDR INPUT  //////////
  ldr_val=analogRead(A0);
  Serial.print("LDR VALUE:");
  Serial.println(ldr_val);

  ///////  GAS INPUT  ///////////
  gas_val=digitalRead(7);
  Serial.print("GAS VALUE:");
  Serial.println(gas_val);

  ////// ULTRASONIC INPUT /////
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration /2)/29.1;
  Serial.print("DISTANCE:");
  Serial.println(distance);
  delay(500);

  ///////////  LDR   //////////
    if(ldr_val<400){
    digitalWrite(BUZZER,HIGH);
    Serial.println("BUZZER ON");
     delay(500);
  }
  else{
    digitalWrite(BUZZER,LOW);
    Serial.println("BUZZER OFF");
     delay(500);
  }

  ///////  GAS SENSOR ////////
  if(gas_val==0){
  digitalWrite(BUZZER,HIGH);
  Serial.println("BUZZER ON");
  delay(100);
  }
  else{
  digitalWrite(BUZZER,LOW);
  Serial.println("BUZZER OFF");
  }

  //////   ULTRASONIC  /////
   if(distance<=150){
    digitalWrite(BUZZER,HIGH);
    Serial.println("BUZZER ON");
    delay(500);
  }
  else{
    digitalWrite(BUZZER,LOW);
    Serial.println("BUZZER OFF");
     }
}
