// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ContadorDePalavras
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
    try {
        // nomeDoArquivoNoDisco - atributo da classe MainWindow
        //Buscando o arquivo no disco
        EnderecoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
        if(EnderecoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");
        ui->lineEdit->setText(EnderecoArquivo);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    try {
        // Verificar se o arquivo foi selecionado
        if (EnderecoArquivo.isEmpty()) {
            throw QString("Selecione um arquivo antes de clicar neste botão.");
        }

        // Criar um objeto ManipularArquivo com o caminho do arquivo
        hil::ManipularArquivo manipulador(EnderecoArquivo);

        // Buscar dados do arquivo
        manipulador.buscarDadosNoArquivo();

        // Obter a árvore de palavras e suas contagens diretamente
        const hil::ArvoreBinaria &arvore = manipulador.getContadorPalavras();

        // Limpar o textEdit antes de exibir novos dados
        ui->textEdit->clear();

        // Exibir as palavras e suas contagens no textEdit
        QString dadosFormatados = arvore.obterDadosFormatados();
        ui->textEdit->setText(dadosFormatados);
    } catch (const QString &erro) {
        // Lidar com possíveis exceções e exibir mensagens de erro
        QMessageBox::critical(this, "Erro", erro);
    }
}
