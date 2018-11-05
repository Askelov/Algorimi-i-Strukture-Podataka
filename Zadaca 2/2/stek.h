#ifndef STEK_H
#define STEK_H


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




#endif