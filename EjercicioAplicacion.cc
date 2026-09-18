#include <iostream>
#include <array>
#include <string>

struct Elemento
{
    int codigo_elemento;
    std::string nombre_elemento;
    float longitud;
    float cargas[3];
    float capacidad_maxima;
    float factor_utilizacion;
    std::string estado_seguridad;
};

// Prototipos
void registrarElemento(Elemento &elemento);
float calcularFactor(Elemento *elemento);
void determinarSeguridad(Elemento &elemento);
Elemento *obtenerElementoCritico(Elemento elementos[], int cantidad);
void aumentarCargas(Elemento &elemento, float porcentaje);
void generarInforme(Elemento elementos[], int cantidad);
void mostrarElemento(const Elemento &elemento);

// ---------- Parte 2: Registro ----------
void registrarElemento(Elemento &elemento)
{
    std::cout << "Ingresa el codigo del elemento: " << std::endl;
    std::cin >> elemento.codigo_elemento;

    std::cout << "Ingresa el nombre del elemento: " << std::endl;
    std::cin >> elemento.nombre_elemento;

    std::cout << "Ingresa la longitud del elemento: " << std::endl;
    std::cin >> elemento.longitud;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingresa la carga " << (i + 1) << " (N): " << std::endl;
        std::cin >> elemento.cargas[i];
    }

    std::cout << "Ingresa la capacidad maxima (N): " << std::endl;
    std::cin >> elemento.capacidad_maxima;
}

// ---------- Parte 3: Factor de utilizacion ----------
float calcularFactor(Elemento *elemento)
{
    float promedio = (elemento->cargas[0] +
                       elemento->cargas[1] +
                       elemento->cargas[2]) / 3.0f;

    float factor = promedio / elemento->capacidad_maxima;

    elemento->factor_utilizacion = factor;

    return factor;
}

// ---------- Parte 4: Estado de seguridad ----------
void determinarSeguridad(Elemento &elemento)
{
    float factor = elemento.factor_utilizacion;

    if (factor <= 0.50f)
        elemento.estado_seguridad = "SEGURO";
    else if (factor <= 0.80f)
        elemento.estado_seguridad = "PRECAUCION";
    else if (factor <= 1.00f)
        elemento.estado_seguridad = "RIESGO";
    else
        elemento.estado_seguridad = "SOBRECARGA";
}

// ---------- Parte 5: Elemento mas comprometido ----------
Elemento *obtenerElementoCritico(Elemento elementos[], int cantidad)
{
    Elemento *critico = elementos;

    for (Elemento *p = elementos + 1; p < elementos + cantidad; p++)
    {
        if (p->factor_utilizacion > critico->factor_utilizacion)
        {
            critico = p;
        }
    }

    return critico;
}

// ---------- Parte 6: Simulacion de incremento de carga ----------
void aumentarCargas(Elemento &elemento, float porcentaje)
{
    for (int i = 0; i < 3; i++)
    {
        elemento.cargas[i] = elemento.cargas[i] * (1 + porcentaje / 100.0f);
    }

    calcularFactor(&elemento);
    determinarSeguridad(elemento);

    std::cout << "\n--- Resultados del elemento tras el incremento ---" << std::endl;
    mostrarElemento(elemento);
}

