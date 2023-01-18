const int trig = 6; //transmits ultrasonic
const int echo = 7; //recieves ultrasonic
const int LED= 13; //pin of the LED
long duration,distance; //long values used for ultrasonic emmiter 

//takes the duration (in microseconds) and converts it to cm
long distanceCalculation(long timeMS){
  return (timeMS/29)/2;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //begins the serial
  //setting up pins
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(trig,LOW);  //guarentees emiiter is off
}

void loop() {
  //check distance to nearest object
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  //Calculations
  duration = pulseIn(echo,HIGH);
  distance = distanceCalculation(duration);
  //print to serial
  char buffer[13];
  sprintf(buffer,"distance = %d cm, duration = %d ms",distance,duration);
  Serial.println(buffer);
  //check if anything is within 30cm
  if(distance<30){
    Serial.print("Motion detected");
    digitalWrite(LED,HIGH);
    delay(5000);
    digitalWrite(LED,LOW);
  }
  delay(100); //allow system to reset
}
