#include <iostream>
#include "nizmapa.h"
#include "binstablomapa.h"
int main() {
    Mapa<int,int>* m;
    m=new BinStabloMapa<int,int>;
    
    srand((unsigned)time(NULL));
    int vel=500000;
    for(int i=0;i<vel;i++){
        (*m)[rand()%vel+1]=i;
    }
    
    for(int i=0;i<10000;i++){
        (*m)[i]=2*i;
    }

    clock_t vrijeme1=clock();
    //dodavanje novog elemnta u bsmapu prosjecno vrijeme 0.9ms
    //za nmapu prosjecno 1.7ms
    (*m)[rand()%vel+vel+1]=25;
    clock_t vrijeme2=clock();
    int ukvrijeme=(vrijeme2-vrijeme1)/(CLOCKS_PER_SEC/1000000);
    std::cout<<"Vrijeme izvrsenja(dodavanje): "<<ukvrijeme<<"mikro sec."<<std::endl;
    
    vrijeme1=clock();
    //pristup postojecem elmentu u bsmapi, prosjecno 0.6ms
    //za nmapu prosjecno 1.1ms
    (*m)[rand()%10000];
    vrijeme2=clock();
    
    ukvrijeme=(vrijeme2-vrijeme1)/(CLOCKS_PER_SEC/1000000);
    std::cout<<"Vrijeme izvrsenja (pristup elementu): "<<ukvrijeme<<"mikro sec."<<std::endl;
    delete m;
    
    
    return 0;
}
