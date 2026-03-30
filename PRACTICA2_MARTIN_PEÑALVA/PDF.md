# Informe de la Práctica 2: Sistema de Pinza Robótica

## 1. Funcionamiento del programa (pinza.cpp)
El programa desarrollado en C++ tiene como objetivo procesar y analizar datos de telemetría de una pinza robótica. Su funcionamiento se divide en las siguientes fases:
1. **Lectura de datos**: Abre el archivo `datos_pinza.txt` y carga hasta 100 registros que incluyen el ID de la muestra, valor de la galga y fuerzas de las pinzas izquierda y derecha.
2. **Procesamiento Estadístico**: Calcula la media aritmética de cada una de las tres magnitudes medidas.
3. **Análisis de Estabilidad**: Para cada muestra, calcula la diferencia absoluta entre la fuerza izquierda y derecha. Si la diferencia es superior a **0.15**, la muestra se clasifica como **INESTABLE**; de lo contrario, es **ESTABLE**.
4. **Salida de Resultados**: Genera el archivo `resultado_pinza.txt` con el resumen de los datos, las medias calculadas y la clasificación de estabilidad de cada toma.

## 2. Explicación del script en Bash (ejecutar.sh)
El script automatiza el ciclo de vida de la ejecución del programa:
- **Compilación**: Utiliza `g++` para compilar `pinza.cpp` y generar el ejecutable.
- **Ejecución en segundo plano**: Lanza el programa `./pinza &` para que se ejecute de forma asíncrona.
- **Control de procesos**: Captura el PID del proceso lanzado y utiliza el comando `wait` para sincronizar la finalización del script con la del programa.
- **Verificación**: Comprueba si el proceso sigue activo tras el `wait` y, en caso afirmativo, realiza una finalización controlada mediante el comando `kill`.

## 3. Capturas de pantalla de ejecución
Para documentar la ejecución correcta del sistema, se deben incluir las siguientes capturas:

1. **Ejecución del script en la terminal**: Captura que muestre la ejecución del comando `./ejecutar.sh`, incluyendo los mensajes de "Compilación correcta", el PID asignado al proceso en segundo plano y el mensaje final de "Proceso finalizado".
2. **Archivo de entrada (datos_pinza.txt)**: Captura de las primeras líneas del archivo de datos para verificar el formato de entrada.
3. **Archivo de resultados (resultado_pinza.txt)**: Captura del archivo generado donde se visualicen las medias calculadas y la clasificación de estabilidad (ESTABLE/INESTABLE).
4. **Código fuente en el IDE**: Captura del entorno de desarrollo mostrando el código de `pinza.cpp` y `ejecutar.sh`.

## 4. Interpretación de resultados
Los resultados permiten identificar fallos en el agarre de la pinza robótica. Una clasificación de **INESTABLE** indica una asimetría en la fuerza aplicada que podría provocar la caída o el daño del objeto manipulado. Las medias proporcionan una visión global del comportamiento del sensor de la galga y la presión nominal del sistema.

## 5. Enlace al repositorio Git
[Repositorio del Proyecto - GitHub](https://github.com/usuario/practica2-pinza-robotica)
