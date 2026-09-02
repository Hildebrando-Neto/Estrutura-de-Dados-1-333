// Funcao: arvorebinaria - estrutura de dados da arvore binaria e seus nos.
// Projeto: ContadorDePalavras
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include<no.h>
#include<QString>
#include<iarvorebinaria.h>

namespace hil{

class ArvoreBinaria : public IArvoreBinaria
{

private:
    No* raiz;

private:
    void inserirRecursivo(No **raiz, int elemento);
    void removerRecursivo(No **raiz, int elemento);
    void emOrdem(No* raiz)const;
    int retornar_Maior(No **raiz);

public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void inserir(int elemento){this->inserirRecursivo(&raiz,elemento);}
    void remover(int elemento){this->removerRecursivo(&raiz, elemento);}
    void imprimir(){emOrdem(raiz);}

    QString obterDadosFormatados() const;
    void emOrdemFormatado(No *raiz, QString &dadosFormatados) const;

    int contarOcorrencias(int elemento) const;
    int contarOcorrenciasRecursivo(No *raiz, int elemento) const;
};
}
#endif // ARVOREBINARIA_H
