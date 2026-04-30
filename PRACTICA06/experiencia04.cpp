/*************************************************************************************************
ARCHIVO     : experiencia04.cpp
AUTOR       : GERARDO MOGROVEJO LIMACHE
FECHA       : 29/04/2026
DESCRIPCIÓN : Programa en C++ que representa un vector en 2D y permite realizar
              operaciones de suma y resta mediante sobrecarga de operadores.
*************************************************************************************************/


#include <iostream>
using namespace std;


class Vector2D {
private:
    float x;
    float y;


public:
    // Constructor por defecto
    Vector2D() {
        x = 0;
        y = 0;
    }


    // Constructor con parámetros
    Vector2D(float x, float y) {
        this->x = x;
        this->y = y;
    }


    // Ingresar datos
    void ingresarDatos() {
        cout << "Ingrese componente X: ";
        cin >> x;
        cout << "Ingrese componente Y: ";
        cin >> y;
    }


    // Mostrar datos
    void mostrar() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }


    // Sobrecarga del operador +
    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }


    // Sobrecarga del operador -
    Vector2D operator-(const Vector2D& otro) const {
        return Vector2D(x - otro.x, y - otro.y);
    }
};


int main() {
    Vector2D v1, v2, suma, resta;
    int opcion;


    cout << "========================================" << endl;
    cout << " EXPERIENCIA DE PRACTICA N° 04" << endl;
    cout << " SOBRECARGA DE OPERADORES" << endl;
    cout << "========================================" << endl;


    cout << "\nIngrese datos del vector 1:" << endl;
    v1.ingresarDatos();


    cout << "\nIngrese datos del vector 2:" << endl;
    v2.ingresarDatos();


    do {
        cout << "\n=========== MENU ===========" << endl;
        cout << "1. Sumar vectores" << endl;
        cout << "2. Restar vectores" << endl;
        cout << "3. Mostrar vectores" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;


        switch (opcion) {
        case 1:
            suma = v1 + v2;
            cout << "Resultado de la suma: ";
            suma.mostrar();
            break;


        case 2:
            resta = v1 - v2;
            cout << "Resultado de la resta: ";
            resta.mostrar();
            break;


        case 3:
            cout << "Vector 1: ";
            v1.mostrar();
            cout << "Vector 2: ";
            v2.mostrar();
            break;


        case 4:
            cout << "Saliendo del programa..." << endl;
            break;


        default:
            cout << "Error: opcion no valida." << endl;
            break;
        }


    } while (opcion != 4);


    return 0;
}
