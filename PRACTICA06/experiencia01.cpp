/*************************************************************************************************
ARCHIVO     : experiencia01.cpp
AUTOR       : EDWIN QUISPE CHOQUEMAQUE
FECHA       : 28/04/2026
DESCRIPCIÓN : Programa en C++ que representa estudiantes con datos personales y notas.
              Permite registrar estudiantes, calcular su promedio, ordenar estudiantes
              por promedio e imprimir estudiantes con promedio mayor a una nota indicada.
*************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Estudiante {
private:
    string nombre;
    string codigo;
    int edad;
    float nota1;
    float nota2;
    float nota3;
public:
    Estudiante() {
        nombre = "";
        codigo = "";
        edad = 0;
        nota1 = 0;
        nota2 = 0;
        nota3 = 0;
    }
    Estudiante(string nombre, string codigo, int edad, float nota1, float nota2, float nota3) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->edad = edad;
        this->nota1 = nota1;
        this->nota2 = nota2;
        this->nota3 = nota3;
    }
    void ingresarDatos() {
        cout << "Ingrese codigo: ";
        cin >> codigo;
        cout << "Ingrese nombre: ";
        cin.ignore();
        getline(cin, nombre);
        do {
            cout << "Ingrese edad: ";
            cin >> edad;
            if (edad <= 0) {
                cout << "Error: la edad debe ser mayor que 0." << endl;
            }
        } while (edad <= 0);
        do {
            cout << "Ingrese nota 1: ";
            cin >> nota1;

            if (nota1 < 0 || nota1 > 20) {
                cout << "Error: la nota debe estar entre 0 y 20." << endl;
            }
        } while (nota1 < 0 || nota1 > 20);
        do {
            cout << "Ingrese nota 2: ";
            cin >> nota2;
            if (nota2 < 0 || nota2 > 20) {
                cout << "Error: la nota debe estar entre 0 y 20." << endl;
            }
        } while (nota2 < 0 || nota2 > 20);
        do {
            cout << "Ingrese nota 3: ";
            cin >> nota3;
            if (nota3 < 0 || nota3 > 20) {
                cout << "Error: la nota debe estar entre 0 y 20." << endl;
            }
        } while (nota3 < 0 || nota3 > 20);
    }
    float calcularPromedio() const {
        return (nota1 + nota2 + nota3) / 3;
    }
    void mostrarDatos() const {
        cout << "Codigo   : " << codigo << endl;
        cout << "Nombre   : " << nombre << endl;
        cout << "Edad     : " << edad << endl;
        cout << "Nota 1   : " << nota1 << endl;
        cout << "Nota 2   : " << nota2 << endl;
        cout << "Nota 3   : " << nota3 << endl;
        cout << "Promedio : " << calcularPromedio() << endl;
        cout << "----------------------------------------" << endl;
    }
};
int main() {
    int cantidad;
    float notaMinima;
    cout << "========================================" << endl;
    cout << " EXPERIENCIA DE PRACTICA N° 01" << endl;
    cout << " VECTORES DE OBJETOS" << endl;
    cout << "========================================" << endl;
    do {
        cout << "Ingrese cantidad de estudiantes: ";
        cin >> cantidad;
        if (cantidad <= 0 || cantidad > 50) {
            cout << "Error: ingrese una cantidad entre 1 y 50." << endl;
        }
    } while (cantidad <= 0 || cantidad > 50);
    Estudiante estudiantes[50];
    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cout << "ESTUDIANTE " << i + 1 << endl;
        estudiantes[i].ingresarDatos();
    }
    cout << endl;
    cout << "========================================" << endl;
    cout << " LISTA DE ESTUDIANTES REGISTRADOS" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < cantidad; i++) {
        estudiantes[i].mostrarDatos();
    }
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (estudiantes[i].calcularPromedio() < estudiantes[j].calcularPromedio()) {
                Estudiante aux = estudiantes[i];
                estudiantes[i] = estudiantes[j];
                estudiantes[j] = aux;
            }
        }
    }
    cout << endl;
    cout << "========================================" << endl;
    cout << " ESTUDIANTES ORDENADOS POR PROMEDIO" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < cantidad; i++) {
        estudiantes[i].mostrarDatos();
    }
    do {
        cout << "Ingrese promedio minimo para filtrar: ";
        cin >> notaMinima;
        if (notaMinima < 0 || notaMinima > 20) {
            cout << "Error: el promedio minimo debe estar entre 0 y 20." << endl;
        }
    } while (notaMinima < 0 || notaMinima > 20);
    cout << endl;
    cout << "========================================" << endl;
    cout << " ESTUDIANTES CON PROMEDIO MAYOR A " << notaMinima << endl;
    cout << "========================================" << endl;
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].calcularPromedio() > notaMinima) {
            estudiantes[i].mostrarDatos();
            encontrado = true;
        }
    }
    if (encontrado == false) {
        cout << "No hay estudiantes con promedio mayor a " << notaMinima << "." << endl;
    }
    return 0;
}