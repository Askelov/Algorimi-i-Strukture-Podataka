#include <iostream>
#include "dplista.h"
#include "iterator.h"

    template<typename Tip1>
    void BROJELEMENATA(DvostrukaLista<Tip1> l1){
        std::cout<<"broj elemenata dvostrukeliste je "<<l1.brojElemenata()<<std::endl<<std::endl;
    }
    
    template<typename Tip1>
    void DODAJIZA(DvostrukaLista<Tip1>& l1){
         l1.dodajIza(6); l1.dodajIza(5); l1.dodajIza(4);
      std::cout<<"dodana su 3 elementa (6,5,4) u dvostrukulistu "<<std::endl<<std::endl;
      }
      
    template<typename Tip1>
    void DODAJISPRED(DvostrukaLista<Tip1>& l1){
         l1.dodajIspred(1); l1.dodajIspred(2); l1.dodajIspred(3);
      std::cout<<"dodana su 3 elementa (1,2,3) u dvostrukulistu "<<std::endl<<std::endl;
      }
    
    template<typename Tip1>
    void OBRISI(DvostrukaLista<Tip1>& l1){
     std::cout<<"brisanje jednog elementa"<<std::endl<<std::endl;
      l1.obrisi();
    }
    
    template<typename Tip1>
     void TRENUTNI(DvostrukaLista<Tip1>& l1){
         std::cout<<"Trenutni element u dvostrukojlisti je "<<l1.trenutni()<<std::endl<<std::endl;
     }
     
     template<typename Tip1>
     void POCETAK(DvostrukaLista<Tip1>& l1){
         l1.pocetak(); 
          std::cout<<"Nakon postavljanja trenutnog na pocetak, trenutni element u dvostrukojlisti je "<<l1.trenutni()<<std::endl<<std::endl;
     }
     
    template<typename Tip1>
     void KRAJ(DvostrukaLista<Tip1>& l1){
         l1.kraj(); 
          std::cout<<"Nakon postavljanja trenutnog na kraj, trenutni element u dvostrukojlisti je "<<l1.trenutni()<<std::endl<<std::endl;
     }
    
     template<typename Tip1>
     void PRETHODNI(DvostrukaLista<Tip1>& l1){
         l1.prethodni();
          std::cout<<"Nakon postavljanja trenutnog na prethodni, trenutni element u dvostrukojlisti je "<<l1.trenutni()<<std::endl<<std::endl;
     }
     
     template<typename Tip1>
     void SLJEDECI(DvostrukaLista<Tip1>& l1){
         l1.sljedeci();
          std::cout<<"Nakon postavljanja trenutnog na sljedeci, trenutni element u dvostrukojlisti je "<<l1.trenutni()<<std::endl<<std::endl;
     }
     
     template<typename Tip1>
     void OPERATOR(DvostrukaLista<Tip1>& l1){
         std::cout<<"ispis elemenata sa operatorom[] "<<std::endl<<"elementi dvostrukeliste su: ";
         int i;
         for(i=0;i<l1.brojElemenata();i++){
             std::cout<<l1[i]<<" ";
          }
          std::cout<<std::endl<<std::endl;
     }
    
    template<typename Tip1>
    void MAKS(DvostrukaLista<Tip1>& l1){
        std::cout<<"Maksimalni element dvostrukeliste je: "<<dajMaksimum(l1)<<std::endl;
    }
    
int main() {
   
     
    
    DvostrukaLista<int> l;
     
      std::cout<<"testiranje metoda dodajispred() za dvostrukulistu "<<std::endl;
      DODAJISPRED(l);
      
      std::cout<<"testiranje metoda brojelemenata() za dvostrukulistu "<<std::endl;
      BROJELEMENATA(l);
    
      std::cout<<"testiranje metoda dodajiza() za dvostrukulistu "<<std::endl;
      DODAJIZA(l);
      
      std::cout<<"testiranje metoda brojelemenata() za dvostrukulistu "<<std::endl;
      BROJELEMENATA(l);
      
      std::cout<<"testiranje metoda obrisi() za dvostrukulistu "<<std::endl;
      OBRISI(l);
      BROJELEMENATA(l);
      
      std::cout<<"testiranje metoda trenutni() za dvostrukulistu "<<std::endl;
      TRENUTNI(l);
      
      std::cout<<"testiranje metoda pocetak() za dvostrukulistu "<<std::endl;
      POCETAK(l);
      
      std::cout<<"testiranje metoda kraj() za dvostrukulistu "<<std::endl;
      KRAJ(l);
      
      std::cout<<"testiranje metoda prethodni() za dvostrukulistu "<<std::endl;
      PRETHODNI(l);
      
      std::cout<<"testiranje metoda sljedeci() za dvostrukulistu "<<std::endl;
      SLJEDECI(l);
      
      std::cout<<"testiranje metoda operator[] za dvostrukulistu "<<std::endl;
      OPERATOR(l);
      
      std::cout<<"testiranje metode dajMaksimum() za dvostrukulistu"<<std::endl;
      MAKS(l);
      
      
    return 0;
}