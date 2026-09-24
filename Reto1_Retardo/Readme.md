# Reto 1: Control de Permanencia por Retardo

El primer reto plantea solucionar un problema crítico de seguridad en sistemas de control de acceso: la puerta no puede cerrarse inmediatamente después de detectar la presencia de un objeto, ya que esto podría causar un impacto o colisión física contra personas o vehículos en movimiento.

El objetivo fue modificar el comportamiento temporal de la lógica de control para garantizar que, una vez activada la apertura, la puerta permanezca abierta durante un intervalo de tiempo seguro de al menos 3 segundos antes de volver a evaluar el entorno.

## Explicación Tecnica y detallada

Para lograr este comportamiento sin alterar el esquema de conexiones físicas, se reestructuró el flujo temporal de la lectura ultrasónica:

1. **Detección Inicial:** El microcontrolador mide la distancia del objeto entrante.
2. **Apertura e Inmovilización Temporal:** Si la lectura es menor o igual a $15\text{ cm}$, se ordena al servomotor desplazarse a la posición de $90^\circ$ (`PUERTA ABIERTA`) y se ejecuta una instrucción de retardo explícito de 3000 milisegundos (`delay(3000)`).
3. **Garantía de Tránsito:** Durante estos 3 segundos, el procesador suspende la ejecución de nuevas lecturas de distancia. La puerta queda congelada en su posición abierta, dando el tiempo necesario para que la persona u objeto cruce el umbral de acceso por completo.
4. **Reevaluación de Entorno:** Cumplido el tiempo de espera, la función vuelve a medir la distancia para verificar si la zona se encuentra despejada; si es así, procede con el cierre seguro de la puerta a $0^\circ$.




## 📁 Archivos en esta carpeta
* **[`Reto 1`](./Reto_1.ino/):** Código fuente con temporización de 3 segundos.
* **[`Videos Reto 1`](./Videos_Reto_1.txt/):** : Demostración en video de la pausa de apertura.

