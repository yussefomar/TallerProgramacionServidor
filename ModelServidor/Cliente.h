#ifndef CLIENTE_H
#define CLIENTE_H

#include "Buffer.h"
#include "../SocketServidor/SocketServidor.h"

class Cliente
{
public:
    Cliente(Buffer* buffer);
    virtual ~Cliente();
    void recibirMensaje();
    void enviarMensaje();
    bool estaConectado();
    bool hayCambios();
    void enviarId(unsigned id);
    std::string recibirUsuario();
    std::string recibirPassword();
    void enviarRespuesta(char codigo);
    std::string hashear(char codigo);

protected:

private:
    static int contadorClientes;
    int id;
    Buffer* buffer;
    SocketServidor socket;
};

#endif // CLIENTE_H
