// Declaración conexiones motor
int izqA = 8;
int izqB = 6;
int derA = 9;
int derB = 10;
int estado = 'c';     

//Declaración de salidas
void setup()  {
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
}

//Movimientos
void loop()  {
  if (estado == 'a') {       // Boton desplazar al Frente
    adelante();
  }
  if (estado == 'b') {      // Boton IZQ
    izquierda();
  }
  if (estado == 'c') {     // Boton Parar
    parar();
  }
  if (estado == 'd') {      // Boton DER
    derecha();
  }
  if (estado == 'e') {      // Boton Reversa
    reversa();
  }
      
 }

//Funciones
void adelante() {
  digitalWrite(derB, HIGH);
  digitalWrite(izqB, LOW);
  digitalWrite(derA, LOW);
  digitalWrite(izqA, HIGH);
}
void izquierda() {
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  digitalWrite(derA, HIGH);
  digitalWrite(izqA, LOW);
}
void parar() {
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  digitalWrite(derA, LOW);
  digitalWrite(izqA, LOW);
}
void derecha() {
  digitalWrite(derB, HIGH);
  digitalWrite(izqB, LOW);
  digitalWrite(izqA, LOW);
  digitalWrite(derA, LOW);
}
void reversa() {
  digitalWrite(derA, HIGH);
  digitalWrite(izqA, LOW);
  digitalWrite(derB, LOW);
  digitalWrite(izqB, HIGH);
}
