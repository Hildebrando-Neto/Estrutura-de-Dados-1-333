// Funcao: listalse - estrutura de dados da lista encadeada e suas operacoes.
// Projeto: ListaSimplesPilotos
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef LISTALSE_H
#define LISTALSE_H

#include "no.h"
#include "piloto.h"

namespace hil {

class ListaLSE
{
private:
    No *inicio;
    int qe;

public:
    ListaLSE();
    int getQe() const;
    bool estaVazia() const;

    // Métodos Inicio
    void inserirInicio(Piloto dado);
    Piloto acessarInicio() const;
    void retirarInicio();

    // Métodos Fim
    void inserirFim(Piloto dado);
    Piloto acessarFim() const;
    void retirarFim();

    // Métodos na Posicao
    void inserirPosicao(int posicao, Piloto dado);
    Piloto acessarPos(int posicao) const;
    void retirarPosicao(int posicao);

    // Métodos na Posição
    void ordenarPorCodigoCrescente() const;
    void ordenarPorNomeDecrescente() const;

    QString toString() const;
};
}
#endif // LISTALSE_H
