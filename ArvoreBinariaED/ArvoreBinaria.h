#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include "No.h"
#include <string>
#include <iostream>
#include "iarvorebinaria.h"

// Funcao: define a estrutura e os metodos da arvore binaria de busca.
// Ela encapsula a raiz, a insercao, a remocao e a impressao em ordem.

namespace ED1{

class ArvoreBinaria : public IArvoreBinaria
{
private:
    No* raiz;

private:
    void inserirRecursivo(No **raiz, int elemento);
    void removerRecursivo(No **raiz, int elemento);
    void emOrdem(No* raiz) const;
    int retornar_Maior(No **raiz);

public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void inserir(int elemento) override { this->inserirRecursivo(&raiz, elemento); }
    void remover(int elemento) override { this->removerRecursivo(&raiz, elemento); }
    void imprimir() override { emOrdem(raiz); }
};
}
#endif // ARVOREBINARIA_H
