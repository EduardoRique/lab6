/**
*@file	pilha.cpp
*@brief	Implementacao da classe pilha
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 09/05/2017
*@date  09/05/2017
*/

#include "pilha.h"

/**
*@details   É alocado um espaço de memoria necessario tamanho maximo
*			recebe esse tamanho e o tamanho inicializa com 0
*@param     n tamanho
*/
Pilha::Pilha(int n){
    pilha = new char[n];
    tamanhomax = n;
    tamanho = 0;
}

/**
*@details   O topo da lista recebe um elemento
*@param     el elemento
*@return    tamanho atual
*/
int Pilha::push(char el){
    if(tamanho == tamanhomax){
        return tamanho;
    }
    pilha[tamanho] = el;
    return tamanho++;
}

/**
*@details   O elemento do topo é removido da pilha
*@return    ultimo elemento
*/
char Pilha::pop(){
    if(tamanho == 0){
        return tamanho;
    }
    return pilha[--tamanho];
}