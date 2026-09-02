// Funcao: executarordenacao - logica de ordenacao aplicada aos dados do projeto.
// Projeto: OrdenacaoPilha
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "executarordenacao.h"

namespace hil {

ExecutarOrdenacao::ExecutarOrdenacao(Pilha &pilha) :
    pilha(pilha)
{
}

void ExecutarOrdenacao::ordenarPilha() {
    int tamanho = pilha.getTamanho();
    int* arrayOrdenado = new int[tamanho];
    int indice = 0;

    while (!pilha.estaVazia()) {
        arrayOrdenado[indice] = pilha.acessar();
        pilha.desempilhar();
        indice++;
    }

    for (int i = 0; i < indice; i++) {
        for (int j = i + 1; j < indice; j++) {
            if (arrayOrdenado[i] < arrayOrdenado[j]) {
                int temp = arrayOrdenado[i];
                arrayOrdenado[i] = arrayOrdenado[j];
                arrayOrdenado[j] = temp;
            }
        }
    }

    while (!pilha.estaVazia()) {
        pilha.desempilhar();
    }

    for (int i = 0; i < indice; i++) {
        pilha.empilhar(arrayOrdenado[i]);
    }

    delete[] arrayOrdenado;
}
}
