#include "aluno.h"

Aluno::Aluno()
{

}

void Aluno::setNome(QString a)
{
    nome=a;
}

void Aluno::setMatricula(QString b)
{
    matricula=b;
}

void Aluno::setCurso()
{
    QString temp;
    temp[0]=matricula[5];
    temp[1]=matricula[6];
    curso=temp.toInt();
}

QString Aluno::getNome()
{
    return nome;
}

QString Aluno::getMatricula()
{
    return matricula;
}

int Aluno::getCurso()
{
    return curso;
}

bool Aluno::veterano()
{
    QString temp;
    temp[0]=matricula[0];
    temp[1]=matricula[1];
    temp[2]=matricula[2];
    temp[3]=matricula[3];
    temp[4]=matricula[4];
    if(temp=="20182"){
        return false;
    }
    else{return true;}
}
