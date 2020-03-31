const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

int notes[] = {250,350,450};

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn (echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if( distance <= 30 && distance>=20) {
    tone(7, notes[0]);
  }
  else if( distance <= 20 && distance>=10) {
    tone(7, notes[2]);
  }
  else if( distance <= 10 && distance>=0) {
    tone(7, notes[1]);
  }
  else {
    noTone(7);
  }
  
}
