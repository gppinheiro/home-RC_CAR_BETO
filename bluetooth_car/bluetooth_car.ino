int outPin1 = 5;     //motor1
int outPin2 = 6;    //motor1

int outPin3 = 10;   //motor2
int outPin4 = 11;   //motor2

char bt = 0;       //BT

const int trigPin = 7; //TRIG
const int echoPin = 8; //ECHO

long duration;
int distance;

int notes[] = {250,350,450};
 

void setup()
{
 Serial.begin(9600);
 
 pinMode(outPin1,OUTPUT);
 pinMode(outPin2,OUTPUT);
 pinMode(outPin3,OUTPUT);
 pinMode(outPin4,OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
}

void loop()
{
 //Controlar Carro
 if (Serial.available() > 0) //save incoming data to variable 'bt'
 {
   bt = Serial.read();
   
   if(bt == 'F')           //move forwards
   {
     digitalWrite(outPin1,HIGH);
     digitalWrite(outPin2,LOW);
     digitalWrite(outPin3,LOW);
     digitalWrite(outPin4,LOW);
   }
   else if (bt == 'B')      //move backwards
   {
     digitalWrite(outPin1,LOW);
     digitalWrite(outPin2,HIGH);
     digitalWrite(outPin3,LOW);
     digitalWrite(outPin4,LOW);
   }
   else if (bt == 'R')    // turn wheels right
   {
     digitalWrite(outPin1,LOW);
     digitalWrite(outPin2,LOW);
     digitalWrite(outPin3,HIGH);
     digitalWrite(outPin4,LOW);
   }
   else if (bt == 'L')     //turn wheels left
   {
     digitalWrite(outPin1,LOW);
     digitalWrite(outPin2,LOW);
     digitalWrite(outPin3,LOW);
     digitalWrite(outPin4,HIGH);
   }
   else if (bt== 'G')      //move forward left
   {
    digitalWrite(outPin1,HIGH);
    digitalWrite(outPin2,LOW);
    digitalWrite(outPin3,LOW);
    digitalWrite(outPin4,HIGH);
   }
   else if (bt== 'I')      //move forward right
   {
    digitalWrite(outPin1,HIGH);
    digitalWrite(outPin2,LOW);
    digitalWrite(outPin3,HIGH);
    digitalWrite(outPin4,LOW);
   }
   else if (bt== 'H')      //move backward left
   {
    digitalWrite(outPin1,LOW);
    digitalWrite(outPin2,HIGH);
    digitalWrite(outPin3,LOW);
    digitalWrite(outPin4,HIGH);
   }
   else if (bt=='J')       //move backward right
   {
    digitalWrite(outPin1,LOW);
    digitalWrite(outPin2,HIGH);
    digitalWrite(outPin3,HIGH);
    digitalWrite(outPin4,LOW);
   }
   else if (bt == 'S')     //stop!!
   {   
     digitalWrite(outPin1,LOW);
     digitalWrite(outPin2,LOW);
     digitalWrite(outPin3,LOW);
     digitalWrite(outPin4,LOW);
   }
   else if (bt== 'F' and bt== 'L')      //move forward left
   {
    digitalWrite(outPin1,HIGH);
    digitalWrite(outPin2,LOW);
    digitalWrite(outPin3,LOW);
    digitalWrite(outPin4,HIGH);
   }
   else if (bt== 'F' and bt== 'R')      //move forward right
   {
    digitalWrite(outPin1,HIGH);
    digitalWrite(outPin2,LOW);
    digitalWrite(outPin3,HIGH);
    digitalWrite(outPin4,LOW);
   }
   else if (bt== 'B' and bt== 'L')      //move backward left
   {
    digitalWrite(outPin1,LOW);
    digitalWrite(outPin2,HIGH);
    digitalWrite(outPin3,LOW);
    digitalWrite(outPin4,HIGH);
   }
   else if (bt=='B' and bt== 'R')       //move backward right
   {
    digitalWrite(outPin1,LOW);
    digitalWrite(outPin2,HIGH);
    digitalWrite(outPin3,HIGH);
    digitalWrite(outPin4,LOW);
   }

   //Sensores
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
  
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
  
   duration = pulseIn (echoPin, HIGH);
   distance = duration*0.034/2;
   
   if( distance <= 30 && distance>=20) {
    tone(3, notes[0]);
   }
  else if( distance <= 20 && distance>=10) {
    tone(3, notes[2]);
  }
  else if( distance <= 10 && distance>=0) {
    tone(3, notes[1]);
  }
  else {
    noTone(3);
  }
 }
}
