// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: Recursividade
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_executar_clicked()
{
    hil::Recursividade teste;
    teste.setNumero(10);
    QString dados = "Iterativo: ";
    dados += teste.MostrarNumerosI();
    ui->saida->setText(dados);
    QString resultadoMostrarNumerosG = "{ ";

    //MOSTRANDO DE FORMA RECURSIVA
    resultadoMostrarNumerosG = teste.mostrarNumerosR(1, resultadoMostrarNumerosG);
    dados += "\nRecursivo: ";
    dados += resultadoMostrarNumerosG;
    ui->saida->setText(dados);
}
