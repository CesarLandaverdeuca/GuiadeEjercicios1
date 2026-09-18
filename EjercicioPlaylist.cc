#include <iostream>
#include <array>

struct Cancion
{
    std::string titulo;
    std::string artista;
    int duracion_segundos;
    int reproducciones;
    bool favorita;
};

int AgregarCancion(std::array<Cancion, 15> &playlist, int &cantidad_canciones);
void MostrarPlaylist(std::array<Cancion, 15> &playlist, int &cantidad_canciones);
void ReproducirCancion(std::array<Cancion, 15> &playlist, int &cantidad_canciones);
void MarcarFavorita(std::array<Cancion, 15> &playlist, int &cantidad_canciones);
void EstadisticasPlaylist(std::array<Cancion, 15> &playlist, int &cantidad_canciones);

int AgregarCancion(std::array<Cancion, 15> &playlist, int &cantidad_canciones)
{
    if (cantidad_canciones >= 15)
    {
        std::cout << "No se pueden agregar mas canciones :(" << std::endl;
        return 0;
    }

    std::cout << "Escribe el titulo de la cancion:" << std::endl;
    std::cin >> playlist[cantidad_canciones].titulo;
    std::cout << "Escribe el artista:" << std::endl;
    std::cin >> playlist[cantidad_canciones].artista;
    std::cout << "Escribe la duracion en segundos:" << std::endl;
    std::cin >> playlist[cantidad_canciones].duracion_segundos;
    
    playlist[cantidad_canciones].reproducciones = 0;
    playlist[cantidad_canciones].favorita = false;

    cantidad_canciones++;
    return 0;
}

void MostrarPlaylist(std::array<Cancion, 15> &playlist, int &cantidad_canciones)
{
    std::cout << "Acontinuacion se imprimiran las canciones disponibles:" << std::endl;

    for (int i = 0; i < cantidad_canciones; i++)
    {
        std::cout << "Cancion num:" << i + 1 << " " << playlist[i].titulo << " - " << playlist[i].artista << std::endl;
    }
}

void ReproducirCancion(std::array<Cancion, 15> &playlist, int &cantidad_canciones)
{
    std::string eleccion;
    MostrarPlaylist(playlist, cantidad_canciones);
    std::cout << "Acontinuacion digita el titulo de la cancion que reproduciras:" << std::endl;
    std::cin >> eleccion;

    for (int i = 0; i < cantidad_canciones; i++)
    {
        if (playlist[i].titulo == eleccion)
        {
            playlist[i].reproducciones++;
            std::cout << "Reproduciendo: " << playlist[i].titulo << ". Total reproducciones: " << playlist[i].reproducciones << std::endl;
        }
    }
}

void MarcarFavorita(std::array<Cancion, 15> &playlist, int &cantidad_canciones)
{
    std::string eleccion;
    MostrarPlaylist(playlist, cantidad_canciones);
    std::cout << "Acontinuacion digita el titulo de la cancion para cambiar su estado de favorita:" << std::endl;
    std::cin >> eleccion;

    for (int i = 0; i < cantidad_canciones; i++)
    {
        if (playlist[i].titulo == eleccion)
        {
            int opcion = 0;
            std::cout << "Digita 1 para marcar como favorita, 2 para desmarcarla:" << std::endl;
            std::cin >> opcion;
            
            // Asignación directa del booleano, tal como aprendimos antes
            if (opcion == 1)
            {
                playlist[i].favorita = true;
            }
            else
            {
                playlist[i].favorita = false;
            }
            std::cout << "Estado actualizado." << std::endl;
        }
    }
}

void EstadisticasPlaylist(std::array<Cancion, 15> &playlist, int &cantidad_canciones)
{
    int total_reproducciones = 0;
    int total_favoritas = 0;
    int duracion_total = 0;
    int max_reproducciones = -1;
    std::string cancion_mas_reproducida = "";

    std::cout << "\n--- CANCIONES FAVORITAS ---" << std::endl;
    for (int i = 0; i < cantidad_canciones; i++)
    {
        if (playlist[i].favorita == true)
        {
            std::cout << "- " << playlist[i].titulo << std::endl;
            total_favoritas++;
        }

        total_reproducciones += playlist[i].reproducciones;
        duracion_total += playlist[i].duracion_segundos;

        if (playlist[i].reproducciones > max_reproducciones)
        {
            max_reproducciones = playlist[i].reproducciones;
            cancion_mas_reproducida = playlist[i].titulo;
        }
    }

    std::cout << "\n--- ESTADISTICAS GENERALES ---" << std::endl;
    std::cout << "Numero de canciones en playlist: " << cantidad_canciones << std::endl;
    std::cout << "Cantidad de canciones favoritas: " << total_favoritas << std::endl;
    std::cout << "Total acumulado de reproducciones: " << total_reproducciones << std::endl;
    std::cout << "Duracion total de la playlist (segundos): " << duracion_total << std::endl;

    if (cantidad_canciones > 0)
    {
        std::cout << "Cancion mas reproducida: " << cancion_mas_reproducida << " (" << max_reproducciones << " reproducciones)" << std::endl;
    }
}

int main()
{
    int cantidad_canciones = 0;
    std::array<Cancion, 15> playlist;

    AgregarCancion(playlist, cantidad_canciones);
    AgregarCancion(playlist, cantidad_canciones);
    
    ReproducirCancion(playlist, cantidad_canciones);
    MarcarFavorita(playlist, cantidad_canciones);
    
    EstadisticasPlaylist(playlist, cantidad_canciones);
    
    return 0;
}