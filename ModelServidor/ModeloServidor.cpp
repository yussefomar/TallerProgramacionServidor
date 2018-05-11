#include "ModeloServidor.h"

ModeloServidor::ModeloServidor(int cantidadClientes) :
    buffer(cantidadClientes),
    clientes(std::vector<Cliente*>(cantidadClientes))
{

}

ModeloServidor::~ModeloServidor()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        delete this->clientes[i];
    }
}

void ModeloServidor::aceptarClientesEntrantes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i] = new Cliente(&(this->buffer));
    }
}

void ModeloServidor::rechazarClientesEntrantes()
{
    //en hilo aparte aceptamos clientes pero enviamos mensajes de
    //que el juego ya esta completo.
}

void ModeloServidor::enviarMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i]->enviarMensajes();
    }
    return;
}

void ModeloServidor::recibirMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i]->recibirMensaje();
    }
    return;
}

bool ModeloServidor::clientesEstanConectados() {
    bool estanConectados = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i) {
        estanConectados |= this->clientes[i]->estaConectado();
    }
    return estanConectados;
}
