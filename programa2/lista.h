#ifndef LISTA_H
#define LISTA_H

template <class T>
class Node {
    public:
        Node<T>* ant;
        T dado;
        Node<T>* prox;
};

//template <class T>
//class LL {
//    public:
//        Node<T>* ll;
//};

template <typename T>
class Lista {
    private:
        //LL<T> *cabeca;
        Node<T> *cauda;
    public:
        Lista() { 
            //cabeca = new LL<T>();
            //cabeca = NULL;
            cauda->prox = NULL;
            cauda->ant = NULL;
        }
        ~Lista() {                                                                                                                                                                                                               
            //delete cabeca;
            delete cauda;
        }
        void Inserir(T el);
        void Remover();

};

template<typename T>
void Lista<T>::Inserir(T el){
    
    Node<T> **aa;
    aa = &(cauda->prox);
    
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