#include "Cliente.h"
#include <iostream>
#define ENTIDAD 0
#define EVENTO 1
Cliente::Cliente(Buffer* buffer, std::string ip, std::string puerto) :
    id(++Cliente::contadorClientes),
    buffer(buffer),
    socket(ip, puerto)
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
    this->socket.enviarByte(codigo);
}

void Cliente::recibirMensaje()
{
    char codigo = this->socket.recibirByte();
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

void Cliente::enviarId(unsigned id)
{
    char idCaracter = id;
    this->socket.enviarByte(idCaracter);
}

void Cliente::enviarRespuesta(char codigo)
{
    this->socket.enviarByte(codigo);
}

char Cliente::recibirUsuario()
{
    char codigo = this->socket.recibirByte();
    return codigo;
}

char Cliente::recibirPassword()
{
    char codigo = this->socket.recibirByte();
    return codigo;
}

unsigned Cliente::getID() {
    return this->id;
}
