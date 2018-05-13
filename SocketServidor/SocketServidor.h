#ifndef SOCKETSERVIDOR_H
#define SOCKETSERVIDOR_H

#include <string>
class SocketServidor
{
public:
    SocketServidor();
    virtual ~SocketServidor();
    void enviarCodigoComando(char codigo);
    void enviarCantidadCambios(unsigned cantidadCambios);
    bool estaConectado();
    char recibirCodigoComando();
    void generarMasterSocketFD();
    void enviarByte(char byte);
    char recibirByte();
    void enviarFinDeCambios();

protected:

private:
    static int masterSocketFD;
    static int masterSocketFDConectado;
    int socketFD;
    bool socketConectado;
};

#endif // SOCKETSERVIDOR_H
