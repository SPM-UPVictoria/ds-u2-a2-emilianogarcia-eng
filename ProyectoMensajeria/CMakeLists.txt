# Indicamos la versión mínima requerida de CMake
cmake_minimum_required(VERSION 3.10)

# Le damos un nombre al proyecto
project(SistemaMensajeria)

# 1. Le decimos a CMake dónde encontrar los archivos .h (cabeceras)
include_directories(include)

# 2. Le decimos que busque todos los archivos .cpp dentro de la carpeta src
file(GLOB SOURCES "src/*.cpp")

# 3. Le ordenamos crear un ejecutable llamado "programa_mensajeria" uniendo todo
add_executable(programa_mensajeria ${SOURCES})
