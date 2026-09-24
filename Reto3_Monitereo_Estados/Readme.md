# Reto 3: Mantenimiento de Estado y Monitoreo Serial

## Objetivo
Integrar el control por histéresis con respuesta fluida en tiempo real ($100\text{ ms}$ de muestreo) y telemetría continua en pantalla.

## Explicación Técnica y Funcionamiento
1. Combina la lógica de zona muerta ($15\text{ cm}$ para abrir y $25\text{ cm}$ para cerrar) eliminando delais extensos.
2. La variable booleana `puertaAbiertaEstado` conserva de forma eficiente la posición del mecanismo en cada iteración del ciclo.
3. En cada intervalo de $100\text{ ms}$, transmite por la consola del **Monitor Serial** la distancia exacta calculada en centímetros y la notificación del estado del sistema (`PUERTA ABIERTA` / `PUERTA CERRADA`).
4. Proporciona una respuesta suave en el hardware junto con visibilidad completa para depuración y control industrial.

## 📁 Archivos en esta carpeta
* `Reto_3.ino`: Código final optimizado.
* `evidencias/video_reto3.mp4`: Demostración en video con la pantalla del Monitor Serial visible.
