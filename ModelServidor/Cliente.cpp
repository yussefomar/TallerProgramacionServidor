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

void Cliente::enviarMensaje()
{
    char codigo = this->buffer->popCodigo(this->id);
    this->socket.enviarCodigoComando(codigo);
}

void Cliente::recibirMensaje()
{
    char codigo = this->socket.recibirCodigoComando();
    this->buffer->pushCodigo(codigo);
}

bool Cliente::estaConectado()
{
    return this->socket.estaConectado();
}

bool Cliente::hayCambios()
{
    return this->buffer->cantidadCodigos(this->id) > 0;
}

void Cliente::enviarFinDeCambios()
{
    this->socket.enviarFinDeCambios();
}
