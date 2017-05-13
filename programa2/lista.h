#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Node {
    public:    
        Node<T>* ant;
        T dado;
        Node<T>* prox;

        Node<T>(){
            ant = prox = NULL;
        }
        Node<T>(const T& el, Node<T> *p = NULL, Node<T> *a = NULL) {
        dado = el; prox = p; ant = a;
        }
};

template <typename T>
class Lista {
    private:
        Node<T> *cabeca;
        Node<T> *cauda;
    public:
        Lista() { 
            cabeca = NULL;
            cauda = NULL;
        }
        ~Lista() {            
            cauda = NULL;
            Node<T> *tmp = cabeca;
            while(tmp){
                cauda = tmp;
                tmp = tmp->prox;
            }
            
            while(cauda != cabeca){
                tmp = cabeca;
                while(tmp->prox && tmp->dado<=cauda->dado){
                    cauda = tmp;
                    tmp = tmp->prox;
                }
                delete tmp;
            }
            
            
            //Node<T> *itd = cabeca;
            //Node<T> *tmp = cauda;
            //while(itd != NULL){
            //   itd = itd->prox;
           // }
           // delete tmp;
            //cauda = itd;

        }
        void Inserir(T el);
        void Remover(T el);
        void Print();

};

template<typename T>
void Lista<T>::Print(){
    Node<T> *itd = cabeca;
    while(itd){
        cout << itd->dado << endl;
        itd = itd->prox;
    }
}

template<typename T>
void Lista<T>::Inserir(T el){
    if(!cabeca || el < cabeca->dado){
        
        Node<T>* tmp = new Node<T>();
        tmp->dado = el;
        tmp->prox = cabeca;
        cabeca = tmp;
    }
    else{
        Node<T> *itd = cabeca;
        Node<T>* tmp = new Node<T>();
        tmp->dado = el;

        while(itd && itd->dado < el && itd->prox){
            itd = itd->prox;
        }
        if(el < itd->dado){
            tmp->prox = itd;
            tmp->ant = itd->ant;
            itd->ant->prox = tmp;   
        }
        else{
            tmp->prox = itd->prox;
            itd->prox = tmp;
            tmp->ant = itd;
        }
    }
}

template<typename T>
void Lista<T>::Remover(T el){
    
    Node<T> *itd = cabeca;
    Node<T> *tmp = NULL;
    
    while(itd && itd->dado != el){
        tmp = itd;
        itd = itd->prox;
    }
    
    if(itd && itd->dado == el){
        if(itd->prox){
            if(tmp){
                tmp->prox = itd->prox;
                itd->prox->ant = tmp;
            }
            else{
                cabeca = itd->prox;
                itd->prox->ant = NULL;
            }
        }
        else{
            if(tmp){
                tmp->prox = NULL;
            }
            else{
                cabeca = NULL;
            }
        }
        
        tmp = itd;
        delete tmp;
    }
    else{
        cout << "Elemento para ser removido não encontrado" << endl;
    }
}



#endif