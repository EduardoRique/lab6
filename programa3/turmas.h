/**
*@file	turmas.h
*@brief	Cabecalho da classe Turma
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 14/05/2017
*@date  15/05/2017
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
        int nota; /**< nota */

        Aluno(){ /**< Construtor padrao */
            nome = "";
            nota = 0;
        }
        Aluno(string n = "", int no = 0) { /**< Construtor parametrizado */
            nome = n;
            nota = no;
        }
};

/**
    * @class   Turma
    * @brief   Classe que representa uma turma
    * @details Os atributos de uma turma são: um ponteiro para a lista de alunos
	*/ 
class Turma {
    private:
       Lista<Aluno>* alunos; /**< lista de alunos */
    public:
        Turma(){ /**< Construtor padrao */
            alunos = NULL;
        }
        void quais(Lista<Aluno>* a); /**< Lista os alunos da turma */
        void quantos(Lista<Aluno>* a); /**< Informa a quantidade de alunos */
        void media(Lista<Aluno>* a); /**< Informa a media das notas */
        friend ostream& operator<<(ostream& os, Aluno a);
        friend istream& operator>>(istream& is, Aluno &a);

};






#endif