// Funcao: recursividade - implementacao de logica recursiva do projeto.
// Projeto: ListaRecursiva
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef RECURSIVIDADE_H
#define RECURSIVIDADE_H

#include <QString>
#include <QMessageBox>
#include <QInputDialog>

namespace hil {

class Recursividade
{
private:
    int numero;
    int auxRecursivoEXERC3(const int *vetor, int tamanho, int menorAtual) const;
    void auxRecursivoEXERC4(int n, QString resultado) const;


public:
    Recursividade();

    int exerc1(int n) const;
    int exerc1_Iterativo(int n) const;

    QString exerc2(int n);
    QString exerc2_Iterativo(int n) const;
    void auxRecursivoEXERC2(int n, QString &resultado);

    int exerc3(const int *vetor, int tamanho) const;
    int exerc3_Iterativo(const int *vetor, int tamanho) const;

    QString exerc4(int n) const;
    QString exerc4_Iterativo(int n) const;

    int exerc5(int base, int expoente) const;
    int exerc5_Iterativa(int base, int expoente) const;

    int exerc6(int n1, int n2) const;
    int exerc6_Iterativo(int n1, int n2) const;





    int getNumero() const;
    void setNumero(int newNumero);
};
}
#endif // RECURSIVIDADE_H
