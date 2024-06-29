#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "MinhaArvoreDeBuscaBinaria.h"

template <typename T>
class MinhaArvoreAVL final : public MinhaArvoreDeBuscaBinaria<T>
{
        private:
        

Nodo<T> *RotateLL(Nodo<T> *Vader) {
    Nodo<T> *tmp_luke=Vader->filhoDireita;
    Vader->filhoDireita=tmp_luke->filhoEsquerda;
    tmp_luke->filhoEsquerda=Vader;
return tmp_luke;}
Nodo<T> *RotateRR(Nodo<T> *Vader){
    Nodo<T> *tmp_luke=Vader->filhoEsquerda;
    Vader->filhoEsquerda=tmp_luke->filhoDireita;
    tmp_luke->filhoDireita=Vader;
return tmp_luke;}
Nodo<T> *RotateLR(Nodo<T> *Vader){
    Vader->filhoEsquerda=this->RotateLL(Vader->filhoEsquerda);
return this->RotateRR(Vader);}
Nodo<T> *RotateRL(Nodo<T> *Vader){
    Vader->filhoDireita=this->RotateRR(Vader->filhoDireita);
    return this->RotateLL(Vader);}
int Themis(Nodo<T> *key) const{
int HeightL=0,HeightR=0;
    if(key!=nullptr){
        if(key->filhoEsquerda!=nullptr){
        HeightL=1+ MinhaArvoreDeBuscaBinaria<T>::TallTree(key->filhoEsquerda);}
        if(key->filhoDireita !=nullptr){
        HeightR=1+ MinhaArvoreDeBuscaBinaria<T>::TallTree(key->filhoDireita);}
        return HeightL-HeightR;}
    return 0;}
void Equilibrium(Nodo<T> *Vader){
if(Vader!=nullptr){
    int Equi=this->Themis(Vader);
    if(Equi< -1){
        Equi=this->Themis(Vader->filhoDireita);
        if(Equi <= 0){
            Nodo<T> *granny = this->Luke(Vader->chave,this->_raiz);
            if(granny==nullptr){
            ArvoreDeBuscaBinaria<T>::_raiz=this->RotateLL(Vader);
            }else{
            granny->filhoDireita=this->RotateLL(Vader);}
        return;
        }else{
        Nodo<T> *granny=this->Luke(Vader->chave,this->_raiz);
            if(granny==nullptr){
            ArvoreDeBuscaBinaria<T>::_raiz=this->RotateRL(Vader);
            }else{
            granny->filhoDireita=this->RotateRL(Vader);
            }return;} }
    if(Equi>1){
        Equi=this->Themis(Vader->filhoEsquerda);
        if(Equi>=0){
            Nodo<T> *granny=this->Luke(Vader->chave,this->_raiz);
            if(granny==nullptr){
            ArvoreDeBuscaBinaria<T>::_raiz=this->RotateRR(Vader);
            }else{
            granny->filhoEsquerda=this->RotateRR(Vader);}
            return;
        }else{Nodo<T> *granny=this->Luke(Vader->chave,this->_raiz);
            if(granny==nullptr){
            ArvoreDeBuscaBinaria<T>::_raiz=this->RotateLR(Vader);
            }else{granny->filhoEsquerda=this->RotateLR(Vader);}
            return;}}
    if(Vader->chave== ArvoreDeBuscaBinaria<T>::_raiz->chave){
        return;}
        return Equilibrium(this->Luke(Vader->chave,this->_raiz));}
return;}
    
        public:
        
void remover(T chave){
Nodo<T> *Vader= this->Luke(chave,this->_raiz);
MinhaArvoreDeBuscaBinaria<T>::remover(chave);
Equilibrium(Vader);}
void inserir(T chave){
MinhaArvoreDeBuscaBinaria<T>::inserir(chave);
Nodo<T> *Vader=this->Luke(chave,this->_raiz);
MinhaArvoreAVL<T>::Equilibrium(Vader); }
 //MinhaArvoreAVL : this->
};
#endif