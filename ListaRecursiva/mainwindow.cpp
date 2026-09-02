// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ListaRecursiva
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
    int resultadoRecursivo = recur.exerc1(n);
    int resultadoIterativo = recur.exerc1_Iterativo(n);

    QString dados = "Soma dos primeiros " + QString::number(n) + " cubos (Recursivo): " + QString::number(resultadoRecursivo) + "\n"
    "Soma dos primeiros " + QString::number(n) + " cubos (Iterativo): " + QString::number(resultadoIterativo);
    ui->saida->setText(dados);
    ui->valor->setText("");
}

void MainWindow::on_executar_2_clicked()
{
    int n = ui->valor2->text().toInt();

    QString resultadoRecursivo = recur.exerc2(n);
    QString resultadoIterativo = recur.exerc2_Iterativo(n);

    QString dados = "Recursivo: " + resultadoRecursivo + "\nIterativo: " + resultadoIterativo;
    ui->saida->setText(dados);
    ui->valor2->setText("");
}

void MainWindow::on_executar_3_clicked()
{
    bool ok;
    int tamanho = ui->valor3->text().toInt(&ok);

    if (!ok || tamanho <= 0) {
        QMessageBox::warning(this, "Erro", "Digite um tamanho de vetor válido.");
        return;
    }

    int* vetor = new int[tamanho];

    QString elementosVetor;

    for (int i = 0; i < tamanho; ++i) {
        bool ok;
        vetor[i] = QInputDialog::getInt(this, "Digite um valor", "Valor para posição " + QString::number(i), 0, INT_MIN, INT_MAX, 1, &ok);

        if (!ok) {
            delete[] vetor;
            return;
        }
        elementosVetor += QString::number(vetor[i]) + " ";
    }

    ui->saida->setText(elementosVetor);

    int menorElemento;

    if (ui->comboBox->currentText() == "Recursivo") {
        menorElemento = recur.exerc3(vetor, tamanho);
    } else {
        menorElemento = recur.exerc3_Iterativo(vetor, tamanho);
    }

    delete[] vetor;

    QString mensagem = "Menor elemento encontrado: " + QString::number(menorElemento);
    QMessageBox::information(this, "Resultado", mensagem);

    ui->valor3->setText("");
}

void MainWindow::on_executar_4_clicked()
{
    bool ok;
    int n = ui->valor4->text().toInt(&ok);

    if (!ok) {
        ui->saida->setText("Digite um número válido.");
        return;
    }

    QString resultado = "Resultado: " + recur.exerc4_Iterativo(n);
    ui->saida->setText(resultado);
    ui->valor4->setText("");
}


void MainWindow::on_executar_5_clicked()
{
    bool ok;
    int base = QInputDialog::getInt(this, "Digite a base", "Base:", 0, INT_MIN, INT_MAX, 1, &ok);

    if (!ok) {
        return;
    }

    int expoente = QInputDialog::getInt(this, "Digite o expoente", "Expoente:", 0, INT_MIN, INT_MAX, 1, &ok);

    if (!ok) {
        return;
    }

    int resultadoRecursivo = recur.exerc5(base, expoente);
    int resultadoIterativo = recur.exerc5_Iterativa(base, expoente);

    ui->saida->setText("Resultado da Potência (Recursivo): " + QString::number(resultadoRecursivo) +
    "\nResultado da Potência (Iterativo): " + QString::number(resultadoIterativo));
}

void MainWindow::on_executar_6_clicked()
{
    bool ok;
    int n1 = QInputDialog::getInt(this, "Digite o primeiro número", "N1:", 0, INT_MIN, INT_MAX, 1, &ok);

    if (!ok) {
        return;
    }

    int n2 = QInputDialog::getInt(this, "Digite o segundo número", "N2:", 0, INT_MIN, INT_MAX, 1, &ok);

    if (!ok) {
        return;
    }

    int resultadoRecursivo = recur.exerc6(n1, n2);
    int resultadoIterativo = recur.exerc6_Iterativo(n1, n2);

    ui->saida->setText("Resultado da Multiplicação (Recursivo): " + QString::number(resultadoRecursivo) +
    "\nResultado da Multiplicação (Iterativo): " + QString::number(resultadoIterativo));
}
