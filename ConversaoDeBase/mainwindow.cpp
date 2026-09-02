// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ConversaoDeBase
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mudabase.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calcularButton, &QPushButton::clicked, this, &MainWindow::calcularBase);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcularBase()
{
    bool conversaoOk;
    int numero = ui->lineEditdecimal->text().toInt(&conversaoOk);

    if (!conversaoOk)
    {
        ui->textEditresultado->setText("Entrada inválida.");
        return;
    }

    int base = ui->baseComboBox->currentText().toInt();
    QString resultado = MudaBase::converterBase(numero, base);

    ui->textEditresultado->setText(resultado);
}
