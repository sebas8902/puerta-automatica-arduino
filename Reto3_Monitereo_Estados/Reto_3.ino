#include <Servo.h>

// Pines del sensor
const int trig = 7;
const int echo = 6;

// Pin del servo
const int pinServo = 9;

// Distancias
const int distanciaApertura = 15;
const int distanciaCierre = 25;

// Posiciones del servo
const int puertaCerrada = 0;
const int puertaAbierta = 90;

// Estado de la puerta
bool puertaAbiertaEstado = false;

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

  // Generar pulso ultrasónico
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  // Medir tiempo del eco
  long tiempo = pulseIn(echo, HIGH);

  // Calcular distancia
  float distancia = tiempo * 0.034 / 2;

  // Mostrar distancia
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // -----------------------------
  // CONTROL DE LA PUERTA
  // -----------------------------

  if (distancia <= distanciaApertura) {

    puerta.write(puertaAbierta);

    puertaAbiertaEstado = true;

    Serial.println("PUERTA ABIERTA");

  }
  else if (distancia >= distanciaCierre) {

    puerta.write(puertaCerrada);

    puertaAbiertaEstado = false;

    Serial.println("PUERTA CERRADA");

  }

  delay(100);
}