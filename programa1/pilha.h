/**
*@file	pilha.h
*@brief	Cabecalho da classe Pilha
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 09/05/2017
*@date  09/05/2017
*/

#ifndef PILHA_H
#define PILHA_H

/**
    * @class   pilha pilha.h
    * @brief   Classe que representa uma pilha
    * @details Os atributos da pilha são: tamanhomax, tamanho e pilha
	*/ 
class Pilha {
    private:
    int tamanhomax; /**< Tamanho maximo da pilha */
    int tamanho; /**< Tamanho */
    char *pilha; /**< elementos */
    
    public:
    Pilha(int tamanho); /**< Construtor padrao */
    int push(char el); /**< Insere no topo */
    char pop(); /**< Remove do topo */
};

#endif