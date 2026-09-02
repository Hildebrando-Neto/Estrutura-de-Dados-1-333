// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ContadorDePalavras
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "no.h"

namespace hil{

No::No(int dado):
    dado(dado),
    direita(0),
    esquerda(0)
{}

No::~No()
{
    QString saida;
    saida = "Metodo Destrutor do No Elemento = " [this->dado];
    if(this->esquerda != 0) delete this->esquerda;
    if(this->direita != 0)  delete this->direita;
}
}
