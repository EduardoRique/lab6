/** 
*@file main.cpp
*@brief Programa que cria uma lista duplamente encadeada generica
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 10/05/2017
*@date  11/05/2017
*/

#include <iostream>
#include "lista.h"

using namespace std;

int main(){

    Lista<int> ist;

    ist.Inserir(5);
    ist.Remover(5);

    return 0;
}
