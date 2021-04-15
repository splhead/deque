#include <string>
#include <ostream>
#ifndef ALUNO_H
#define ALUNO_H
using namespace std;
class Aluno {
private:
    string m_nome;
    string m_matricula;
public:
    Aluno();
    Aluno(string);
    Aluno(string,string);
    string getNome();
    void setNome(string);
    string getMatricula();
    void setMatricula(string);    
    friend bool operator==(Aluno aluno1, Aluno aluno2) {
        return (aluno1.getMatricula().compare(aluno2.getMatricula())==0);
    }
    friend ostream& operator<<(std::ostream &strm, const Aluno &aluno) {
        return strm << "Aluno= "<<aluno.m_nome;
    }
};
#endif /* ALUNO_H */