// ---------- Parte 7: Informe general ----------
void generarInforme(Elemento elementos[], int cantidad)
{
    int contadorSeguro = 0;
    int contadorPrecaucion = 0;
    int contadorRiesgo = 0;
    int contadorSobrecarga = 0;
    float sumaFactores = 0.0f;

    std::cout << "\n===== INFORME GENERAL =====" << std::endl;

    for (int i = 0; i < cantidad; i++)
    {
        float promedio = (elementos[i].cargas[0] +
                           elementos[i].cargas[1] +
                           elementos[i].cargas[2]) / 3.0f;

        std::cout << "Codigo: " << elementos[i].codigo_elemento
                   << " | Nombre: " << elementos[i].nombre_elemento
                   << " | Carga promedio: " << promedio
                   << " | Factor: " << elementos[i].factor_utilizacion
                   << " | Estado: " << elementos[i].estado_seguridad
                   << std::endl;

        sumaFactores += elementos[i].factor_utilizacion;

        if (elementos[i].estado_seguridad == "SEGURO")
            contadorSeguro++;
        else if (elementos[i].estado_seguridad == "PRECAUCION")
            contadorPrecaucion++;
        else if (elementos[i].estado_seguridad == "RIESGO")
            contadorRiesgo++;
        else if (elementos[i].estado_seguridad == "SOBRECARGA")
            contadorSobrecarga++;
    }

    float factorPromedio = sumaFactores / cantidad;

    std::cout << "\nResumen por estado de seguridad:" << std::endl;
    std::cout << "SEGURO: " << contadorSeguro << std::endl;
    std::cout << "PRECAUCION: " << contadorPrecaucion << std::endl;
    std::cout << "RIESGO: " << contadorRiesgo << std::endl;
    std::cout << "SOBRECARGA: " << contadorSobrecarga << std::endl;

    std::cout << "\nFactor de utilizacion promedio de la estructura: "
               << factorPromedio << std::endl;
}

// Funcion auxiliar (no pedida explicitamente, evita repetir el mismo bloque
// de cout en la Parte 5 y la Parte 6)
void mostrarElemento(const Elemento &elemento)
{
    std::cout << "Codigo: " << elemento.codigo_elemento << std::endl;
    std::cout << "Nombre: " << elemento.nombre_elemento << std::endl;
    std::cout << "Longitud: " << elemento.longitud << std::endl;
    std::cout << "Carga 1: " << elemento.cargas[0] << std::endl;
    std::cout << "Carga 2: " << elemento.cargas[1] << std::endl;
    std::cout << "Carga 3: " << elemento.cargas[2] << std::endl;
    std::cout << "Capacidad maxima: " << elemento.capacidad_maxima << std::endl;
    std::cout << "Factor de utilizacion: " << elemento.factor_utilizacion << std::endl;
    std::cout << "Estado de seguridad: " << elemento.estado_seguridad << std::endl;
}

int main()
{
    std::array<Elemento, 10> elementos;
    int cantidad = 0;

    // Parte 1: validar cantidad entre 1 y 10
    do
    {
        std::cout << "Cuantos elementos deseas registrar (1-10)? " << std::endl;
        std::cin >> cantidad;

        if (cantidad < 1 || cantidad > 10)
            std::cout << "Cantidad invalida. Debe estar entre 1 y 10." << std::endl;

    } while (cantidad < 1 || cantidad > 10);

    // Parte 2: registro de cada elemento
    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "\n--- Registro del elemento " << (i + 1) << " ---" << std::endl;
        registrarElemento(elementos[i]);
    }

    // Parte 3 y 4: calcular factor y estado de cada elemento
    // (recorrido mediante punteros, como pide el enunciado)
    for (Elemento *p = elementos.data(); p < elementos.data() + cantidad; p++)
    {
        calcularFactor(p);
        determinarSeguridad(*p);
    }

    // Mostrar resultados iniciales de todos los elementos
    std::cout << "\n===== RESULTADOS INICIALES =====" << std::endl;
    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "\nElemento " << (i + 1) << ":" << std::endl;
        mostrarElemento(elementos[i]);
    }

    // Parte 5: elemento mas comprometido
    Elemento *critico = obtenerElementoCritico(elementos.data(), cantidad);
    std::cout << "\n===== ELEMENTO MAS COMPROMETIDO =====" << std::endl;
    mostrarElemento(*critico);

    // Parte 6: simulacion de incremento de carga sobre el elemento critico
    float porcentaje;
    std::cout << "\nIngresa el porcentaje de incremento de carga a simular: " << std::endl;
    std::cin >> porcentaje;

    aumentarCargas(*critico, porcentaje);

    // Parte 7: informe final de toda la estructura
    generarInforme(elementos.data(), cantidad);

    return 0;
}