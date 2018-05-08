#ifndef CLIENTE_H
#define CLIENTE_H

#include "Buffer.h"
#include "../SocketServidor/SocketServidor.h"

class Cliente
{
    public:
        Cliente(int id, Buffer* buffer);
        virtual ~Cliente();
        void recibirMensaje();
        void enviarMensajes();

    protected:

    private:
        int id;
        Buffer* buffer;
        SocketServidor socket;
};

#endif // CLIENTE_H
