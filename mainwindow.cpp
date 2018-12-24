#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inserirNaTabela(Aluno fulano, int linha)
{
    ui->tbl_dados->setItem(linha,0,new QTableWidgetItem(fulano.getNome()));
    ui->tbl_dados->setItem(linha,1,new QTableWidgetItem(fulano.getMatricula()));
    ui->tbl_dados->setItem(linha,2,new QTableWidgetItem(calculoVeterano(fulano.veterano())));
    ui->tbl_dados->setItem(linha,3,new QTableWidgetItem(calculoCurso(fulano.getCurso())));
}

QString MainWindow::calculoVeterano(bool a)
{
    QString resultado;
    if(a==false){
        resultado="Não";
    }
    else{
        resultado="Sim";
    }
    return resultado;
}

QString MainWindow::calculoCurso(int b)
{
    QString resultado;
    if(b==1){resultado="Engenharia Elétrica";}
    else if(b==2){resultado="Administrção";}
    else if(b==3){resultado="Computação";}
    else if(b==4){resultado="Automação Industrial";}
    else if(b==5){resultado="Contabilidade";}
    else if(b==6){resultado="Design de Interiores";}
    else if(b==7){resultado="Engenharia Civil";}
    else if(b==8){resultado="Telecomunicações";}
    else if(b==9){resultado="Geoprocessamento";}
    else if(b==10){resultado="Engenharia Química";}
    return resultado;
}

void MainWindow::calcularQuantidade(Aluno b)
{
    if(b.getCurso()==1){EE++;}
    else if(b.getCurso()==2){Admin++;}
    else if(b.getCurso()==3){Comput++;}
    else if(b.getCurso()==4){AI++;}
    else if(b.getCurso()==5){Cont++;}
    else if(b.getCurso()==6){DI++;}
    else if(b.getCurso()==7){EC++;}
    else if(b.getCurso()==8){Tele++;}
    else if(b.getCurso()==9){Geo++;}
    else if(b.getCurso()==10){EQ++;}
}

void MainWindow::mostrarQuantidade()
{
    ui->lne_EngenhariaEletrica->setText(QString::number(EE));
    ui->lne_Administracao->setText(QString::number(Admin));
    ui->lne_Computacao->setText(QString::number(Comput));
    ui->lne_AutomacaoIndustrial->setText(QString::number(AI));
    ui->lne_Contabilidade->setText(QString::number(Cont));
    ui->lne_DesignDeInteriores->setText(QString::number(DI));
    ui->lne_EngenhariaCivil->setText(QString::number(EC));
    ui->lne_Telecomunicacoes->setText(QString::number(Tele));
    ui->lne_Geoprocessamento->setText(QString::number(Geo));
    ui->lne_EngenhariaQuimica->setText(QString::number(EQ));
}

void MainWindow::on_btn_inserir_clicked()
{
if(ui->lne_nome->text().size() != 0 && ui->lne_matricula->text().size() == 9){
    Aluno fulano;
    fulano.setNome(ui->lne_nome->text());
    fulano.setMatricula(ui->lne_matricula->text());
    fulano.setCurso();
    QString temporario=fulano.getMatricula();

    if(fulano.getCurso()>0 && fulano.getCurso()<11 && temporario[4]>'0' && temporario[4]<'3'){

        ui->lne_nome->clear();
        ui->lne_matricula->clear();

        bool temp=true;

        for(int i=0;i<Matriculados.size();i++){
            if(Matriculados[i].getNome()==fulano.getNome() or Matriculados[i].getMatricula()==fulano.getMatricula()){
                inserirNaTabela(fulano,i);
                temp=false;

                calcularQuantidade(fulano);

                if(Matriculados[i].getCurso()==1){EE--;}
                else if(Matriculados[i].getCurso()==2){Admin--;}
                else if(Matriculados[i].getCurso()==3){Comput--;}
                else if(Matriculados[i].getCurso()==4){AI--;}
                else if(Matriculados[i].getCurso()==5){Cont--;}
                else if(Matriculados[i].getCurso()==6){DI--;}
                else if(Matriculados[i].getCurso()==7){EC--;}
                else if(Matriculados[i].getCurso()==8){Tele--;}
                else if(Matriculados[i].getCurso()==9){Geo--;}
                else if(Matriculados[i].getCurso()==10){EQ--;}

                Matriculados.replace(i,fulano);
            }
        }
        if(temp==true){
            int row = ui->tbl_dados->rowCount();
            ui->tbl_dados->insertRow(row);
            inserirNaTabela(fulano, row);

            Matriculados.inserirAluno(fulano);

            calcularQuantidade(fulano);
        }
        mostrarQuantidade();
        }
    else{QMessageBox::warning(this,"Erro","Matrícula inválida");}
    }
}

void MainWindow::on_btn_OrdenarNome_clicked()
{
     ui->tbl_dados->clearContents();

     Matriculados.ordenarPorNome();
         for(int i = 0; i<Matriculados.size(); i++){
             inserirNaTabela(Matriculados[i], i);
         }
}

void MainWindow::on_btn_OrdenarMatricula_clicked()
{
    ui->tbl_dados->clearContents();

    Matriculados.ordenarPorMatricula();
        for(int i = 0; i<Matriculados.size(); i++){
            inserirNaTabela(Matriculados[i], i);
        }
}
void MainWindow::on_btn_OrdenarCurso_clicked()
{
    ui->tbl_dados->clearContents();

    Matriculados.ordenarPorCurso();
        for(int i = 0; i<Matriculados.size(); i++){
            inserirNaTabela(Matriculados[i], i);
        }
}
void MainWindow::on_actionSalvar_triggered()
{
    QString nome_arquivo = QFileDialog::getSaveFileName(this,"Salvar arquivo","","(*.txt)");

    QFile arquivo(nome_arquivo);
    arquivo.open(QIODevice::WriteOnly);

    QTextStream saida(&arquivo);
    for(int i=0;i<Matriculados.size();i++){
        saida<<Matriculados[i].getNome()<<" , "<<Matriculados[i].getMatricula()<<" , "<<calculoCurso(Matriculados[i].getCurso())<<endl;
    }
    arquivo.close();
}

void MainWindow::on_actionCarregar_triggered()
{
    ui->tbl_dados->clearContents();
    Matriculados.clear();

    QString nome_arquivo = QFileDialog::getOpenFileName(this,"Carregar arquivo","","(*.txt)");

    QFile arquivo(nome_arquivo);
    arquivo.open(QIODevice::ReadOnly);

    QTextStream entrada(&arquivo);

    QString linha;

    while(!entrada.atEnd()){
       linha=entrada.readLine();
       QStringList dados=linha.split(" , ");

       Aluno a;
       a.setNome(dados[0]);
       a.setMatricula(dados[1]);
       a.setCurso();
       Matriculados.inserirAluno(a);

    }
    for(int i=0;i<Matriculados.size();i++){
         if(i >= ui->tbl_dados->rowCount()){
             ui->tbl_dados->insertRow(i);
         }
         inserirNaTabela(Matriculados[i],i);
         calcularQuantidade(Matriculados[i]);
     }
    mostrarQuantidade();
    arquivo.close();
}
