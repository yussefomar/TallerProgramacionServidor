#ifndef MODELOSERVIDOR_H
#define MODELOSERVIDOR_H

#include <vector>
#include "Cliente.h"
#include "Buffer.h"

#include "../Utils/Util_Configuracion.h"

class ModeloServidor
{
public:
    ModeloServidor(int cantidadMaxClientes);
    virtual ~ModeloServidor();
    void enviarMensajes();
    void recibirMensajes();
    void aceptarClientesEntrantes();
    void rechazarClientesEntrantes();
    bool clientesEstanConectados();
    bool hayCambiosPorEnviar();
    void recibirInformacion();
    void verificarUsuario(std::string usuario, unsigned i);
    void verificarPassword(std::string usuario, std::string password, unsigned i);

protected:

private:
    Buffer buffer;
    std::vector<Cliente*> clientes;
    std::vector<User*> usuarios;
    int cantidadClientes;
};

#endif // MODELOSERVIDOR_H
