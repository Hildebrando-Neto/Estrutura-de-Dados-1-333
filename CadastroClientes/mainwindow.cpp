// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: CadastroClientes
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


void MainWindow::on_pushButton_clicked()
{
    hil::Cliente p1(10,"Manuel Gomes","canetaazul@caneta.com");
    array[0] = p1;

    hil::Cliente p2(20,"Edinaldo Pereira","pereiraedis_04@gmail.com");
    array[1] = p2;

    hil::Cliente p3(30,"Diogo Defante","alegriaaaaa@gmail.com");
    array[2] = p3;

    hil::Cliente p4(40,"Julio Cocielo","filhosefuteboleacademia@gmail.com");
    array[3] = p4;

    hil::Cliente p5(50,"Lula","picanhaEcervejinha@governogov.com");
    array[4] = p5;

    //Limpar a grid
    ui->tableWidget->setRowCount(0);

    //Montando a grid

    for(int pos = 0; pos < 5; pos++){

    try {
            QTableWidgetItem *itemCodigo = new QTableWidgetItem (QString::number(array[pos].getCodigo()));
            QTableWidgetItem *itemNome = new QTableWidgetItem (array[pos].getNome());
            QTableWidgetItem *itemEmail = new QTableWidgetItem (array[pos].getEmail());

            int linha = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(linha);
            ui->tableWidget->setItem(linha,2,itemCodigo);
            ui->tableWidget->setItem(linha,1,itemNome);
            ui->tableWidget->setItem(linha,0,itemEmail);

    } catch (std::bad_alloc) {
            throw QString("A Grid não pode ser montada");
    }
    }
}//e pra fazer todos os metodos da lista lse e inserir ordenado crescente e decrescente
//combo box ordenado cres e decres pelo codigo e ordenado cres e decres pelo nome
