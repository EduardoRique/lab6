/**
*@file	turmas.cpp
*@brief	Implementacao da classe Turma
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 14/05/2017
*@date  15/05/2017
*/

#include "lista.h"
#include "turmas.h"

void quais(Lista<Aluno>* a){

}

void quantos(Lista<Aluno>* a){

}

void media(Lista<Aluno>* a){

}

/** 
* @details O operador é sobrecarregado para representar o aluno
* @param	os Referência para stream de saída
* @param	e Referência para o objeto empresa a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Aluno a) {
	os <<  a.nome << " " << a.nota;
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Aluno a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Aluno &a) {
    is >> a.nome >> a.nota;
    return is;
}