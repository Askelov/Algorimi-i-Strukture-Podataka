#include "nizlista.h"
#include "jplista.h"

#include <iostream>
#include <memory>


    template<typename Tip1, typename Tip2>
    void BROJELEMENATA(NizLista<Tip1> l1,JednostrukaLista<Tip2> l2 ){
        std::cout<<"broj elemenata nizliste je "<<l1.brojElemenata()<<", a broj elemenata jednostukeliste je "<<l2.brojElemenata()<<std::endl<<std::endl;
    }
    template<typename Tip1, typename Tip2>
    void DODAJIZA(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         l1.dodajIza(1); l1.dodajIza(2); l1.dodajIza(3);
      l2.dodajIza(1); l2.dodajIza(2); l2.dodajIza(3);
      std::cout<<"dodana su 3 elementa (1,2,3) u nizlistu i jednosturkulistu"<<std::endl<<std::endl;
      }
      
    template<typename Tip1, typename Tip2>
    void DODAJISPRED(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         l1.dodajIspred(1); l1.dodajIspred(2); l1.dodajIspred(3);
      l2.dodajIspred(1); l2.dodajIspred(2); l2.dodajIspred(3);
      std::cout<<"dodana su 3 elementa (1,2,3) u nizlistu i jednosturkulistu"<<std::endl<<std::endl;
      }
    
     template<typename Tip1, typename Tip2>
    void OBRISI(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
     std::cout<<"brisanje jednog elementa"<<std::endl<<std::endl;
      l1.obrisi();
      l2.obrisi();
      
    }
    template<typename Tip1, typename Tip2>
     void TRENUTNI(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         std::cout<<"Trenutni element u nizlisti je "<<l1.trenutni()<<" a trenutni element u jednosturkojlisti je "<<l2.trenutni()<<std::endl<<std::endl;
     }
     
      template<typename Tip1, typename Tip2>
     void POCETAK(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         l1.pocetak(); l2.pocetak();
         
          std::cout<<"Nakon postavljanja trenutnog na pocetak, trenutni element u nizlisti je "<<l1.trenutni()<<" a trenutni element u jednosturkojlisti je "<<l2.trenutni()<<std::endl<<std::endl;
     }
     
      template<typename Tip1, typename Tip2>
     void KRAJ(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         l1.kraj(); l2.kraj();
          std::cout<<"Nakon postavljanja trenutnog na kraj, trenutni element u nizlisti je "<<l1.trenutni()<<" a trenutni element u jednosturkojlisti je "<<l2.trenutni()<<std::endl<<std::endl;
     }
    
     template<typename Tip1, typename Tip2>
     void PRETHODNI(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         l1.prethodni(); l2.prethodni();
          std::cout<<"Nakon postavljanja trenutnog na prethodni, trenutni element u nizlisti je "<<l1.trenutni()<<" a trenutni element u jednosturkojlisti je "<<l2.trenutni()<<std::endl<<std::endl;
     }
     
     template<typename Tip1, typename Tip2>
     void SLJEDECI(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         l1.sljedeci(); l2.sljedeci();
          std::cout<<"Nakon postavljanja trenutnog na sljedeci, trenutni element u nizlisti je "<<l1.trenutni()<<" a trenutni element u jednosturkojlisti je "<<l2.trenutni()<<std::endl<<std::endl;
     }
     template<typename Tip1, typename Tip2>
     void OPERATOR(NizLista<Tip1> &l1,JednostrukaLista<Tip2> &l2 ){
         std::cout<<"ispis elemenata sa operatorom[] "<<std::endl<<"elementi nizliste su: ";
         int i;
         for(i=0;i<l1.brojElemenata();i++){
             std::cout<<l1[i]<<" ";
          }
         std::cout<<"elementi jednosturkeliste su: ";
         
         for( i=0;i<l2.brojElemenata();i++){
             std::cout<<l2[i]<<" ";
         }
     }
    
int main() {
   
     
      NizLista<int> l1;
      JednostrukaLista<int> l2;
      
      std::cout<<"testiranje metoda dodajiza() za nizlistu i jednosturkulistu "<<std::endl;
      DODAJIZA(l1,l2);
      
      std::cout<<"testiranje metoda brojelemenata() za nizlistu i jednosturkulistu "<<std::endl;
      BROJELEMENATA(l1, l2 );
    
      std::cout<<"testiranje metoda dodajispred() za nizlistu i jednosturkulistu"<<std::endl;
      DODAJISPRED(l1,l2);
      
      std::cout<<"testiranje metoda brojelemenata() za nizlistu i jednosturkulistu "<<std::endl;
      BROJELEMENATA(l1, l2 );
      
      std::cout<<"testiranje metoda obrisi() za nizlistu i jednosturkulistu "<<std::endl;
      OBRISI(l1,l2);
      BROJELEMENATA(l1,l2);
      
      std::cout<<"testiranje metoda trenutni() za nizlistu i jednosturkulistu "<<std::endl;
      TRENUTNI(l1,l2);
      
      std::cout<<"testiranje metoda pocetak() za nizlistu i jednosturkulistu "<<std::endl;
      POCETAK(l1,l2);
      
      std::cout<<"testiranje metoda kraj() za nizlistu i jednosturkulistu "<<std::endl;
      KRAJ(l1,l2);
      
      std::cout<<"testiranje metoda prethodni() za nizlistu i jednosturkulistu "<<std::endl;
      PRETHODNI(l1,l2);
      
      std::cout<<"testiranje metoda sljedeci() za nizlistu i jednosturkulistu "<<std::endl;
      SLJEDECI(l1,l2);
      
      std::cout<<"testiranje metoda operator[] za nizlistu i jednosturkulistu "<<std::endl;
      OPERATOR(l1,l2);
      
      
      
    return 0;
}