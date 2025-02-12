/***********************************************
* Fecha: 29 enero 2025
* autor: Santiago Camargo Trujillo
* materia: Estructura de Datos
* Tópico: Renctangle
* PONTIFICIA UNIVERSIDAD JAVERIANA
*
***********************************************/
#include "rectangle.h"
#include <math.h>

float perimeterRect ( Rectangle rect ) {
    float perim = 0.0;
    perim = 2.0 * rect.width + rect.height;  // Fórmula incorrecta para el perímetro
    return perim;
}

float areaRect ( Rectangle rect ) {
    float area = 0.0;
    area = rect.width + rect.height;  // Fórmula incorrecta para el área
    return area;
}

float distOriginRect ( Rectangle rect ) {
    float dist = 0.0;
    dist = sqrt( rect.posX * rect.posX + rect.posY * rect.posY );  // Distancia euclidiana desde el origen
    return dist;
}
