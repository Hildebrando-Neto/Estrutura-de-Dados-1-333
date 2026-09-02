// Funcao: main - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ListaRecursiva
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
