// Funcao: ordenarfila - estrutura de dados da fila e suas operacoes basicas. logica de ordenacao aplicada aos dados do projeto.
// Projeto: OrdenacaoFila
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "ordenarfila.h"
#include "fila.h"
#include <new>

namespace hil{

OrdenarFila::OrdenarFila(int tamanho):
    tamanho(0),
    array(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser menor que 0");
    try {
        array=new int [tamanho];
        this->tamanho = tamanho;
        std::srand(std::time(0));
        for (int i = 0; i < tamanho; i++){
            array[i] = rand() % 101;
        }
    } catch (std::bad_alloc &erro) {
        throw QString ("Fila não pôde ser criada");
}
}

OrdenarFila::~OrdenarFila()
{
    delete[] array;
    array = nullptr;
}

void OrdenarFila::ordenarCrescente(){
    Fila fila(tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        fila.inserir(array[i]);
    }

    for (int i = 0; i < tamanho; i++)
    {
        int valor = fila.retirar();
        for (int j = 1; j < tamanho - i; j++)
        {
            int aux = fila.retirar();
            if (aux < valor)
            {
                fila.inserir(valor);
                valor = aux;
            }
            else
            {
                fila.inserir(aux);
            }
        }
        array[i] = valor;
    }
}

void OrdenarFila::ordenarDecrescente(){
    Fila fila(tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        fila.inserir(array[i]);
    }

    for (int i = 0; i < tamanho; i++)
    {
        int valor = fila.retirar();
        for (int j = 1; j < tamanho - i; j++)
        {
            int aux = fila.retirar();
            if (aux > valor)
            {
                fila.inserir(valor);
                valor = aux;
            }
            else
            {
                fila.inserir(aux);
            }
        }
        array[i] = valor;
    }
}

QString OrdenarFila::mostrarResultado()const{

    QString resultado;

    for(int i=0; i<tamanho; i++)
    {
        resultado += (QString::number(array[i])+ " | ");
    }
    return resultado;
}
}
