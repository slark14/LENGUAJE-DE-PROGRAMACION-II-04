#include <iostream>
#include <cmath>
 
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
	Circulo(float r) {
    	radio = r;
    	diametro = r * 2;
	}
	float getRadio() const {
    	return radio;
	}
	float getDiametro() const {
    	return diametro;
    }
	friend float calcularArea(const Circulo &c);
};
float calcularArea(const Circulo &c) {
	return 3.1416 * c.radio * c.radio;
}
int main() {
	Circulo c1(5);
	Circulo c2(10);
	Circulo c3(3.5);
 
	cout << "Circulo 1 area: " << calcularArea(c1) << endl;
	cout << "Circulo 2 area: " << calcularArea(c2) << endl;
	cout << "Circulo 3 area: " << calcularArea(c3) << endl;
	return 0;
}

