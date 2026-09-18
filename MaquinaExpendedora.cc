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

void ProductosDisponibles(std::array<Producto, 15> &producto, int &cantidad_producto);

void VenderProducto(std::array<Producto, 15> &producto, int &cantidad_producto);

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
    return 0;
}

void ProductosDisponibles(std::array<Producto, 15> &producto, int &cantidad_producto)
{
    std::cout << "Acontinuacinon se imprimiran los productos disponibles:" << std::endl;

    for (int i = 0; i < cantidad_producto; i++)
    {
        std::cout << "Producto num:" << i + 1 << producto[i].nombre << std::endl;
    }
}

void ReabastecerProducto(std::array<Producto, 15> &producto, int &cantidad_producto)
{

    std::string eleccion;

    ProductosDisponibles(producto, cantidad_producto);
    std::cout << "Acontinuacion digita el nombre de producto al que reabasteciras" << std::endl;
    std::cin >> eleccion;

    for (int i = 0; i < cantidad_producto; i++)
    {

        if (producto[i].nombre == eleccion)
        {
            int eleccion = 0;
            std::cout << "cuantas productos reabasteciras:" << std::endl;
            std::cin >> eleccion;
            producto[i].cantidad_disponible = producto[i].cantidad_disponible + eleccion;
            std::cout << "productos disponibles: " << producto[i].cantidad_disponible;
        }
    }
}

void VenderProducto(std::array<Producto, 15> &producto, int &cantidad_producto)
{
    std::string eleccion;
    ProductosDisponibles(producto, cantidad_producto);
    std::cout << "Acontinuacion digita el nombre de producto al que quieres:" << std::endl;
    std::cin >> eleccion;

    for (int i = 0; i < cantidad_producto; i++)
    {
        if (producto[i].nombre == eleccion)
        {
            int eleccion = 0;
            std::cout << "Acontinuacion digita el numero de producto al que quieres comprar:" << std::endl;
            std::cin >> eleccion;
            producto[i].cantidad_disponible = producto[i].cantidad_disponible - eleccion;
            producto[i].unidades_vendidas += eleccion;
        }
    }
}

int main()
{

    int cantidad_producto = 0;
    std::array<Producto, 15> producto;

    CrearProducto(producto, cantidad_producto);
    ProductosDisponibles(producto, cantidad_producto);

    VenderProducto(producto, cantidad_producto);
    ReabastecerProducto(producto, cantidad_producto);
}