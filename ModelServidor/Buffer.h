#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <queue>
#include <string>

class Buffer
{
    public:
        Buffer(int cantidadClientes);
        virtual ~Buffer();
        unsigned cantidadCodigosEnCanal(int idCanal);
        std::string popCodigoEnCanal(int idCanal);
        void pushCodigo(std::string codigo);

    protected:

    private:
        std::vector<std::queue<std::string>> buffers;
};

#endif // BUFFER_H
