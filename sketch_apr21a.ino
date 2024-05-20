
#include <Adafruit_LiquidCrystal.h>
          
  
#define trigger 9   // sensor de obstaculo 8,9                    
#define echo 8                          
#define trigger1 5     
#define echo1 4 

int motor= 12;
int Buzzer= 13;

int motor2= 7;
float distancia = 0;                    
float tempo = 0;
float distancia1=0;
float tempo1=0;



void leitura(); // leitura do sensor de obstaculo
void leitura1(); // leitura do sensor de desnivel



  
void setup() {
  
  Serial.begin(9600);    // porta serial
  pinMode(trigger1, OUTPUT); 
  pinMode(echo1, LOW);       
  pinMode(trigger, OUTPUT); 
  pinMode(echo, LOW);
  pinMode(Buzzer,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(motor2,OUTPUT);
  
  //delay(2000);
  
  

  
}

void loop() {
  leitura();
  distancia= tempo/59;
  Serial.print("CM:");
  Serial.println(distancia);
  delay (1000);
  
  
  leitura1();
  distancia1= tempo1/59;
  Serial.print("CM:");
  Serial.println(distancia1);
  delay (1000);
  
 
  
 
 // primeiro sensor echo, trigger(8 e 9)
  // este sensor tem como objetivo identificar obstaculo
 
  
  
  // sensor de obstaculo// longe
  
  if (distancia>=21 && distancia<=29){
    digitalWrite(motor,HIGH);
    tone(Buzzer, 756, 754); 
     delayMicroseconds(500);
    
    
  } // obstaculo longe      
  
  else  {
  digitalWrite(motor, LOW);
  }
  
  //sensor  de obstaculo// perto
  
  if (distancia<20){
    digitalWrite(motor,HIGH);
    tone(Buzzer, 3456, 354); 
     delayMicroseconds(500);
   
    
  }  //obstaculo perto    
  else  {
  //digitalWrite(motor, LOW);
  }
  
 
  
  //sensor de desnivel
 if (distancia1>=20 && distancia1<=30){
    digitalWrite(motor2,HIGH);
    tone(Buzzer, 856, 554);
     delayMicroseconds(500); 
   
    } // desnivel de 10cm
  else  {
  digitalWrite(motor2, LOW);
  }
// sensor de desnivel // buraco
  if (distancia1>31){
    digitalWrite(motor2,HIGH);
    tone(Buzzer, 4456, 5554);
     delayMicroseconds(500); 
    
  
  }
  
}
  void leitura()
  {
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    pinMode(echo, INPUT);
    tempo=pulseIn(echo,HIGH);
  }



void leitura1(){
    
    pinMode(trigger1, OUTPUT);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10);
    digitalWrite(trigger1, LOW);
    pinMode(echo1, INPUT);
    tempo1=pulseIn(echo1,HIGH);
    
    
  }

  
  

 

 
