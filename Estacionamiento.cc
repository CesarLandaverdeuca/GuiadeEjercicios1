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
int EliminarVehiculo(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos);

int CrearNuevoVehiculo(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos)
{

    std::cout << "Agregar placa:" << std::endl;
    std::cin >> estacionamiento[cantidad_vehiculos].placa;
    cantidad_vehiculos++;

    return 0;
}

int EliminarVehiculo(std::array<Vehiculo, 50> &estacionamiento, int &cantidad_vehiculos)
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

int BuscarVehiculoPorPlaca(std::array<Vehiculo,50> &estacionamiento , int &cantidad_vehiculos){

      std::string placa_buscada;
    std::cout << "buscar vehiculo por placa , para buscarlo pon la placa:" << std::endl;
    std::cin >> placa_buscada;


}

int main()
{
    int cantidad_vehiculos = 0;
    std::array<Vehiculo, 50> estacionamiento;

    return 0;//cambios
};
