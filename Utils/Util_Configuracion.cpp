#include <yaml-cpp/yaml.h>
#include <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "../Utils/Util_Configuracion.h"

Util_ParserUsuario parser;
/**ModeloServidor* model, Util_LoggerObserver* loggerObserver**/
Util_Configuracion::Util_Configuracion()
{
//   this->Attach(loggerObserver);
//   parser.Attach(loggerObserver);
    try
    {
        std::vector<User> users = parser.GetUsuarios();
        int cantidadClientes = parser.GetCantidadClientes();

        //this->modeloServidor = model;
        //METODOS PARA CONFIGURAR EL MODEL
        //this->model->SetUsuarios(users);
        //this->model->setIp(parametros.ip);

    }
    catch(...)
    {
        // NotifyError("Error desconocido que no se ha podido especificar.", "Util_Configuracion.cpp");
    }
}

void Util_Configuracion::close()
{

}

Util_Configuracion::~Util_Configuracion()
{

    this->close();
}




