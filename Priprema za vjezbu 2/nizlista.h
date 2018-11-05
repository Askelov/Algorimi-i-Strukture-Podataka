#ifndef NIZLISTA_H
#define NIZLISTA_H

const int VELICINA = 1000;

#include "lista.h"
#include <algorithm>

template <typename Tip>
class NizLista : public Lista<Tip> {
    Tip** niz;
    int kapacitet;
    int tekuci;
    int duzina;
    int metode[10];
public: 
    NizLista() : Lista<Tip>() {
        niz = new Tip*[VELICINA];
        kapacitet = VELICINA;
        duzina = 0;
        tekuci = -1;
    }
    ~NizLista() {
        for(int i(0); i < duzina; i++)
            delete niz[i];
        delete[] niz;
    }
    NizLista(const NizLista<Tip>& n) { //konst kopije
        kapacitet = n.kapacitet;
        duzina = n.duzina;
        tekuci = n.tekuci;
        niz = new Tip*[kapacitet];
        for(int i(0); i < duzina; i++)
            niz[i] = new Tip(*n.niz[i]);
    }
    NizLista<Tip>& operator=(const NizLista<Tip>& n) {
        if(this == &n)          //samododjela
            return *this;
       
        for(int i(0); i < duzina; i++)      //destruktor
            delete niz[i];
        delete[] niz;
       
        kapacitet = n.kapacitet;        //konsturktor
        duzina = n.duzina;
        tekuci = n.tekuci;
        niz = new Tip*[kapacitet];
        for(int i(0); i < duzina; i++)
            niz[i] = new Tip(*n.niz[i]);
        return *this;
    }
    int brojElemenata() const { return duzina; }
   
    Tip& operator[](int i) {
        metode[0]++;
        if(i < 0 or i >= duzina)
            throw "ERROR!";
        return *(niz[i]);
    }
    Tip operator[](int i) const {
        if(i < 0 or i >= duzina)
            throw "ERROR!";
        return *(niz[i]);
    }
    Tip& trenutni() {
        metode[1]++;
        if(duzina == 0)
            throw "ERROR!";
        return *niz[tekuci];
    }
    Tip trenutni() const {
        if(duzina == 0)
            throw "ERROR!";
        return *niz[tekuci];
    }
    bool prethodni() {
        metode[2]++;
        if(duzina == 0)
            throw "ERROR!";
        if(tekuci == 0)
            return false;
        tekuci--;
        return true;
    }
    bool sljedeci() {
        metode[3]++;
        if(duzina == 0)
            throw "ERROR!";
        if(tekuci == duzina - 1)
            return false;
        tekuci++;
        return true;
    }
    void pocetak() {
        metode[4]++;
        if(duzina == 0)
            throw "ERROR!";
        tekuci = 0;
    }
    void kraj() {
        metode[5]++;
        if(duzina == 0)
            throw "ERROR!";
        tekuci = duzina - 1;
    }
    void obrisi() {
        metode[6]++;
        if(duzina == 0)
            throw "ERROR!";
        delete niz[tekuci];
        duzina--;
        for(int i(tekuci); i < duzina; i++)
            niz[i] = niz[i+1];
        if((tekuci == duzina && duzina > 0) || duzina == 0 )
            tekuci--;
    }
    void dodajIspred(const Tip& el) {
        metode[7]++;
        if(kapacitet == duzina) {       //realokacija
            kapacitet*=2;
            Tip** niz1 = new Tip*[kapacitet];
            for(int i(0); i < duzina; i++) {
                niz1[i] = new Tip(*niz[i]);
                delete niz[i];
            }
            delete[] niz;
            niz = niz1;
        }
        if(duzina == 0)
            niz[0] = new Tip(el);
        else {
            for(int i(duzina); i > tekuci; i--)
                niz[i] = niz[i-1];
            niz[tekuci] = new Tip(el);
        }
        tekuci++;
        duzina++;
    }
    void dodajIza(const Tip& el) {
        metode[8]++;
        
        if(kapacitet == duzina) { //realkacija
            kapacitet*=2;
            Tip** niz1 = new Tip*[kapacitet];
            for(int i(0); i < duzina; i++) {
                niz1[i] = new Tip(*niz[i]);
                delete niz[i];
            }
            delete[] niz;
            niz = niz1;
        }
        for(int i(duzina); i > tekuci + 1; i--)
            niz[i] = niz[i-1];
        niz[tekuci + 1] = new Tip(el);
        if(duzina == 0)
            tekuci++;
        duzina++;
    }
};




#endif