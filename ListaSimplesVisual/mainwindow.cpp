// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ListaSimplesVisual
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
    int n = ui->valor->text().toInt();
    recur.setNumero(n);
    QString dados = "Iterativo: ";
    dados += recur.exerc1_Iterativo();
    ui->saida->setText(dados);

    //MOSTRANDO DE FORMA RECURSIVA
    QString resultadoMostrarNumerosG = "{ ";
    resultadoMostrarNumerosG = recur.exerc1(1, 1, resultadoMostrarNumerosG);
    dados += "\nRecursivo: ";
    dados += resultadoMostrarNumerosG;
    ui->saida->setText(dados);
}

void MainWindow::on_executar2_clicked()
{
    int n = ui->valor2->text().toInt();
    recur.setNumero(n);

    QString dadosIterativo = "Iterativo (Pares): ";
    dadosIterativo += recur.exerc2_Iterativo();
    ui->saida->setText(dadosIterativo);

    //MOSTRANDO DE FORMA RECURSIVA
    QString resultadoMostrarNumerosParesR = "{ ";
    resultadoMostrarNumerosParesR = recur.exerc2(2, resultadoMostrarNumerosParesR);
    QString dadosRecursivo = "Recursivo (Pares): ";
    dadosRecursivo += resultadoMostrarNumerosParesR;
    ui->saida->append(dadosRecursivo);
}

void MainWindow::on_executar3_clicked()
{
    int n = ui->valor3->text().toInt();
    recur.setNumero(n);

    QString dadosIterativo = "Iterativo (Ímpares): ";
    dadosIterativo += recur.exerc3_Iterativo();
    ui->saida->setText(dadosIterativo);

    //MOSTRANDO DE FORMA RECURSIVA
    QString resultadoMostrarNumerosImparesR = "{ ";
    resultadoMostrarNumerosImparesR = recur.exerc3(1, resultadoMostrarNumerosImparesR);
    QString dadosRecursivo = "Recursivo (Ímpares): ";
    dadosRecursivo += resultadoMostrarNumerosImparesR;
    ui->saida->append(dadosRecursivo);
}

void MainWindow::on_executar4_clicked()
{
    int n = ui->valor4->text().toInt();
    recur.setNumero(n);

    QString dadosIterativo = "Somatório (Iterativo): ";
    dadosIterativo += QString::number(recur.exerc4_Iterativo());
    ui->saida->setText(dadosIterativo);

    //MOSTRANDO DE FORMA RECURSIVA
    QString dadosRecursivo = "Somatório (Recursivo): ";
    dadosRecursivo += QString::number(recur.exerc4(recur.getNumero()));
    ui->saida->append(dadosRecursivo);
}

void MainWindow::on_executar5_clicked()
{
    double precisao = 0.0001;

    QString dadosIterativo = "Pi (Iterativo): " + QString::number(recur.exerc5_Iterativo(100000), 'f', 15);
    ui->saida->setText(dadosIterativo);

    // Adicionando valores iniciais para a chamada recursiva
    QString dadosRecursivo = "Pi (Recursivo): " + QString::number(recur.exerc5(precisao, 0, 0.0), 'f', 15);
    ui->saida->append(dadosRecursivo);
}

void MainWindow::on_executar6_clicked()
{
    double piIterativo = recur.exerc6_Iterativo();
    double piRecursivo = recur.exerc6(51);

    QString dados = "Pi (Iterativo): " + QString::number(piIterativo, 'f', 4) + "\n"
    "Pi (Recursivo): " + QString::number(piRecursivo, 'f', 4);
    ui->saida->setText(dados);
}

