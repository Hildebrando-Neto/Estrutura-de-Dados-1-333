#include "No.h"

// Funcao: implementa a criacao e destruicao de cada nodo da arvore.
// Ao destruir um nodo, tambem remove recursivamente seus filhos para evitar vazamento de memoria.

namespace ED1{
No::No(int dado):
    dado(dado),
    direita(nullptr),
    esquerda(nullptr)
{
}

No::~No()
{
    std::cout << "Metodo Destrutor do No Elemento = " << this->dado << std::endl;
    if (this->esquerda != nullptr) {
        delete this->esquerda;
        this->esquerda = nullptr;
    }
    if (this->direita != nullptr) {
        delete this->direita;
        this->direita = nullptr;
    }
}

}
