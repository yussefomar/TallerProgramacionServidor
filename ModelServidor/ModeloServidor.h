#ifndef MODELOSERVIDOR_H
#define MODELOSERVIDOR_H

#include <vector>
#include "Cliente.h"
#include "Buffer.h"

class ModeloServidor
{
    public:
        ModeloServidor(int cantidadMaxClientes);
        virtual ~ModeloServidor();

        void enviarMensajes();
        void recibirMensajes();

    protected:

    private:
        Buffer buffer;
        std::vector<Cliente*> clientes;
};

#endif // MODELOSERVIDOR_H
