#include <iostream>
#include <string>
#include <time.h>
using namespace std;

template <typename TipKljuca, typename TipVrijednosti>
class Mapa{
    public:
        Mapa() {}
        virtual ~Mapa() {}
        virtual TipVrijednosti operator [](TipKljuca k) const =0;
        virtual TipVrijednosti &operator [](TipKljuca k) =0;
        virtual int brojElemenata()const =0;
        virtual void obrisi() =0;
        virtual void obrisi(const TipKljuca& k) =0;
};


template <typename TipKljuca, typename TipVrijednosti>
struct Cvor{
    TipKljuca kljuc=TipKljuca(); 
    TipVrijednosti vrijednost=TipVrijednosti();
    Cvor* lijevo=nullptr, *desno=nullptr, *roditelj=nullptr;
    int balans=0;
};

template <typename TipKljuca, typename TipVrijednosti>
class AVLStabloMapa : public Mapa<TipKljuca, TipVrijednosti>{
    private:
        int velicina=0;
        Cvor<TipKljuca, TipVrijednosti>* korijen;
        void preorder(Cvor<TipKljuca, TipVrijednosti>* pok, Cvor<TipKljuca, TipVrijednosti>* &pok1, Cvor<TipKljuca, TipVrijednosti>* pok2=nullptr);
        void azurirajBalans(Cvor<TipKljuca,TipVrijednosti>* cvor);
        void lijevaRotacija(Cvor<TipKljuca,TipVrijednosti>* cvor);
        void desnaRotacija(Cvor<TipKljuca,TipVrijednosti>* cvor);
    public:
        AVLStabloMapa() { korijen=nullptr; }
        ~AVLStabloMapa() { this->obrisi(); }
        int brojElemenata() const { return velicina; }
        void obrisi();
        void obrisi(const TipKljuca& k);
        TipVrijednosti operator [](TipKljuca k) const;
        TipVrijednosti &operator [](TipKljuca k);
        AVLStabloMapa(const AVLStabloMapa<TipKljuca,TipVrijednosti> &temp);
        AVLStabloMapa(AVLStabloMapa<TipKljuca,TipVrijednosti> &&temp);
        AVLStabloMapa& operator=(const AVLStabloMapa<TipKljuca,TipVrijednosti> &temp);
        AVLStabloMapa& operator=(AVLStabloMapa<TipKljuca,TipVrijednosti> &&temp);
        
};
//rotacije
template <typename TipKljuca,typename TipVrijednosti>
void AVLStabloMapa<TipKljuca, TipVrijednosti>:: lijevaRotacija(Cvor<TipKljuca,TipVrijednosti>*cvor){
    if(cvor->balans * cvor->desno->balans<0) desnaRotacija(cvor->desno);
    Cvor<TipKljuca, TipVrijednosti>* p=cvor->desno;
    p->roditelj=cvor->roditelj;
    cvor->desno=nullptr; p->lijevo=cvor;
    cvor->roditelj=p;
    p->balans=0;
    cvor->balans=0;
}

template<typename TipKljuca, typename TipVrijednosti>
void AVLStabloMapa<TipKljuca,TipVrijednosti>::desnaRotacija(Cvor<TipKljuca,TipVrijednosti>*cvor) {
    if(cvor->balans*cvor->lijevo->balans<0) lijevaRotacija(cvor->lijevo);
    Cvor<TipKljuca,TipVrijednosti>*p=cvor->lijevo;
    p->roditelj=cvor->roditelj;
    cvor->lijevo=nullptr;
    p->desno=cvor;
    cvor->roditelj=p;
    p->balans=0;
    cvor->balans=0;
}

template<typename TipKljuca, typename TipVrijednosti>
void AVLStabloMapa<TipKljuca,TipVrijednosti>::azurirajBalans(Cvor<TipKljuca,TipVrijednosti>*cvor) {
    if(cvor->roditelj==nullptr) return;
    Cvor<TipKljuca,TipVrijednosti>*p=cvor->roditelj;
    if(p->lijevo==cvor)
        p->balans++;
    else p->balans--;
    if(p->balans>1) desnaRotacija(p);
    else if(p->balans<-1) lijevaRotacija(p);
    
}

template<typename TipKljuca, typename TipVrijednosti>
void AVLStabloMapa<TipKljuca,TipVrijednosti>::preorder(Cvor<TipKljuca,TipVrijednosti>*pok,Cvor<TipKljuca,TipVrijednosti>* &pok1, Cvor<TipKljuca,TipVrijednosti>*pok2){
  if(pok!=nullptr){
      pok1=new Cvor<TipKljuca,TipVrijednosti>();
      pok1->kljuc=pok->kljuc;
      pok1->vrijednost=pok->vrijednost;
      pok1->balans=pok->balans;
      pok1->roditelj=pok2;
      preorder(pok->lijevo,pok1->lijevo,pok2); preorder(pok->desno,pok1->desno,pok2);
  }  
} 

template <typename TipKljuca, typename TipVrijednosti>
AVLStabloMapa<TipKljuca,TipVrijednosti>::AVLStabloMapa(const AVLStabloMapa<TipKljuca,TipVrijednosti> &temp){
    velicina=temp.velicina;
    preorder(temp.korijen, korijen);
}

