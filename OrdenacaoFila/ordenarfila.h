// Funcao: ordenarfila - estrutura de dados da fila e suas operacoes basicas. logica de ordenacao aplicada aos dados do projeto.
// Projeto: OrdenacaoFila
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <ctime>
#include <fila.h>
#include <QString>

namespace hil {

class OrdenarFila {
private:
    int tamanho;
    int *array;

public:
    OrdenarFila(int tamanho);
    ~OrdenarFila();

    QString mostrarResultado() const;

    void ordenarCrescente();
    void ordenarDecrescente();
};
}
#endif // ORDENACAO_H
