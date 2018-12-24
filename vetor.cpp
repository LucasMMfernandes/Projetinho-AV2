#include "vetor.h"


Vetor::Vetor()
{

}
void Vetor::inserirAluno(Aluno a)
{
    alunos.push_back(a);
}

void Vetor::ordenarPorNome()
{
    std::sort(alunos.begin(), alunos.end(), [](Aluno a, Aluno b){return a.getNome()<b.getNome();});
}

void Vetor::ordenarPorMatricula()
{
    ordenarPorNome();
    std::stable_sort(alunos.begin(),alunos.end(),[](Aluno a, Aluno b){return a.getMatricula()<b.getMatricula();});
}

void Vetor::ordenarPorCurso()
{
    ordenarPorNome();
    std::stable_sort(alunos.begin(),alunos.end(),[](Aluno a, Aluno b){return a.getCurso()<b.getCurso();});
}

int Vetor::size()
{
    return alunos.size();
}
void Vetor::clear()
{
    alunos.clear();
}

void Vetor::replace(int a,Aluno aluno)
{
    alunos.replace(a,aluno);
}
Aluno Vetor::operator[](int i)
{
    return alunos[i];
}
