// Funcao: recursividade - implementacao de logica recursiva do projeto.
// Projeto: Recursividade
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef RECURSIVIDADE_H
#define RECURSIVIDADE_H
#include <QString>

namespace hil{

class Recursividade
{
private:
    int numero;

public:
    Recursividade();

    QString mostrarNumerosR(int aux, QString saida) const;
    QString MostrarNumerosI() const;
    QString mostrarNumerosG() const;

    int getNumero() const;
    void setNumero(int newNumero);
};
}
#endif // RECURSIVIDADE_H
