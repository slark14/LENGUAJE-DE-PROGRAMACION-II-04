/**********************************************************************************************
***
ARCHIVO    : EXPERIENCIA03.CPP
AUTOR      : EDWIN QUISPE CHOQUEMAQUE
FECHA      : 04/08/2024
DESCRIPCIÓN: Programa que demuestra jerarquías y polimorfismo dinámico.
***********************************************************************************************
**/

#include <iostream>
#include <vector>

using namespace std;

class Figura {
public:
    virtual void dibujar() = 0;
    virtual double calcularArea() = 0;
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) {
        radio = r;
    }

    void dibujar() {
        cout << "Dibujando circulo" << endl;
    }

    double calcularArea() {
        return 3.1416 * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double a) {
        base = b;
        altura = a;
    }

    void dibujar() {
        cout << "Dibujando rectangulo" << endl;
    }

    double calcularArea() {
        return base * altura;
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double a) {
        base = b;
        altura = a;
    }

    void dibujar() {
        cout << "Dibujando triangulo" << endl;
    }

    double calcularArea() {
        return (base * altura) / 2;
    }
};

int main() {
    vector<Figura*> figuras;

    figuras.push_back(new Circulo(5));
    figuras.push_back(new Rectangulo(4, 6));
    figuras.push_back(new Triangulo(3, 8));

    for (int i = 0; i < figuras.size(); i++) {
        figuras[i]->dibujar();

        cout << "Area: " << figuras[i]->calcularArea() << endl;
        cout << endl;
    }

    for (int i = 0; i < figuras.size(); i++) {
        delete figuras[i];
    }

    return 0;
}