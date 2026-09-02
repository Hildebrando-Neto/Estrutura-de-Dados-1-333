// Funcao: manipular - modulo de manipulacao e persistencia dos dados do projeto.
// Projeto: ListaSimplesPilotos
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef MANIPULARARQUIVO_H
#define MANIPULARARQUIVO_H

#include <QString>
#include <fstream>
#include <QStringList>
#include <piloto.h>
#include "listalse.h"

namespace hil {

class Manipular {

private:
    QString nomeDoArquivoNoDisco;
    ListaLSE colecaoDePilotosF1;

public:
    Manipular(QString nomeDoArquivo);
    void buscarDadosNoArquivo();
    const ListaLSE &getColecaoDePilotosF1() const;
};
}
#endif // MANIPULARARQUIVO_H
