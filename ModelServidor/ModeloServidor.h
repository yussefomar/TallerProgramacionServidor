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
    void aceptarClientesEntrantes();
    void rechazarClientesEntrantes();
    bool clientesEstanConectados();
    bool hayCambiosPorEnviar();
    void recibirInformacion();
    void verificarUsuario(char usuario, unsigned i);
    void verificarPassword(char usuario, char password, unsigned i);
    char hashear(std::string unString);
    std::vector<char> usuariosNombre;
    std::vector<char> usuariosPassword;

protected:

private:
    Buffer buffer;
    std::vector<Cliente*> clientes;
    int cantidadClientes;
};

#endif // MODELOSERVIDOR_H
