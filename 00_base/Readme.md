# Módulo Base: Integración del Sensor Ultrasónico y Servomotor

## Objetivo
Establecer la comunicación básica entre el sensor HC-SR04 y el servomotor en Arduino, verificando que la puerta responda de forma directa ante la presencia de un objeto a corta distancia.

## Explicación Técnica y Funcionamiento
1. Se inicializan la librería `Servo.h` y la comunicación serial a 9600 baudios.
2. El sensor envía un pulso de $10\ \mu\text{s}$ por el pin `Trig` (Pin 7).
3. El pin `Echo` (Pin 6) mide la duración del eco en microsegundos y calcula la distancia con la fórmula:
   $$\text{Distancia (cm)} = \frac{\text{Tiempo } \times 0.034}{2}$$
4. Si la distancia es $\le 15\text{ cm}$, el servomotor gira a $90^\circ$ (`PUERTA ABIERTA`).
5. En caso contrario, se mantiene en $0^\circ$ (`PUERTA CERRADA`).
6. Posee un tiempo de muestreo corto de $100\text{ ms}$.

## 📁 Archivos en esta carpeta
* `Base.ino`: Código ejecutable en Arduino IDE.
* `evidencias/montaje.jpg`: Foto del montaje físico.
* `evidencias/video_base.mp4`: Demostración en video.
