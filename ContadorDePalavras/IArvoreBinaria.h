// Funcao: IArvoreBinaria - estrutura de dados da arvore binaria e seus nos.
// Projeto: ContadorDePalavras
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef IARVOREBINARIA_H
#define IARVOREBINARIA_H

#include <QString>

namespace hil{

class IArvoreBinaria{

    virtual void inserir(int elemento) = 0;
    virtual void imprimir() = 0;
    virtual void remover(int elemento) = 0;
};
}
#endif // IARVOREBINARIA_H
