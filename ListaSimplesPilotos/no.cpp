// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ListaSimplesPilotos
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "no.h"

namespace hil{

Piloto No::getDado() const
{
    return dado;
}
void No::setDado(Piloto newDado)
{
    dado = newDado;
}
No *No::getProximo() const
{
    return proximo;
}
void No::setProximo(No *newProximo)
{
    proximo = newProximo;
}
No::No():
    dado(),
    proximo(0)
{
}
No::No(Piloto dado):
    dado(dado),
    proximo(0)
{
}
QString No::toString()const{
    return dado.toString();
}
}
