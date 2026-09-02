// Funcao: recursividade - implementacao de logica recursiva do projeto.
// Projeto: Recursividade
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "recursividade.h"

namespace hil{

int Recursividade::getNumero() const
{
    return numero;
}

void Recursividade::setNumero(int newNumero)
{
    numero = newNumero;
}

QString Recursividade::mostrarNumerosR(int aux, QString saida) const
{
    if( aux <= numero){
        saida += QString::number(aux);
        saida += " ";
        return mostrarNumerosR(++aux, saida);
    }
    else return (saida + " }");
}

Recursividade::Recursividade():
    numero(0)
{
}

QString Recursividade::mostrarNumerosG() const
{
    return mostrarNumerosR(1, "{ ") + " }";
}

QString Recursividade::MostrarNumerosI() const
{
    QString saida = "{ ";
    for(int aux = 1; aux <= numero; aux++)
    {
        saida += QString::number(aux);
        saida += " ";
    }
    saida += " }";
    return saida;
}
}
