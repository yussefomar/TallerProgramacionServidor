#ifndef UTIL_PARSERUSUARIO_H_
#define UTIL_PARSERUSUARIO H_

#include <iostream>
#include <string>
#include <list>
#include <yaml-cpp/yaml.h>


using namespace std;


////class Usuario
////{
////public:
////   Usuario(const YAML::Node &node) :
////        name(node["name"].as<std::string>()),
////        pass(node["pass"].as<std::string>()) {};
////    std::string const &get_name() const
////    {
////        return name;
////    };
////    std::string const &get_pass() const
////    {
////        return pass;
////    };
////private:
////    std::string name;
////    std::string pass;
////
////};

class User {
public:
	User(const YAML::Node &node) :
		name(node["name"].as<std::string>()),
		password(node["password"].as<std::string>()) {};
	std::string const &get_name() const { return name; };
	std::string const &get_password() const { return password; };
private:
	std::string name;
	std::string password;
};



class Util_ParserUsuario
{
public:
    inline bool usuarioValido(std::string &name);
    std::vector<User> GetUsuarios();
    std::vector<User> read_yaml_Usuario();
private:



};



#endif
