//Librerias
#include <ThreeWire.h>
#include <RtcDS1302.h>

//Declaración variables, display de siete segmentos

int Hd = 2; //Digito 1: Hora decenas
int Hu = 3; //Digito 2: Hora unidades
int Md = 4; //Digiot 3: Minuto decenas
int Mu = 5; //Digito 4: Minuto unidades
int A = 6;
int F = 7;
int B = 8;
int E = 9;
int D = 10;
int C = 11;
int G = 12;

//Inicialización el modulo de tiempo real utilizando la libreria "ThreeWire"
ThreeWire myWire(18,17,19);
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  //Inicializacion de la comunicación con el monitor serial 
  Serial.begin(57600);

  //Inicialización comunicación con el módulo de tiempo real.
  Rtc.Begin();

  //Definición de pines de salida:
  pinMode(Hd, OUTPUT);
  pinMode(Hu, OUTPUT);
  pinMode(Md, OUTPUT);
  pinMode(Mu, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(G, OUTPUT);

}

void loop() {

  RtcDateTime now = Rtc.GetDateTime(); // Obtener y almacenar la hora actual en la variable "now"

  // Visualización hora actual en el display de 7 segmentos en formato 24 horas
  limpiar();
  digito(Hd);
  HoraDecenas(now.Hour());
  delay(5);
  
  limpiar();
  digito(Hu);
  HoraUnidades(now.Hour());
  delay(5);
  
  limpiar();
  digito(Md);
  MinutosDecenas(now.Minute());
  delay(5);
  
  limpiar();
  digito(Mu);
  MinutosUnidades(now.Minute());
  delay(5);
}

//Declaración de funciones

void HoraDecenas(int hora)
{
  int decenas = hora / 10;
  digito(Hd);
  numero(decenas);
}

void HoraUnidades(int hora)
{
  int unidades = hora % 10;
  digito(Hu);
  numero(unidades);
}

void MinutosDecenas(int minutos)
{
  int decenas = minutos / 10;
  digito(Md);
  numero(decenas);
}

void MinutosUnidades(int minutos)
{
  int unidades = minutos % 10;
  digito(Mu);
  numero(unidades);
}

void digito(int digito)
{
  digitalWrite(Hd, HIGH);
  digitalWrite(Hu, HIGH);
  digitalWrite(Md, HIGH);
  digitalWrite(Mu, HIGH);
  
  switch (digito)
  {
  case 2:
    digitalWrite(Hd, LOW);
    break;
  case 3:
    digitalWrite(Hu, LOW);
    break;
  case 4:
    digitalWrite(Md, LOW);
    break;
  case 5:
    digitalWrite(Mu, LOW);
    break;
  default:
    digitalWrite(Hd, HIGH);
    digitalWrite(Hu, HIGH);
    digitalWrite(Md, HIGH);
    digitalWrite(Mu, HIGH);
    break;
  }
}

void numero(int x)
{
  limpiar();
  switch (x)
  {
  case 1:
    uno();
    break;
  case 2:
    dos();
    break;
  case 3:
    tres();
    break;
  case 4:
    cuatro();
    break;
  case 5:
    cinco();
    break;
  case 6:
    seis();
    break;
  case 7:
    siete();
    break;
  case 8:
    ocho();
    break;
  case 9:
    nueve();
    break;
  default:
    cero();
    break;
  }
}

void limpiar()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

//Declaración numeros en el display
void cero()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void uno()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void dos()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void tres()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void cuatro()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void cinco()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void seis()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void siete()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void ocho()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void nueve()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
