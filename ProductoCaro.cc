#include <iostream>
#include <string>

struct Producto {
    std::string nombre;
    float precio;
};

// La función promete retornar un puntero (Producto*) y recibe el arreglo como puntero
Producto* ObtenerProductoMasCaro(Producto* inventario, int cantidad) {
    // Apuntamos temporalmente al primer casillero asumiendo que es el más caro
    Producto* direccion_mas_caro = &inventario[0];

    for (int i = 1; i < cantidad; i++) {
        // Usamos la flecha (->) para leer el precio porque direccion_mas_caro es un puntero
        if (inventario[i].precio > direccion_mas_caro->precio) {
            // Si encontramos uno más caro, actualizamos nuestro puntero con la nueva dirección
            direccion_mas_caro = &inventario[i];
        }
    }

    // Retornamos la dirección de memoria exacta del producto ganador
    return direccion_mas_caro;
}

int main() {
    int cantidad = 4;
    
    // Creamos el arreglo con algunos productos de prueba
    Producto inventario[4] = {
        {"Teclado", 45.50},
        {"Monitor", 250.00},
        {"Laptop", 1200.00},
        {"Raton", 25.00}
    };

    // Al pasar 'inventario', C++ envía automáticamente el puntero al primer elemento
    Producto* el_mas_caro = ObtenerProductoMasCaro(inventario, cantidad);

    // El main utiliza el puntero recibido para mostrar los datos finales
    std::cout << "--- PRODUCTO MAS CARO ---" << std::endl;
    std::cout << "Nombre: " << el_mas_caro->nombre << std::endl;
    std::cout << "Precio: $" << el_mas_caro->precio << std::endl;

    return 0;
}