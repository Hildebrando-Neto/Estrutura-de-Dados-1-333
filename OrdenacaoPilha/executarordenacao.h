// Funcao: executarordenacao - logica de ordenacao aplicada aos dados do projeto.
// Projeto: OrdenacaoPilha
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef EXECUTARORDENACAO_H
#define EXECUTARORDENACAO_H

#include "pilha.h"

namespace hil {

class ExecutarOrdenacao {
private:
    Pilha &pilha;
public:
    ExecutarOrdenacao(Pilha &pilha);
    void ordenarPilha();
};
}
#endif // EXECUTARORDENACAO_H
