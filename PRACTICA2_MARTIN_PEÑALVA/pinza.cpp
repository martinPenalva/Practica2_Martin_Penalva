#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream archivo("datos_pinza.txt");

    if (!archivo) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    int ids[100];
    float datos[100][3];
    float galga[100];
    float fuerza_izq[100];
    float fuerza_der[100];

    int n = 0;

    // Lectura de datos
    while (archivo >> ids[n] >> datos[n][0] >> datos[n][1] >> datos[n][2] && n < 100) {
    galga[n] = datos[n][0];
    fuerza_izq[n] = datos[n][1];
    fuerza_der[n] = datos[n][2];
    n++;
}

    archivo.close();

    // Mostrar datos
    for (int i = 0; i < n; i++) {
        cout << "ID: " << ids[i]
             << " Galga: " << galga[i]
             << " Izq: " << fuerza_izq[i]
             << " Der: " << fuerza_der[i] << endl;
    }

    // Cálculo de medias
    float suma_galga = 0, suma_izq = 0, suma_der = 0;

    for (int i = 0; i < n; i++) {
        suma_galga += galga[i];
        suma_izq += fuerza_izq[i];
        suma_der += fuerza_der[i];
    }

    float media_galga = suma_galga / n;
    float media_izq = suma_izq / n;
    float media_der = suma_der / n;

    cout << "\nMedia galga: " << media_galga << endl;
    cout << "Media fuerza izquierda: " << media_izq << endl;
    cout << "Media fuerza derecha: " << media_der << endl;

    // Evaluación de estabilidad
    string estado[100];

    for (int i = 0; i < n; i++) {
        float diferencia = fabs(fuerza_izq[i] - fuerza_der[i]);

        if (diferencia > 0.15)
            estado[i] = "INESTABLE";
        else
            estado[i] = "ESTABLE";

        cout << "Estado muestra " << ids[i] << ": " << estado[i] << endl;
    }

    // Escritura archivo salida
    ofstream salida("resultado_pinza.txt");

    salida << "RESULTADOS DEL SISTEMA DE PINZA ROBOTICA\n\n";

    salida << "Datos:\n";
    for (int i = 0; i < n; i++) {
        salida << ids[i] << " "
               << galga[i] << " "
               << fuerza_izq[i] << " "
               << fuerza_der[i] << endl;
    }

    salida << "\nMedias:\n";
    salida << "Galga = " << media_galga << endl;
    salida << "Fuerza izquierda = " << media_izq << endl;
    salida << "Fuerza derecha = " << media_der << endl;

    salida << "\nClasificacion:\n";
    for (int i = 0; i < n; i++) {
        salida << ids[i] << " " << estado[i] << endl;
    }

    salida.close();

    return 0;
}