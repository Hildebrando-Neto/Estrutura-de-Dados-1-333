// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ListaDuplamenteEncadeada
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

//tela igual o sistema LLSE
//com os tres primeiros metodos ja feitos
//ao inserir sempre mostrar a lista crescente e decrescente
//metodos no fim para quarta

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap img ("/home/puc/Área de Trabalho");
    ui->label_img->setPixmap(img.scaled(100,100,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonInserirInicio_clicked()
{
    QString elemento = ui->lineEdit->text();
    int elemento2 = elemento.toInt();

    try {
        lista.inserirInicio(elemento2);
        QString listaString_InicioFim = lista.toString_InicioFim();
        QString listaString_FimInicio = lista.toString_FimInicio();

        ui->textEdit->clear();
        ui->textEdit->append("Inicio para Fim: " + listaString_InicioFim);
        ui->textEdit->append("Fim para Início: " + listaString_FimInicio);
    } catch (const QString &erro) {
        QMessageBox::critical(this,"Erro",erro);
    }
}

void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try {
        int primeiroElemento = lista.acessarInicio();
        QMessageBox::information(this, "primeiroElemento", "O primeiro elemento é: " + QString::number(primeiroElemento));
    } catch (const QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
}

void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try {
        lista.retirarInicio();
        QString listaString_InicioFim = lista.toString_InicioFim();
        QString listaString_FimInicio = lista.toString_FimInicio();

        ui->textEdit->clear();
        ui->textEdit->append("Inicio para Fim: " + listaString_InicioFim);
        ui->textEdit->append("Fim para Início: " + listaString_FimInicio);
    } catch (const QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
        ui->textEdit->clear();
    }
}

void MainWindow::on_pushButtonInserirFim_clicked()
{
    QString elemento = ui->lineEdit->text();
    int elemento2 = elemento.toInt();

    try {
        lista.inserirFim(elemento2);
        QString listaString_InicioFim = lista.toString_InicioFim();
        QString listaString_FimInicio = lista.toString_FimInicio();

        ui->textEdit->clear();
        ui->textEdit->append("Inicio para Fim: " + listaString_InicioFim);
        ui->textEdit->append("Fim para Início: " + listaString_FimInicio);
    } catch (const QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
}

void MainWindow::on_pushButtonAcessarFim_clicked()
{
    try {
        int ultimoElemento = lista.acessarFim();
        QMessageBox::information(this, "ultimoElemento", "O último elemento é: " + QString::number(ultimoElemento));
    } catch (const QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
}

void MainWindow::on_pushButtonRetirarFim_clicked()
{
    try {
        lista.retirarFim();
        QString listaString_InicioFim = lista.toString_InicioFim();
        QString listaString_FimInicio = lista.toString_FimInicio();

        ui->textEdit->clear();
        ui->textEdit->append("Inicio para Fim: " + listaString_InicioFim + "->");
        ui->textEdit->append("Fim para Início: " + listaString_FimInicio + "->");
    } catch (const QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
        ui->textEdit->clear();
    }
}

void MainWindow::on_pushButtonInserirPos_clicked()
{
    int posicaoInsercao = ui->lineEditPosicao->text().toInt();
    int elementoInserir = ui->lineEdit->text().toInt();

    if (posicaoInsercao < 0) {
        QMessageBox::critical(this, "Erro", "Posição inválida");
        return;
    }

    int quantElementos = lista.getQuantElementos();

    if (posicaoInsercao == 0) {
        lista.inserirInicio(elementoInserir);
    } else if (posicaoInsercao == quantElementos) {
        lista.inserirFim(elementoInserir);
    } else if (posicaoInsercao > quantElementos) {
        QMessageBox::critical(this, "Erro", "Posição inválida");
    } else {
        lista.inserirPosicao(elementoInserir, posicaoInsercao);
    }

    QString listaString_InicioFim = lista.toString_InicioFim();
    QString listaString_FimInicio = lista.toString_FimInicio();

    ui->textEdit->clear();
    ui->textEdit->append("Inicio para Fim: " + listaString_InicioFim);
    ui->textEdit->append("Fim para Início: " + listaString_FimInicio);
}

void MainWindow::on_pushButtonAcessarPos_clicked()
{
    int posicaoAcesso = ui->lineEditPosicao->text().toInt();

    if (posicaoAcesso < 0 || posicaoAcesso >= lista.getQuantElementos()) {
        QMessageBox::critical(this, "Erro", "Posição inválida");
        return;
    }

    int elementoAcessado = lista.acessarPosicao(posicaoAcesso);
    QMessageBox::information(this, "Elemento Acessado", "Elemento na posição " + QString::number(posicaoAcesso) + " é: " + QString::number(elementoAcessado));
}

void MainWindow::on_pushButtonRetirarPos_clicked()
{
    int posicaoRetirada = ui->lineEditPosicao->text().toInt();

    if (posicaoRetirada < 0 || posicaoRetirada >= lista.getQuantElementos()) {
        QMessageBox::critical(this, "Erro", "Posição inválida");
        return;
    }

    lista.retirarPosicao(posicaoRetirada);

    QString listaString_InicioFim = lista.toString_InicioFim();
    QString listaString_FimInicio = lista.toString_FimInicio();

    ui->textEdit->clear();
    ui->textEdit->append("Inicio para Fim: " + listaString_InicioFim);
    ui->textEdit->append("Fim para Início: " + listaString_FimInicio);
}

void MainWindow::on_pushButtonInserirOrd_clicked()
{
    QString elemento = ui->lineEdit->text();
    int elemento2 = elemento.toInt();

    try {
        lista.inserirOrdenado(elemento2);
        QString listaString_InicioFim = lista.toString_InicioFim();
        QString listaString_FimInicio = lista.toString_FimInicio();

        ui->textEdit->clear();
        ui->textEdit->append("Inicio para Fim: " + listaString_InicioFim);
        ui->textEdit->append("Fim para Início: " + listaString_FimInicio);
    } catch (const QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
}
