#ifndef ALUNO_H
#define ALUNO_H

#include <QObject>

class Aluno{

private:
    QString nome;
    QString matricula;
    int curso;

public:
    Aluno();
    void setNome(QString a);
    void setMatricula(QString b);
    void setCurso();
    QString getNome();
    QString getMatricula();
    int getCurso();
    bool veterano();
};

#endif // ALUNO_H
