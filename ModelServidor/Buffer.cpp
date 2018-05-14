#include "Buffer.h"
#include <iostream>

#define COMMNULL 0x0A

Buffer::Buffer(int cantidadClientes) :
    buffers(std::vector<std::queue<char>>(cantidadClientes))
{

}

Buffer::~Buffer()
{
    //dtor
}

unsigned Buffer::cantidadCodigos(int idCanal) {
    return this->buffers[idCanal].size();
}

char Buffer::popCodigo(int idCanal) {
    if (this->buffers[idCanal].empty()) return COMMNULL;
    char codigo = this->buffers[idCanal].front();
    this->buffers[idCanal].pop();
    return codigo;
}

void Buffer::pushCodigo(char codigo) {
    char evento = codigo & 0x0F;
    if(evento == COMMNULL) return;
    for(unsigned i = 0; i < this->buffers.size(); ++i) {
        this->buffers[i].push(codigo);

    }
}
