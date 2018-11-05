#ifndef ITERATOR_H
#define ITERATOR_H

#include "dplista.h"

template <typename Tip>
class DvostrukaLista;

template <typename Tip>
class Iterator{
    const DvostrukaLista<Tip>* dl;
    typename DvostrukaLista<Tip>::Cvor*tekuci;
public:
    Iterator(const Lista<Tip>& l){
        dl=(const DvostrukaLista<Tip>*)&l;
        tekuci=dl->pocetni;
    }
    
    Iterator(const DvostrukaLista<Tip>& dpl): dl(&dpl), tekuci(dl->pocetni){}
    
    bool prethodni(){
         if(dl->duzina==0)
            throw "greska, lista je prazna";
        if(tekuci==dl->pocetni)
            return false;
        tekuci=tekuci->prosli;
        return true;
    }
    
    bool sljedeci(){
         if(dl->duzina==0)
            throw "greska, lista je prazna";
        if(tekuci==dl->krajnji)
            return false;
        tekuci=tekuci->iduci;
        return true;
        
    }
    
    void pocetak(){
         if(dl->duzina==0)
            throw "greska, lista je prazna";
        tekuci=dl->pocetni;
    }
    
    void kraj(){
         if(dl->duzina==0)
            throw "greska, lista je prazna";
        tekuci=dl->krajnji;
    }
    
    
    Tip& trenutni(){
        if(dl->duzina==0) 
            throw "greska, lista je prazna";
        return tekuci->info;
    }
};
    template<typename Tip>
    Tip dajMaksimum(const Lista<Tip>& n){
        Iterator<Tip> it(n);
        Tip max=it.trenutni();
        it.sljedeci();
        for(int i(1);i<n.brojElemenata();i++){
            if(it.trenutni()>max) max=it.trenutni();
            it.sljedeci();
        }
        return max;
    }

#endif