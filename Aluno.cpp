#include "Aluno.h"

Aluno::Aluno() {
    m_nome="João Ninguém";
    m_matricula="000000";
}
Aluno::Aluno(string nome) {
    m_nome=nome;
    m_matricula="000000";
}
Aluno::Aluno(string nome,string matricula) {
    m_nome=nome;
    m_matricula=matricula;
}
void Aluno::setNome(string nome) {
    m_nome=nome;
}
string Aluno::getNome() {
    return m_nome;
}
void Aluno::setMatricula(string matricula) {
    m_nome=matricula;
}
string Aluno::getMatricula() {
    return m_matricula;
}