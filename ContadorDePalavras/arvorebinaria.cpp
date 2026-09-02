// Funcao: arvorebinaria - estrutura de dados da arvore binaria e seus nos.
// Projeto: ContadorDePalavras
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "arvorebinaria.h"

namespace hil{

ArvoreBinaria::ArvoreBinaria():
    raiz(0)
{}

ArvoreBinaria::~ArvoreBinaria()
{
    if(raiz != 0){
        delete raiz;
    }
}

void ArvoreBinaria::inserirRecursivo(No **raiz, int elemento)
{
    if(*raiz == 0){
        *raiz = new No(elemento);

    }else
        if(elemento < (*raiz)->getDado())
            inserirRecursivo(&(*raiz)->esquerda, elemento);

        else
            if(elemento > (*raiz)->getDado() )
                inserirRecursivo(&(*raiz)->direita, elemento);

            else throw QString("Elemento já Existe");
}

void ArvoreBinaria::emOrdem(No* raiz)const
{
    if(raiz != 0){
        emOrdem(raiz->getEsquerda());
        QString dados;
        dados = "Elemento=>  " [raiz->getDado()];
        emOrdem(raiz->getDireita());
    }
}

int ArvoreBinaria::retornar_Maior(No **raiz)
{
    int valor;
    No *aux = 0;

    if((*raiz)->direita != 0) return (retornar_Maior(&(*raiz)->direita));

    else{
        aux = *raiz;
        valor = (*raiz)->getDado();
        *raiz = (*raiz)->esquerda;
        aux->esquerda = 0;
        aux->direita = 0;

        delete aux;
        return valor;
    }
}

void ArvoreBinaria::removerRecursivo(No **raiz, int elemento)
{
    No *aux = 0;
    if(*raiz != 0){
        if((*raiz)->getDado() == elemento){
            aux = *raiz;
            if((*raiz)->esquerda == 0){
                *raiz = (*raiz)->direita;
                aux->esquerda = 0;
                aux->direita = 0;
                delete aux;

            }else
                if((*raiz)->direita == 0){
                    *raiz = (*raiz)->esquerda;
                    aux->esquerda = 0;
                    aux->direita = 0;
                    delete aux;

                }else{
                    (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
                }
        }else{
            if((*raiz)->getDado() < elemento)
                removerRecursivo(&(*raiz)->direita,elemento);
            else
                if((*raiz)->getDado() > elemento)
                    removerRecursivo(&(*raiz)->esquerda,elemento);
        }
    }
    else throw QString("Elemento não Existe");
}

QString ArvoreBinaria::obterDadosFormatados() const {
    QString dadosFormatados;
    emOrdemFormatado(raiz, dadosFormatados);
    return dadosFormatados;
}

void ArvoreBinaria::emOrdemFormatado(No *raiz, QString &dadosFormatados) const {
    if (raiz != nullptr) {
        emOrdemFormatado(raiz->getEsquerda(), dadosFormatados);
        dadosFormatados += QString("Palavra: %1, Contagem: %2\n")
            .arg(raiz->getDado())
            .arg(contarOcorrencias(raiz->getDado()));
        emOrdemFormatado(raiz->getDireita(), dadosFormatados);
    }
}

int ArvoreBinaria::contarOcorrencias(int elemento) const {
    return contarOcorrenciasRecursivo(raiz, elemento);
}

int ArvoreBinaria::contarOcorrenciasRecursivo(No *raiz, int elemento) const {
    if (raiz == nullptr) {
        return 0;
    }

    int contagem = 0;

    if (raiz->getDado() == elemento) {
        contagem++;
    }

    contagem += contarOcorrenciasRecursivo(raiz->getEsquerda(), elemento);
    contagem += contarOcorrenciasRecursivo(raiz->getDireita(), elemento);

    return contagem;
}
}
