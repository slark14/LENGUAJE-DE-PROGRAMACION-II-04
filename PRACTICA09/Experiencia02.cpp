/**********************************************************************************************
***
ARCHIVO    : EXPERIENCIA02.CPP
AUTOR      : EDWIN QUISPE CHOQUEMAQUE
FECHA      : 04/08/2024
DESCRIPCIÓN: Programa que demuestra el polimorfismo estático mediante sobrecarga.
***********************************************************************************************
**/

#include <iostream>
#include <string>

using namespace std;

class Matematicas {
public:
    int calcularPromedio(int a, int b) {
        return (a + b) / 2;
    }

    double calcularPromedio(double a, double b, double c) {
        return (a + b + c) / 3;
    }

    void calcularPromedio(string nombre) {
        cout << "Hola, " << nombre << endl;
    }
};

int main() {
    Matematicas obj;

    cout << "Promedio de enteros: ";
    cout << obj.calcularPromedio(10, 20) << endl;

    cout << "Promedio de decimales: ";
    cout << obj.calcularPromedio(10.5, 20.5, 30.5) << endl;

    obj.calcularPromedio("Carlos");

    cout << "Conversion implicita: ";
    cout << obj.calcularPromedio(10.8f, 20.2f) << endl;

    return 0;
}