# Reto 2: Control con Histéresis / Zona Muerta

## Objetivo
Eliminar el rebote o la vibración continua del servomotor cuando un objeto se detiene en el límite del sensor (alrededor de los $15\text{ cm}$).

## Explicación Técnica y Funcionamiento
Se diseña un algoritmo de **histéresis** que separa la distancia de apertura de la distancia de cierre, apoyándose en la variable booleana `puertaAbiertaEstado`:

* **Umbral de Apertura (`distanciaApertura`):** Se activa solo cuando el objeto está a $\le 15\text{ cm}$. La puerta se abre a $90^\circ$ y la variable pasa a `true`.
* **Zona Muerta:** Si el objeto se mueve entre los $15\text{ cm}$ y los $25\text{ cm}$, la puerta **no cambia de posición** y se mantiene abierta.
* **Umbral de Cierre (`distanciaCierre`):** La puerta solo vuelve a $0^\circ$ (`PUERTA CERRADA`) cuando el objeto se aleja a una distancia $\ge 25\text{ cm}$, cambiando la variable a `false`.

Esto evita que el motor oscile entre abrir y cerrar ante variaciones mínimas de lectura.

## 📁 Archivos en esta carpeta
* `Reto_2.ino`: Código fuente con lógica de histéresis.
* `evidencias/video_reto2.mp4`: Demostración en video evaluando los márgenes de 15 cm y 25 cm.
