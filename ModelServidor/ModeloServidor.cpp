#include "ModeloServidor.h"

#define LI_NOMBRE_OK 0X0B //NOMBRE CORRECTO.
#define LI_NOMBRE_ERROR 0X0C //NOMBRE INCORRECTO.
#define LI_NOMBRE_REPETIDO 0X0D //NOMBRE EXISTENTE.
#define LI_CREDENCIALES_OK 0X0E //CREDENCIALES CORRECTAS.
#define LI_CREDENCIALES_ERROR 0X0F //CREDENCIALES INCORRECTAS.

ModeloServidor::ModeloServidor()
{

}

ModeloServidor::~ModeloServidor()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        delete this->clientes[i];
    }
    delete this->buffer;
}

void ModeloServidor::aceptarClientesEntrantes()
{
    for(unsigned i = 0; i < this->clientes.size(); ++i)
    {
        this->clientes[i] = new Cliente(this->buffer);
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
    bool sinUsuario = true;
    bool sinPass = true;
    char usuario;
    char password;
    while( sinUsuario || sinPass )
    {
        if(sinUsuario)
        {
            for(unsigned i = 0; i < this->clientes.size(); ++i)
            {
                usuario = this->clientes[i]->recibirUsuario();
                sinUsuario = this->verificarUsuario(usuario, i);
            }
        }
        else if((!sinUsuario) && sinPass)
        {
            for(unsigned i = 0; i < this->clientes.size(); ++i)
            {
                password = this->clientes[i]->recibirPassword();
                sinPass = this->verificarPassword(usuario, password, i);
            }
        }
    }
    return;
}

bool ModeloServidor::verificarUsuario(char usuario, unsigned i)
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
                return true;
            }
        }
    }
    for(unsigned j = 0; j < this->usuariosNombre.size(); ++j)
    {
        if(this->usuariosNombre[j] == usuario)
        {
            //0X0B NOMBRE CORRECTO Y LIBRE. //ACTUALIZO EL CLIENTE.
            this->clientes[i]->nombreUsuario = usuario;
            this->clientes[i]->enviarRespuesta(0X0B);
            return false;
        }
    }
    // 0X0C NOMBRE INCORRECTO.
    this->clientes[i]->enviarRespuesta(0X0C);
    return true;
}

bool ModeloServidor::verificarPassword(char usuario, char password, unsigned i)
{
    //EL INDICE DEL USUARIO Y EL PASSWORD POR LÓGICA DEBEN DE COINCIDIR.-
    for(unsigned j = 0; j < this->usuariosNombre.size(); ++j)
    {
        if(this->usuariosNombre[j] == usuario && this->usuariosPassword[j] == password)
        {
            //0X0E NOMBRE CORRECTO Y CONTRASEÑA CORRECTA.
            this->clientes[i]->enviarRespuesta(0X0E);
            return false;
        }
    }
    // 0X0F CREDENCIALES CORRECTAS. //ACTUALIZO EL CLIENTE.
    this->clientes[i]->nombreUsuario = usuario;
    this->clientes[i]->passwordUsuario = password;
    this->clientes[i]->enviarRespuesta(0X0F);
    return true;
}

char ModeloServidor::hashear(std::string unString)
{
    char code;
    for(unsigned i = 0; i < unString.size(); ++i)
    {
        code = code | unString[i];
    }
    return code;
}

void ModeloServidor::setClientesPermitidos(int cantidadMaxClientes)
{
    this->buffer = new Buffer(cantidadMaxClientes);
    this->clientes = (std::vector<Cliente*>(cantidadMaxClientes));
}

void ModeloServidor::setIpYPuerto(std::string ip, std::string puerto)
{
    this->ip = ip;
    this->puerto = puerto;
}
