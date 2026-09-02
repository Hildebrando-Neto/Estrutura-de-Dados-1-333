// Funcao: recursividade - implementacao de logica recursiva do projeto.
// Projeto: ListaRecursiva
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "recursividade.h"

namespace hil {

Recursividade::Recursividade() : numero(0) {}

int Recursividade::getNumero() const
{
    return numero;
}

void Recursividade::setNumero(int newNumero)
{
    numero = newNumero;
}

int Recursividade::exerc1(int n) const
{
    if (n == 0) {
        return 0;
    } else {
        return n * n * n + exerc1(n - 1);
    }
}

int Recursividade::exerc1_Iterativo(int n) const
{
    int resultado = 0;

    for (int i = 1; i <= n; ++i) {
        resultado += i * i * i;
    }
    return resultado;
}

QString Recursividade::exerc2(int n)
{
    QString resultado;
    auxRecursivoEXERC2(n, resultado);
    return resultado;
}

QString Recursividade::exerc2_Iterativo(int n) const
{
    QString resultado;
    for (int i = n; i >= 0; --i) {
        resultado += QString::number(i) + " ";
    }
    return resultado;
}

void Recursividade::auxRecursivoEXERC2(int n, QString &resultado)
{
    if (n >= 0) {
        resultado += QString::number(n) + " ";
        auxRecursivoEXERC2(n - 1, resultado);
    }
}

int Recursividade::exerc3(const int *vetor, int tamanho) const
{
    if (tamanho <= 0) {
        throw QString("Tamanho inválido");
            return -1;
    }
    return auxRecursivoEXERC3(vetor, tamanho, vetor[0]);
}

int Recursividade::exerc3_Iterativo(const int *vetor, int tamanho) const
{
    if (tamanho <= 0) {
        throw QString("Tamanho inválido");
            return -1;
    }

    int menor = vetor[0];

    for (int i = 1; i < tamanho; ++i) {
        menor = std::min(menor, vetor[i]);
    }
    return menor;
}

int Recursividade::auxRecursivoEXERC3(const int *vetor, int tamanho, int menorAtual) const
{
    if (tamanho <= 0) {
        return menorAtual;
    }

    menorAtual = std::min(menorAtual, vetor[tamanho - 1]);

    return auxRecursivoEXERC3(vetor, tamanho - 1, menorAtual);
}

QString Recursividade::exerc4(int n) const
{
    QString resultado;
    auxRecursivoEXERC4(n, resultado);
    return resultado;
}

QString Recursividade::exerc4_Iterativo(int n) const
{
    QString resultado;

    while (n > 0) {
        resultado = QString::number(n % 2) + resultado;
        n /= 2;
    }
    return resultado.isEmpty() ? "0" : resultado;
}

int Recursividade::exerc5(int base, int expoente) const
{
    if (expoente == 0) {
        return 1;
    } else if (expoente < 0) {
        return 1 / exerc5(base, -expoente);
    } else {
        return base * exerc5(base, expoente - 1);
    }
}

int Recursividade::exerc5_Iterativa(int base, int expoente) const
{
    int resultado = 1;

    while (expoente > 0) {
        resultado *= base;
        expoente--;
    }
    return resultado;
}

int Recursividade::exerc6(int n1, int n2) const
{
    if (n2 == 0) {
        return 0;
    } else {
        return n1 + exerc6(n1, n2 - 1);
    }
}

int Recursividade::exerc6_Iterativo(int n1, int n2) const
{
    int resultado = 0;

    while (n2 > 0) {
        resultado += n1;
        n2--;
    }
    return resultado;
}

void Recursividade::auxRecursivoEXERC4(int n, QString resultado) const
{
    if (n > 0) {
        auxRecursivoEXERC4(n / 2, resultado);
        resultado += QString::number(n % 2);
    }
}
}
