// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ListaRecursiva
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "recursividade.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_executar_clicked();

    void on_executar_2_clicked();

    void on_executar_3_clicked();

    void on_executar_4_clicked();

    void on_executar_5_clicked();

    void on_executar_6_clicked();

private:
    Ui::MainWindow *ui;
    hil::Recursividade recur;
};
#endif // MAINWINDOW_H
