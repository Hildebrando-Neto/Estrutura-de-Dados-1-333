// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ListaSimplesPilotos
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef NO_H
#define NO_H

#include<QString>
#include<piloto.h>

namespace hil{

class No
{
private:
    Piloto dado;
    No *proximo;
public:
    No();
    No(Piloto dado);
    Piloto getDado() const;
    void setDado(Piloto newDado);
    No *getProximo() const;
    void setProximo(No *newProximo);
    QString toString()const;
};
}
#endif // NO_H
