// Funcao: fila - estrutura de dados da fila e suas operacoes basicas.
// Projeto: OrdenacaoFila
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef FILA_H
#define FILA_H

namespace hil {

class Fila
{
private:
    int fim;
    int inicio;
    int tamanho;
    int *array;
    int quantElemento;
public:
    Fila(int tamanho);
    ~Fila();
    bool estaVazia() const;
    bool estaCheia() const;
    void inserir(int elemento);
    int retirar();
    int acessar() const;
};
}
#endif // FILA_H
