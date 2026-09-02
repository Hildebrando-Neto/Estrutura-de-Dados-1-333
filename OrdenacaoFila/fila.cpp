// Funcao: fila - estrutura de dados da fila e suas operacoes basicas.
// Projeto: OrdenacaoFila
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "fila.h"
#include <QString>

namespace hil{

Fila::Fila(int tamanho):
    fim(-1),
    inicio(-1),
    tamanho(0),
    array(0),
    quantElemento(0)
{
    if (tamanho<=0)throw QString ("Tamanho não pode ser menor que 0");
    try {
        array = new int[tamanho];
        this->tamanho=tamanho;
    } catch (std::bad_alloc &erro) {
        throw QString ("Fila não pôde ser criada");
    }
}

Fila::~Fila(){
    if(array) delete []array;
}

bool Fila::estaCheia()const{
    return (quantElemento==tamanho);
}

bool Fila::estaVazia()const{
    return (quantElemento==0);
}

void Fila::inserir(int elemento){
    if (estaCheia())throw QString ("A fila está cheia");

    if (estaVazia())inicio=0;

    fim++;

    if(fim==tamanho)fim=0;
    array[fim]=elemento;
    quantElemento++;
}

int Fila::retirar(){
    if (estaVazia())throw QString ("A fila está vazia");

    int aux=array[inicio];
    inicio++;

    if (inicio==tamanho)inicio=0;
    quantElemento--;

    if (estaVazia())inicio=fim=-1;
    return aux;
}

int Fila::acessar()const{
    if (estaVazia())throw QString ("Não há elementos para acessar");

    return array[inicio];
}
}
