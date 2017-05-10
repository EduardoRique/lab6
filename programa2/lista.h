#ifndef LISTA_H
#define LISTA_H

/**template <class T>
class LL {
    public:
        Node* ll;
        Node(Node* l = NULL);
};*/

template <class T>
class Node {
    public:
        Node* ant;
        T dado;
        Node* prox;
        Node(Node* a = NULL, Node* p = NULL);
};

template <typename T>
class Lista {
    private:
        Node<T> *cabeca;
        Node<T> *cauda;
    public:
        Lista() {
            cabeca = new Node<T>();
            cauda = new Node<T>();
        }
        ~Lista() {                                                                                                                                                                                                               
            delete cabeca;
            delete cauda;
        }
        void Inserir(T el);
        void Remover();

};

template<typename T>
void Lista<T>::Inserir(T el){
    
    Node<T> **aa;
    aa = &cabeca;
    
    while(*aa && *aa->dado < el){
        aa = &((*aa)->prox);
    }
    
    Node<T>* tmp = new Node<T>();
    tmp->dado = el;
    tmp->prox = *aa;
    tmp->ant = (*aa)->ant;
}

template<typename T>
void Lista<T>::Remover(){
    
}




#endif