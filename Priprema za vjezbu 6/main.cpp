#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

template <typename Tip>
void selection_sort(Tip* niz, int vel){
    for(int i=0;i<vel-1;i++){
        int min =i;
        for(int j=i+1;j<vel;j++){
            if(niz[j]<niz[min])
                min=j;
        }
        Tip pom=niz[i];
        niz[i]=niz[min];
        niz[min]=pom;
    }   
}

template <typename Tip>
void bubble_sort(Tip* niz, int vel){
    for(int i=vel-1;i>0;i--){
        for(int j=1;j<=i;j++){
            if(niz[j]<niz[j-1]){
                Tip pom=niz[j];
                niz[j]=niz[j-1];
                niz[j-1]=pom;
            }
        }
    }
}

template<typename Tip>
void merge(Tip* niz, int l, int p, int q, int u){
    int i=0, j=q-l, k=l;
    Tip* pom= new Tip[u-l+1];
    for(int m=0;m<=u-l;m++)
        pom[m]=niz[l+m];
    while(i<=p-l && j<=u-l){
        if(pom[i]<pom[j])
            niz[k]=pom[i++];
        else 
            niz[k]=pom[j++];
        k++;
    }
    while(i<=p-l)
        niz[k++]=pom[i++];
    while(j<=u-l)
        niz[k++]=pom[j++];
    delete[] pom;
}

template <typename Tip>
void mergesort(Tip* niz, int l, int u){
    if(u>l){
        int p=(u+l-1)/2;
        int q=p+1;
        mergesort(niz,l,p);
        mergesort(niz,q,u);
        merge(niz,l,p,q,u);
    }
}

template <typename Tip>
void merge_sort(Tip* niz, int vel){
    mergesort(niz,0,vel-1);
}

template <typename Tip>
int particija(Tip* niz, int poc, int kr){
    Tip pivot=niz[poc];
    int p=poc+1;
    while(p<=kr && niz[p]<pivot)
        p++;
    for(int i=p+1;i<=kr;i++){
        if(niz[i]<pivot){
            std::swap(niz[i],niz[p]);
            p++;
        }
    }
    std::swap(niz[poc],niz[p-1]);
    return p-1;
}

template <typename Tip>
void quicksort(Tip* niz, int poc, int kr){
    if(poc<kr){
        int j=particija(niz,poc,kr);
        quicksort(niz,poc,j-1);
        quicksort(niz,j+1,kr);
    }
}

template <typename Tip>
void quick_sort(Tip* niz, int vel){
    quicksort(niz, 0, vel-1);
}

bool jeLiSortiran(int*niz, int vel){
    for(int i=1;i<vel;i++){
        if(niz[i]<niz[i-1])
         return false;
    }
    return true;
}

void ucitaj(std::string filename, int*& niz, int &vel){
    std::ifstream ulaz(filename);
    int max_vel=5000000;
    niz=new int[max_vel];
    int broj,i=0;
    while(ulaz>>broj){
        niz[i++]=broj;
    }
    vel=i;
}

void generisi(std::string filename,int vel){
    std::ofstream izlaz(filename);
    srand((unsigned) time(NULL));
    for(int i=0;i<vel;i++)
        izlaz<<rand()%100000+1<<std::endl;
}
void upisi(std::string filename, int* niz, int vel){
    std::string sort=filename.substr(0,filename.length()-4)+"_sortirano_txt";
    std::ofstream izlaz(sort);
    for(int i=0;i<vel;i++)
        izlaz<<niz[i]<<std::endl;
}
int main() {
    std::string filename;
    int *niz, n, vel=0;
    std::cout << "unesi ime ili put do datoteke" << std::endl;
    std::getline(std::cin,filename);
    generisi(filename,1000);
    ucitaj(filename,niz,vel);
    std::cout<<"odredi algoritam za sotritanje:\n 1-BUBBLE\n2-SELECTION\n3-QUICK\n4-MERGE";
    std::cin>>n;
    clock_t vr1=clock();
    switch(n){
        case 1: bubble_sort(niz,vel); break;
        case 2: selection_sort(niz,vel); break;
        case 3: quick_sort(niz,vel); break;
        case 4: merge_sort(niz,vel); break;
        
    }
    clock_t vr2=clock();
    std::cout<<"vrijeme izvrsavanja "<<(vr2-vr1)/(CLOCKS_PER_SEC/1000)<<"ms.\n";
    int sort= jeLiSortiran(niz,vel);
    if(sort) std::cout<<"niz je sortiran";
    else std::cout<<"niz nije sortiran";
    upisi(filename,niz,vel);
    delete[] niz;
  
    return 0;
}
