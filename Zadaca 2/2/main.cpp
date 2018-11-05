#include <iostream>
#include "stek.h"
#include <vector>
using namespace std;

int pretraziBinarno(std::vector<int> v, int t){
    if(v.empty())
        return -1;
    int pocetak=0;
    int kraj=v.size()-1;
    while(kraj>pocetak){
        int srednji=(pocetak+kraj)/2;
        if(v[srednji]<t)
            pocetak=srednji+1;
        else 
            kraj=srednji;
    }
    if(v[kraj]==t)
        return kraj;
    return -1;
}

void pretraga(Stek<std::vector<int>>&s, int trazeni){
    if(s.brojElemenata()==0){
        std::cout<<"Nema elementa";
        return; }
    if(!s.vrh().empty() && s.vrh()[0]<=trazeni){
        int t=pretraziBinarno(s.vrh(),trazeni);
        if(t!=-1)  std::cout<<t<<" "<<s.brojElemenata()-1;
        else std::cout<<"Nema elementa";
        return ;
    }
    else {
        std::vector<int>v=s.skini();
        pretraga(s,trazeni);
        s.stavi(v);
    }
}

//primjer iz predavanja treba da ispise 1 2
void funkcija1(Stek<std::vector<int>>&s,int trazeni){
    pretraga(s,trazeni);
}

//provjera funkcije pretrazi binarno kada postoji element u vektoru
void funkcija2(std::vector<int>& v, int trazeni){
    std::cout<<"element je na "<<pretraziBinarno(v,trazeni)<<" poziciji u vektoru"; 
}

//provjera funkcije pretrazi binardno kada nema elementa u vektoru
void funkcija3(std::vector<int>& v, int trazeni){
    if(pretraziBinarno(v,trazeni)==-1) std::cout<<"nema elementa u vektoru"; 
}
int main() {
    Stek<std::vector<int>> s;
    std::vector<int> v={1,2,3,4,5};
    s.stavi(v);
    v={6,8};
    s.stavi(v);
    v={9,10,130};
    s.stavi(v);
    v={157,226,3424};
    s.stavi(v);
    funkcija1(s,10);
    std::cout<<std::endl;
    funkcija2(v,157);
    std::cout<<std::endl;
    funkcija3(v,1);
    std::cout<<std::endl;
    
   
    return 0;
}
