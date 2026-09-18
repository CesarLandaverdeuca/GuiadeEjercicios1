#include <iostream>

void depositar(float* saldo, float cantidad) {
    // 1. Usamos el operador de desreferencia (*) para acceder al valor original
    // 2. Le sumamos la cantidad usando el atajo +=
    *saldo += cantidad;
}

int main() {
    // Definimos el saldo inicial en la función principal
    float saldo_cuenta = 1500.50f;
    float cantidad_deposito = 300.00f;

    std::cout << "Saldo antes del deposito: $" << saldo_cuenta << std::endl;

    // Pasamos la dirección de memoria (&) del saldo a la función
    depositar(&saldo_cuenta, cantidad_deposito);

    std::cout << "Saldo despues del deposito: $" << saldo_cuenta << std::endl;

    return 0;
}