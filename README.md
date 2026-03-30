# Práctica 2: Sistema de Pinza Robótica

Este proyecto es una aplicación en C++ que analiza datos de un sistema de pinza robótica. Lee datos de sensores, calcula estadísticas básicas y evalúa la estabilidad del sistema.

## Descripción

El programa procesa datos de mediciones de una pinza robótica, incluyendo:
- Valores de galga (sensor de deformación)
- Fuerzas ejercidas por el lado izquierdo y derecho de la pinza

Calcula las medias de estos valores y clasifica cada medición como "ESTABLE" o "INESTABLE" basándose en la diferencia entre las fuerzas izquierda y derecha (umbral: 0.15).

## Archivos

- `pinza.cpp`: Código fuente del programa
- `datos_pinza.txt`: Archivo de entrada con los datos de las mediciones
- `resultado_pinza.txt`: Archivo de salida con los resultados del análisis
- `ejecutar.sh`: Script de bash para compilar y ejecutar el programa

## Requisitos

- Compilador C++ (g++ recomendado)
- Sistema operativo con soporte para bash (Linux, macOS, o Windows con WSL)

## Compilación

Para compilar el programa:

```bash
g++ pinza.cpp -o pinza
```

## Ejecución

Ejecuta el programa directamente:

```bash
./pinza
```

O usa el script incluido:

```bash
./ejecutar.sh
```

El script compila automáticamente y ejecuta el programa.

## Salida

El programa muestra en pantalla:
- Los datos leídos de cada medición
- Las medias calculadas para galga, fuerza izquierda y derecha
- La clasificación de estabilidad para cada muestra

Además, genera un archivo `resultado_pinza.txt` con todos los resultados formateados.

## Formato de Datos

El archivo `datos_pinza.txt` debe contener líneas con el formato:
```
ID GALGA FUERZA_IZQ FUERZA_DER
```

Ejemplo:
```
5118 0.240 1.796 1.752
6574 0.220 1.595 1.676
```

## Notas

- El programa procesa hasta 100 mediciones
- La estabilidad se determina si la diferencia absoluta entre fuerzas izquierda y derecha es ≤ 0.15</content>
<parameter name="filePath">c:\Users\Martin\Documents\martin\2026\UBU\Sistemas operativos\C++\ejercicios_c++\PRACTICA2_MARTIN_PEÑALVA\README.md