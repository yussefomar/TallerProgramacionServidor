#include "Buffer.h"
#include <iostream>
Buffer::Buffer(int cantidadClientes) :
    buffers(std::vector<std::queue<std::string>>(cantidadClientes))
{

}

Buffer::~Buffer()
{
    //dtor
}

unsigned Buffer::cantidadCodigos(int idCanal) {
    return this->buffers[idCanal].size();
}

std::string Buffer::popCodigo(int idCanal) {
    std::string codigo = this->buffers[idCanal].front();
    this->buffers[idCanal].pop();
    return codigo;
}

void Buffer::pushCodigo(std::string codigo) {
    for(unsigned i = 0; i < this->buffers.size(); ++i) {
        this->buffers[i].push(codigo);

    }
}