template <typename TipKljuca, typename TipVrijednosti>
AVLStabloMapa<TipKljuca,TipVrijednosti>& AVLStabloMapa<TipKljuca,TipVrijednosti>::operator=(const AVLStabloMapa<TipKljuca,TipVrijednosti> &temp){
    if(&temp==this) return *this;
    this->obrisi();
    velicina=temp.velicina;
    preorder(temp.korijen, korijen);
    return *this;
}

template <typename TipKljuca, typename TipVrijednosti>
AVLStabloMapa<TipKljuca,TipVrijednosti>& AVLStabloMapa<TipKljuca,TipVrijednosti>::operator=(AVLStabloMapa<TipKljuca,TipVrijednosti> &&temp){
    if(&temp==this) return *this;
    this->obrisi();
    velicina=temp.velicina;
    korijen=temp.korijen;
    return *this;
}

template <typename TipKljuca, typename TipVrijednosti>
AVLStabloMapa<TipKljuca,TipVrijednosti>::AVLStabloMapa(AVLStabloMapa<TipKljuca,TipVrijednosti> &&temp){
    velicina=temp.velicina;
    korijen=temp.korijen;
}

template <typename TipKljuca, typename TipVrijednosti>
TipVrijednosti &AVLStabloMapa<TipKljuca, TipVrijednosti>::operator [](TipKljuca k){
    Cvor<TipKljuca, TipVrijednosti>* temp=korijen;
    Cvor<TipKljuca, TipVrijednosti>* p=nullptr;
    while(temp!=nullptr && k!=temp->kljuc){
        p=temp;
        if(k>temp->kljuc) temp=temp->desno;
        else temp=temp->lijevo;
    }
    if(temp!=nullptr) return temp->vrijednost;
    else {
        temp=new Cvor<TipKljuca, TipVrijednosti>();
        temp->vrijednost=TipVrijednosti();
        temp->kljuc=k;
        temp->lijevo=nullptr; temp->desno=nullptr; temp->balans=0;
       
       if(korijen==nullptr){
           velicina++; korijen=temp; return temp->vrijednost;
       }
        else{ 
            if(k>p->kljuc) p->desno=temp;
            else p->lijevo=temp;
            azurirajBalans(temp);
            velicina++;
    }
        
    }
    return temp->vrijednost;
}

template <typename TipKljuca, typename TipVrijednosti>
TipVrijednosti AVLStabloMapa<TipKljuca, TipVrijednosti>::operator[] (TipKljuca k) const{
    Cvor<TipKljuca, TipVrijednosti>* walker=korijen;
    while(walker!=nullptr && k!=walker->kljuc){
        if(k>walker->kljuc) walker=walker->desno;
        else walker=walker->lijevo;
    }
    if(walker==nullptr) return TipVrijednosti();
    return walker->vrijednost;
}

template <typename TipKljuca, typename TipVrijednosti>
void AVLStabloMapa<TipKljuca, TipVrijednosti>::obrisi(){
    while(korijen!=nullptr) obrisi(korijen->kljuc);
    korijen=nullptr;
    velicina=0;
}


template <typename TipKljuca, typename TipVrijednosti>
void AVLStabloMapa<TipKljuca, TipVrijednosti>::obrisi(const TipKljuca& k){
    if(velicina==0) return;
    velicina=velicina-1;
    
    Cvor<TipKljuca, TipVrijednosti>* p=korijen;
    Cvor<TipKljuca, TipVrijednosti>* r=nullptr;
    
    while(p!=nullptr && k!=p->kljuc){
        r=p;
        if(k<p->kljuc) p=p->lijevo;
        else p=p->desno;
    }
    
    if(p==nullptr) 
        return;
   
    Cvor<TipKljuca, TipVrijednosti>* m=nullptr;
    
    if(p->lijevo==nullptr) m=p->desno;
    else{
        if(p->desno==nullptr) m=p->lijevo;
        else{
            Cvor<TipKljuca, TipVrijednosti>* pm=p;
            m=p->lijevo;
            Cvor<TipKljuca, TipVrijednosti>* tmp=m->desno;
            while(tmp!=nullptr){
                
                pm=m;
                m=tmp;
                tmp=m->desno;
            
                
            }
            if(pm!=p){
               
                pm->desno=m->lijevo;
                m->lijevo=p->lijevo;
           
            }
            m->desno=p->desno;
        }
    }
    if(r==nullptr) korijen=m;
    else{
        if(p==r->lijevo){
            
            r->balans--;  r->lijevo=m;
            
        }
        else {
           
            r->desno=m;  r->balans++;
            
        }
    }
    delete p;
}




int main() {
    AVLStabloMapa<std::string, std::string> m;
    m["Sarajevo"]="BIH";
    m["Zagreb"]="HRV";
    cout<<"dodana su 2 elementa:"<<endl;
    if(m.brojElemenata()==2)//2 elementa
    cout<<"U stablu su 2 elementa.Tacno: Da"<<endl;
    else 
    cout<<"U stablu su 2 elementa.Tacno: NE"<<endl;
    m.obrisi("Sarajevo");
    cout <<"izbacen 1 element";
    if(m.brojElemenata()==1)//1 elementa
    cout<<"U stablu je 1 element.Tacno: Da"<<endl;
    else 
    cout<<"U stablu je 1 element.Tacno: NE"<<endl;
    cout<<"ispisi sa [operatorom] za grad Zagreb : "<<m["Zagreb"];
    return 0;
}
