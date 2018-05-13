#include "Buffer.h"
#include <iostream>
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
    char codigo = this->buffers[idCanal].front();
    this->buffers[idCanal].pop();
    return codigo;
}

void Buffer::pushCodigo(char codigo) {
    for(unsigned i = 0; i < this->buffers.size(); ++i) {
        this->buffers[i].push(codigo);

    }
}
