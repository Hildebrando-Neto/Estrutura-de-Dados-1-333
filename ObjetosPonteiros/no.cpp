// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ObjetosPonteiros
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "no.h"

namespace hil{

No::No(std::string nome, int elemento):
    nome(nome),
    elemento(elemento),
    proximo(0)
{
}

const std::string &No::getNome() const
{
    return nome;
}

void No::setNome(const std::string &newNome)
{
    nome = newNome;
}

int No::getElemento() const
{
    return elemento;
}

void No::setElemento(int newElemento)
{
    elemento = newElemento;
}

No *No::getProximo() const
{
    return proximo;
}

void No::setProximo(No *newProximo)
{
    proximo = newProximo;
}

std::string No::toString() const
{
    std::string saida = "Nome: " + nome + "\n";
    saida += "Elemento: " + std::to_string(elemento) + "\n";
    return saida;
}

}
