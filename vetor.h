#ifndef VETOR_H
#define VETOR_H

#include<QObject>
#include"aluno.h"
#include <QVector>
#include<algorithm>

class Vetor{  
private:
    QVector<Aluno> alunos;

public:
    Vetor();
    void inserirAluno(Aluno a);
    void ordenarPorNome();
    void ordenarPorMatricula();
    void ordenarPorCurso();
    int size();
    void clear();
    void replace(int a,Aluno aluno);
    Aluno operator[](int i);
};

#endif // VETOR_H
