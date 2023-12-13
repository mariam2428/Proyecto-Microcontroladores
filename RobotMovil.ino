//Librerias
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 13, 7);

int izqA = 8;
int izqB = 6;
int derA = 9;
int derB = 10;
int estado = 'c';

const int trigPin = 3;
const int echoPin = 2;
const int buzzer = 19;

long duration;
int distance;
int distance1;
int distance2;
double Speed;


void setup()  {
  
  lcd.begin(16, 2);     // inicializa a display de 16 columnas y 2 lineas  

  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);

}

void loop()  {
  ultrasonicRead();
  velocidad();
  if(Serial.available()>0){ 
    estado = Serial.read();
  }
  
  if (distance >= 0 && distance <= 15) {
    parar();
    delay(500);
    digitalWrite(19, HIGH);
    if (digitalRead(19) == HIGH){
      lcd.setCursor(0, 0);
      lcd.print("Objeto Detectado");
      delay(1000);
    }
    tone(buzzer, 1000); //
    delay(100); 
    noTone(buzzer);
    delay(10);
    parar();
    delay(1000);
    reversa(); 
    delay(1000);
    derecha();
    delay(500);
    digitalWrite(19, LOW);
    if (digitalRead(7) == LOW) {
      lcd.setCursor(0, 0);
      lcd.print("Objeto Evitado");
      delay(200);
    }    
  }    
  if (distance >= 15 && distance <= 30) {
    lcd.setCursor(0, 0);
    lcd.print("En movimiento");
    delay(200);
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer); 

  }
  if (estado == 'a') {
    adelante();
  }
  if (estado == 'b') {
    izquierda();
  }
  if (estado == 'c') {
    parar();
  }
  if (estado == 'd') {
    derecha();
  }
  if (estado == 'e') {
    reversa();
  }

 }



 void adelante() {
  digitalWrite(izqB, LOW);
  digitalWrite(derA, LOW);
  digitalWrite(izqA, HIGH);
  digitalWrite(derB, HIGH);
}
void izquierda() {
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  digitalWrite(izqA, LOW);
  digitalWrite(derA, HIGH);
}
void parar() {
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  digitalWrite(derA, LOW);
  digitalWrite(izqA, LOW);
}
void derecha() {
  digitalWrite(izqB, LOW);
  digitalWrite(izqA, LOW);
  digitalWrite(derA, LOW);
  digitalWrite(derB, HIGH);
}
void reversa() {
  digitalWrite(izqA, LOW);
  digitalWrite(derB, LOW);
  digitalWrite(izqB, HIGH);
  digitalWrite(derA, HIGH);
}
float ultrasonicRead () {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

float velocidad(){
   distance1 = ultrasonicRead();
   delay(1000);
   distance2 = ultrasonicRead();
   Speed = ((distance2 - distance1)/1.0)/100;
   lcd.setCursor(0, 1);
   lcd.print("Speed: ");
   lcd.print(Speed);
   lcd.print("m/s");
   delay(1000);
}
