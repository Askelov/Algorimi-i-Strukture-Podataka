#include <iostream>

template<typename Tip>
class Red{
    struct Cvor{
        Tip info;
        Cvor* sljedeci;
        Cvor(const Tip& el): info(el), sljedeci(nullptr){}
        Cvor(){info=Tip(); sljedeci=nullptr;}
    };
    int duzina;
    Cvor* pocetak;
    Cvor* kraj;
public:
    Red():duzina(0),pocetak(nullptr),kraj(nullptr){}
    ~Red();
    Red(const Red<Tip>& red);
    Red<Tip>& operator =(const Red<Tip>& red);
    void brisi();
    void stavi(const Tip& el);
    Tip skini();
    Tip& celo() const;
    int brojElemenata() const{ return duzina; };
};

template<typename Tip>
Red<Tip>::~Red(){
    while(pocetak!=nullptr){
        Cvor* pom=pocetak;
        pocetak=pocetak->sljedeci;
        delete pom;
    }
}

template<typename Tip>
Red<Tip>::Red(const Red<Tip>& red){
    duzina=red.duzina;
    Cvor* tmp(red.pocetak);
    Cvor* tmp1(nullptr);
    while(tmp!=nullptr){
    Cvor* novi= new Cvor(tmp->info);
    if(tmp1==nullptr)
        pocetak=novi;
    else
        tmp1->sljedeci=novi;
    tmp1=novi;
    
    tmp=tmp->sljedeci;
    }
    kraj=tmp1;
}

template<typename Tip>
Red<Tip>& Red<Tip>::operator =(const Red<Tip>& red){
    if(this==&red) return *this;
    while(pocetak!=nullptr){
        Cvor* pom=pocetak;
        pocetak=pocetak->sljedeci;
        delete pom;
    }
    duzina=red.duzina;
    Cvor* tmp(red.pocetak);
    Cvor* tmp1(nullptr);
    while(tmp!=nullptr){
    Cvor* novi= new Cvor(tmp->info);
    if(tmp1==nullptr)
        pocetak=novi;
    else
        tmp1->sljedeci=novi;
    tmp1=novi;
    
    tmp=tmp->sljedeci;
    }
    kraj=tmp1;
    return *this;
}

template<typename Tip>
void Red<Tip>::brisi(){
    while(pocetak!=nullptr){
        Cvor* pom=pocetak;
        pocetak=pocetak->sljedeci;
        delete pom;
    }
    duzina=0;
}

template<typename Tip>
void Red<Tip>::stavi(const Tip& el){
    Cvor* novi= new Cvor(el);
    if(duzina==0)
        pocetak=novi;
    else 
    kraj->sljedeci=novi;
    kraj=novi;
    duzina++;
}

template<typename Tip>
Tip Red<Tip>::skini(){
    if(duzina==0) 
        throw "greska, red je prazan ";
    Tip rez=pocetak->info;
    Cvor* pom= pocetak;
    pocetak=pocetak->sljedeci;
    delete pom;
    if(duzina==1)
        kraj=nullptr;
    duzina--;
    return rez;
}

template<typename Tip>
Tip& Red<Tip>::celo() const{
    if(duzina==0) 
        throw "greska, red je prazan ";
    return pocetak->info;
}

template <typename Tip>
void STAVI(Red<Tip>& s){
    s.stavi(1); s.stavi(2); s.stavi(3);
    std::cout<<" na red smo stavili 3 elementa (1,2,3) "<<std::endl;
}

template <typename Tip>
void BROJELEMENATA(Red<Tip>& s){
    std::cout<<"u redu se nalaze " << s.brojElemenata()<<" elementa "<<std::endl;
}

template <typename Tip>
void CELO(Red<Tip>& s){
    std::cout<<"element na celu reda trenutno je "<<s.celo()<<std::endl;
}

template <typename Tip>
void SKINI(Red<Tip>& s){
    s.skini();
    std::cout<<"nakon skidanja elementa iz reda, trenutno na celu je "<<s.celo()<<std::endl;
}

template <typename Tip>
void OPERATOR(Red<Tip>& s, Red<Tip>& n){
    n=s;
    std::cout<<"nakon n=s, u n redu se nalaze 2 elementa : "<<n.celo();
    n.skini();
    std::cout<<" "<<n.celo()<<std::endl;
}

template <typename Tip>
void BRISI (Red<Tip>& s){
    s.brisi();
    std::cout<<"red s je obrisan i ima "<<s.brojElemenata()<<" elemenata ";
}

int main() {
    
    Red<int> s;
   std::cout<<"Testiramo metodu stavi()... ";
   STAVI(s);
   std::cout<<"Testiramo metodu brojElemenata()... ";
   BROJELEMENATA(s);
   std::cout<<"Testiramo metodu celo()... ";
   CELO(s);
   std::cout<<"Testiramo metodu skini()... ";
   SKINI(s);
   std::cout<<"Testiramo operator=... ";
   Red<int>n;
   OPERATOR(s,n);
   std::cout<<"Testiramo metodu brisi()... ";
   BRISI(s);
    
    return 0;
}
