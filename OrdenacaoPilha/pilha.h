// Funcao: pilha - estrutura de dados da pilha e suas operacoes basicas.
// Projeto: OrdenacaoPilha
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef PILHA_H
#define PILHA_H

#include <QString>
#include <ctime>

namespace hil {

class Pilha
{
private:
    int tamanho;
    int topo;
    int *array;
public:
    Pilha(int tamanho);
    ~Pilha();
    int getTamanho() const;
    void empilhar(int elemento);
    void desempilhar();
    bool estaCheia() const;
    bool estaVazia() const;
    int acessar() const;
    int* getArray() const;
};
}
#endif // PILHA_H
