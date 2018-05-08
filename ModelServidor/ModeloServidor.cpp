#include "ModeloServidor.h"

ModeloServidor::ModeloServidor(int cantidadClientes) :
    buffer(cantidadClientes),
    clientes(std::vector<Cliente*>(cantidadClientes))
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i] = new Cliente(i, &(this->buffer));
    }
}

ModeloServidor::~ModeloServidor()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        delete this->clientes[i];
    }
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
