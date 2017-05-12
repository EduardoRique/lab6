#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Node {
    public:
        Node<T>* ant;
        T dado;
        Node<T>* prox;
};

template <typename T>
class LL {
    public:
        Node<T>* inicio;
};

template <typename T>
class Lista {
    private:
        LL<T> *cabeca;
        Node<T> *cauda;
    public:
        Lista() { 
            cabeca = new LL<T>();
            cabeca = NULL;
        }
        ~Lista() {                                                                                                                                                                                                               
            Node<T> **aa = &cauda->prox;
            while(*aa){
                Node<T> *tmp = *aa;
                *aa = (*aa)->prox;
                delete tmp; 
            }
        }
        void Inserir(T el);
        void Remover(T el);

};

template<typename T>
void Lista<T>::Inserir(T el){
    
    Node<T> **aa = &cabeca->inicio;
    
    while(*aa && ((*aa)->dado) < el){
        aa = &((*aa)->prox);
    }
    
    Node<T>* tmp = new Node<T>();
    tmp->dado = el;
    tmp->prox = *aa;
    tmp->ant = (*aa)->ant;
}

template<typename T>
void Lista<T>::Remover(T el){
    
    Node<T> **aa = &cabeca->inicio;
     
    while(*aa && ((*aa)->dado != el)){
        aa = &((*aa)->prox);
    }

    Node<T> *tmp = *aa;
    *aa = (*aa)->prox;
    if(*aa) (*aa)->ant = tmp->ant;
    if(tmp) delete tmp;
}



#endif