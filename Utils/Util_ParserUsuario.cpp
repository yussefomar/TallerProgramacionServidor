#include <yaml-cpp/yaml.h>
#include <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

#include "../Utils/Util_ParserUsuario.h"

//std::vector<Usuario> usuarios;
std::vector<User> users;

inline bool Util_ParserUsuario::usuarioValido(std::string &name)
{

        if (name.size() > 99 )
        {
           return false;
        }

}

std::vector<User> Util_ParserUsuario::read_yaml_Usuario()
{

 std::vector<YAML::Node> baseNode = YAML::LoadAllFromFile("./Configs/Usuarios.yaml");


           for (auto &document : baseNode) {
            std::for_each(document["users"].begin(), document["users"].end(), [&users](YAML::Node user) {
                users.emplace_back(user);
            });
        }
return users;

//Funciona muy bien
////////////        usuarios.clear();
////////////        for (auto &document : baseNode)
////////////        {
////////////            usuarios.emplace_back(document["us1"]);
////////////        }
////////////        for (auto &document : baseNode)
////////////        {
////////////            usuarios.emplace_back(document["us2"]);
////////////        }
////////////        for (auto &document : baseNode)
////////////        {
////////////            usuarios.emplace_back(document["us3"]);
////////////        }
////////////        for (auto &document : baseNode)
////////////        {
////////////            usuarios.emplace_back(document["us4"]);
////////////        }
////////////        for (auto &document : baseNode)
////////////        {
////////////            usuarios.emplace_back(document["us5"]);
////////////        }


}

std::vector<User> Util_ParserUsuario::GetUsuarios()
{
    try
    {
        this->read_yaml_Usuario();
        return users;
    }
    catch(YAML::Exception ex)
    {
        //NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo xxxxxx", "Util_ParserUsuario.cpp");
       // parametrosObtenidos.esValido = 0;
    }

}


