// Funcao: manipular - modulo de manipulacao e persistencia dos dados do projeto.
// Projeto: ListaSimplesPilotos
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "manipular.h"

namespace hil {

const hil::ListaLSE& Manipular::getColecaoDePilotosF1() const {
    return colecaoDePilotosF1;
}

Manipular::Manipular(QString nomeDoArquivo)
    : nomeDoArquivoNoDisco(nomeDoArquivo), colecaoDePilotosF1() {}

void Manipular::buscarDadosNoArquivo() {
    try {
        // Criando um arquivo de entrada
        std::ifstream arquivo;
        // Abrindo um arquivo de entrada
        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
        // Verificando erro de abertura do arquivo de entrada
        if (!arquivo.is_open()) throw QString("ERRO Arquivo nao pode ser aberto");
        // Lendo dados do arquivo texto
        std::string linha;
        // Lendo do arquivo
        getline(arquivo, linha);
        // Teste de fim do arquivo
        while (!arquivo.eof()) {
            QString texto = QString::fromStdString(linha);
            QStringList strList = texto.split(';');
            int codigo = strList[0].toInt();
            QString nome = strList[1];
            QString pais = strList[2];
            int idade = strList[3].toInt();
            QString equipe = strList[4];
            QString motor = strList[5];
            Piloto p(codigo, nome, pais, idade, equipe, motor);
            // Inserindo valores na ListaLSE
            colecaoDePilotosF1.inserirFim(p);
            // Lendo do arquivo
            getline(arquivo, linha);
        }
        // Fechando o arquivo de entrada
        arquivo.close();
    } catch (QString &erro) {
        throw erro;
    }
}
}
