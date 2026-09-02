// Funcao: recursivo - implementacao de logica recursiva do projeto.
// Projeto: ListaSimplesVisual
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef RECURSIVO_H
#define RECURSIVO_H
#include <QString>
#include <cmath>

namespace hil {

class Recursivo
{
private:
    int numero;

public:
    Recursivo();

    QString exerc1 (int n, int aux, QString saida);
    QString exerc1_Iterativo();

    QString exerc2 (int aux, QString saida);
    QString exerc2_Iterativo();

    QString exerc3 (int aux, QString saida);
    QString exerc3_Iterativo();

    int exerc4(int n) const;
    int exerc4_Iterativo() const;

    double exerc5(double precisao, int termoAtual, double somaAtual) const;
    double exerc5_Iterativo(int termos) const;

    double exerc6(int n) const;
    double exerc6_Iterativo() const;

    int getNumero() const;
    void setNumero(int newNumero);
};
}
#endif // RECURSIVO_H
