#ifndef MINHA_ARVORE_DE_BUSCA_BINARIA_HPP
#define MINHA_ARVORE_DE_BUSCA_BINARIA_HPP

#include "ArvoreDeBuscaBinaria.h"

template<typename T>
class MinhaArvoreDeBuscaBinaria : public ArvoreDeBuscaBinaria<T>
{
    public:

~MinhaArvoreDeBuscaBinaria(){
    if(this->_raiz !=nullptr){
    MinhaArvoreDeBuscaBinaria<T>::Motoserra(this->_raiz); //Destruidor de arvores, cortador de lenha
    }
    return;};
    
bool vazia()const{
    if(this->_raiz ==nullptr){
    return true;}
    return false;};
virtual int quantidade()const{
    int Qnt=0;
    Qnt= this->CheckQnt(this->_raiz);
    return Qnt;};
virtual bool contem(T chave) const{    
    if(!this->vazia()){
        Nodo<T> *tmp_raiz =this->SeekHave(chave,this->_raiz);
        if(tmp_raiz==nullptr){
        return false;}
        if(tmp_raiz->chave==chave){
        return true;}}
    return false;};
virtual std::optional<int> altura(T chave)const{
    if(this->contem(chave)){
        Nodo<T> *tmp_raiz=  MinhaArvoreDeBuscaBinaria<T>::SeekHave(chave,this->_raiz);
        return MinhaArvoreDeBuscaBinaria<T>::TallTree(tmp_raiz);}
    return{};};
virtual void inserir(T chave){
return MinhaArvoreDeBuscaBinaria<T>::insert(this->_raiz,chave);};
virtual void remover(T chave){
    Nodo<T> *tmp_raiz =this->_raiz;
    if(tmp_raiz->chave==chave && this->CheckLeaf(tmp_raiz)){
    ArvoreDeBuscaBinaria<T>::_raiz=nullptr;
    delete tmp_raiz;
    return;}
if(this->contem(chave)){
    Nodo<T> *Vader =this->Luke(chave,tmp_raiz);
    if(Vader==nullptr){
    MinhaArvoreDeBuscaBinaria<T>::PurgeTree(chave,tmp_raiz);
    return;}
    this->PurgeTree(chave,Vader);}
    return;};
virtual std::optional<T> filhoEsquerdaDe(T chave)const{
    if(this->contem(chave)){
    Nodo<T> *Vader = this->SeekHave(chave,this->_raiz);
    if(Vader->filhoEsquerda !=nullptr){
    return Vader->filhoEsquerda->chave;}}
    return {};};
virtual std::optional<T> filhoDireitaDe(T chave)const{
    if(this->contem(chave)){
    Nodo<T> *Vader = MinhaArvoreDeBuscaBinaria<T>::SeekHave(chave,this->_raiz);
    if(Vader->filhoDireita !=nullptr){
    return Vader->filhoDireita->chave;}}
    return {};};
virtual ListaEncadeadaAbstrata<T>* emOrdem()const{
ListaEncadeadaAbstrata<T> *MyEmOrdem =new MinhaListaEncadeada<T>();
    MinhaArvoreDeBuscaBinaria<T>::ExeEO(this->_raiz,MyEmOrdem);
return MyEmOrdem;};
virtual ListaEncadeadaAbstrata<T>* preOrdem()const{
ListaEncadeadaAbstrata<T> *MyPreOrdem =new MinhaListaEncadeada<T>();
    MinhaArvoreDeBuscaBinaria<T>::ExePreO(this->_raiz,MyPreOrdem);
return MyPreOrdem;};
virtual ListaEncadeadaAbstrata<T>* posOrdem()const{
ListaEncadeadaAbstrata<T> *MyPosOrdem =new MinhaListaEncadeada<T>();
    MinhaArvoreDeBuscaBinaria<T>::ExePO(this->_raiz,MyPosOrdem);
return MyPosOrdem;};


    
    protected:
    
void Motoserra(Nodo<T> *chave){
    if(chave!=nullptr){
    MinhaArvoreDeBuscaBinaria<T>::Motoserra(chave->filhoEsquerda);
    MinhaArvoreDeBuscaBinaria<T>::Motoserra(chave->filhoDireita);
    delete chave;}}
    
int TallTree(Nodo<T> *chave)const{
    int tall=0,tallE=0,tallD=0;
    if(chave->filhoEsquerda!=nullptr){
    tallE=TallTree(chave->filhoEsquerda)+1;}
    if(chave->filhoDireita!=nullptr){
    tallD=TallTree(chave->filhoDireita)+1;}
    return CheckHeight(tallE,tallD,tall);}
int CheckHeight(int left,int right,int height)const{
    if(left>=right){
    height=left;
    return height;
    }else{
    height=right;
    return height;}}
int CheckQnt(Nodo<T> *chave)const{
    if(chave!=nullptr){
    return (this->CheckQnt(chave->filhoEsquerda) +1+ this->CheckQnt(chave->filhoDireita));}
    return 0;}
void insert(Nodo<T> *chaveAtual,T newValue){
    if(this->vazia()){
    Nodo<T> *newkey=new Nodo<T>{newValue, 0};
    delete this->_raiz;
    ArvoreDeBuscaBinaria<T>::_raiz=newkey;
    return;}
    if(chaveAtual->chave >newValue){
        if(chaveAtual->filhoEsquerda ==nullptr){
            Nodo<T> *newkey=new Nodo<T>{newValue,chaveAtual->altura+1};
            chaveAtual->filhoEsquerda=newkey;
        }else{MinhaArvoreDeBuscaBinaria<T>::insert(chaveAtual->filhoEsquerda,newValue);}
    }else{if (chaveAtual->filhoDireita ==nullptr){
        Nodo<T> *newkey=new Nodo<T>{newValue,chaveAtual->altura+1};
        chaveAtual->filhoDireita=newkey;
        }else{MinhaArvoreDeBuscaBinaria<T>::insert(chaveAtual->filhoDireita,newValue);}}
    return;}
Nodo<T> *SeekHave(T key,Nodo<T> *tmpraiz)const{
    while(tmpraiz !=nullptr && tmpraiz->chave !=key){
        if(tmpraiz->chave <key){tmpraiz=tmpraiz->filhoDireita;
        }else{tmpraiz=tmpraiz->filhoEsquerda;}}
    return tmpraiz;}
bool CheckLeaf(Nodo<T> *chave){
    if(chave->filhoEsquerda ==nullptr && chave->filhoDireita ==nullptr){
        return true;}
    return false;}

Nodo<T> *Luke(T key,Nodo<T> *Vader)const{
    if(Vader==nullptr){
        return nullptr;}
    if(Vader->chave ==key){
        return nullptr;}
    if(Vader !=nullptr && Vader->chave !=key){
        if(Vader->chave <key){
            if(Vader->filhoDireita->chave !=key){
                return this->Luke(key,Vader->filhoDireita);}}
        if(Vader->chave >key){
            if(Vader->filhoEsquerda->chave !=key){
                return this->Luke(key,Vader->filhoEsquerda);}}}
    return Vader;}
T PurgeTree(T toClean,Nodo<T> *Vader){
Nodo<T> *tmp_key;
    if(Vader->chave ==toClean){
        if(CheckLeaf(Vader)){
        T Clean= Vader->chave;
        Vader=nullptr;
        delete Vader;
        return Clean;}
        tmp_key=Vader;
    }else if(Vader->filhoEsquerda !=nullptr &&Vader->filhoEsquerda->chave ==toClean){
        tmp_key= Vader->filhoEsquerda;
        if(CheckLeaf(tmp_key)){
        T Clean= tmp_key->chave;
        Vader->filhoEsquerda=nullptr;
        delete tmp_key;
        return Clean;}
    }else if(Vader->filhoDireita !=nullptr &&Vader->filhoDireita->chave ==toClean){
        tmp_key= Vader->filhoDireita;
        if (CheckLeaf(tmp_key)){
            T Clean=tmp_key->chave;
            Vader->filhoDireita= nullptr;
            delete tmp_key;
            return Clean;}}
    if(tmp_key !=nullptr && tmp_key->filhoDireita !=nullptr){
        Nodo<T> *keyAux=tmp_key->filhoDireita;
        Nodo<T> *VaderAux=tmp_key;
        while(keyAux->filhoEsquerda !=nullptr){
            VaderAux=keyAux;
            keyAux=keyAux->filhoEsquerda;}
        tmp_key->chave=keyAux->chave;
        keyAux->chave=toClean;
        return this->PurgeTree(toClean,VaderAux);}
return toClean;}
void ExeEO(Nodo<T> *key,ListaEncadeadaAbstrata<T> *MyEmOrdem)const{
    if(key!=nullptr){
        MinhaArvoreDeBuscaBinaria<T>::ExeEO(key->filhoEsquerda,MyEmOrdem);
        MyEmOrdem->inserirNoFim(key->chave);
        MinhaArvoreDeBuscaBinaria<T>::ExeEO(key->filhoDireita,MyEmOrdem);}
return;}
void ExePreO(Nodo<T> *key,ListaEncadeadaAbstrata<T> *MyPreOrdem)const{
    if(key!=nullptr){
        MyPreOrdem->inserirNoFim(key->chave);
        MinhaArvoreDeBuscaBinaria<T>::ExePreO(key->filhoEsquerda,MyPreOrdem);
        MinhaArvoreDeBuscaBinaria<T>::ExePreO(key->filhoDireita,MyPreOrdem);}
return;}
void ExePO(Nodo<T> *key,ListaEncadeadaAbstrata<T> *MyPosOrdem)const{
    if(key!=nullptr){
        MinhaArvoreDeBuscaBinaria<T>::ExePO(key->filhoEsquerda,MyPosOrdem);
        MinhaArvoreDeBuscaBinaria<T>::ExePO(key->filhoDireita,MyPosOrdem);
        MyPosOrdem->inserirNoFim(key->chave);}
return;}
};
#endif