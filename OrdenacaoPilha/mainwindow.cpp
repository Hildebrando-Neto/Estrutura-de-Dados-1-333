// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: OrdenacaoPilha
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pilha.h"
#include "executarordenacao.h"
#include <QMessageBox>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    textEditResultados = ui->textEditResultados;
    connect(ui->pushButtonOrdenar, SIGNAL(clicked()), this, SLOT(ordenarPilha()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonOrdenar_clicked()
{
    QString tamanhoTexto = ui->lineEditTamanho->text();
    int tamanho = tamanhoTexto.toInt();

    try {
        hil::Pilha pilha(tamanho);

        QString arrayOriginalStr = "Array Original: [";
        for (int i = 0; i < tamanho; ++i) {
            int valor = pilha.getArray()[i];
            pilha.empilhar(valor);
            arrayOriginalStr += QString::number(valor);

            if (i < tamanho - 1) {
                arrayOriginalStr += ", ";
            }
        }
        arrayOriginalStr += "]";

        hil::ExecutarOrdenacao ordenador(pilha);

        ordenador.ordenarPilha();

        QString arrayOrdenadoStr = "Array Ordenado: [";
        for (int i = 0; i < tamanho; ++i) {
            arrayOrdenadoStr += QString::number(pilha.getArray()[tamanho - 1 - i]);

            if (i < tamanho - 1) {
                arrayOrdenadoStr += ", ";
            }
        }
        arrayOrdenadoStr += "]";

        textEditResultados->setText(arrayOriginalStr + "\n" + arrayOrdenadoStr);
    } catch (const QString &erro) {
        QMessageBox::warning(this, "Erro", erro);
    }
}
