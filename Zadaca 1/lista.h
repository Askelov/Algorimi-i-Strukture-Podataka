#ifndef LISTA_H
#define LISTA_H

template <typename Tip>
class Lista {
public:
    Lista() {}              //konstruktor
    virtual ~ Lista() {}    //destruktor
    virtual int brojElemenata() const = 0;
    virtual Tip& trenutni() = 0;       // l.trenutni()=3
    virtual Tip trenutni() const = 0;  // ispis
    virtual bool prethodni() = 0;
    virtual bool sljedeci() = 0;
    virtual void pocetak() = 0;
    virtual void kraj() = 0;
    virtual void obrisi() = 0;
    virtual void dodajIspred(const Tip& el) = 0;
    virtual void dodajIza(const Tip& el) = 0;
    virtual Tip& operator[](int i) = 0;
    virtual Tip operator[](int i) const = 0;
    
    
};

#endif