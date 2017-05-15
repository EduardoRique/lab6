/** 
*@file main.cpp
*@brief Programa que cria uma lista duplamente encadeada generica
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 10/05/2017
*@date  13/05/2017
*/

#include <iostream>
#include "tarefa2/lista.h"

using namespace std;

int main(){

    Lista<int> ist;

    int opcao; /**< Opcao que sera passada pelo usuario */
    do{ 
        cout << endl;
        cout << "=========================================" << endl;
        cout << "Lista" << endl;
        cout << "=========================================" << endl;
        cout << "(1) Inserir elemento" << endl;
        cout << "(2) Remover elemento" << endl;
        cout << "(3) Imprimir elementos" << endl;
        cout << "(0) Sair" << endl;

        cout << endl;
        cout << "Digite a sua opcao: ";
        cin >> opcao;

        cout << endl;
        
        if(opcao<0 || opcao>3) cout << endl << endl << "=======================" << endl << "Digite uma opcao valida" << endl << "=======================" << endl << endl;
        
        switch(opcao) {
            case 1:
                
                int x;
	            cout << "Digite um valor para inserir: ";
                cin >> x;
                ist.Inserir(x);
            
                break;
            case 2:
                
                int y;
	            cout << "Digite um valor para remover: ";
                cin >> y;
                ist.Remover(y);

                break;
            case 3:
                ist.Print();
                break;
        }

    }while(opcao != 0);

    return 0;
}
