#ifndef DEC0006_MINHA_LISTA_ENCADEADA_H
#define DEC0006_MINHA_LISTA_ENCADEADA_H

#include <cstddef>
// std::size_t

#include "Elemento.h"
// Elemento
#include "ListaEncadeadaAbstrata.h"
#include "excecoes.h"
// ExcecaoDadoInexistente
// ExcecaoListaEncadeadaVazia
// ExcecaoNaoImplementado
// ExcecaoPosicaoInvalida

/**
 * @brief Uma lista encadeada de dados.
 *
 * @tparam T O tipo dos dados armazenados na lista.
 */
template <typename T>
class MinhaListaEncadeada : public ListaEncadeadaAbstrata<T>
{
    // Implemente aqui as funcões marcadas com virtual na ListaEncadeadaAbstrata
    // Lembre-se de implementar o construtor e destrutor da classe
public:  
 
    MinhaListaEncadeada(){
        this->_tamanho = 0;
        this->_primeiro = nullptr;
    }; 
    
    ~MinhaListaEncadeada(){
    Elemento<T>*tmp=this->_primeiro;
        while(tmp != nullptr){
            Elemento<T>* tmpaux = tmp->proximo;
            delete tmp;
            tmp= tmpaux;
        }
    delete tmp;
    };

    std::size_t tamanho() const{
        return this->_tamanho;
    };

    bool vazia() const{
       if(this->tamanho()==0){
            return true;
        }
        else{
            return false;
        }
    };

    std::size_t posicao(T dado) const{
        if(this->vazia()){
            throw ExcecaoListaEncadeadaVazia();
        }
        Elemento<T>*tmp=this->_primeiro;
        int i=0;
        while(tmp != nullptr){
            if(tmp->dado==dado){
                return i;
            }else{
              i++;
            tmp=tmp->proximo;  
            }
        }
        throw ExcecaoDadoInexistente();
    };

     virtual bool contem(T dado) const {
        Elemento<T>* tmp =this->_primeiro;
        while(tmp != nullptr){
            if(tmp->dado == dado){
                //delete tmp;
                return true;
            }
            tmp = tmp->proximo;
        }
        //delete tmp;
        return false;
    };

    virtual void inserirNoInicio(T dado){
        Elemento<T> *tmp=new Elemento<T>{dado,this->_primeiro};
        this->_primeiro=tmp;
        this->_tamanho++;
        return;
        //delete tmp;
    };

    virtual void inserir(std::size_t posicao, T dado) {
        if(posicao < 0 || this->_tamanho+1 <= posicao){
            throw ExcecaoPosicaoInvalida();
        }
        if(posicao == 0){
            inserirNoInicio(dado);
            return ;
        }
        if(posicao == this->_tamanho){
            inserirNoFim(dado);
            return ;
        }
        Elemento<T>*tmp = this->_primeiro;
        
        size_t i=0;
        while(i<posicao){
            tmp = tmp->proximo;
            i++;
        }
        Elemento<T>*novoel = new Elemento<T>{dado, tmp->proximo};
        tmp->proximo = novoel;
        this->_tamanho++;
        //delete novoel;
        return;
    };

   virtual void inserirNoFim(T dado) {
        Elemento<T>*tmp = this->_primeiro;
        if(this->_primeiro == nullptr){
            inserirNoInicio(dado);
            return;
        }
        while(tmp->proximo != nullptr){
            tmp = tmp->proximo;
        }
        Elemento<T>*novoel = new Elemento<T>{dado,nullptr};
        tmp->proximo = novoel;
        this->_tamanho++;
        return;
    }; 

    virtual T removerDoInicio(){
    if(this->vazia()){
        throw ExcecaoListaEncadeadaVazia(); 
    }
    else{
        Elemento<T>* tmp= this->_primeiro;
        this->_primeiro=tmp->proximo;
        T dado = tmp->dado;
        this->_tamanho--;
        delete tmp;
        return dado;
    }
    };

    T removerDe(std::size_t posicao){
        if (posicao < 0 || posicao >= this->_tamanho){
            throw ExcecaoPosicaoInvalida();
        }
        if (posicao == 0){
            return this->removerDoInicio();
        }
        if (posicao == this->_tamanho - 1){
            return this->removerDoFim();
        }
        Elemento<T> *tmp = this->_primeiro;
        for (size_t i = 0; i < posicao - 1; i++){
            tmp = tmp->proximo;
        }
        Elemento<T> *tmpaux = this->_primeiro;
        for (size_t j = 0; j < posicao; j++){
            tmpaux = tmpaux->proximo;
        }

        T dado = tmpaux->dado;
        tmp->proximo = tmpaux->proximo;
        delete tmpaux;
        this->_tamanho--;
        return dado;
    };

   virtual T removerDoFim(){
        if(this->vazia()){
            throw ExcecaoListaEncadeadaVazia();
        }
        if (this->_tamanho == 1){
            return removerDoInicio();
        }
        Elemento<T>* tmp= this->_primeiro;
        while(tmp->proximo != nullptr){
                tmp=tmp->proximo;
            }
                T dado = tmp->dado;
                delete tmp;
                this->_tamanho--;
                return dado;
    };
    
    virtual void remover(T dado){
        if (this->vazia()){
            throw ExcecaoListaEncadeadaVazia();
        }
        if(contem(dado)==true){
            this->removerDe(this->posicao(dado));
            return;
        }
        throw ExcecaoDadoInexistente();
    };
};

#endif