// Funcao: manipulararquivo - modulo de manipulacao e persistencia dos dados do projeto.
// Projeto: ContadorDePalavras
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef MANIPULARARQUIVO_H
#define MANIPULARARQUIVO_H

#include <QTextStream>
#include <QString>
#include <fstream>
#include <QStringList>
#include <arvorebinaria.h>

namespace hil {

class ManipularArquivo {

private:
    QString nomeDoArquivoNoDisco;
    ArvoreBinaria ContadorPalavras;

public:
    ManipularArquivo(QString nomeDoArquivo);
    void buscarDadosNoArquivo();
    const ArvoreBinaria &getContadorPalavras() const;
};
}
#endif // MANIPULARARQUIVO_H
