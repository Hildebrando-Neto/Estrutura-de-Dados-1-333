// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ListaDuplamenteEncadeada
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "no.h"

namespace hil{

No *No::getAnterior() const
{
    return anterior;
}

void No::setAnterior(No *newAnterior)
{
    anterior = newAnterior;
}

int No::getDado() const
{
    return dado;
}

void No::setDado(int newDado)
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
    anterior(0),
    dado(0),
    proximo(0)
{

}

No::No(int dado):
    anterior(0),
    dado(dado),
    proximo(0)
{
}
}
