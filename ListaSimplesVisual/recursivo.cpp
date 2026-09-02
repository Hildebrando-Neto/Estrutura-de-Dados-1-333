// Funcao: recursivo - implementacao de logica recursiva do projeto.
// Projeto: ListaSimplesVisual
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "recursivo.h"

namespace hil {

int Recursivo::getNumero() const
{
    return numero;
}

void Recursivo::setNumero(int newNumero)
{
    numero = newNumero;
}

Recursivo::Recursivo():
    numero(0)
{
}

QString Recursivo::exerc1(int n, int aux, QString saida)
{
    if( aux <= numero){
        saida += QString::number(aux);
        saida += " ";
        return exerc1(n, ++aux, saida);
    }
    else return (saida + " }");
}

QString Recursivo::exerc1_Iterativo()
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

QString Recursivo::exerc2(int aux, QString saida)
{
    if (aux <= numero) {
        saida += QString::number(aux) + " ";
        return exerc2(aux + 2, saida);

        } else {
            return saida + "}";
    }
}

QString Recursivo::exerc2_Iterativo()
{
    QString resultado = "{ ";
        for (int i = 2; i <= numero; i += 2) {
            resultado += QString::number(i) + " ";
        }
        resultado += "}";
        return resultado;
}

QString Recursivo::exerc3(int aux, QString saida)
{
        if (aux <= numero) {
            saida += QString::number(aux) + " ";
            return exerc3(aux + 2, saida);
        } else {
            return saida + "}";
        }
}

QString Recursivo::exerc3_Iterativo()
{
        QString resultado = "{ ";
        for (int i = 1; i <= numero; i += 2) {
            resultado += QString::number(i) + " ";
        }
        resultado += "}";
        return resultado;
}

int Recursivo::exerc4(int n) const
{
    if (n == 1) {
        return 1;
    } else {
        return n + exerc4(n - 1);
    }
}

int Recursivo::exerc4_Iterativo() const
{
    int somatorio = 0;
    for (int i = 1; i <= numero; ++i) {
        somatorio += i;
    }
    return somatorio;
}

double Recursivo::exerc5_Iterativo(int termos) const
{
    double pi = 0.0;
    double termo;
    int termoAtual = 0;

    do {
        termo = (termoAtual % 2 == 0 ? 1.0 : -1.0) / (2.0 * termoAtual + 1);
        pi += termo;
        ++termoAtual;
    } while (termo >= termos || termo <= -termos);

    return pi * 4.0;
}

double Recursivo::exerc5(double precisao, int termoAtual, double somaAtual) const
{
    double termo = (termoAtual % 2 == 0 ? 1.0 : -1.0) / (2.0 * termoAtual + 1);
    double novaSoma = somaAtual + termo;

    if (termo >= precisao || termo <= -precisao) {
        return exerc5(precisao, termoAtual + 1, novaSoma);
    } else {
        return novaSoma * 4.0;
    }
}

double Recursivo::exerc6(int n) const
{
    if (n == 0) {
        return 0.0;
    } else {
        return exerc6(n - 1) + (n % 2 == 0 ? -1.0 : 1.0) / (2.0 * n + 1);
    }
}

double Recursivo::exerc6_Iterativo() const
{
    double pi = 0.0;
    int termos = 51;

    for (int i = 0; i < termos; ++i) {
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1);
    }
    return pi * 4.0;
}
}
