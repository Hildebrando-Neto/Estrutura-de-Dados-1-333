// Funcao: mudabase - modulo de conversao e manipulacao de valores entre bases numericas.
// Projeto: ConversaoDeBase
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "mudabase.h"

QString MudaBase::converterBase(int number, int base)
{
    if (base < 2 || base > 16)
        return "Base inválida.";

    hil::Pilha tempPilha(100);

    while (number > 0)
    {
        int resto = number % base;
        tempPilha.empilhar(resto);
        number /= base;
    }

    QString result;
    while (!tempPilha.estaVazia())
    {
        int valor = tempPilha.acessar();
        if (valor >= 10 && base == 16)
            result.append(QChar('A' + valor - 10));
        else
            result.append(QString::number(valor));
        tempPilha.desempilhar();
    }

    return result;
}
