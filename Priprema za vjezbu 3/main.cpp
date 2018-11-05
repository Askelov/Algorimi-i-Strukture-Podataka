#include <iostream>

template <typename Tip>
class Stek{
    struct Cvor{
      Tip info;
      Cvor* sljedeci;
      Cvor(const Tip& el):info(el),sljedeci(nullptr){}
      Cvor(){ info=Tip(); sljedeci=nullptr;}
    };
    int duzina;
    Cvor* top;
public:
    Stek():duzina(0),top(nullptr){}
    ~Stek();
    Stek(const Stek<Tip>& s);
    Stek<Tip>& operator =(const Stek<Tip>& s);
    void brisi();
    void stavi(const Tip& el);
    Tip skini();
    Tip& vrh() const;
    int brojElemenata() const { return duzina; }
};

template<typename Tip>
Stek<Tip>:: Stek(const Stek<Tip>& s){
    duzina=s.duzina;
    Cvor* tmp=s.top;
    Cvor* tmp1=nullptr;
    while(tmp!=nullptr){
        Cvor* novi= new Cvor(tmp->info);
        if(tmp==s.top){
            tmp1=novi;
            top=tmp1;
           }
         else 
            tmp1->sljedeci=novi;
        tmp1=novi;
        
        tmp=tmp->sljedeci;
    }
}

template<typename Tip>
Stek<Tip>:: ~Stek(){
    while(top!=nullptr){
        Cvor* pom = top;
        top=top->sljedeci;
        delete pom;
    }
}

template<typename Tip>
Stek<Tip>& Stek<Tip>::operator =(const Stek<Tip>& s){
    
    if(this==&s) return *this;
    
    while(top!=nullptr){
        Cvor* pom = top;
        top=top->sljedeci;
        delete pom;
    }
    
    duzina=s.duzina;
    Cvor* tmp=s.top;
    Cvor* tmp1=nullptr;
    while(tmp!=nullptr){
        Cvor* novi= new Cvor(tmp->info);
        if(tmp==s.top){
            tmp1=novi;
            top=tmp1;
           }
         else 
            tmp1->sljedeci=novi;
        tmp1=novi;
        
        tmp=tmp->sljedeci;
    }
    return *this;
}

template<typename Tip>
void Stek<Tip>::stavi(const Tip& el){
    Cvor* novi= new Cvor(el);
    novi->sljedeci=top;
    top=novi;
    duzina++;
}

template<typename Tip>
Tip Stek<Tip>::skini(){
    if(duzina==0) 
        throw "Greska, prazan stek ";
    duzina--;
    Tip rez=top->info;
    Cvor* pom=top;
    top=top->sljedeci;
    delete pom;
    return rez;
}

template<typename Tip>
Tip& Stek<Tip>::vrh() const{
    if(duzina==0)
        throw "Greska, prazan stek ";
    return top->info;
}

template <typename Tip>
void Stek<Tip>:: brisi(){
    while(top!=nullptr){
        Cvor* pom=top;
        top=top->sljedeci;
        delete pom;
        }
        duzina=0;
}


template <typename Tip>
void STAVI(Stek<Tip>& s){
    s.stavi(1); s.stavi(2); s.stavi(3);
    std::cout<<" na stek smo stavili 3 elementa (1,2,3) "<<std::endl;
}

template <typename Tip>
void BROJELEMENATA(Stek<Tip>& s){
    std::cout<<"u steku se nalaze " << s.brojElemenata()<<" elementa "<<std::endl;
}

template <typename Tip>
void VRH(Stek<Tip>& s){
    std::cout<<"element na vrhu steka trenutno je "<<s.vrh()<<std::endl;
}

template <typename Tip>
void SKINI(Stek<Tip>& s){
    s.skini();
    std::cout<<"nakon skidanja elementa sa vrha steka, trenutno na vrhu je "<<s.vrh()<<std::endl;
}

template <typename Tip>
void OPERATOR(Stek<Tip>& s, Stek<Tip>& n){
    n=s;
    std::cout<<"nakon n=s, u n steku se nalaze 2 elementa : "<<n.vrh();
    n.skini();
    std::cout<<" "<<n.vrh()<<std::endl;
}

template <typename Tip>
void BRISI (Stek<Tip>& s){
    s.brisi();
    std::cout<<"Stek s je obrisan i ima "<<s.brojElemenata()<<" elemenata ";
}
    

int main() {
   
   Stek<int> s;
   std::cout<<"Testiramo metodu stavi()... ";
   STAVI(s);
   std::cout<<"Testiramo metodu brojElemenata()... ";
   BROJELEMENATA(s);
   std::cout<<"Testiramo metodu vrh()... ";
   VRH(s);
   std::cout<<"Testiramo metodu skini()... ";
   SKINI(s);
   std::cout<<"Testiramo operator=... ";
   Stek<int>n;
   OPERATOR(s,n);
   std::cout<<"Testiramo metodu brisi()... ";
   BRISI(s);
   
    return 0;
}
