/***********************************************************************
 ARCHIVO     : ejercicio03_nomina.cpp
 PRACTICA    : 09 - Polimorfismo en la Programacion Orientada a Objetos
 DESCRIPCION : Sistema de Nomina Polimorfico.
               Implementa:
               - Clase abstracta Empleado con atributos protegidos
                 (nombre, ID) y metodos virtuales puros
               - EmpleadoAsalariado: sueldo fijo semanal
               - EmpleadoPorHoras: tarifa * horas + horas extra
               - EmpleadoComision: porcentaje sobre ventas brutas
               - GestorNomina con vector<Empleado*> y reporte polimorfico
               - Destructores virtuales para gestion correcta de memoria
 ***********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ── CLASE ABSTRACTA: Empleado ────────────────────────────────────────────
// Define el contrato que todas las categorias laborales deben cumplir.
// No se puede instanciar directamente (tiene metodos virtuales puros).
class Empleado {
protected:
    string nombre;      // Nombre del empleado (accesible por derivadas)
    string id;          // Identificador unico del empleado

public:
    Empleado(const string& nom, const string& identificador)
        : nombre(nom), id(identificador) {}

    // Metodo virtual puro: cada tipo de empleado calcula su pago de forma distinta
    virtual float calcularPago() const = 0;

    // Metodo virtual puro: cada tipo muestra su propio reporte
    virtual void mostrarReporte() const = 0;

    // Getters para que GestorNomina pueda acceder a los datos
    string getNombre() const { return nombre; }
    string getId()     const { return id; }

    // Destructor virtual: obligatorio en clases base polimorfica
    // Sin esto, "delete ptrBase;" no llamaria al destructor de la clase derivada
    virtual ~Empleado() = default;
};

// ── CLASE DERIVADA: EmpleadoAsalariado ───────────────────────────────────
// Recibe un sueldo fijo semanal independiente de las horas trabajadas.
class EmpleadoAsalariado : public Empleado {
private:
    float sueldoSemanal;    // Monto fijo de pago por semana

public:
    EmpleadoAsalariado(const string& nom, const string& id, float sueldo)
        : Empleado(nom, id), sueldoSemanal(sueldo > 0 ? sueldo : 0.0f) {}

    // Reemplazo total: el pago es simplemente el sueldo fijo
    float calcularPago() const override {
        return sueldoSemanal;
    }

    void mostrarReporte() const override {
        cout << "  [ASALARIADO] ID: " << id
             << " | Nombre: " << nombre << endl;
        cout << "    Sueldo semanal fijo : S/. "
             << fixed << setprecision(2) << sueldoSemanal << endl;
        cout << "    PAGO CALCULADO      : S/. "
             << fixed << setprecision(2) << calcularPago() << endl;
    }

    ~EmpleadoAsalariado() override = default;
};

// ── CLASE DERIVADA: EmpleadoPorHoras ─────────────────────────────────────
// Cobra por hora trabajada; las horas extra (>40h/sem) se pagan al 1.5x.
class EmpleadoPorHoras : public Empleado {
private:
    float tarifaPorHora;        // Pago base por cada hora normal
    float horasTrabajadas;      // Total de horas trabajadas en la semana

    static const float HORAS_REGULARES;  // Limite de horas sin recargo (40h)
    static const float FACTOR_EXTRA;     // Factor de recargo horas extra (1.5x)

public:
    EmpleadoPorHoras(const string& nom, const string& id,
                     float tarifa, float horas)
        : Empleado(nom, id),
          tarifaPorHora(tarifa > 0 ? tarifa : 0.0f),
          horasTrabajadas(horas > 0 ? horas : 0.0f) {}

    // Refinamiento del calculo: horas regulares + bonus por horas extra
    float calcularPago() const override {
        if (horasTrabajadas <= HORAS_REGULARES) {
            return tarifaPorHora * horasTrabajadas;
        }
        // Horas regulares + horas extra al 1.5x
        float pagoRegular = tarifaPorHora * HORAS_REGULARES;
        float pagoExtra   = tarifaPorHora * FACTOR_EXTRA
                            * (horasTrabajadas - HORAS_REGULARES);
        return pagoRegular + pagoExtra;
    }

    void mostrarReporte() const override {
        cout << "  [POR HORAS] ID: " << id
             << " | Nombre: " << nombre << endl;
        cout << "    Tarifa por hora     : S/. "
             << fixed << setprecision(2) << tarifaPorHora << endl;
        cout << "    Horas trabajadas    : "
             << fixed << setprecision(1) << horasTrabajadas << "h" << endl;
        if (horasTrabajadas > HORAS_REGULARES)
            cout << "    Horas extra         : "
                 << fixed << setprecision(1)
                 << (horasTrabajadas - HORAS_REGULARES) << "h (x1.5)" << endl;
        cout << "    PAGO CALCULADO      : S/. "
             << fixed << setprecision(2) << calcularPago() << endl;
    }

    ~EmpleadoPorHoras() override = default;
};

// Definicion de constantes estaticas fuera de la clase
const float EmpleadoPorHoras::HORAS_REGULARES = 40.0f;
const float EmpleadoPorHoras::FACTOR_EXTRA     = 1.5f;

// ── CLASE DERIVADA: EmpleadoComision ─────────────────────────────────────
// Su pago depende de un porcentaje sobre las ventas brutas generadas.
class EmpleadoComision : public Empleado {
private:
    float ventasBrutas;         // Total de ventas generadas en el periodo
    float porcentajeComision;   // Porcentaje que recibe sobre las ventas (0-1)

public:
    EmpleadoComision(const string& nom, const string& id,
                     float ventas, float porcentaje)
        : Empleado(nom, id),
          ventasBrutas(ventas > 0 ? ventas : 0.0f),
          porcentajeComision(porcentaje > 0 ? porcentaje : 0.0f) {}

    // Reemplazo total: pago = ventas * porcentaje
    float calcularPago() const override {
        return ventasBrutas * porcentajeComision;
    }

    void mostrarReporte() const override {
        cout << "  [COMISION]  ID: " << id
             << " | Nombre: " << nombre << endl;
        cout << "    Ventas brutas       : S/. "
             << fixed << setprecision(2) << ventasBrutas << endl;
        cout << "    Porcentaje comision : "
             << fixed << setprecision(1)
             << (porcentajeComision * 100) << "%" << endl;
        cout << "    PAGO CALCULADO      : S/. "
             << fixed << setprecision(2) << calcularPago() << endl;
    }

    ~EmpleadoComision() override = default;
};

// ── CLASE GESTORA: GestorNomina ──────────────────────────────────────────
// Centraliza la gestion de todos los empleados.
// Almacena punteros a la clase base y opera polimoricamente.
class GestorNomina {
private:
    vector<Empleado*> empleados;    // Contenedor polimorfico

public:
    // Agrega un empleado al sistema (el gestor toma posesion del puntero)
    void agregarEmpleado(Empleado* emp) {
        if (emp != nullptr)
            empleados.push_back(emp);
    }

    // Genera el reporte completo de la nomina
    // calcularPago() y mostrarReporte() se resuelven en tiempo de ejecucion
    void generarReporte() const {
        cout << "\n========================================================" << endl;
        cout << "             REPORTE GENERAL DE NOMINA                  " << endl;
        cout << "========================================================" << endl;

        float totalNomina = 0.0f;
        int   contador    = 0;

        for (Empleado* emp : empleados) {
            cout << endl;
            emp->mostrarReporte();          // Polimorfismo dinamico en accion
            totalNomina += emp->calcularPago();
            contador++;
        }

        cout << "\n--------------------------------------------------------" << endl;
        cout << "  Total empleados en nomina : " << contador << endl;
        cout << "  COSTO TOTAL DE NOMINA     : S/. "
             << fixed << setprecision(2) << totalNomina << endl;
        cout << "========================================================" << endl;
    }

    // Destructor: libera toda la memoria de los empleados
    // Los destructores virtuales garantizan la destruccion correcta
    ~GestorNomina() {
        cout << "\n--- Liberando recursos del GestorNomina ---" << endl;
        for (Empleado* emp : empleados) {
            cout << "  Eliminando: " << emp->getNombre() << endl;
            delete emp;
        }
        empleados.clear();
    }
};

// ── PROGRAMA PRINCIPAL ───────────────────────────────────────────────────
int main() {
    cout << "========================================================" << endl;
    cout << "   EJERCICIO 3: SISTEMA DE NOMINA POLIMORFICO           " << endl;
    cout << "   Clases Abstractas, Polimorfismo y GestorNomina       " << endl;
    cout << "========================================================" << endl;

    // Intento de instanciar clase abstracta (COMENTADO: genera error de compilacion)
    // Empleado e("Error", "E000");  // ERROR: Empleado es abstracta

    // Crear el gestor de nomina
    GestorNomina gestor;

    // Agregar empleados de distintas categorias al sistema
    gestor.agregarEmpleado(
        new EmpleadoAsalariado("Ana Velazco",  "E001", 1800.00f));
    gestor.agregarEmpleado(
        new EmpleadoAsalariado("Carlos Rios",  "E002", 2200.00f));
    gestor.agregarEmpleado(
        new EmpleadoPorHoras("Maria Huanca",   "E003", 15.50f, 45.0f));
    gestor.agregarEmpleado(
        new EmpleadoPorHoras("Luis Condori",   "E004", 12.00f, 38.0f));
    gestor.agregarEmpleado(
        new EmpleadoComision("Sofia Paredes",  "E005", 25000.00f, 0.08f));
    gestor.agregarEmpleado(
        new EmpleadoComision("Pedro Mamani",   "E006", 18500.00f, 0.10f));

    // El gestor genera el reporte de forma totalmente polimorfica
    gestor.generarReporte();

    // El destructor de GestorNomina libera toda la memoria automaticamente
    return 0;
}
