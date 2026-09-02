// Funcao: llde - estrutura de dados da lista encadeada e suas operacoes.
// Projeto: ListaDuplamenteEncadeada
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "llde.h"
#include "no.h"
#include <QString>

namespace hil{

LLDE::LLDE():
    inicio(0),
    fim(0),
    quantElementos(0)
{
}

int LLDE::getQuantElementos() const
{
    return quantElementos;
}

bool LLDE::estaVazia() const
{
    return(quantElementos == 0);
}

void LLDE::inserirInicio(int elemento)
{
    try{
        No *novoNo = new No(elemento);

        if (estaVazia()) {
            inicio = fim = novoNo;

        } else {
            novoNo->setProximo(inicio);
            inicio->setAnterior(novoNo);
            inicio = novoNo;
        }
        quantElementos++;

        } catch (std::bad_alloc& erro) {
        throw QString("O Novo nó não pôde ser criado Caga Tronco");
     }
}

void LLDE::retirarInicio()
{
    if(estaVazia()) throw QString ("A lista esta vazia Jararaquaro");

    if (quantElementos == 1) {
            delete inicio;
            inicio = fim = nullptr;

        } else {
            inicio = inicio->getProximo();
            delete inicio->getAnterior();
            inicio->setAnterior(nullptr);
        }
        quantElementos--;
}

int LLDE::acessarInicio() const
{
    if(estaVazia()) throw QString ("A lista esta vazia Iveto Sangalo");

    return inicio->getDado();
}

void LLDE::inserirFim(int elemento)
{
    try {
        No *novoNo = new No(elemento);

        if (estaVazia()) {
            inicio = fim = novoNo;

        } else {
            novoNo->setAnterior(fim);
            fim->setProximo(novoNo);
            fim = novoNo;
        }
        quantElementos++;

    } catch (std::bad_alloc& erro) {
        throw QString ("O Novo No não pôde ser criado Rango Brabo");
    }
}

void LLDE::retirarFim()
{
    if (estaVazia()) throw QString ("A lista esta vazia Sereio");

    if (quantElementos == 1) {
        delete fim;
        inicio = fim = nullptr;

    } else {
        fim = fim->getAnterior();
        delete fim->getProximo();
        fim->setProximo(nullptr);
    }
    quantElementos--;
}

int LLDE::acessarFim() const
{
    if (estaVazia()) throw QString("A lista está vazia CNPJOTO");

    return fim->getDado();
}

void LLDE::inserirPosicao(int elemento, int pos)
{
    if (pos < 0 || pos > quantElementos) throw QString("Invalid Position My Friend");

    if (pos == 0) inserirInicio(elemento);
    if (pos == quantElementos) inserirFim(elemento);

    No *pAux = inicio;
    for (int i = 0; i < pos; i++) {
        pAux = pAux->getProximo();
    }
    No *novoNo = new No(elemento);
    novoNo->setAnterior(pAux->getAnterior());
    novoNo->setProximo(pAux);
    pAux->getAnterior()->setProximo(novoNo);
    pAux->setAnterior(novoNo);
    quantElementos++;
}

void LLDE::retirarPosicao(int pos)
{
    if (pos < 0 || pos >= quantElementos) throw QString("Invalid Position My Friend");

    if (pos == 0) {
        retirarInicio();
        return;
    }
    if (pos == quantElementos - 1) {
        retirarFim();
        return;
    }

    No *pAux = inicio;
    for (int i = 0; i < pos; i++) {
        pAux = pAux->getProximo();
    }

    pAux->getAnterior()->setProximo(pAux->getProximo());
    pAux->getProximo()->setAnterior(pAux->getAnterior());

    delete pAux;
    quantElementos--;
}

int LLDE::acessarPosicao(int pos) const
{
    if (pos < 0 || pos >= quantElementos) throw QString("Invalid Position My Friend");

    if (pos == 0) return inicio->getDado();
    if (pos == quantElementos - 1) return fim->getDado();

    No *pAux = inicio;
    for (int i = 0; i < pos; i++) {
        pAux = pAux->getProximo();
    }

    return pAux->getDado();
}

void LLDE::inserirOrdenado(int elemento)
{
    try {
        if (estaVazia()) {
            inserirInicio(elemento);
            return;
        }

        No* pAux = inicio;

        while (pAux != nullptr && elemento >= pAux->getDado()) {
            if (elemento == pAux->getDado()) {
                throw QString("Elemento já existe na lista");
            }
            pAux = pAux->getProximo();
        }

        No* novoNo = new No(elemento);

        if (pAux != nullptr) {
            novoNo->setAnterior(pAux->getAnterior());
            novoNo->setProximo(pAux);
            if (pAux->getAnterior() != nullptr) {
                pAux->getAnterior()->setProximo(novoNo);
            } else {
                inicio = novoNo;
            }
            pAux->setAnterior(novoNo);
        } else {
            novoNo->setAnterior(fim);
            fim->setProximo(novoNo);
            fim = novoNo;
        }

        quantElementos++;
    } catch (std::bad_alloc& erro) {
        throw QString("Memória foi pro pau");
    }
}

QString LLDE::toString_InicioFim() const
{
    QString result;
    No *percorre = inicio;

    while (percorre != nullptr) {
        result += "| " + QString::number(percorre->getDado()) + " |";

        if (percorre->getProximo() != nullptr) {
            result += " -> ";
        }

        percorre = percorre->getProximo();
    }

    return result;
}

QString LLDE::toString_FimInicio() const
{
    QString result;
    No *percorre = fim;

    while (percorre != nullptr) {
        result += "| " + QString::number(percorre->getDado()) + " |";

        if (percorre->getAnterior() != nullptr) {
            result += " -> ";
        }

        percorre = percorre->getAnterior();
    }

    return result;
}
}
