#ifndef UTIL_PARSERUSUARIO_H_
#define UTIL_PARSERUSUARIO H_

#include <iostream>
#include <string>
#include <list>
#include <yaml-cpp/yaml.h>


using namespace std;

class Servidor
{
public:
    Servidor(const YAML::Node &node) :
        cantidadClientes(node["cantidadCli"].as<std::string>()) {};
    std::string const &get_cantidadClientes() const
    {
        return cantidadClientes;
    };
private:
    std::string cantidadClientes;
};

class User
{
public:
    User(const YAML::Node &node) :
        name(node["name"].as<std::string>()),
        password(node["password"].as<std::string>()) {};
    std::string const &get_name() const
    {
        return name;
    };
    std::string const &get_password() const
    {
        return password;
    };
private:
    std::string name;
    std::string password;
};



class Util_ParserUsuario
{
public:
    std::vector<User> GetUsuarios();
    std::vector<User> read_yaml_Usuario();
    int GetCantidadClientes();
    Servidor read_yaml_CantidadClientes();
private:



};



#endif
