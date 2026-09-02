#ifndef IARVOREBINARIA_H
#define IARVOREBINARIA_H

// Funcao: define a interface abstrata da arvore binaria.
// Ela padroniza os metodos basicos de insercao, impressao e remocao
// que qualquer implementacao da estrutura deve fornecer.

namespace ED1{

class IArvoreBinaria{
public:
    virtual void inserir(int elemento) = 0;
    virtual void imprimir() = 0;
    virtual void remover(int elemento) = 0;
    virtual ~IArvoreBinaria() = default;
};
}
#endif // IARVOREBINARIA_H
