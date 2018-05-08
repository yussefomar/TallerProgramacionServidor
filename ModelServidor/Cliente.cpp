#include "Cliente.h"
#include <iostream>

Cliente::Cliente(int id, Buffer* buffer) : id(id), buffer(buffer)
{
}

Cliente::~Cliente()
{
    //dtor
}

void Cliente::enviarMensajes() {
    std::string codigo;
//    unsigned cantidadCodigos = this->buffer->cantidadCodigosEnCanal(this->id);
//    cantidadCodigos = cantidadCodigos < 5 ? cantidadCodigos : 4;

    for(unsigned i = 0; i < 4; ++i) {
        codigo = this->buffer->popCodigoEnCanal(this->id);
        this->socket.enviarCodigoComando(codigo);
    }
}

void Cliente::recibirMensaje() {
    std::string codigo;
    codigo = this->socket.recibirCodigoComando();
    this->buffer->pushCodigo(codigo);
}
