#ifndef MODELOSERVIDOR_H
#define MODELOSERVIDOR_H

#include <vector>
#include "Cliente.h"
/*#include "Buffer.h"*/

class ModeloServidor
{
public:
    ModeloServidor();
    virtual ~ModeloServidor();
    void enviarMensajes();
    void recibirMensajes();
    void aceptarClientesEntrantes();
    void rechazarClientesEntrantes();
    bool clientesEstanConectados();
    bool hayCambiosPorEnviar();
    void recibirInformacion();
    bool verificarUsuario(char usuario, unsigned i);
    bool verificarPassword(char usuario, char password, unsigned i);
    char hashear(std::string unString);
    std::vector<char> usuariosNombre;
    std::vector<char> usuariosPassword;
    void setClientesPermitidos(int cantidadMaxClientes);
    void setIpYPuerto(std::string ip, std::string puerto);

protected:

private:
    Buffer* buffer;
    std::vector<Cliente*> clientes;
    int cantidadClientes;
    std::string ip;
    std::string puerto;
};

#endif // MODELOSERVIDOR_H
