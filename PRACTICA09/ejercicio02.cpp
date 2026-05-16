/***********************************************************************
 ARCHIVO     : ejercicio02_ecosistema.cpp
 PRACTICA    : 09 - Polimorfismo en la Programacion Orientada a Objetos
 DESCRIPCION : Simulador de Ecosistema con herencia multiple.
               Implementa:
               - Clase abstracta Animal con metodo virtual alimentarse()
               - Interfaz pura IAcuatico con metodo nadar()
               - Interfaz pura IVolador con metodo volar()
               - Clases concretas: Pato (Animal+IAcuatico+IVolador),
                 Leon (Animal), Salmon (Animal+IAcuatico),
                 Aguila (Animal+IVolador)
               - dynamic_cast seguro para verificar capacidades
               - Destructores virtuales para gestion correcta de memoria
 ***********************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ── INTERFAZ PURA: IAcuatico ─────────────────────────────────────────────
// Contrato: cualquier clase que lo implemente sabe nadar
class IAcuatico {
public:
    virtual void nadar() = 0;           // Metodo virtual puro
    virtual ~IAcuatico() = default;     // Destructor virtual (buena practica)
};

// ── INTERFAZ PURA: IVolador ──────────────────────────────────────────────
// Contrato: cualquier clase que lo implemente sabe volar
class IVolador {
public:
    virtual void volar() = 0;           // Metodo virtual puro
    virtual ~IVolador() = default;      // Destructor virtual (buena practica)
};

// ── CLASE ABSTRACTA: Animal ──────────────────────────────────────────────
// Base de la jerarquia. No se puede instanciar directamente.
class Animal {
protected:
    string nombre;      // Nombre del animal (accesible por derivadas)
    string especie;     // Especie del animal

public:
    Animal(const string& nom, const string& esp)
        : nombre(nom), especie(esp) {}

    // Metodo virtual puro: cada animal debe definir como se alimenta
    virtual void alimentarse() = 0;

    // Metodo virtual con implementacion base (puede refinarse)
    virtual void mostrarInfo() const {
        cout << "  [" << especie << "] " << nombre << endl;
    }

    // Destructor virtual: esencial para liberar memoria correctamente
    // cuando se elimina un objeto derivado a traves de un puntero base
    virtual ~Animal() {
        cout << "  ~Animal: " << nombre << " eliminado correctamente." << endl;
    }
};

// ── CLASE CONCRETA: Leon ─────────────────────────────────────────────────
// Hereda solo de Animal. No nada, no vuela.
class Leon : public Animal {
public:
    Leon(const string& nom)
        : Animal(nom, "Leon") {}

    // Reemplazo total (override puro): implementacion especifica del leon
    void alimentarse() override {
        cout << "  " << nombre << " (Leon) caza una cebra en la sabana." << endl;
    }

    ~Leon() override = default;
};

// ── CLASE CONCRETA: Salmon ───────────────────────────────────────────────
// Hereda de Animal e IAcuatico. No vuela.
class Salmon : public Animal, public IAcuatico {
public:
    Salmon(const string& nom)
        : Animal(nom, "Salmon") {}

    void alimentarse() override {
        cout << "  " << nombre << " (Salmon) atrapa insectos en el rio." << endl;
    }

    // Implementacion del contrato IAcuatico
    void nadar() override {
        cout << "  " << nombre << " (Salmon) nada contracorriente rio arriba." << endl;
    }

    ~Salmon() override = default;
};

// ── CLASE CONCRETA: Aguila ───────────────────────────────────────────────
// Hereda de Animal e IVolador. No nada.
class Aguila : public Animal, public IVolador {
public:
    Aguila(const string& nom)
        : Animal(nom, "Aguila") {}

    void alimentarse() override {
        cout << "  " << nombre << " (Aguila) caza un raton en picada." << endl;
    }

    // Implementacion del contrato IVolador
    void volar() override {
        cout << "  " << nombre << " (Aguila) planea a gran altitud sobre las montanas." << endl;
    }

    ~Aguila() override = default;
};

// ── CLASE CONCRETA: Pato ─────────────────────────────────────────────────
// Herencia multiple: Animal + IAcuatico + IVolador
// Puede nadar Y volar, demostrando la potencia de la herencia multiple
class Pato : public Animal, public IAcuatico, public IVolador {
public:
    Pato(const string& nom)
        : Animal(nom, "Pato") {}

    void alimentarse() override {
        cout << "  " << nombre << " (Pato) busca semillas y pequenos peces en el lago." << endl;
    }

    // Implementa el contrato IAcuatico
    void nadar() override {
        cout << "  " << nombre << " (Pato) nada graciosamente en el lago." << endl;
    }

    // Implementa el contrato IVolador
    void volar() override {
        cout << "  " << nombre << " (Pato) alza el vuelo sobre los juncos." << endl;
    }

    ~Pato() override = default;
};

// ── FUNCION AUXILIAR: verificarHabilidades ───────────────────────────────
// Usa dynamic_cast seguro para detectar en tiempo de ejecucion
// si el animal implementa IAcuatico y/o IVolador
void verificarHabilidades(Animal* animal) {
    cout << "  Habilidades especiales:" << endl;

    // dynamic_cast<IAcuatico*>: devuelve nullptr si el objeto NO implementa IAcuatico
    IAcuatico* acuatico = dynamic_cast<IAcuatico*>(animal);
    if (acuatico != nullptr) {
        acuatico->nadar();  // Llamada polimorfica segura
    } else {
        cout << "    -> No puede nadar." << endl;
    }

    // dynamic_cast<IVolador*>: devuelve nullptr si el objeto NO implementa IVolador
    IVolador* volador = dynamic_cast<IVolador*>(animal);
    if (volador != nullptr) {
        volador->volar();   // Llamada polimorfica segura
    } else {
        cout << "    -> No puede volar." << endl;
    }
}

// ── PROGRAMA PRINCIPAL ───────────────────────────────────────────────────
int main() {
    cout << "========================================================" << endl;
    cout << "   EJERCICIO 2: SIMULADOR DE ECOSISTEMA                 " << endl;
    cout << "   Polimorfismo, Herencia Multiple y dynamic_cast        " << endl;
    cout << "========================================================" << endl;

    // Arreglo polimorfico de punteros a la clase base Animal
    // Cada elemento puede ser de cualquier subclase
    vector<Animal*> ecosistema;
    ecosistema.push_back(new Leon("Simba"));
    ecosistema.push_back(new Salmon("Nemo"));
    ecosistema.push_back(new Aguila("Zeus"));
    ecosistema.push_back(new Pato("Donald"));

    // ── 1) Iteracion polimorfica: alimentarse() ──────────────────────
    cout << "\n--- ESTIMULO: Hora de alimentarse ---" << endl;
    for (Animal* animal : ecosistema) {
        animal->alimentarse();  // Late binding: cada objeto responde a su manera
    }

    // ── 2) dynamic_cast para verificar habilidades de cada animal ────
    cout << "\n--- VERIFICACION DE HABILIDADES (via dynamic_cast) ---" << endl;
    for (Animal* animal : ecosistema) {
        animal->mostrarInfo();
        verificarHabilidades(animal);
        cout << endl;
    }

    // ── 3) Liberacion de memoria (destructores virtuales actuan) ─────
    cout << "--- LIBERANDO MEMORIA DEL ECOSISTEMA ---" << endl;
    for (Animal* animal : ecosistema) {
        delete animal;  // El destructor virtual garantiza la destruccion correcta
    }
    ecosistema.clear();

    cout << "\n========================================================" << endl;
    cout << "   Simulacion finalizada correctamente." << endl;
    cout << "========================================================" << endl;

    return 0;
}
