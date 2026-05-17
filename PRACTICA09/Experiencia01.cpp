/**********************************************************************************************
***
ARCHIVO    : EXPERIENCIA01_ESCENARIO_A.CPP
AUTOR      : EDWIN QUISPE CHOQUEMAQUE
FECHA      : 04/08/2024
DESCRIPCIÓN: Programa que demuestra el enlace temprano o estático.
***********************************************************************************************
**/

#include <iostream>
using namespace std;

class AnimalBase {
public:
    void emitirSonido() {
        cout << "Sonido generico" << endl;
    }
};

class Perro : public AnimalBase {
public:
    void emitirSonido() {
        cout << "Guau" << endl;
    }
};

int main() {
    AnimalBase* ptr = new Perro();

    ptr->emitirSonido();

    delete ptr;

    return 0;
}

/**********************************************************************************************
***
ARCHIVO    : EXPERIENCIA01_ESCENARIO_B.CPP
AUTOR      : EDWIN QUISPE CHOQUEMAQUE
FECHA      : 04/08/2024
DESCRIPCIÓN: Programa que demuestra el enlace tardío o dinámico usando funciones virtuales.
***********************************************************************************************
**/

#include <iostream>
using namespace std;

class AnimalBase {
public:
    virtual void emitirSonido() {
        cout << "Sonido generico" << endl;
    }
};

class Perro : public AnimalBase {
public:
    void emitirSonido() {
        cout << "Guau" << endl;
    }
};

int main() {
    AnimalBase* ptr = new Perro();

    ptr->emitirSonido();

    delete ptr;

    return 0;
}