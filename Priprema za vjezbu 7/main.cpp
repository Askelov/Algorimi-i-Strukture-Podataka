#include <iostream>
#include "nizmapa.h"
int main() {
    NizMapa<int,int> brojevi;
    for(int i=0;i<500;i++)
        brojevi[i]=i;
    std::cout<<brojevi.brojElemenata() << std::endl;
    brojevi.obrisi(10);
    std::cout<<brojevi.brojElemenata()<<std::endl;  
    for(int i=0;i<20;i++)
        std::cout<<brojevi[i]<<" ";
    std::cout<<std::endl;
    
    brojevi.obrisi();
    std::cout<<brojevi.brojElemenata();
    return 0;
}
