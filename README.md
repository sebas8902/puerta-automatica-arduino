# Sistema de Control de Puerta Automática con Servomotor y HC-SR04

Este repositorio contiene el desarrollo completo del proyecto de **Puerta Automática** controlada mediante un sensor ultrasónico HC-SR04 y un servomotor SG90 gestionados por un microcontrolador Arduino.

El proyecto está estructurado de forma modular y progresiva, dividido en carpetas independientes para el montaje base y para cada uno de los **3 Retos de Control**:



## 🗂️ Índice de Módulos y Retos

1. **[`Sensor y servomotor`](./Modulo_Base/):** Montaje inicial del circuito, calibración del servomotor y lectura directa de distancia.
2. **[`Reto 1`](./Reto1_Retardo/):** Control de temporización con retardo de 3 segundos para paso seguro.
3. **[`Reto 2`](./Reto2_Histeresis/):** Implementación de margen de tolerancia (zona muerta) para evitar oscilaciones del motor.
4. **[`Reto 3`](./Reto3_Monitoreo_Estados/):** Control continuo de estados y monitoreo en tiempo real por el Monitor Serial.


## Especificaciones de Componentes y Hardware

* **Arduino UNO R3:** Microcontrolador ATmega328P encargada del procesamiento de señales digitales y control PWM.
* **Sensor Ultrasónico HC-SR04:** Transductor que emite ráfagas de alta frecuencia (40 kHz) para el cálculo de distancia por tiempo de vuelo.
* **Servomotor (SG90):** Actuador de posicionamiento angular que controla mecánicamente la apertura (90°) y el cierre (0°) del paso.
* **Protoboard y Conectores Dupont:** Línea de transmisión para la distribución de alimentación a +5V, masa y buses de señales digitales.



## Esquema General de Conexiones

| Componente | Pin del Componente | Pin Arduino UNO | Modo Pin | Función / Descripción |
| :--- | :--- | :--- | :--- | :--- |
| **HC-SR04** | VCC | 5V | Power | Alimentación (+5V) |
| **HC-SR04** | GND | GND | Power | Tierra común |
| **HC-SR04** | Trig | Pin 7 | `OUTPUT` | Disparo del pulso ultrasónico |
| **HC-SR04** | Echo | Pin 6 | `INPUT` | Lectura del eco reflejado |
| **Servomotor** | Señal (Naranja/Amarillo) | Pin 9 | `OUTPUT` (`PWM`) | Control angular ($0^\circ$ a $90^\circ$) |
| **Servomotor** | VCC (Rojo) | 5V | Power | Alimentación (+5V) |
| **Servomotor** | GND (Marrón/Negro) | GND | Power | Tierra común |



## Principio de Funcionamiento Físico y Matemático

El principio de funcionamiento del sistema se basa en la **eco-localización acústica** para detectar la presencia de objetos y en la modulación por ancho de pulso **(PWM)** para mover mecánicamente la puerta.

### 1. Generación y Emisión del Pulso Ultrasónico
El sensor **HC-SR04** cuenta con dos transductores piezoeléctricos: un emisor (Trig) y un receptor (Echo).
* El Arduino genera una señal digital en el pin `Trig` (Pin 7) en estado alto (`HIGH`) durante exactamente **10 microsegundos** ($10\ \mu\text{s}$).
* Al recibir esta instrucción, el circuito interno del HC-SR04 emite una ráfaga de **8 pulsos de ultrasonido a una frecuencia de 40 kHz** (inaudible para el oído humano).

### 2. Propagación y Retorno de la Onda (Tiempo de Vuelo)
* Las ondas sonoras viajan por el aire a la velocidad del sonido ($\approx 343\text{ m/s}$ a $20^\circ\text{C}$).
* Cuando el frente de onda choca contra la superficie de una persona u objeto, se produce un rebote o reflexión (eco).
* El transductor receptor captura el eco de regreso y conmuta inmediatamente el pin `Echo` (Pin 6) a nivel alto (`HIGH`).
* El pin `Echo` permanece en alto durante todo el tiempo transcurrido desde la emisión hasta la recepción de la onda. El Arduino mide la duración de este pulso mediante la función `pulseIn()`.

### 3. Modelo Matemático para el Cálculo de Distancia
Sabiendo que la velocidad del sonido en el aire es de aproximadamente $0.0343\text{ cm/}\mu\text{s}$ ($343\text{ m/s}$), y considerando que el tiempo medido por el pin `Echo` representa el viaje completo de **ida y vuelta** de la onda sonora, la distancia unidireccional entre el sensor y el objeto se calcula con la siguiente fórmula física:

$$\text{Distancia (cm)} = \frac{\text{Tiempo de Eco } (\mu\text{s}) \times 0.0343}{2}$$

### 4. Actuación Mecánica (Servomotor SG90)
Una vez calculada la distancia, el microcontrolador evalúa la posición del objeto frente a los criterios programados (umbrales de $15\text{ cm}$ o lógica de histéresis):
* **Posición CERRADA (0°):** El Arduino transmite una señal PWM al pin de control del servomotor (Pin 9) con un ancho de pulso aproximado de $1\text{ ms}$, manteniendo la talanquera o puerta cruzada bloqueando el acceso.
* **Posición ABIERTA (90°):** Al detectar la presencia dentro del rango válido, el pulso PWM cambia a un ancho de aprox. $1.5\text{ ms}$, rotando el eje interno del servomotor hacia los $90^\circ$ para despejar el área de paso.  
  
## Autores:  

**Estudiantes:**

* Alberto Fandino
* Camilo Martinez
* Martin Castro
* Sebastian De Luque
* Sebastian Martinez
* Steven Santamaria
* Yeimer Ortiz
* Alexandro Leones


**Asignatura:**
* Fundamentos de Mecatrónica


**Institución:**    
* Corporación Universitaria Americana
