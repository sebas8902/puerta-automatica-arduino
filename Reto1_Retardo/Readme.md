# Reto 1: Control de Permanencia por Retardo

## Objetivo
Resolver el problema de cierres prematuros o abruptos de la puerta cuando una persona o vehículo está atravesando el umbral de acceso.

## Explicación Técnica y Funcionamiento
1. Se mantiene la lectura básica de distancia con umbral de $15\text{ cm}$.
2. Se modifica la temporización al final del ciclo incorporando una pausa de `delay(3000)` ($3\text{ segundos}$).
3. **Comportamiento:** Al detectar un objeto a $\le 15\text{ cm}$, la puerta se abre inmediatamente a $90^\circ$ y el microcontrolador entra en pausa durante 3 segundos enteros.
4. Esto garantiza un tiempo de paso completamente seguro sin que el mecanismo intente cerrarse interrumpiendo el tránsito.

## 📁 Archivos en esta carpeta
* `Reto_1.ino`: Código fuente con temporización de 3 segundos.
* `evidencias/video_reto1.mp4`: Demostración en video de la pausa de apertura.
