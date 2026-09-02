// Funcao: listalse - estrutura de dados da lista encadeada e suas operacoes.
// Projeto: ListaSimplesPilotos
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "listalse.h"

namespace hil {

int ListaLSE::getQe() const {
    return qe;
}

bool ListaLSE::estaVazia() const {
    return (qe == 0);
}

void ListaLSE::inserirInicio(Piloto dado) {
    try {
        No *novoNo = new No(dado);
        novoNo->setProximo(inicio);
        inicio = novoNo;
        qe++;

    } catch (std::bad_alloc &erro) {
        throw QString("O Novo nó não pôde ser criado");
    }
}

Piloto ListaLSE::acessarInicio() const {
    if (estaVazia()) throw QString("A Lista está vazia");

            return inicio->getDado();
}

void ListaLSE::retirarInicio() {
    if (estaVazia()) throw QString("A Lista está vazia");

            No *pAux = inicio;
    inicio = inicio->getProximo();
    qe--;

    delete pAux;
}

Piloto ListaLSE::acessarFim() const {
    if (estaVazia()) throw QString("A Lista está vazia");

            No *pAux = inicio;

    while (pAux->getProximo() != nullptr) {
        pAux = pAux->getProximo();
    }
    return pAux->getDado();
}

void ListaLSE::inserirFim(Piloto dado) {
    try {
        No *novoNo = new No(dado);
        if (estaVazia()) {
            inicio = novoNo;
            qe++;
            return;
        }
        No *pAux = inicio;

        while (pAux->getProximo() != nullptr) {
            pAux = pAux->getProximo();
        }
        pAux->setProximo(novoNo);
        qe++;
    } catch (std::bad_alloc &erro) {
        throw QString("O Novo nó não pôde ser criado");
    }
}

void ListaLSE::retirarFim() {
    if (estaVazia()) throw QString("A Lista está vazia");
            if (qe == 1) {
            delete inicio;
            inicio = nullptr;
            qe = 0;
            return;
        }
    No *pAnt = nullptr;
    No *pAux = inicio;

    while (pAux->getProximo() != nullptr) {
        pAnt = pAux;
        pAux = pAux->getProximo();
    }
    pAnt->setProximo(nullptr);
    qe--;
    delete pAux;
}

void ListaLSE::inserirPosicao(int posicao, Piloto dado) {
    if (posicao < 1 || posicao > qe + 1) throw QString("Posição inválida");

    if (posicao == 1) {
        inserirInicio(dado);
        return;
    }

    try {
        No *novoNo = new No(dado);
        No *pAux = inicio;
        int pular = 1;

        while (pular < posicao - 1) {
            pAux = pAux->getProximo();
            pular++;
        }

        novoNo->setProximo(pAux->getProximo());
        pAux->setProximo(novoNo);
        qe++;

    } catch (std::bad_alloc &erro) {
        throw QString("O Novo nó não pôde ser criado");
    }
}

Piloto ListaLSE::acessarPos(int posicao) const {
    if (estaVazia()) throw QString("A Lista está vazia");
            if (posicao < 1 || posicao > qe) throw QString("Posição inválida");

    No *pAux = inicio;
    int pular = 1;

    while (pular < posicao) {
        pAux = pAux->getProximo();
        pular++;
    }

    return pAux->getDado();
}

void ListaLSE::retirarPosicao(int posicao) {
    if (estaVazia()) throw QString("A Lista está vazia");
            if (posicao < 1 || posicao > qe) throw QString("Posição inválida");

    if (posicao == 1) {
        retirarInicio();
        return;
    }

    No *pAnt = inicio;
    No *pAux = inicio->getProximo();
    int pular = 2;

    while (pular < posicao) {
        pAnt = pAux;
        pAux = pAux->getProximo();
        pular++;
    }

    pAnt->setProximo(pAux->getProximo());
    delete pAux;
    qe--;
}

void ListaLSE::ordenarPorCodigoCrescente() const {

    if (estaVazia() || inicio->getProximo() == nullptr) {
        return;
    }
    No *pAux = inicio;
    No *pInt = nullptr;

    while (pAux != nullptr) {
        pInt = pAux->getProximo();

        while (pInt != nullptr) {
            if (pAux->getDado().getCodigo() > pInt->getDado().getCodigo()) {
                Piloto temp = pAux->getDado();
                pAux->setDado(pInt->getDado());
                pInt->setDado(temp);
            }

            pInt = pInt->getProximo();
        }

        pAux = pAux->getProximo();
    }
}

void ListaLSE::ordenarPorNomeDecrescente() const {
    if (estaVazia() || inicio->getProximo() == nullptr) {
        throw QString("Esta Vazia");
    }

    No *pAux = inicio;
    No *pInt = nullptr;

    while (pAux != nullptr) {
        pInt = pAux->getProximo();

        while (pInt != nullptr) {
            if (pAux->getDado().getNome() < pInt->getDado().getNome()) {
                Piloto temp = pAux->getDado();
                pAux->setDado(pInt->getDado());
                pInt->setDado(temp);
            }
            pInt = pInt->getProximo();
        }
        pAux = pAux->getProximo();
    }
}

QString ListaLSE::toString() const {
    if (estaVazia()) throw QString("A Lista está vazia");

            QString saida = "Dados da Lista: ";

    No *pAux = inicio;

    while (pAux != nullptr) {
        saida += pAux->getDado().toString();
        pAux = pAux->getProximo();
    }
    return saida;
}

ListaLSE::ListaLSE() :
    inicio(nullptr),
    qe(0) {
}
}
