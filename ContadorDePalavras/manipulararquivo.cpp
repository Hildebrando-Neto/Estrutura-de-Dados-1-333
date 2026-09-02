// Funcao: manipulararquivo - modulo de manipulacao e persistencia dos dados do projeto.
// Projeto: ContadorDePalavras
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "manipulararquivo.h"

namespace hil{

ManipularArquivo::ManipularArquivo(QString nomeDoArquivo):
    nomeDoArquivoNoDisco(nomeDoArquivo)
{}

void ManipularArquivo::buscarDadosNoArquivo()
{
    try {
        // Criando um arquivo de entrada
        std::ifstream arquivo(nomeDoArquivoNoDisco.toStdString());

        // Verificando erro de abertura do arquivo de entrada
        if (!arquivo.is_open()) {
            throw QString("ERRO: O arquivo não pode ser aberto");
        }

        // Lendo dados do arquivo texto
        std::string linha;

        // Lendo do arquivo
        while (getline(arquivo, linha)) {
            QString texto = QString::fromStdString(linha);
            // Substitua ',' e ' ' por caracteres que podem separar palavras no seu arquivo
            QStringList strList = texto.split(",", Qt::SkipEmptyParts);

            for (const QString &palavra : strList) {
                // Remova caracteres indesejados, se necessário
                QString palavraLimpa = palavra.trimmed();
                // Converta para minúsculas para não diferenciar maiúsculas de minúsculas
                QString palavraLowerCase = palavraLimpa.toLower();
                // Inserir na árvore binária
                ContadorPalavras.inserir(std::stoi(palavraLowerCase.toStdString()));
            }
        }

        // Fechando o arquivo de entrada
        arquivo.close();
    } catch (const std::exception &e) {
        throw QString("ERRO: ") + e.what();
    } catch (...) {
        throw QString("ERRO desconhecido ao processar o arquivo");
    }
}
}
