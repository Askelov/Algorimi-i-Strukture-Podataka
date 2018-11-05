#include <iostream>

int pom(int n, int a=0, int b=1) {
    if(n<1) 
        return a;
    return pom(n-1,b,a+b);
}

int fib2_0(int n) {
    return pom(n,0,1);
}

int fib_petlja (int n) {
    if (n<=1) 
        return n;
    int pretprosli=0, prosli=1, rezultat;
    for (int i=2; i<=n; i++) {
        rezultat = pretprosli+prosli;
        pretprosli = prosli;
        prosli = rezultat;
    }
    return rezultat;
}


int nzd(int x,int y){
    if(y==0)
        return x;
    return nzd(y,x%y);
}

int main() {
    int a,b,c;
    std::cout<<"Unesite 2 broja (za pronalazak nzd): ";
    std::cin>>a>>b;
    std::cout << "NZD("<<a<<","<<b<<") = "<<nzd(a,b);
    
    std::cout<<"\nUnesite broj (za pronalazak fib. broja): ";
    std::cin>>c;
    std::cout<<"faktorijel broja "<<c<<" je "<<fib2_0(c)<<" i "<<fib_petlja(c);
    
    return 0;
}
