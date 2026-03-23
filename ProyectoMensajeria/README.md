Descripción del Proyecto

Este proyecto es un simulador de un sistema de mensajería desarrollado en C++. Su objetivo principal es aplicar los conceptos fundamentales de las Estructuras de Datos Lineales y No Lineales para resolver problemas reales de logística, como la gestión de rutas entre ciudades, el despacho de paquetes según su prioridad y el cálculo de tiempos y distancias.

El proyecto está estructurado bajo las mejores prácticas de desarrollo en C++, separando la lógica en archivos de cabecera (/include) y código fuente (/src), y utilizando CMake para la automatización de la compilación (Out-of-source build).
Estructuras de Datos Implementadas

Para modular el sistema, se utilizó una estructura de datos específica para cada necesidad del negocio logístico:
1. Gestión de Ciudades y Rutas (Listas Enlazadas)

    Estructura: Lista Enlazada Simple.

    Justificación: Permite agregar ciudades a la ruta de entrega de forma dinámica sin un límite predefinido de tamaño, optimizando el uso de la memoria dinámica (punteros). Se implementaron punteros inicio y fin para optimizar la inserción de nuevas ciudades con una complejidad de O(1).

2. Control de Paquetes y Prioridades (Pilas y Colas)

    Paquetes Normales (Cola - FIFO): Se utilizó la librería <queue> de C++. Los paquetes ordinarios se despachan estrictamente en el orden en que fueron recibidos (First-In, First-Out).

    Paquetes Urgentes (Pila - LIFO): Se utilizó la librería <stack>. Los paquetes marcados como urgentes se apilan, garantizando que el último paquete urgente en llegar sea el primero en subirse al camión de despacho (Last-In, First-Out).

3. Flotilla de Camiones (Cola Circular)

    Estructura: Arreglo estático con lógica circular mediante el operador módulo (%).

    Justificación: Los camiones recorren un circuito cerrado de puntos de control (ej. Monterrey -> Saltillo -> Torreón -> Monterrey). La fórmula (posicionActual + 1) % cantidadPuntos permite que el camión reinicie su recorrido automáticamente sin desbordar el arreglo.

4. Tiempos, Distancias y Rutas de Alta Prioridad (Matrices)

    Matriz 1D (Arreglo): Almacena las distancias lineales directas desde la central hacia cada ciudad.

    Matriz 2D: Una cuadrícula de Origen x Destino que guarda los tiempos estimados de viaje entre cualquier par de ciudades.

    Matriz Dispersa: Diseñada conceptualmente para almacenar rutas de alta prioridad, optimizando la memoria al registrar únicamente las conexiones existentes (evitando guardar miles de ceros).
 Arquitectura del Proyecto
Plaintext

ProyectoMensajeria/
├── CMakeLists.txt        # Configuración del compilador CMake
├── include/              # Archivos de cabecera (.h)
│   ├── Ciudad.h
│   ├── Ruta.h
│   ├── Paquete.h
│   ├── GestorPaquetes.h
│   ├── GestorRutas.h
│   └── SistemaMensajeria.h
├── src/                  # Código fuente (.cpp)
│   ├── main.cpp          # Menú interactivo principal
│   ├── Ciudad.cpp
│   ├── Ruta.cpp
│   ├── Paquete.cpp
│   ├── GestorPaquetes.cpp
│   ├── GestorRutas.cpp
│   └── SistemaMensajeria.cpp
└── build/                # Directorio de compilación (Ejecutable)

 Instalación y Uso (Linux/Ubuntu)

El proyecto requiere g++ y cmake instalados en el sistema.

    Clonar el repositorio:
    Bash

    git clone [URL_DE_TU_REPOSITORIO]
    cd ProyectoMensajeria

    Preparar el entorno de compilación:
    Bash

    mkdir -p build
    cd build
    cmake ..

    Compilar y ejecutar:
    Bash

    make
    ./programa_mensajeria

 Conclusión Técnica

El desarrollo de este simulador demostró empíricamente cómo la elección correcta de una estructura de datos impacta directamente en el rendimiento de un sistema de software. Mientras que un arreglo simple fue suficiente para las distancias estáticas, la flexibilidad de la Lista Enlazada fue indispensable para la ruta dinámica. Asimismo, dominar la división de archivos .h y .cpp mediante CMake representó un salto significativo hacia el desarrollo de software escalable y profesional en C++.


