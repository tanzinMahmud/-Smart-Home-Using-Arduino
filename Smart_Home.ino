#include <Servo.h>
float temperature;
Servo servoMotor;

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(A0,INPUT);
  servoMotor.attach(12);
}

void loop() {
  if(Serial.available()>0)
  {
    char data=Serial.read();
    if(data=='a')
    {
      digitalWrite(8,HIGH);
    }
    else if(data=='b')
    {
      digitalWrite(8,LOW);
    }
    else if(data=='c')
    {
      digitalWrite(13,HIGH);
    }
    else if(data=='d')
    {
      digitalWrite(13,LOW);
    }
    else if(data=='f')
    {
      servoMotor.write(0);
    }
    else if(data=='g')
    {
      servoMotor.write(180);
    }
  }
  temperature = analogRead(A0);
  temperature = temperature * 0.48828125;
  if(temperature>55)
  {
      digitalWrite(7,HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
  }
}
