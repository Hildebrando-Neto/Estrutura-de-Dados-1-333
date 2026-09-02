// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ListaSimplesVisual
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <recursivo.h>
#include <QMainWindow>
#include <QMessageBox>

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

    void on_executar2_clicked();

    void on_executar3_clicked();

    void on_executar4_clicked();

    void on_executar5_clicked();

    void on_executar6_clicked();

private:
    Ui::MainWindow *ui;
    hil::Recursivo recur;
};
#endif // MAINWINDOW_H
