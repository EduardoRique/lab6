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

using namespace std;

#include "pilha.h"
#include "tratastring.h"

/**
* @brief    Função principal
*/
int main(void){

    string p1; /**< String que será verificada */
    string p2 = ""; /**< String de comparacao */
    cout << "Digite a palavra: ";
    getline(cin, p1);

    tratar_string(p1);
    
    Pilha pilha(p1.length());

//    for(unsigned int i=0; i<p1.length(); i++){
       
//        if((int)p1[i] == 160){ //|| p1[i] == 'à' || p1[i] == 'ã' || p1[i] == 'â'){
//            p1[i] = 'a';
//        }
//        if(p1[i] == 'é' || p1[i] == 'è' || p1[i] == 'ê' || p1[i] == 'ẽ'){
//            p1[i] = 'e';
//        }
//        if(p1[i] == 'í' || p1[i] == 'ì' || p1[i] == 'î'){
//            p1[i] = 'i';
//        }
//        if(p1[i] == 'ó' || p1[i] == 'ô' || p1[i] == 'ò' || p1[i] == 'õ'){
//            p1[i] = 'o';
        //}
        //if(p1[i] == 'ú' || p1[i] == 'ù' || p1[i] == 'û'){
          //  p1[i] = 'u';
        //}
//    }
//cout << p1 << endl;

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