#ifndef DVOSTRANIRED_H
#define DVOSTRANIRED_H

template <typename Tip>
class DvostraniRed{
    struct Cvor{
        Tip info;
        Cvor* sljedeci;
        Cvor* prethodni;
        Cvor(const Tip& el) {
                info=el;
                sljedeci=nullptr;
                prethodni=nullptr;
        }
        Cvor(){
            info=Tip();
            sljedeci=nullptr;
            prethodni=nullptr;
        }
    };
     int duzina;
     Cvor* pocetak;
     Cvor* kraj;
public:
    DvostraniRed():duzina(0),pocetak(nullptr),kraj(nullptr){}
    ~DvostraniRed();
    DvostraniRed(const DvostraniRed<Tip>& dRed);
    DvostraniRed<Tip>& operator =(const DvostraniRed<Tip>& dRed);
    int brojElemenata() const { return duzina; }
    void brisi();
    void staviNaVrh(const Tip&);
    Tip skiniSaVrha();
    void staviNaCelo(const Tip&);
    Tip skiniSaCela();
    Tip& vrh() const;
    Tip& celo() const;
    
};

template <typename Tip>
DvostraniRed<Tip>::~DvostraniRed(){
    while(kraj!=nullptr){
        Cvor* tmp=kraj;
        kraj=kraj->prethodni;
        delete tmp;
    }
}
template <typename Tip>
DvostraniRed<Tip>::DvostraniRed(const DvostraniRed<Tip>& dRed) {
    duzina=dRed.duzina;
    Cvor* tmp = dRed.pocetak;
    Cvor* tmp1 = nullptr;
    while(tmp != nullptr) {
        Cvor* novi = new Cvor(tmp -> info);
        if(tmp1 == nullptr)
            pocetak = novi;
        else {
            novi -> prethodni = tmp1;
            tmp1 -> sljedeci = novi;
        }
        tmp1 = novi;
        tmp = tmp -> sljedeci;
    }
    kraj =tmp1;
}


template <typename Tip>
DvostraniRed<Tip>& DvostraniRed<Tip>::operator =(const DvostraniRed<Tip>& dRed) {
    if(this==&dRed)
        return *this;
    
     while(kraj!=nullptr){
        Cvor* tmp=kraj;
        kraj=kraj->prethodni;
        delete tmp;
    }
    
    duzina=dRed.duzina;
    Cvor* tmp = dRed.pocetak;
    Cvor *tmp1= nullptr;
    while(tmp!=nullptr){
        Cvor* novi= new Cvor(tmp->info);
        if(tmp1==nullptr)
            pocetak=novi;
        else{
            novi->prethodni=tmp1;
            tmp1->sljedeci=novi;
        }
        tmp1=novi;
        tmp=tmp->sljedeci;
    }
    kraj=tmp1;
    return *this;
    
}

template <typename Tip>
void DvostraniRed<Tip>::brisi(){
    while(pocetak!=nullptr){
        Cvor* tmp=pocetak;
        pocetak=pocetak->sljedeci;
        delete tmp;
    } 
  duzina=0;
}

template <typename Tip>
void DvostraniRed<Tip>::staviNaVrh(const Tip& el){
    Cvor* novi=new Cvor(el);
    if(duzina==0)
        pocetak=novi;
    else{
        novi->prethodni=kraj;
        kraj->sljedeci= novi;
    }
    kraj=novi;
    duzina++;
}

template <typename Tip>
Tip DvostraniRed<Tip>:: skiniSaVrha(){
    if(duzina==0)
        throw "red prazan";
    duzina--;
    Cvor* tmp=kraj;
    Tip rez=tmp->info;
    kraj=kraj->prethodni;
    if(kraj!=nullptr)
        kraj->sljedeci=nullptr;
    if(tmp==pocetak)
        pocetak=nullptr;
    delete tmp;
    return rez;
}

template<typename Tip>
void DvostraniRed<Tip>::staviNaCelo(const Tip& el){
    Cvor* novi= new Cvor(el);
    if(duzina==0)
        kraj=novi;
    else {
        novi->sljedeci=pocetak;
        pocetak->prethodni=novi;
    }
    pocetak=novi;
    duzina++;
}

template <typename Tip>
Tip DvostraniRed<Tip>::skiniSaCela(){
    if(duzina==0)
        throw "prazan red";
    duzina--;
    Cvor* tmp=pocetak;
    Tip rez=tmp->info;
    pocetak=pocetak->sljedeci;
    if(pocetak!=nullptr)
        pocetak->prethodni=nullptr;
    if(tmp==kraj)
        kraj=nullptr;
    delete tmp;
    return rez;
}

template <typename Tip>
Tip& DvostraniRed<Tip>::vrh() const{
    if(duzina==0)
        throw "prazan red";
    return kraj->info;
}

template <typename Tip>
Tip& DvostraniRed<Tip>::celo() const{
    if(duzina==0)
        throw "prazan red";
    return pocetak->info;
}

#endif