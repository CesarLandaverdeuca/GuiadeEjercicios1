#include <iostream>
#include <array>

struct Vehiculo
{
    std::string placa;
    std::string tipo_vehiculo;
    float hora_entrada;
    bool estado_estacionamiento;
};

int CrearNuevoVehiculo(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos);
void EliminarVehiculo(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos);
void MostrarInformacion(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos);
void BuscarVehiculoPorPlaca(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos);

int CrearNuevoVehiculo(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos)
{

    if (cantidad_vehiculos >= 50)
    {
        std::cout << "Estacionamiento lleno" << std::endl;
        return 0;
    }
    else
    {
        std::string placa_buscada;
        std::cout << "Agregar placa:" << std::endl;
        std::cin >> placa_buscada;

        for (int i = 0; i < cantidad_vehiculos; i++)
        {

            if (estacionamiento[i].placa == placa_buscada)
            {
                std::cout << "No se puede agregar dos vehiculos con el mismo placa" << std::endl;

                return 0;
            }
        }

        estacionamiento[cantidad_vehiculos].placa=placa_buscada;
        std::cout << "agregar tipo vehiculo:" << std::endl;
        std::cin >> estacionamiento[cantidad_vehiculos].tipo_vehiculo;
        std::cout << "agregar hora de entrada" << std::endl;
        std::cin >> estacionamiento[cantidad_vehiculos].hora_entrada;
        std::cout << "ingrea 1 o 2 para el estado del estacionamiento 1=ocupado 2 =libre" << std::endl;
        int eleccion = 0;
        std::cin >> eleccion;
        if (eleccion == 1)
        {
            estacionamiento[cantidad_vehiculos].estado_estacionamiento = false;
        }
        else
        {
            estacionamiento[cantidad_vehiculos].estado_estacionamiento = true;
        }

        cantidad_vehiculos++;

        return 0;
    }
}

void BuscarVehiculoPorPlaca(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos)
{

    std::string placa_buscada;
    std::cout << "buscar vehiculo por placa , para buscarlo pon la placa:" << std::endl;
    std::cin >> placa_buscada;

    for (int i = 0; i < cantidad_vehiculos; i++)
    {
        if (estacionamiento[i].placa == placa_buscada)
        {
            std::cout << "Su parqueo esta en la pocision" << i << std::endl;
           
        }
    }
}

void EliminarVehiculo(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos)
{
    std::string placa_buscada;
    std::cout << "eliminar placa , para eliminarla pon la placa:" << std::endl;
    std::cin >> placa_buscada;

    for (int i = 0; i < cantidad_vehiculos; i++)
    {
        if (estacionamiento[i].placa == placa_buscada)
        {
            for (int j = i; j < cantidad_vehiculos - 1; j++)
            {
                estacionamiento[j] = estacionamiento[j + 1];
            }

            cantidad_vehiculos--;
            break;
        }
    }
}

void MostrarInformacion(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos)
{
    int espacios_libres = 50 - cantidad_vehiculos;
    float porcentaje_ocupacion = (cantidad_vehiculos / 50.0) * 100;
    std::cout << "Espacios ocupados:" << cantidad_vehiculos << std::endl;
    std::cout << "Espacios libres:" << espacios_libres << std::endl;
    std::cout << "Porcentaje de ocupación:" << porcentaje_ocupacion << std::endl;
}

int main()
{
    int cantidad_vehiculos = 0;
    std::array<Vehiculo, 50> estacionamiento;

    for (int i = 0; i < 3; i++)
    {
        CrearNuevoVehiculo(estacionamiento, cantidad_vehiculos);
        
    }

    MostrarInformacion(estacionamiento, cantidad_vehiculos);
    EliminarVehiculo(estacionamiento, cantidad_vehiculos);
    MostrarInformacion(estacionamiento, cantidad_vehiculos);

    return 0; // cambios
};
