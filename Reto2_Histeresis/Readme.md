# Reto 2: Implementación de Histéresis y Zona Muerta

En la práctica real, los sensores de ultrasonido presentan pequeñas fluctuaciones en sus lecturas debido al ruido ambiental o rebotes irregulares del eco. Si un objeto se detiene exactamente a los $15\text{ cm}$, la lectura varía constantemente entre $14.9\text{ cm}$ y $15.1\text{ cm}$, provocando que el servomotor abra y cierre agresivamente en cuestión de milisegundos.

El objetivo del Reto 2 fue implementar un algoritmo de **histéresis de dos umbrales** (también conocido como control por zona muerta) junto con el uso de una **variable de estado booleana**, para estabilizar la respuesta del motor y extender la vida útil del mecanismo.  

## Explicación Técnica y Funcionamiento
En lugar de depender de una sola distancia límite para tomar ambas decisiones (abrir y cerrar), la lógica se dividió en dos umbrales desacoplados controlados por la variable `puertaAbiertaEstado`:

* **Umbral de Apertura ($15\text{ cm}$):** La condición de apertura solo se activa cuando el objeto entra profundamente en la zona de acceso ($\le 15\text{ cm}$). El servomotor se posiciona a $90^\circ$ y la bandera del estado de la puerta conmuta a verdadero (`true`).
* **Zona Muerta o Margen de Tolerancia ($15\text{ cm}$ a $25\text{ cm}$):** Si el objeto retrocede levemente o se detiene entre los $15\text{ cm}$ y los $25\text{ cm}$, la lógica condicional **no realiza ninguna acción**. El sistema recuerda que la puerta está abierta gracias a la variable de estado y mantiene la posición a $90^\circ$ de forma completamente estable.
* **Umbral de Cierre ($25\text{ cm}$):** La orden de cierre a $0^\circ$ solo se emite cuando el objeto se ha alejado formalmente del área de peligro, superando o igualando los $25\text{ cm}$. En este punto la variable de estado conmuta a falso (`false`).

Esta arquitectura elimina cualquier vibración o conmutación errática en la electrónica de potencia del servomotor.

## 📁 Archivos en esta carpeta  

* `Reto_2.ino`: Código fuente con lógica de histéresis.
* `evidencias/video_reto2.mp4`: Demostración en video evaluando los márgenes de 15 cm y 25 cm.


