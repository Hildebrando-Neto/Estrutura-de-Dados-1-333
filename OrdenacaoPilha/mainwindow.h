// Funcao: mainwindow - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: OrdenacaoPilha
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtextedit.h"
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
   void on_pushButtonOrdenar_clicked();   

private:
    Ui::MainWindow *ui;
    QTextEdit *textEditResultados;
};
#endif // MAINWINDOW_H
