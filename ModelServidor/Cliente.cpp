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

std::string Cliente::recibirUsuario() {
    char codigo = this->socket.recibirByte();
    std::string usuario = this->hashear(codigo);
    return usuario;
}

std::string Cliente::recibirPassword() {
    char codigo = this->socket.recibirByte();
    std::string password = this->hashear(codigo);
    return password;
}

std::string Cliente::hashear(char codigo)
{
    //esta misma funcion tiene que estar disponible en el server para hashear
    //los datos que pasan desde configuracion.
    std::string code;
    /*for(unsigned i = 0; i < unString.size(); ++i)
    {
        code = code | unString[i];
    }*/
    return code;
}
