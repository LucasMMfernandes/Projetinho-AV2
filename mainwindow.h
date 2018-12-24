#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aluno.h"
#include "vetor.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Vetor Matriculados;
    int EE=0,Admin=0,Comput=0,AI=0,Cont=0,DI=0,EC=0,Tele=0,Geo=0,EQ=0;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_inserir_clicked();

    void on_btn_OrdenarNome_clicked();

    void on_btn_OrdenarMatricula_clicked();

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_btn_OrdenarCurso_clicked();

private:
    Ui::MainWindow *ui;

    void inserirNaTabela(Aluno fulano,int linha);
    QString calculoVeterano(bool a);
    QString calculoCurso(int b);
    void calcularQuantidade(Aluno b);
    void mostrarQuantidade();
};

#endif // MAINWINDOW_H
