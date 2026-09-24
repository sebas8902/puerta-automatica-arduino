# Reto 3: Control Continuo de Estados y Monitoreo Serial

El Reto 3 representa la versión final y más robusta del sistema. Su objetivo fue combinar la estabilidad mecánica del algoritmo de histéresis (Reto 2) con un ciclo de procesamiento de alta velocidad en tiempo real ($100\text{ ms}$), incorporando un sistema de telemetría e impresiones diagnósticas hacia el Monitor Serial del Arduino IDE.

## Explicación Técnica y Funcionamiento
Este desarrollo resuelve el inconveniente de bloquear el procesador con pausas largas. Al eliminar los retardos extensos de software y sustituirlos por un refresco de $100\text{ ms}$, la placa realiza un monitoreo fluido y constante:

1. **Lectura sin Congelamiento:** El microcontrolador mide la distancia 10 veces por segundo. La velocidad de refresco permite responder instantáneamente a la llegada de cualquier persona u objeto.
2. **Evaluación Dinámica de Estados:**
   * Al cruzar los $\le 15\text{ cm}$, el servomotor gira de inmediato a $90^\circ$, asigna `puertaAbiertaEstado = true` e imprime en la consola serial el aviso en texto claro `"PUERTA ABIERTA"`.
   * Mientras el objeto se mantenga en la zona de confort ($15\text{ cm}$ a $25\text{ cm}$), el sistema sigue registrando la distancia en tiempo real pero conserva la puerta abierta sin enviar órdenes redundantes al motor.
   * Al superar los $\ge 25\text{ cm}$, se actualiza la bandera a `false`, se regresa el motor a $0^\circ$ y se notifica el evento `"PUERTA CERRADA"`.
3. **Telemetría para Depuración:** En cada ciclo se envía la cadena de caracteres etiquetada con la medición exacta en centímetros, permitiendo supervisar visualmente el comportamiento del sensor y la respuesta del actuador desde la pantalla de la computadora.


## 📁 Archivos en esta carpeta
* `Reto_3.ino`: Código final optimizado.
* `evidencias/video_reto3.mp4`: Demostración en video con la pantalla del Monitor Serial visible.

