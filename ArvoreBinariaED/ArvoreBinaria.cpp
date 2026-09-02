#include "ArvoreBinaria.h"

// Funcao: implementa as operacoes de insercao, remocao e viagem da arvore binaria de busca.
// Aqui ficam as regras de busca, remocao de nos e impressao em ordem.

namespace ED1{
ArvoreBinaria::ArvoreBinaria():
    raiz(nullptr)
{
}

ArvoreBinaria::~ArvoreBinaria()
{
    if (raiz != nullptr) {
        delete raiz;
        raiz = nullptr;
    }
}

void ArvoreBinaria::inserirRecursivo(No **raiz, int elemento){
    if (*raiz == nullptr) {
        *raiz = new No(elemento);
        return;
    }

    if (elemento < (*raiz)->getDado()) {
        inserirRecursivo(&(*raiz)->esquerda, elemento);
        return;
    }

    if (elemento > (*raiz)->getDado()) {
        inserirRecursivo(&(*raiz)->direita, elemento);
        return;
    }

    throw std::string("Elemento ja Existe");
}

void ArvoreBinaria::emOrdem(No* raiz) const {
    if (raiz != nullptr) {
        emOrdem(raiz->getEsquerda());
        std::cout << std::endl << "Elemento=>  " << raiz->getDado();
        emOrdem(raiz->getDireita());
    }
}

int ArvoreBinaria::retornar_Maior(No **raiz){
    if ((*raiz)->direita != nullptr) {
        return retornar_Maior(&(*raiz)->direita);
    }

    No *aux = *raiz;
    int valor = (*raiz)->getDado();
    *raiz = (*raiz)->esquerda;
    aux->esquerda = nullptr;
    aux->direita = nullptr;
    delete aux;
    return valor;
}

void ArvoreBinaria::removerRecursivo(No **raiz, int elemento){
    if (*raiz == nullptr) {
        throw std::string("Elemento nao Existe");
    }

    if ((*raiz)->getDado() == elemento) {
        No *aux = *raiz;

        if ((*raiz)->esquerda == nullptr) {
            *raiz = (*raiz)->direita;
            aux->esquerda = nullptr;
            aux->direita = nullptr;
            delete aux;
            return;
        }

        if ((*raiz)->direita == nullptr) {
            *raiz = (*raiz)->esquerda;
            aux->esquerda = nullptr;
            aux->direita = nullptr;
            delete aux;
            return;
        }

        (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
        return;
    }

    if ((*raiz)->getDado() < elemento) {
        removerRecursivo(&(*raiz)->direita, elemento);
        return;
    }

    removerRecursivo(&(*raiz)->esquerda, elemento);
}

}
