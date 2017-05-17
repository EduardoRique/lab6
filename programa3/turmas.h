/**
*@file	turmas.h
*@brief	Cabecalho da classe Turma
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 14/05/2017
*@date  17/05/2017
*/
#ifndef TURMAS_H
#define TURMAS_H

#include <iostream>
#include <string>
#include "lista.h"

using namespace std;


/**
    * @class   Aluno
    * @brief   Classe que representa um aluno
    * @details Os atributos de um no são: o nome e nota
	*/ 
class Aluno {
    public:    
        string nome; /**< nome */
        long int matricula; /**< matricula */
        int faltas; /**< faltas */
        float nota; /**< nota */

        Aluno(string n = "", long int m = 0, int f = 0, float no = 0) { /**< Construtor parametrizado */
            nome = n;
            matricula = m;
            faltas = f;
            nota = no;
        }
        bool operator<(Aluno const a) {
            if (nota < a.nota) return true;
            return false;
        }
        bool operator!=(Aluno const a) {
            if (matricula != a.matricula) return true;
            return false;
        }
        bool operator==(Aluno const a) {
            if (matricula == a.matricula) return true;
            return false;
        }
};

/**
    * @class   Turma
    * @brief   Classe que representa uma turma
    * @details Os atributos de uma turma são: um ponteiro para a lista de alunos
	*/ 
class Turma {
    private:
       string nomeT;
       Lista<Aluno> alunos; /**< lista de alunos */
    public:
        Turma(){ /**< Construtor padrao */
            nomeT = "";
        }
        void setnome(string n);
        string getnome();
        void Inserir(Aluno a); /**< Insere aluno na turma */
        void Remover(Aluno a); /**< Remove aluno da turma */
        void quais(); /**< Lista os alunos da turma */
        void quantos(); /**< Informa a quantidade de alunos */
        void media(); /**< Informa a media das notas */
        friend ostream& operator<<(ostream& os, Aluno a);
        friend istream& operator>>(istream& is, Aluno &a);

};






#endif