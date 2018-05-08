#ifndef SOCKETSERVIDOR_H
#define SOCKETSERVIDOR_H

#include <string>
class SocketServidor
{
    public:
        SocketServidor();
        virtual ~SocketServidor();
        void enviarCodigoComando(std::string codigo);
        std::string recibirCodigoComando();

    protected:

    private:
};

#endif // SOCKETSERVIDOR_H
