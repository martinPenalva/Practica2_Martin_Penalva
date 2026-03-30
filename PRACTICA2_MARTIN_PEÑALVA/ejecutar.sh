#!/bin/bash

echo "===== INICIO DEL SCRIPT ====="

# 1. Compilar el programa
echo "Compilando programa..."
g++ pinza.cpp -o pinza

# Comprobar si la compilación fue correcta
if [ $? -ne 0 ]; then
    echo "Error en la compilación"
    exit 1
fi

echo "Compilación correcta"

# 2. Ejecutar en segundo plano
echo "Ejecutando programa en segundo plano..."
./pinza &

PID=$!

echo "Proceso lanzado con PID: $PID"

# 3. Esperar a que termine
wait $PID

echo "Proceso finalizado (wait)"

# 4. Comprobar si sigue activo
if ps -p $PID > /dev/null
then
    echo "El proceso sigue activo. Finalizando..."
    
    # 5. Finalización controlada
    kill $PID
    
    echo "Proceso terminado manualmente"
else
    echo "El proceso ya terminó correctamente"
fi

echo "===== FIN DEL SCRIPT ====="