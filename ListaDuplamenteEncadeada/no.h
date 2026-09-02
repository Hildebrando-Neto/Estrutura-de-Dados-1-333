// Funcao: no - estrutura de dados da arvore binaria e seus nos.
// Projeto: ListaDuplamenteEncadeada
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef NO_H
#define NO_H

namespace hil{

class No
{
private:
    No *anterior;
    int dado;
    No *proximo;
public:
    No();
    No(int dado);

    No *getAnterior() const;
    void setAnterior(No *newAnterior);

    int getDado() const;
    void setDado(int newDado);

    No *getProximo() const;
    void setProximo(No *newProximo);
};
}
#endif // NO_H
