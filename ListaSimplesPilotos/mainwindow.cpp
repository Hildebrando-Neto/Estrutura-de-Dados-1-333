// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ListaSimplesPilotos
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

void MainWindow::on_pushButtonBuscarArquivo_clicked()
{
    try {
        //Buscando o arquivo no disco
        EnderecoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
        if(EnderecoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");
        ui->lineEditArquivo->setText(EnderecoArquivo);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonMostrar_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);

    hil::Manipular manipularArquivo(EnderecoArquivo);

    // Chama o método para buscar dados no arquivo
    manipularArquivo.buscarDadosNoArquivo();

    // Obtem a coleção de pilotos do objeto ManipularArquivo
    const hil::ListaLSE& colecaoDePilotosF1 = manipularArquivo.getColecaoDePilotosF1();

    // Configura o número de linhas na tabela com base no tamanho da coleção
    int numLinhas = colecaoDePilotosF1.getQe();
    ui->tableWidget->setRowCount(numLinhas);

    for (int row = 0; row < numLinhas; ++row) {
        const hil::Piloto& piloto = colecaoDePilotosF1.acessarPos(row + 1);

        try {

            QTableWidgetItem* itemCodigo = new QTableWidgetItem(QString::number(piloto.getCodigo()));
            QTableWidgetItem* itemNome = new QTableWidgetItem(piloto.getNome());
            QTableWidgetItem* itemPais = new QTableWidgetItem(piloto.getPais());
            QTableWidgetItem* itemIdade = new QTableWidgetItem(QString::number(piloto.getIdade()));
            QTableWidgetItem* itemEquipe = new QTableWidgetItem(piloto.getEquipe());
            QTableWidgetItem* itemMotor = new QTableWidgetItem(piloto.getMotor());

            ui->tableWidget->setItem(row, 0, itemCodigo);
            ui->tableWidget->setItem(row, 1, itemNome);
            ui->tableWidget->setItem(row, 2, itemPais);
            ui->tableWidget->setItem(row, 3, itemIdade);
            ui->tableWidget->setItem(row, 4, itemEquipe);
            ui->tableWidget->setItem(row, 5, itemMotor);

            int colunaComNomeLongo = 1;
            ui->tableWidget->horizontalHeader()->resizeSection(colunaComNomeLongo, 150);

            ui->tableWidget->setColumnCount(6);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Código" << "Nome" << "País" << "Idade" << "Equipe" << "Motor");

        } catch (std::bad_alloc &FUDEU) {
            throw QString("A Grid não pode ser criada");
        }
    }
}

void MainWindow::on_pushButtonOrdenar_clicked() {    
    try {
        if (ui->comboBox->currentText() == "Código") {
            hil::Manipular manipularArquivo(EnderecoArquivo);
            manipularArquivo.buscarDadosNoArquivo();

            // Faz uma cópia da coleção de pilotos
            hil::ListaLSE colecaoDePilotosF1Copia = manipularArquivo.getColecaoDePilotosF1();

            // Ordena a cópia da coleção
            colecaoDePilotosF1Copia.ordenarPorCodigoCrescente();

            // Limpa o conteúdo atual da tabela
            ui->tableWidget->clear();
            ui->tableWidget->setRowCount(0);

            // Configura o número de linhas na tabela com base no tamanho da coleção
            int numLinhas = colecaoDePilotosF1Copia.getQe();
            ui->tableWidget->setRowCount(numLinhas);

            // Preenche a tabela com os dados ordenados
            for (int row = 0; row < numLinhas; ++row) {
                const hil::Piloto& piloto = colecaoDePilotosF1Copia.acessarPos(row + 1);

                // Preenche cada célula da linha com os dados do piloto
                QTableWidgetItem* itemCodigo = new QTableWidgetItem(QString::number(piloto.getCodigo()));
                QTableWidgetItem* itemNome = new QTableWidgetItem(piloto.getNome());
                QTableWidgetItem* itemPais = new QTableWidgetItem(piloto.getPais());
                QTableWidgetItem* itemIdade = new QTableWidgetItem(QString::number(piloto.getIdade()));
                QTableWidgetItem* itemEquipe = new QTableWidgetItem(piloto.getEquipe());
                QTableWidgetItem* itemMotor = new QTableWidgetItem(piloto.getMotor());

                ui->tableWidget->setItem(row, 0, itemCodigo);
                ui->tableWidget->setItem(row, 1, itemNome);
                ui->tableWidget->setItem(row, 2, itemPais);
                ui->tableWidget->setItem(row, 3, itemIdade);
                ui->tableWidget->setItem(row, 4, itemEquipe);
                ui->tableWidget->setItem(row, 5, itemMotor);

                ui->tableWidget->setColumnCount(6);
                ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Código" << "Nome" << "País" << "Idade" << "Equipe" << "Motor");
               }
        }
        }catch (QString& erro) {
            QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

        try{

            if (ui->comboBox->currentText() == "Nome") {
            hil::Manipular manipularArquivo(EnderecoArquivo);
            manipularArquivo.buscarDadosNoArquivo();

            // Faz uma cópia da coleção de pilotos
            hil::ListaLSE colecaoDePilotosF1Copia = manipularArquivo.getColecaoDePilotosF1();

            // Ordena a cópia da coleção em ordem decrescente por nome
            colecaoDePilotosF1Copia.ordenarPorNomeDecrescente();

            // Limpa o conteúdo atual da tabela
            ui->tableWidget->clear();
            ui->tableWidget->setRowCount(0);

            // Configura o número de linhas na tabela com base no tamanho da coleção
            int numLinhas = colecaoDePilotosF1Copia.getQe();
            ui->tableWidget->setRowCount(numLinhas);

            // Preenche a tabela com os dados ordenados
            for (int row = 0; row < numLinhas; ++row) {
                const hil::Piloto& piloto = colecaoDePilotosF1Copia.acessarPos(row + 1);

                QTableWidgetItem* itemCodigo = new QTableWidgetItem(QString::number(piloto.getCodigo()));
                QTableWidgetItem* itemNome = new QTableWidgetItem(piloto.getNome());
                QTableWidgetItem* itemPais = new QTableWidgetItem(piloto.getPais());
                QTableWidgetItem* itemIdade = new QTableWidgetItem(QString::number(piloto.getIdade()));
                QTableWidgetItem* itemEquipe = new QTableWidgetItem(piloto.getEquipe());
                QTableWidgetItem* itemMotor = new QTableWidgetItem(piloto.getMotor());

                ui->tableWidget->setItem(row, 0, itemCodigo);
                ui->tableWidget->setItem(row, 1, itemNome);
                ui->tableWidget->setItem(row, 2, itemPais);
                ui->tableWidget->setItem(row, 3, itemIdade);
                ui->tableWidget->setItem(row, 4, itemEquipe);
                ui->tableWidget->setItem(row, 5, itemMotor);

                ui->tableWidget->setColumnCount(6);
                ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Código" << "Nome" << "País" << "Idade" << "Equipe" << "Motor");
            }
            }
            } catch (QString& erro) {
                 QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}
