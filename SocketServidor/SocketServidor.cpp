#include "SocketServidor.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

#include <iostream>

#include <string.h>
#include <stdio.h>
#include <errno.h>

#include <stdbool.h>

#define LOCALHOST "localhost" //puede ser NULL tambien
#define PUERTOSERVER "8080"
#define FORSKTOPT 1
#define MAXCONECT 20

#define SIZECOMMAND 2
#define SIZEBYTE 1

#define ENTIDAD 0
#define EVENTO 1

SocketServidor::SocketServidor()
{
    if(!SocketServidor::masterSocketFDConectado)
    {
        this->generarMasterSocketFD();
    }

    /*intentamos aceptar un cliente entrante*/
    do
    {
        this->socketFD = accept(SocketServidor::masterSocketFD, NULL, NULL);
    }
    while (this->socketFD == -1);
    this->socketConectado = true;
}

SocketServidor::~SocketServidor()
{
    shutdown(this->socketFD, SHUT_RDWR);
    close(this->socketFD);
    if(SocketServidor::masterSocketFDConectado)
    {
        shutdown(SocketServidor::masterSocketFD, SHUT_RDWR);
        close(SocketServidor::masterSocketFD);
        SocketServidor::masterSocketFDConectado = 0;
    }
}

int SocketServidor::masterSocketFD = 0;
int SocketServidor::masterSocketFDConectado = 0;

void SocketServidor::generarMasterSocketFD()
{
    struct addrinfo hints;
    struct addrinfo *posibilidades;
    int resultado = 0;
    int posibleSocketFD = 0;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IP v4*/
    hints.ai_socktype = SOCK_STREAM; /* Protocolo TCP */
    hints.ai_flags = AI_PASSIVE; /*For server*/

    std::string ip = LOCALHOST;
    std::string puerto = PUERTOSERVER;

    resultado = getaddrinfo(ip.c_str(), puerto.c_str(), &hints, &posibilidades);

    /*Pasar esto a un tipo de enunciado de error en logg del servidor*/
    if (resultado != 0)
    {
        std::cerr << "ERROR EN ADDRINFO: " << gai_strerror(resultado) << std::endl;
        return;
    }

    posibleSocketFD = socket(posibilidades->ai_family,
                             posibilidades->ai_socktype,
                             posibilidades->ai_protocol);

    /*Pasar esto a un tipo de enunciado de error en logg del servidor*/
    if (posibleSocketFD == -1)
    {
        std::cerr << "ERROR EN SKT: " << gai_strerror(resultado) << std::endl;
        freeaddrinfo(posibilidades);//ver si esto no lo podemos poner en alguna clase RAII
        return;
    }

    /*Activamos opcion reusar direccion*/
    int val = FORSKTOPT;
    resultado = setsockopt(posibleSocketFD, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (resultado != 0)
    {
        std::cerr << "ERROR EN SKTOPT: " << gai_strerror(resultado) << std::endl;
        close(posibleSocketFD);
        freeaddrinfo(posibilidades);
        return;
    }

    resultado = bind(posibleSocketFD, posibilidades->ai_addr, posibilidades->ai_addrlen);
    if (resultado != 0)
    {
        std::cerr << "ERROR EN BIND: " << gai_strerror(resultado) << std::endl;
        close(posibleSocketFD);
        freeaddrinfo(posibilidades);
        return;
    }

    freeaddrinfo(posibilidades);

    resultado = listen(posibleSocketFD, MAXCONECT);
    if (resultado != 0)
    {
        std::cerr << "ERROR EN LISTEN: " << gai_strerror(resultado) << std::endl;
        close(posibleSocketFD);
        return ;
    }

    SocketServidor::masterSocketFD = posibleSocketFD;
    SocketServidor::masterSocketFDConectado = 1;
}

char SocketServidor::recibirCodigoComando()
{
    return this->recibirByte();
}

void SocketServidor::enviarCodigoComando(char comando)
{
    this->enviarByte(comando);
}

void SocketServidor::enviarCantidadCambios(unsigned cantidadCambios)
{
    char byte = 0x00;
    byte = byte + cantidadCambios;
    this->enviarByte(byte);
}

bool SocketServidor::estaConectado()
{
    return this->socketConectado;
}

void SocketServidor::enviarByte(char byte)
{
    this->socketConectado = send(this->socketFD, &byte, sizeof(char), MSG_NOSIGNAL) > 0;
}

char SocketServidor::recibirByte() {
    char byte;
    this->socketConectado = recv(this->socketFD, &byte, sizeof(char), MSG_NOSIGNAL) > 0;
    return byte;
}

void SocketServidor::enviarFinDeCambios() {
    char byte = 0xFF;
    this->enviarByte(byte);
    this->enviarByte(byte);
}
