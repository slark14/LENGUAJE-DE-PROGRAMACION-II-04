#include <iostream>
using namespace std;

class Circulo {
private:
    float radio;
    float diametro;
public:
    Circulo() {
        radio = 0;
        diametro = 0;
    }
    Circulo(float radio) {
        this->radio = radio;
        this->diametro = radio * 2;
    }
    void ingresarDatos() {
        do {
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            if (radio <= 0) {
                cout << "Error: el radio debe ser mayor que 0." << endl;
            }
        } while (radio <= 0);
        diametro = radio * 2;
    }
    void mostrarDatos() {
        cout << "Radio    : " << radio << endl;
        cout << "Diametro : " << diametro << endl;
    }
    friend float calcularArea(Circulo c);
};
float calcularArea(Circulo c) {
    float pi = 3.1416;
    return pi * c.radio * c.radio;
}
int main() {
    int cantidad;
    cout << "========================================" << endl;
    cout << " EXPERIENCIA DE PRACTICA N° 02" << endl;
    cout << " FUNCIONES Y CLASES AMIGAS" << endl;
    cout << "========================================" << endl;
    do {
        cout << "Ingrese la cantidad de circulos: ";
        cin >> cantidad;
        if (cantidad <= 0 || cantidad > 50) {
            cout << "Error: ingrese una cantidad entre 1 y 50." << endl;
        }
    } while (cantidad <= 0 || cantidad > 50);
    Circulo circulos[50];
    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cout << "CIRCULO " << i + 1 << endl;
        circulos[i].ingresarDatos();
    }
    cout << endl;
    cout << "========================================" << endl;
    cout << " AREAS DE LOS CIRCULOS" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cout << "CIRCULO " << i + 1 << endl;
        circulos[i].mostrarDatos();
        cout << "Area     : " << calcularArea(circulos[i]) << endl;
        cout << "----------------------------------------" << endl;
    }
    return 0;
}