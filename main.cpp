#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <ModeloServidor.h>

#define CANTCLT 2

int main(int argc, char* args[])
{
    std::cout << "server run" << std::endl;
    ModeloServidor modeloServidor(CANTCLT);
    modeloServidor.aceptarClientesEntrantes();
    modeloServidor.rechazarClientesEntrantes();
    std::cout << "server with clients" << std::endl;

    while(modeloServidor.clientesEstanConectados())
    {
        modeloServidor.recibirMensajes();
        std::cout << "server recv msg" << std::endl;

        modeloServidor.enviarMensajes();
        std::cout << "server send msg" << std::endl;
    }


    return 0;
}
