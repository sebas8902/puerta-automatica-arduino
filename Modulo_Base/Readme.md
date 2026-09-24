# Módulo Base: Integración del Sensor Ultrasónico y Servomotor


## Descripción General y Objetivos   
En esta etapa inicial se realizó la integración física y lógica entre el sensor ultrasónico HC-SR04 y el servomotor en la placa Arduino UNO. El objetivo principal fue verificar la continuidad del cableado en protoboard, calibrar el ángulo de barrido del servo ($0^\circ$ a $90^\circ$) y establecer un ciclo básico de lectura y respuesta sin intermediación de condiciones complejas.


## Explicación Técnica y Funcionamiento

Durante la ejecución de este montaje base, la placa procesa la distancia en ciclos de muestreo ultra rápidos de $100\text{ ms}$. 

1. **Ciclo de Sensado:** En cada iteración de la función principal, el pin `Trig` genera el disparo de ultrasonido y la función `pulseIn()` captura la duración de la respuesta en microsegundos sobre el pin `Echo`.
2. **Evaluación Umbral:** El programa compara el resultado del cálculo frente al umbral límite de $15\text{ cm}$.
3. **Acción Mecánica Inmediata:**
   * Si un objeto interrumpe el haz a una distancia menor o igual a $15\text{ cm}$, la librería `<Servo.h>` posiciona inmediatamente el motor a $90^\circ$ (marcando la estado de `PUERTA ABIERTA`).
   * Tan pronto como el objeto se desplaza fuera del rango de los $15\text{ cm}$, el motor regresa en la siguiente iteración a $0^\circ$ (marcando el estado de `PUERTA CERRADA`).

Esta versión permite confirmar la precisión del sensor HC-SR04, pero expone la limitación física del sistema: si un objeto pasa demasiado rápido o se detiene justo en el borde de los $15\text{ cm}$, el servomotor reacciona con movimientos bruscos e inestables.   

## 📂 Archivo del Programa         
* **[`Codigo Base`](./Base.ino/):** Código ejecutable en Arduino IDE.
* **[`Imagenes`](./Evidencias/Montaje.png/):** Foto del montaje físico.
* **[`Video`](./Evidencias/Video_modulo_base.txt/):** Demostración en video.

