#include <iostream>
#include <array>

struct Producto
{
    std::string nombre;
    float precio;
    int cantidad_disponible;
    int unidades_vendidas;
};

int CrearProducto(std::array<Producto, 15> &producto, int &cantidad_producto);

void ReabastecerProducto(std::array<Producto, 15> &producto);

void ProductosDisponibles(std::array<Producto, 15> &producto);

void VenderProducto(std::array<Producto, 15> &producto);

int CrearProducto(std::array<Producto, 15> &producto, int &cantidad_producto)
{
    if (cantidad_producto >= 15)
    {
        std::cout << "No se puede crear mas productos :(" << std::endl;

        return 0;
    }

    std::cout << "Escribe el nombre del producto:" << std::endl;
    std::cin >> producto[cantidad_producto].nombre;
    std::cout << "Escribe el precio" << std::endl;
    std::cin >> producto[cantidad_producto].precio;
    std::cout << "Escribe la cantidad disponible de ese producto: " << std::endl;
    std::cin >> producto[cantidad_producto].cantidad_disponible;
    producto[cantidad_producto].unidades_vendidas = 0;

    cantidad_producto++;
}
int main()
{

    int cantidad_producto = 0;
    std::array<Producto, 15> producto;

    CrearProducto(producto, cantidad_producto);
}