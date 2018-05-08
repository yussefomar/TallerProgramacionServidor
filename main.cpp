#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <ModeloServidor.h>
#include "SocketCliente/SocketCliente.h"

void srv_run()
{
    std::cout << "server run" << std::endl;
    //Setea la cantidad de clientes a esperar
    ModeloServidor modeloServidor(2);
    //Temporal hasta agregar thread
//    while(true)
//    {
//        modeloServidor.recibirMensajes();
//        modeloServidor.enviarMensajes();
//    }
    modeloServidor.recibirMensajes();
    modeloServidor.enviarMensajes();
}

void clt_run()
{
    std::cout << "client run" << std::endl;

    SocketCliente socket;
    std::string mensaje = "ho";
//    while(true)
//    {
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//        socket.enviarCodigoComando(mensaje);
//        socket.recibirCodigoComando(mensaje);
//    }
    socket.enviarCodigoComando(mensaje);

    mensaje = socket.recibirCodigoComando();
    std::cout << mensaje << std::endl;
    mensaje = socket.recibirCodigoComando();
    std::cout << mensaje << std::endl;

}

int main(int argc, char* args[])
{
    if(argc == 2 && strncmp("srv", args[1], 3) == 0)
    {
        srv_run();
    }
    if(argc == 2 && strncmp("clt", args[1], 3) == 0)
    {
        clt_run();
    }
    return 0;
}
