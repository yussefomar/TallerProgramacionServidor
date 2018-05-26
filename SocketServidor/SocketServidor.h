#ifndef SOCKETSERVIDOR_H
#define SOCKETSERVIDOR_H

#include <string>
class SocketServidor
{
public:
    SocketServidor();
    virtual ~SocketServidor();
    bool estaConectado();
    void generarMasterSocketFD();
    void enviarByte(char byte);
    char recibirByte();

protected:

private:
    static int masterSocketFD;
    static int masterSocketFDConectado;
    int socketFD;
    bool socketConectado;
};

#endif // SOCKETSERVIDOR_H
