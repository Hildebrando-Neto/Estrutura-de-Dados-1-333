// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ContadorDePalavras
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef NO_H
#define NO_H

#include <QString>

namespace hil{

class No
{
private:
    int dado;

public:
    No *direita;
    No *esquerda;

public:
    No(int dado);
    ~No();

    int getDado()const {return dado;}
    void setDado(int dado) {this->dado = dado;}

    No* getDireita() {return direita;}
    void setDireita(No* direita) {this->direita = direita;}

    No* getEsquerda() {return esquerda;}
    void setEsquerda(No* esquerda) {this->esquerda = esquerda;}
};
}
#endif // NO_H
