#include "ModeloServidor.h"

#define LI_NOMBRE_OK 0X0B //NOMBRE CORRECTO.
#define LI_NOMBRE_ERROR 0X0C //NOMBRE INCORRECTO.
#define LI_NOMBRE_REPETIDO 0X0D //NOMBRE EXISTENTE.
#define LI_CREDENCIALES_OK 0X0E //CREDENCIALES CORRECTAS.
#define LI_CREDENCIALES_ERROR 0X0F //CREDENCIALES INCORRECTAS.

ModeloServidor::ModeloServidor(int cantidadClientes) :
    buffer(cantidadClientes),
    clientes(std::vector<Cliente*>(cantidadClientes))
{

}

ModeloServidor::~ModeloServidor()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        delete this->clientes[i];
    }
}

void ModeloServidor::aceptarClientesEntrantes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i] = new Cliente(&(this->buffer));
        this->clientes[i]->enviarId(i);
    }
}

void ModeloServidor::rechazarClientesEntrantes()
{
    //en hilo aparte aceptamos clientes pero enviamos mensajes de
    //que el juego ya esta completo.
}

void ModeloServidor::enviarMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i]->enviarMensaje();
    }
    return;
}

void ModeloServidor::recibirMensajes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i]->recibirMensaje();
    }
    return;
}

bool ModeloServidor::clientesEstanConectados()
{
    bool estanConectados = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        estanConectados |= this->clientes[i]->estaConectado();
    }
    return estanConectados;
}


bool ModeloServidor::hayCambiosPorEnviar()
{
    bool hayCambios = false;

    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        hayCambios |= this->clientes[i]->hayCambios();
    }
    return hayCambios;
}

void ModeloServidor::recibirInformacion()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        std::string usuario = this->clientes[i]->recibirUsuario();
        this->verificarUsuario(usuario, i);
        std::string password = this->clientes[i]->recibirPassword();
        this->verificarPassword(usuario, password, i);
    }
    return;
}

void ModeloServidor::verificarUsuario(std::string usuario, unsigned i)
{
    for(unsigned j = 0; j < this->clientes.size(); ++j)
    {
        //Para todos menos para el usuario actual.
        if(i != j)
        {   //Si hay otro usuario con el mismo nombre está mal.
            if(this->clientes[j]->nombreUsuario == usuario)
            {
                //0X0D NOMBRE OCUPADO.
                this->clientes[i]->enviarRespuesta(0X0D);
                return;
            }
        }
    }
    for(unsigned j = 0; j < this->usuarios.size(); ++j)
    {
        if(this->usuarios[j]->get_name() == usuario)
        {
            //0X0B NOMBRE CORRECTO Y LIBRE.
            this->clientes[i]->enviarRespuesta(0X0B);
            return;
        }
    }
    // 0X0C NOMBRE INCORRECTO.
    this->clientes[i]->enviarRespuesta(0X0C);
}

void ModeloServidor::verificarPassword(std::string usuario, std::string password, unsigned i)
{
    for(unsigned j = 0; j < this->usuarios.size(); ++j)
    {
        if(this->usuarios[j]->get_name() == usuario && this->usuarios[j]->get_password() == password)
        {
            //0X0E NOMBRE CORRECTO Y CONTRASEÑA CORRECTA.
            this->clientes[i]->enviarRespuesta(0X0E);
            return;
        }
    }
    // 0X0F CREDENCIALES CORRECTAS.
    this->clientes[i]->enviarRespuesta(0X0F);
}
