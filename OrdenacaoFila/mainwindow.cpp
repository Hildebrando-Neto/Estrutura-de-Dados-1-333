// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: OrdenacaoFila
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
    delete objetoArray;
    objetoArray = nullptr;
    delete ui;
}

void MainWindow::on_pushButtonCriar_clicked()
{
    try {
        objetoArray = new hil::OrdenarFila(ui->lineEditQuantidadeElementos->text().toInt());
        ui->textEditVetorOriginal->setText(objetoArray->mostrarResultado());
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonOrdenar_clicked()
{
    try
    {
        if (ui->comboBox->currentText() == "Ordem Crescente")
        {
            objetoArray->ordenarCrescente();
        }
        else
        {
            objetoArray->ordenarDecrescente();
        }
        ui->textEditVetorOrdenado->setText(objetoArray->mostrarResultado());
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}

