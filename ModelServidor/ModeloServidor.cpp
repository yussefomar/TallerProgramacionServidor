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
        this->clientes[i]->enviarId(i);
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
        this->clientes[i]->enviarMensaje();
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

bool ModeloServidor::clientesEstanConectados()
{
    bool estanConectados = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        estanConectados |= this->clientes[i]->estaConectado();
    }
    return estanConectados;
}


bool ModeloServidor::hayCambiosPorEnviar()
{
    bool hayCambios = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        hayCambios |= this->clientes[i]->hayCambios();
    }
    return hayCambios;
}

void ModeloServidor::recibirInformacion() {
//    for(unsigned i = 0; i < this->clientes.size(); ++i)
//    {
//        std::string usuario = this->clientes[i]->recibirUsuario();
//        this->verificarUsuario(usuario, i); //verifico si el usuario esta en bdd o esta repetido
//        //mandar codigo con estos posibles sucesos y que el usuario se encargue.
//        std::string password = this->clientes[i]->recibirUsuario();
//        this->verificarPassword(usuario, password, i); //verifico si el password corresponde con el usuario. en caso de erro comunicarlo.
//    }
    return;
}
