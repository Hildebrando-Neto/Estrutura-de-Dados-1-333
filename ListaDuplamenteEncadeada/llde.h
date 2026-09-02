// Funcao: llde - estrutura de dados da lista encadeada e suas operacoes.
// Projeto: ListaDuplamenteEncadeada
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef LLDE_H
#define LLDE_H
#include <QString>
#include "no.h"

namespace hil{

class LLDE
{
private:
    No *inicio;
    No *fim;
    int quantElementos;

public:
    LLDE();
    int getQuantElementos() const;
    bool estaVazia() const;

    QString toString_InicioFim() const;
    QString toString_FimInicio() const;

    //METODOS NO INICIO
    void inserirInicio(int elemento);
    void retirarInicio();
    int acessarInicio() const;

    //METODOS NO FIM
    void inserirFim(int elemento);
    void retirarFim();
    int acessarFim() const;

    //METODOS NA POSIÇAO
    void inserirPosicao(int elemento, int pos);
    void retirarPosicao(int pos);
    int acessarPosicao(int pos) const;

    //ORDENADO
    void inserirOrdenado(int elemento);
};
}
#endif // LLDE_H
