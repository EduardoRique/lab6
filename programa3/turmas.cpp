/**
*@file	turmas.cpp
*@brief	Implementacao da classe Turma
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 14/05/2017
*@date  17/05/2017
*/

#include "lista.h"
#include "turmas.h"

/** 
* @details Da o nome a turma
* @param	string n
*/
void Turma::setnome(string n){
    nomeT = n;
}

/** 
* @return	nome da turma
*/
string Turma::getnome(){
    return nomeT;
}

/** 
* @details Adiciona aluno a turma
* @param	a aluno a ser inserido na turma
*/
void Turma::Inserir(Aluno a){
    
    Node<Aluno> *itd = alunos.getCabeca();
    int cont=0;
    while(itd){
        if(a.matricula == itd->dado.matricula)cont++;
        itd = itd->prox;
    }
    if(cont > 0){
        cout << "Aluno ja inserido" << endl;
    }
    else alunos.Inserir(a);
}

/** 
* @details Remove um aluno da turma
* @param	a aluno a ser removido
*/
void Turma::Remover(Aluno a){
    alunos.Remover(a);
}

/** 
* @details imprime os alunos da turma
*/
void Turma::quais(){
    cout << endl;
    cout << "Nome / Matricula / Nº de faltas / Nota" << endl;
    alunos.Print();
}

/** 
* @details imprime a quantidade de alunos da turma
*/
void Turma::quantos(){
    cout << endl;

    Node<Aluno> *itd = alunos.getCabeca();
    int cont=0;
    while(itd){
        cont++;
        itd = itd->prox;
    }
    cout << cont << " alunos nesta turma" << endl;
}

/** 
* @details imprime a media da turma
*/
void Turma::media(){
    cout << endl;

    float sum;

    Node<Aluno> *itd = alunos.getCabeca();
    
    int cont=0;
    
    while(itd){
        cont++;
        sum += itd->dado.nota;
        itd = itd->prox;
    }
    cout << "Media da turma = " << (sum/cont) << endl;
}

/** 
* @details O operador é sobrecarregado para representar o aluno
* @param	os Referência para stream de saída
* @param	e Referência para o objeto empresa a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Aluno a) {
	os <<  a.nome << " " << a.matricula << " " << a.faltas << " " << a.nota;
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Aluno a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Aluno &a) {
    is >> a.nome >> a.matricula >> a.faltas >> a.nota;
    return is;
}