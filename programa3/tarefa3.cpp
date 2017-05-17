/**
*@file	tarefa3.cpp
*@brief	Programa que cadastra turma e alunos
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 14/05/2017
*@date  17/05/2017
*/
#include <iostream>
#include <string>
#include <fstream>
#include "turmas.h"
#include "lista.h"

using namespace std;

/**
    * @brief   Funcao principal
	*/ 
int main(int argc, char* argv[]){

    Turma turmas[100];
    int i=0;

    ifstream entrada(argv[1]); 
    if(entrada){

        string n; /**< nome do aluno */
        long int m; /**< matricula */
        int f; /**< faltas */
        float no; /**< nota */
                    
        
        string asd; /**< Recebe o nome da turma */
        cout << "Digite o nome da turma: ";
        cin >> asd;
        turmas[i].setnome(asd);
        

        string aux; /**< auxiliar para a leitura do arquivo */
        int cont=0;
        
        while(getline(entrada, aux)){
            cont++;
        }

        entrada.clear();
        entrada.seekg(entrada.beg);

        int count = 0;
        string s = "";
        int ii;

        while(count < cont){
            ii = 0;
            getline(entrada, aux);
            while(aux[ii] != ' '){
                s += aux[ii];
                ii++;
            }
            ii++;
            n = s;
            s = "";
            while(aux[ii] != ' '){
                s += aux[ii];
                ii++;
            }
            ii++;
            m = stol(s);
            s = "";
            while(aux[ii] != ' '){
                s += aux[ii];
                ii++;
            }
            ii++;
            f = stoi(s);
            s = "";
            while(ii < (int)aux.length()){
                s += aux[ii];
                ii++;
            }
            no = stof(s);
            s = "";

            Aluno x(n, m, f, no);
            turmas[0].Inserir(x);
            count++;
        }
    i++;
    }

        int opcao; /**< Opcao que sera passada pelo usuario */
    do{ 
        cout << endl;
        cout << "=========================================" << endl;
        cout << "Lista" << endl;
        cout << "=========================================" << endl;
        cout << "(1) Cadastrar turma" << endl;
        cout << "(2) Cadastrar aluno" << endl;
        cout << "(3) Remover aluno" << endl;
        cout << "(4) Imprimir a turma" << endl;
        cout << "(5) Imprimir a quantidade de alunos na turma" << endl;
        cout << "(6) Imprimir a media da turma" << endl;
        cout << "(0) Sair" << endl;

        cout << endl;
        cout << "Digite a sua opcao: ";
        cin >> opcao;

        cout << endl;
        
        if(opcao<0 || opcao>6) cout << endl << endl << "=======================" << endl << "Digite uma opcao valida" << endl << "=======================" << endl << endl;
        
        else if(opcao == 1){

                string n;
                cout << "Digite o nome da turma: ";
                cin >> n;
                turmas[i].setnome(n);
                i++;
            }
            
        else if(opcao == 2){
                
            if(i > 0){
                cout << "Deseja inserir em qual turma? " << endl;
                
                for(int ii=0; ii<i; ii++){
                    cout << "(" << ii << "): " << turmas[ii].getnome() << endl;
                }

                int j;
                cin >> j;
                if(j < i){
                    string n;
                    long int m;
                    int f;
                    float no;
                    
                    cout << "Digite o nome do aluno: ";
                    cin >> n;
                    cout << "Digite a matricula do aluno: ";
                    cin >> m;
                    cout << "Digite a quantidade de faltas do aluno: ";
                    cin >> f;
                    cout << "Digite a nota do aluno: ";
                    cin >> no;
                    
                    Aluno y(n, m, f, no);

                    turmas[j].Inserir(y);
                }
                else cout << "Turma inexistente" << endl;
            }
        }

        else if(opcao == 3){

            if(i > 0){
                cout << "Deseja remover de qual turma? " << endl;
            
                for(int ii=0; ii<i; ii++){
                cout << "(" << ii << "): " << turmas[ii].getnome() << endl;
                }

                int j;
                cin >> j;

                if(j < i){
                    string n;
                    long int m;
                    int f;
                    float no;
                    
                    cout << "Digite o nome do aluno: ";
                    cin >> n;
                    cout << "Digite a matricula do aluno: ";
                    cin >> m;
                    cout << "Digite a quantidade de faltas do aluno: ";
                    cin >> f;
                    cout << "Digite a nota do aluno: ";
                    cin >> no;
                    
                    Aluno x(n, m, f, no);

                    turmas[j].Remover(x);
                }
                else cout << "Turma inexistente" << endl;
            } 
        }
        else if(opcao == 4){
            
            if(i > 0){
                cout << "Deseja imprimir qual turma? " << endl;
            
                for(int ii=0; ii<i; ii++){
                cout << "(" << ii << "): " << turmas[ii].getnome() << endl;
                }

                int j;
                cin >> j;

                if(j < i){
                    turmas[j].quais();
                }
                else cout << "Turma inexistente" << endl;
            }
        }
        else if(opcao == 5){

            if(i > 0){
                cout << "Deseja a quantidade de alunos de qual turma? " << endl;
            
                for(int ii=0; ii<i; ii++){
                cout << "(" << ii << "): " << turmas[ii].getnome() << endl;
                }

                int j;
                cin >> j;

                if(j < i){
                    turmas[j].quantos();
                }
                else cout << "Turma inexistente" << endl;
            }
        }
        else if(opcao == 6){

            if(i > 0){
                cout << "Deseja a media de qual turma? " << endl;
            
                for(int ii=0; ii<i; ii++){
                cout << "(" << ii << "): " << turmas[ii].getnome() << endl;
                }

                int j;
                cin >> j;

                if(j < i){
                    turmas[j].media();
                }
                else cout << "Turma inexistente" << endl;
            }
        }

    }while(opcao != 0);
    

    return 0;
}