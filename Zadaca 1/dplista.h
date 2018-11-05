#ifndef DPLISTA_H
#define DPLISTA_H

#include "lista.h"
#include "iterator.h"



template <typename Tip>
class Iterator;

template <typename Tip>
class DvostrukaLista: public Lista<Tip>{
    struct Cvor{
            Tip info;
            Cvor* iduci;
            Cvor* prosli;
            Cvor(const Tip& el): info(el), iduci(nullptr), prosli(nullptr){}
            Cvor(){
                info=Tip();
                iduci=nullptr;
                prosli=nullptr;
            }
    };
    int duzina;
    Cvor*pocetni;
    Cvor*krajnji;
    Cvor*tekuci;
public:
     DvostrukaLista() : Lista<Tip>(), duzina(0), pocetni(nullptr), krajnji(nullptr), tekuci(nullptr) {}
    ~DvostrukaLista();
    DvostrukaLista(const DvostrukaLista<Tip>& dpl);
    DvostrukaLista<Tip>& operator =(const DvostrukaLista<Tip>& dpl);
    int brojElemenata() const { return duzina; }
    Tip& trenutni();
    Tip trenutni() const;
    bool prethodni();
    bool sljedeci();
    void pocetak();
    void kraj();
    void obrisi();
    Tip& operator [](int);
    Tip operator [](int) const;
    void dodajIspred(const Tip&);
    void dodajIza(const Tip&);
    friend class Iterator<Tip>;
};


   template<typename Tip>
    DvostrukaLista<Tip>::~DvostrukaLista(){
        while(pocetni!=nullptr){
            tekuci=pocetni;
            pocetni=pocetni->iduci;
            delete tekuci;
        }
    }
    
    template<typename Tip>
    DvostrukaLista<Tip>::DvostrukaLista(const DvostrukaLista<Tip>& dpl){
        duzina=dpl.duzina;
        Cvor* tmp(dpl.pocetni);
        Cvor* tmp1(nullptr);
        while(tmp!=nullptr){
            Cvor* novi= new Cvor(tmp->info);
            if(tmp1==nullptr)
                pocetni=novi;
            else{
                tmp1->iduci=novi;
                novi->prosli=tmp1;
            }
            tmp1=novi;
            if(tmp==dpl.tekuci)
                tekuci=tmp1;
            tmp=tmp->iduci;
        }
        krajnji=tmp1;
    }
    
    template<typename Tip>
    DvostrukaLista<Tip>& DvostrukaLista<Tip>::operator =(const DvostrukaLista<Tip>& dpl) {
        if(this==&dpl)
            return *this;
        duzina=dpl.duzina;
        while(pocetni!=nullptr) {
            tekuci=pocetni;
            pocetni=pocetni->iduci;
            delete tekuci;
        }
        Cvor* tmp(dpl.pocetni);
        Cvor* tmp1(nullptr);
        while(tmp!=nullptr) {
            Cvor* novi=new Cvor(tmp->info);
            if(tmp1==nullptr)
                pocetni=novi;
            else {
                tmp1->iduci=novi;
                novi->prosli=tmp1;
            }
            tmp1=novi;
            if(tmp==dpl.tekuci)
                tekuci=tmp1;
            tmp=tmp->iduci;
        }
        krajnji=tmp1;
        return *this;
    }

    
    template<typename Tip>
    Tip&  DvostrukaLista<Tip>::trenutni(){
        if(duzina==0) 
            throw "greska, lista je prazna";
        return tekuci->info;
    }
    
    template<typename Tip>
    Tip  DvostrukaLista<Tip>::trenutni() const{
        if(duzina==0) 
            throw "greska, lista je prazna";
        return tekuci->info;
    }
   
    template<typename Tip> 
    bool  DvostrukaLista<Tip>::prethodni(){
        if(duzina==0)
            throw "greska, lista je prazna";
        if(tekuci==pocetni)
            return false;
        tekuci=tekuci->prosli;
        return true;
    }
   
    template<typename Tip> 
    bool  DvostrukaLista<Tip>::sljedeci(){
        if(duzina==0)
            throw "greska, lista je prazna";
        if(tekuci==krajnji)
            return false;
        tekuci=tekuci->iduci;
        return true;
    }
    
    template<typename Tip>
    void  DvostrukaLista<Tip>::pocetak(){
        if(duzina==0)
            throw "greska, lista je prazna";
        tekuci=pocetni;
    }
    
    template<typename Tip>
    void  DvostrukaLista<Tip>::kraj(){
        if(duzina==0)
            throw "greska, lista je prazna";
        tekuci=krajnji;
    }
    
    template<typename Tip>
    void  DvostrukaLista<Tip>::obrisi(){
        if(duzina==0)
            throw "greska, lista je prazna";
        Cvor*tmp(tekuci);
        if(pocetni==tekuci){
            pocetni=tekuci=pocetni->iduci;
            if(tekuci!=nullptr)
                tekuci->prosli=nullptr;
            if(krajnji==tmp)
                krajnji=nullptr;
        }
        else if(krajnji==tekuci){
            krajnji=tekuci=krajnji->prosli;
            tekuci->iduci=nullptr;
        }
        else{
            tekuci->prosli->iduci=tekuci->iduci;
            tekuci->iduci->prosli=tekuci->prosli;
            tekuci=tmp->iduci;
        }
        delete tmp;
        duzina--;
    }
    
    template<typename Tip>
    Tip&  DvostrukaLista<Tip>::operator [](int i){
        if(i<0 ||i>=duzina)
            throw "greska, pristup nije moguc";
        if(i<duzina/2){
            Cvor* poc(pocetni);
            for(int j(0);j<i;j++)
                poc=poc->iduci;
            return poc->info;
        } 
        else {
            Cvor* kr(krajnji);
            for(int j(duzina-1);j>i;j--)
                kr=kr->prosli;
            return kr->info;
        }
    }
    
    template<typename Tip>
    Tip  DvostrukaLista<Tip>::operator [](int i) const{
         if(i<0 ||i>=duzina)
            throw "greska, pristup nije moguc";
        if(i<duzina/2){
            Cvor* poc(pocetni);
            for(int j(0);j<i;j++)
                poc=poc->iduci;
            return poc->info;
        } 
        else {
            Cvor* kr(krajnji);
            for(int j(duzina-1);j>i;j--)
                kr=kr->prosli;
            return kr->info;
        }
    }
    
   template<typename Tip>
   void  DvostrukaLista<Tip>::dodajIza(const Tip& el) {
    Cvor* novi=new Cvor(el);
    if(tekuci==krajnji) {
        novi->prosli=tekuci;
        krajnji=novi;
        if(pocetni==nullptr)
            pocetni=novi;
        if(tekuci==nullptr)
            tekuci=novi;
        else
            tekuci->iduci=novi;
    }
    else {
        novi->prosli=tekuci;
        novi->iduci=tekuci->iduci;
        tekuci->iduci=novi;
        novi->iduci->prosli=novi;
    }
    duzina++;
}
    
    template<typename Tip>
    void DvostrukaLista<Tip>::dodajIspred(const Tip& el) {
        Cvor* novi=new Cvor(el);
        if(tekuci==pocetni) {
            novi->iduci=tekuci;
            pocetni=novi;
            if(krajnji==nullptr)
                krajnji=novi;
            if(tekuci==nullptr)
                tekuci=novi;
            else 
                tekuci->prosli=novi;
        }
        else {
            novi->iduci=tekuci;
            novi->prosli=tekuci->prosli;
            tekuci->prosli=novi;
            novi->prosli->iduci=novi;
        }
        duzina++;
    }
    

#endif