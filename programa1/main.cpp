/** 
*@file main.cpp
*@brief Programa que diz se uma palavra ou frase é palindroma ou não
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 09/05/2017
*@date  09/05/2017
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

#include "pilha.h"
#include "tratastring.h"

/**
* @brief    Função principal
*/
int main(void){

    string p1; /**< String que será verificada */
    string p2 = ""; /**< String de comparacao */
    cout << "Digite a frase: ";
    getline(cin, p1);

    for(unsigned int i=(p1.length()-1); i!=0; i--){
       
        switch((int)p1[i]){
            case -93:
            case -94:
            case -95:
            case -125:
            case -126:
            case -127:
                p1[i] = ' ';
                p1[i-1] = 'a';
                break;
            case -75:
            case -76:
            case -77:
            case -107:
            case -108:
            case -109:
                p1[i] = ' ';
                p1[i-1] = 'o';
                break;
            case -86:
            case -87:
            case -118:
            case -119:
                p1[i] = ' ';
                p1[i-1] = 'e';
                break;
            case -83:
            case -115:
                p1[i] = ' ';
                p1[i-1] = 'i';
                break;
            case -70:
            case -102:
                p1[i] = ' ';
                p1[i-1] = 'u';
                break;
        }

    }

    tratar_string(p1);
    
    Pilha pilha(p1.length());

    for(unsigned int i=0; i<p1.length(); i++){
        pilha.push(p1[i]);
    }

    for(unsigned int i=0; i<p1.length(); i++){
        p2 += pilha.pop();   
    }
    if(p1 == p2){
        cout << "palindromo!" << endl;
    }
    else{
        cout << "Não palindromo!" << endl;
    }

    return 0;
}