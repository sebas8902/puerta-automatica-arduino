# Sistema de Control de Puerta Automática con Servomotor y HC-SR04

Este repositorio contiene el desarrollo completo del proyecto de **Puerta Automática** controlada mediante un sensor ultrasónico HC-SR04 y un servomotor SG90 gestionados por un microcontrolador Arduino.

El proyecto está estructurado de forma modular y progresiva, dividido en carpetas independientes para el montaje base y para cada uno de los **3 Retos de Control**:



## 🗂️ Índice de Módulos y Retos

1. **[`/00_Base`](./00_Base/):** Montaje inicial del circuito, calibración del servomotor y lectura directa de distancia.
2. **[`/01_Reto1_Retardo`](./01_Reto1_Retardo/):** Control de temporización con retardo de 3 segundos para paso seguro.
3. **[`/02_Reto2_Histeresis`](./02_Reto2_Histeresis/):** Implementación de margen de tolerancia (zona muerta) para evitar oscilaciones del motor.
4. **[`/03_Reto3_Monitoreo_Estados`](./03_Reto3_Monitoreo_Estados/):** Control continuo de estados y monitoreo en tiempo real por el Monitor Serial.



## 🔌 Esquema General de Conexiones

| Componente | Pin del Componente | Pin Arduino UNO | Modo Pin | Función / Descripción |
| :--- | :--- | :--- | :--- | :--- |
| **HC-SR04** | VCC | 5V | Power | Alimentación (+5V) |
| **HC-SR04** | GND | GND | Power | Tierra común |
| **HC-SR04** | Trig | Pin 7 | `OUTPUT` | Disparo del pulso ultrasónico |
| **HC-SR04** | Echo | Pin 6 | `INPUT` | Lectura del eco reflejado |
| **Servomotor** | Señal (Naranja/Amarillo) | Pin 9 | `OUTPUT` (`PWM`) | Control angular ($0^\circ$ a $90^\circ$) |
| **Servomotor** | VCC (Rojo) | 5V | Power | Alimentación (+5V) |
| **Servomotor** | GND (Marrón/Negro) | GND | Power | Tierra común |




## 👥 Integrantes
* **Estudiante:** Sebastian DeLuque Garcia
* **Asignatura:** Fundamentos de Mecatrónica / Sistemas
* **Institución:** Corporación Universitaria Americana
