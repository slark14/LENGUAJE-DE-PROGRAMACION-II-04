/*************************************************************************************************
ARCHIVO     : experiencia_estudiante.cpp
AUTOR       : GERARDO MOGROVEJO LIMACHE
FECHA       : 29/04/2026
DESCRIPCIÓN : Programa en C++ que registra estudiantes utilizando un arreglo de objetos.
              Permite ingresar nombre y promedio desde teclado y mostrar los datos.
*************************************************************************************************/


#include <iostream>
#include <string>
using namespace std;


class Estudiante {
private:
    string nombre;
    float promedio;


public:
    // Constructor que ingresa datos desde teclado
    Estudiante() {
        cout << "Ingrese nombre del estudiante: ";
        cin.ignore();
        getline(cin, nombre);


        cout << "Ingrese promedio: ";
        cin >> promedio;
    }


    // Mostrar datos
    void mostrar() const {
        cout << "Nombre   : " << nombre << endl;
        cout << "Promedio : " << promedio << endl;
    }
};


int main() {
    Estudiante estudiantes[3];


    cout << "========================================" << endl;
    cout << " REGISTRO DE ESTUDIANTES" << endl;
    cout << "========================================" << endl;


    // Mostrar datos
    cout << "\n===== LISTA DE ESTUDIANTES =====" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        estudiantes[i].mostrar();
    }


    return 0;
}
