/***********************************************
* Fecha: 29 enero 2025
* autor: Santiago Camargo Trujillo
* materia: Estructura de Datos
* Tópico: Renctangle
* PONTIFICIA UNIVERSIDAD JAVERIANA
*
***********************************************/

#include <iostream>
#include "rectangle.h"

using namespace std;

int main () {
    Rectangle rect1;  // Declaración de una variable de tipo Rectangle llamada rect1
    int a, b;

    // Solicitar al usuario las coordenadas y dimensiones del rectángulo
    cout << "Ingrese coordenada X de la posicion del rectangulo: ";
    cin >> rect1.posX;
    cout << "Ingrese coordenada Y de la posicion del rectangulo: ";
    cin >> rect1.posY;
    cout << "Ingrese ancho del rectangulo: ";
    cin >> rect1.width;
    cout << "Ingrese alto del rectangulo: ";
    cin >> rect1.height;

    // Mostrar los resultados del cálculo de perímetro, área y distancia
    cout << "\nPerimetro del rectangulo: " << perimeterRect( rect1 ) << endl;
    cout << "Area del rectangulo: " << areaRect( rect1 ) << endl;
    cout << "Distancia del rectangulo al origen de coordenadas: " << distOriginRect( rect1 ) << endl;

    return 0;  // Fin de la ejecución del programa
}
