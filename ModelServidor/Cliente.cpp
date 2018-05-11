#include "Cliente.h"
#include <iostream>
#define ENTIDAD 0
#define EVENTO 1
Cliente::Cliente(Buffer* buffer) : id(++Cliente::contadorClientes), buffer(buffer)
{
    /*El cliente posiblemente deba tener estada. Es decir, implementar patron estado
    donde pueda estar conectado o desconectado y actuar en concecuencia.
    Si esta desconectado, intentar conectarse cada que pueda. y pedir requisitos necesarios)*/
}

Cliente::~Cliente()
{
    //dtor
}

int Cliente::contadorClientes = -1;

void Cliente::enviarMensajes()
{
    std::string codigo;
    unsigned cantidadCambios = this->buffer->cantidadCodigosEnCanal(this->id);
    this->socket.enviarCantidadCambios(cantidadCambios);
    for(unsigned i = 0; i < cantidadCambios && this->socket.estaConectado(); ++i)
    {
        codigo = this->buffer->popCodigoEnCanal(this->id);
        this->socket.enviarCodigoComando(codigo);
    }
}

void Cliente::recibirMensaje()
{
    std::string codigo;
    codigo = this->socket.recibirCodigoComando();
    this->buffer->pushCodigo(codigo);

}

bool Cliente::estaConectado()
{
    return this->socket.estaConectado();
}
