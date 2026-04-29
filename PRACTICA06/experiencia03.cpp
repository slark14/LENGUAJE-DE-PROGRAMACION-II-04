/*************************************************************************************************
ARCHIVO     : experiencia03.cpp
AUTOR       : EDWIN QUISPE CHOQUEMAQUE
FECHA       : 29/04/2026
DESCRIPCIÓN : Programa en C++ que representa un banco con una tasa de interés estática.
              También representa una cuenta bancaria que permite realizar depósitos,
              retiros y calcular el interés ganado usando la tasa del banco.
*************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Banco {
private:
    static float tasaInteres;
public:
    static void cambiarTasaInteres(float nuevaTasa) {
        if (nuevaTasa >= 0) {
            tasaInteres = nuevaTasa;
            cout << "La tasa de interes fue actualizada correctamente." << endl;
        } else {
            cout << "Error: la tasa de interes no puede ser negativa." << endl;
        }
    }
    static float obtenerTasaInteres() {
        return tasaInteres;
    }
};
float Banco::tasaInteres = 5.0;
class CuentaBancaria {
private:
    string titular;
    string numeroCuenta;
    float saldo;
public:
    CuentaBancaria() {
        titular = "";
        numeroCuenta = "";
        saldo = 0;
    }
    CuentaBancaria(string titular, string numeroCuenta, float saldo) {
        this->titular = titular;
        this->numeroCuenta = numeroCuenta;
        if (saldo >= 0) {
            this->saldo = saldo;
        } else {
            this->saldo = 0;
        }
    }
    void ingresarDatos() {
        cout << "Ingrese el nombre del titular: ";
        cin.ignore();
        getline(cin, titular);
        cout << "Ingrese el numero de cuenta: ";
        getline(cin, numeroCuenta);
        do {
            cout << "Ingrese el saldo inicial: ";
            cin >> saldo;

            if (saldo < 0) {
                cout << "Error: el saldo no puede ser negativo." << endl;
            }
        } while (saldo < 0);
    }
    void depositar(float monto) {
        if (monto > 0) {
            saldo = saldo + monto;
            cout << "Deposito realizado correctamente." << endl;
        } else {
            cout << "Error: el monto a depositar debe ser mayor que 0." << endl;
        }
    }
    void retirar(float monto) {
        if (monto <= 0) {
            cout << "Error: el monto a retirar debe ser mayor que 0." << endl;
        } else if (monto > saldo) {
            cout << "Error: saldo insuficiente." << endl;
        } else {
            saldo = saldo - monto;
            cout << "Retiro realizado correctamente." << endl;
        }
    }
    float calcularInteresGanado() {
        return saldo * Banco::obtenerTasaInteres() / 100;
    }
    void mostrarDatos() {
        cout << "Titular          : " << titular << endl;
        cout << "Numero de cuenta : " << numeroCuenta << endl;
        cout << "Saldo actual     : S/ " << saldo << endl;
        cout << "Tasa de interes  : " << Banco::obtenerTasaInteres() << "%" << endl;
        cout << "Interes ganado   : S/ " << calcularInteresGanado() << endl;
    }
};
int main() {
    CuentaBancaria cuenta;
    int opcion;
    float monto;
    float nuevaTasa;
    cout << "========================================" << endl;
    cout << " EXPERIENCIA DE PRACTICA N° 03" << endl;
    cout << " MIEMBROS ESTATICOS" << endl;
    cout << "========================================" << endl;
    cuenta.ingresarDatos();
    do {
        cout << endl;
        cout << "============ MENU DE OPCIONES ==========" << endl;
        cout << "1. Mostrar datos de la cuenta" << endl;
        cout << "2. Depositar dinero" << endl;
        cout << "3. Retirar dinero" << endl;
        cout << "4. Cambiar tasa de interes del banco" << endl;
        cout << "5. Calcular interes ganado" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << endl;
            cout << "========== DATOS DE LA CUENTA ==========" << endl;
            cuenta.mostrarDatos();
            break;
        case 2:
            cout << "Ingrese el monto a depositar: ";
            cin >> monto;
            cuenta.depositar(monto);
            break;
        case 3:
            cout << "Ingrese el monto a retirar: ";
            cin >> monto;
            cuenta.retirar(monto);
            break;
        case 4:
            cout << "Ingrese la nueva tasa de interes: ";
            cin >> nuevaTasa;
            Banco::cambiarTasaInteres(nuevaTasa);
            break;
        case 5:
            cout << "Interes ganado: S/ " << cuenta.calcularInteresGanado() << endl;
            break;
        case 6:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Error: opcion no valida." << endl;
            break;
        }
    } while (opcion != 6);
    return 0;
}