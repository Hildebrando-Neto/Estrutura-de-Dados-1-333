// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ObjetosPonteiros
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef NO_H
#define NO_H

#include <string>

namespace hil{

class No
{
private:
    std::string nome;
    int elemento;
    No* proximo;
public:
    No(std::string, int elemento);
    const std::string &getNome() const;
    void setNome(const std::string &newNome);
    int getElemento() const;
    void setElemento(int newElemento);
    No *getProximo() const;
    void setProximo(No *newProximo);
    std::string toString() const;
};
}
#endif // NO_H
