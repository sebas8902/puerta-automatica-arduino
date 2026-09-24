#include <Servo.h>

// Pines del sensor
const int trig = 7;
const int echo = 6;

// Pin del servo
const int pinServo = 9;

// Distancia para abrir la puerta
const int distanciaApertura = 15;

// Posiciones del servo
const int puertaCerrada = 0;
const int puertaAbierta = 90;

// Crear servo
Servo puerta;

void setup() {

  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  puerta.attach(pinServo);

  // La puerta inicia cerrada
  puerta.write(puertaCerrada);
}

void loop() {

  // -----------------------------
  // Generar pulso ultrasónico
  // -----------------------------

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  // -----------------------------
  // Medir tiempo del eco
  // -----------------------------

  long tiempo = pulseIn(echo, HIGH);

  // -----------------------------
  // Calcular distancia
  // -----------------------------

  float distancia = tiempo * 0.034 / 2;

  // Mostrar distancia
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // -----------------------------
  // Controlar puerta
  // -----------------------------

  if (distancia <= distanciaApertura) {

    puerta.write(puertaAbierta);

    Serial.println("PUERTA ABIERTA");

  } else {

    puerta.write(puertaCerrada);

    Serial.println("PUERTA CERRADA");
  }

  delay(100);
}

