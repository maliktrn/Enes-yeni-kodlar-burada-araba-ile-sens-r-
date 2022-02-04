int trigPin = 3;
int echoPin = 4;
int a = 8;
int b = 9;
int c = 10;
int buzzerPin = 12;

long sure;
long mesafe;

void setup()
{
pinMode(13,OUTPUT);   //sağ  motor 
pinMode(12,OUTPUT);   //sol motor
pinMode(11,OUTPUT);   //sağ motor2 
pinMode(6,OUTPUT);   //sol motor 2
Serial.begin(9600);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2)/29.1;

  if(mesafe <= 10)
  {
    digitalWrite(c,HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    digitalWrite(b,LOW);
    digitalWrite(a,LOW);
  }
  else if(mesafe <= 15)
  {
    digitalWrite(c,HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    digitalWrite(c,LOW);
    digitalWrite(buzzerPin,LOW);
    delay(100);
        
    digitalWrite(b,LOW);
    digitalWrite(a,LOW);
  }
  else if(mesafe <= 20)
  {
    digitalWrite(b,HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    digitalWrite(b,LOW);
    digitalWrite(buzzerPin,LOW);
    delay(100);
        
    digitalWrite(c,LOW);
    digitalWrite(a,LOW);
  }
  else if(mesafe <= 25)
  {
    digitalWrite(a,HIGH);
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    digitalWrite(a,LOW);
    digitalWrite(buzzerPin,LOW);
    delay(100);
        
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
  }
  else
  {
    digitalWrite(a,HIGH);
  }
  
  
  if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){    
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'G'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(13,HIGH); 
  digitalWrite(11,HIGH);
}
 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(12,HIGH);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(10,HIGH);
}

 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}



}
