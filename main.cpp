#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <ModeloServidor.h>

#define CANTCLT 1

void modoMultiJugador();
void modoSingleJugador();

int main(int argc, char* args[])
{
    modoSingleJugador();
    return 0;
}

void modoMultiJugador()
{
    /*Aun no esta preparado, ni muy pensado*/
    std::cout << "server run" << std::endl;
    ModeloServidor modeloServidor(CANTCLT);
    modeloServidor.aceptarClientesEntrantes();
    modeloServidor.rechazarClientesEntrantes();
    std::cout << "server with clients" << std::endl;
    unsigned i = 0;

    long double MSPORUPDATE = 89.0;
    long double tiempoActual = 0.0;
    long double lapsoDeTiempo = 0.0;
    long double tiempoPrevio = clock();
    long double lag = 0.0;

    while(modeloServidor.clientesEstanConectados())
    {
        tiempoActual = clock();
        lapsoDeTiempo = (tiempoActual - tiempoPrevio) / (CLOCKS_PER_SEC / 1000);
        tiempoPrevio = tiempoActual;
        lag += lapsoDeTiempo;

        modeloServidor.recibirMensajes();
        std::cout << "server recv msg" << std::endl;
        while(lag >= MSPORUPDATE && modeloServidor.hayCambiosPorEnviar())
        {
            modeloServidor.enviarMensajes();
            lag -= MSPORUPDATE;

        }

        std::cout << "server send msg" << std::endl;
        std::cout << "ciclo nro: " << i << std::endl;
        ++i;
    }
}

void modoSingleJugador()
{
    std::cout << "server run" << std::endl;
    Buffer buffer(1);
    Cliente cliente(&buffer);
    std::cout << "server with clients" << std::endl;
    int i = 0;
    while(cliente.estaConectado())
    {
        cliente.recibirMensaje();
        cliente.enviarMensaje();
        ++i;
        std::cout << "Termino el Ciclo nro: " << i << std::endl;
    }

    std::cout << "Server desconectado" << std::endl;

}
