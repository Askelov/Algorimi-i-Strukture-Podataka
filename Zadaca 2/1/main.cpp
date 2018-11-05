#include <iostream>
#include "dvostranired.h"

  template<typename Tip>
    void STAVINAVRH(DvostraniRed<Tip>& dr){
        dr.staviNaVrh(1);
        dr.staviNaVrh(2);
        dr.staviNaVrh(3);
        std::cout<<"Stavljenja 3 elementa (1,2,3) "<<std::endl<<std::endl;
       }

  template<typename Tip>
    void VRH(DvostraniRed<Tip>& dr){
        std::cout<<"Element na vrhu je "<<dr.vrh()<<std::endl<<std::endl;
       }
    
    template<typename Tip>
    void STAVINACELO(DvostraniRed<Tip>& dr){
        dr.staviNaCelo(10);
        std::cout<<"Stavljen element na celo (10) "<<std::endl<<std::endl;
       }
    
    template<typename Tip>
    void CELO(DvostraniRed<Tip>& dr){
        std::cout<<"Element na celu je "<<dr.celo()<<std::endl<<std::endl;
       }
    
    template<typename Tip>
    void SKINISACELA(DvostraniRed<Tip>& dr){
        dr.skiniSaCela();
        std::cout<<"Skinut element sa cela "<<std::endl<<std::endl;
       }
    
    template<typename Tip>
    void SKINISAVRHA(DvostraniRed<Tip>& dr){
        dr.skiniSaVrha();
        std::cout<<"Skinut element sa vrha"<<std::endl<<std::endl;
       }
  
      
int main() {
    
      DvostraniRed<int> dr;
      /*testiranje 
        ● staviNaVrh()
        ● skiniSaVrha()
        ● staviNaCelo()
        ● skiniSaCela()
        ● vrh()
        ● celo()*/
     
      std::cout<<"testiranje metode staviNaVrh() "<<std::endl;
      STAVINAVRH(dr);
      std::cout<<"testiranje metode Vrh() "<<std::endl;
      VRH(dr);
      std::cout<<"testiranje metodestaviNaCelo() "<<std::endl;
      STAVINACELO(dr);
      std::cout<<"testiranje metode Celo() "<<std::endl;
      CELO(dr);
      std::cout<<"testiranje metode skiniSaCela() "<<std::endl;
      SKINISACELA(dr);
      std::cout<<"testiranje metode skiniSaVrha() "<<std::endl;
      SKINISAVRHA(dr);
      CELO(dr);
      VRH(dr);
      
      
      
     
     
    return 0;
}
