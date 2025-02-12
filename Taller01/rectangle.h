/***********************************************
* Fecha: 29 enero 2025
* autor: Santiago Camargo Trujillo
* materia: Estructura de Datos
* Tópico: Renctangle
* PONTIFICIA UNIVERSIDAD JAVERIANA
*
***********************************************/
#ifndef RECTANGLE_H
#define RECTANGLE_H

struct Rectangle {
    float posX;  // Coordenada X de la posición del rectángulo
    float posY;  // Coordenada Y de la posición del rectángulo
    float width; // Ancho del rectángulo
    float height; // Alto del rectángulo
};

float perimeterRect(Rectangle rect);
float areaRect(Rectangle rect);
float distOriginRect(Rectangle rect);

#endif
