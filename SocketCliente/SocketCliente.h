#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H

#include <string>

class SocketCliente
{
    public:
        SocketCliente();
        virtual ~SocketCliente();

        void enviarCodigoComando(std::string codigo);
        std::string recibirCodigoComando();

    protected:

    private:
};

#endif // SOCKETCLIENTE_H
