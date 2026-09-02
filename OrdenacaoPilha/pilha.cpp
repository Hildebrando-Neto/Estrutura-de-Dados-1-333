// Funcao: pilha - estrutura de dados da pilha e suas operacoes basicas.
// Projeto: OrdenacaoPilha
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "pilha.h"

namespace hil{

Pilha::Pilha(int tamanho) :
    tamanho(0),
    topo(-1),
    array(0)
{
    if (tamanho <= 0) throw QString("O Tamanho precisa ser maior que 0");
    try {
        array = new int[tamanho];
        this->tamanho = tamanho;

        std::srand(std::time(0));
        for (int i = 0; i < tamanho; ++i) {
            *(array + i) = rand() % 101;
        }
    } catch (std::bad_alloc&) {
        throw QString("Pilha não pode ser criada");
    }
}

Pilha::~Pilha(){
    if (array != 0) delete[] array;
}
int Pilha::getTamanho() const{
    return tamanho;
}
void Pilha::empilhar(int elemento){
    if(estaCheia()) throw QString("A Pilha está cheia");
            topo++;
    *(array+topo) = elemento;
}
bool Pilha::estaCheia() const{
    return(topo == (tamanho - 1));
}
bool Pilha::estaVazia() const{
    return(topo == -1);
}
void Pilha::desempilhar(){
    if(estaVazia()) throw QString ("Esta Vazia");
    topo--;
}
int Pilha::acessar() const{
    if(estaVazia()) throw QString("Esta vazia");
    return *(array + topo);

}
int* Pilha::getArray() const {
    return array;
}
}
