#ifndef JPLISTA_H
#define JPLISTA_H
#include "lista.h"
#include <iostream>

template<typename Tip>
class JednostrukaLista : public Lista<Tip> {
    struct Cvor {
        Tip info;
        Cvor* sljedeci;
        Cvor(Tip el):info(el),sljedeci(nullptr){}
        Cvor(){
            sljedeci =nullptr;
            info=Tip();
        }
    };
    Cvor* poc, *krajnji, *tekuci;
    int duzina,metode[10];
public:
    JednostrukaLista() : Lista<Tip>() {
        poc = krajnji = tekuci = nullptr;
        duzina = 0;
    }
    ~JednostrukaLista() {
        
        while(poc != nullptr) {
    
            tekuci = poc;
            poc = poc -> sljedeci;
            
            delete tekuci;
        }
      
    }
    JednostrukaLista(const JednostrukaLista<Tip>& l): Lista<Tip>(){
         Cvor* tmp(l.poc), *tmp1(nullptr);
         //poc=tmp1;
    while(tmp != nullptr) {
        
        Cvor* novi=new Cvor;
        novi->info = tmp->info;
        if(tmp1 == nullptr)
            poc = novi;
        else
            tmp1 -> sljedeci = novi;
        tmp1 = novi;
        if(tmp == l.tekuci)
            tekuci = novi;
        tmp = tmp -> sljedeci;
    }
    
    krajnji = tmp1;
    duzina = l.duzina;
}
     JednostrukaLista<Tip>& operator=(const JednostrukaLista<Tip>& n) {
        if(this == &n)          //samododjela
            return *this;
       
         while(poc != nullptr) {
            tekuci = poc;
            poc = poc -> sljedeci;
            delete tekuci;
        }
       Cvor* tmp(n.poc), *tmp1(nullptr);
         //poc=tmp1;
    while(tmp != nullptr) {
        
        Cvor* novi=new Cvor;
        novi->info = tmp->info;
        if(tmp1 == nullptr)
            poc = novi;
        else
            tmp1 -> sljedeci = novi;
        tmp1 = novi;
        if(tmp == n.tekuci)
            tekuci = novi;
        tmp = tmp -> sljedeci;
    }
    
    krajnji = tmp1;
    duzina = n.duzina;
    return *this;
    }

    
    int brojElemenata() const {
        
        return duzina;
        
    }
    Tip  operator [](int i) const {
        if(i < 0 || i >= duzina) 
             throw "ERROR!";
         Cvor* tmp(poc);
        for(int j(0); j < i; j++)
            tmp = tmp -> sljedeci;
        return tmp -> info;
    }
    
    Tip& operator [](int i) {
        metode[0]++;
    if(i < 0 || i >= duzina) 
        throw "ERROR!";
    Cvor* tmp(poc);
    for(int j(0); j < i; j++)
        tmp = tmp -> sljedeci;
    return tmp -> info;
    }
    
    Tip& trenutni(){
        metode[1]++;
        if(poc==nullptr)
            throw "ERROR!";
        return tekuci-> info;
    }
    
    Tip trenutni() const{
        if(poc==nullptr)
            throw "ERROR!";
        return tekuci-> info;
    }
    
    bool prethodni(){
        metode[2]++;
        if(poc==nullptr) 
            throw "ERROR!";
        if(tekuci==poc) 
            return false;
        Cvor* tmp (poc);
        while(tmp->sljedeci!=tekuci)
            tmp=tmp-> sljedeci;
        tekuci=tmp;
        return true;
    }
    
    bool sljedeci(){
        metode[3]++;
        if(poc==nullptr)
            throw "ERROR";
        if(tekuci->sljedeci==nullptr)
            return false;
        tekuci=tekuci->sljedeci;
        return true;
    }
    
     void pocetak(){
         metode[4]++;
         if(poc==nullptr)
            throw "ERROR";
        tekuci=poc;
    }
    void kraj(){
        metode[5]++;
        if(poc==nullptr)
            throw "ERROR";
        tekuci=krajnji;
    }
    
    void obrisi() {
        metode[6]++;
    if(poc == nullptr) 
            throw "ERROR!";
    duzina--;
    if(tekuci == poc) {
        poc = poc -> sljedeci;
        delete tekuci;
        tekuci = poc;
        if(duzina==0)
            krajnji=nullptr;
        return;
    }else {
        Cvor* tmp(poc);
        while(tmp->sljedeci!=tekuci)
            tmp=tmp->sljedeci;
        tmp->sljedeci=tekuci->sljedeci;
        delete tekuci;
        tekuci=tmp->sljedeci;
        if(tekuci==nullptr)
            krajnji=tekuci=tmp;
        }
    }
    
    void dodajIspred(const Tip& el) {
        metode[7]++;
    Cvor* novi(new Cvor(el));
    duzina++;
    if(duzina == 1) 
        poc= krajnji= tekuci = novi;
    else if(tekuci == poc) {
        poc = novi;
        novi -> sljedeci = tekuci;
    }
    else {
        Cvor* tmp(poc);
        while(tmp -> sljedeci != tekuci)
            tmp = tmp -> sljedeci;
        tmp -> sljedeci = novi;
        novi -> sljedeci = tekuci;
    }
}

    void dodajIza(const Tip& el) {
        metode[8]++;
    Cvor* novi(new Cvor(el));
    duzina++;
    if(duzina == 1)
        poc = krajnji = tekuci = novi;
    else {
        novi -> sljedeci = tekuci -> sljedeci;
        tekuci -> sljedeci = novi;
        if(tekuci == krajnji)
            krajnji = novi;
    }
}


};

#endif