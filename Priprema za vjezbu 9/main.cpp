#include <iostream>
#include "binstablomapa.h"
#include "nizmapa.h"
#include "hashmapa.h"
unsigned int hash(int ulaz, unsigned int max){
    unsigned int suma=23;
    suma=suma  + ulaz*31;
    return suma%max;}

int main() {
    HashMapa<int,int>m;
m.definisiHashFunkciju(hash);
   
    return 0;
}
