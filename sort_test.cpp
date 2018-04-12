#include<cstdio>
#include<time.h>
#include<random>
#include<cstdlib>
using namespace std;

int array1[3005],array2[3005];
double avertime[2][3005];

void make(int n){
    for(int i=0;i<n;i++){
        array1[i]=rand()%6000;
        array2[i]=array1[i];
    }
    
}

void select_sort(int n){
    int k,min;
    clock_t start,finish;
    start=clock();
    for(int i=n-1;i>0;i--){
        min=9999;
        for(int j=0;j<=i;j++){
            if(array1[j]<min){
                min=array1[j];
                k=j;
            }
        }
        int swap=array1[i];array1[i]=array1[k];array1[k]=swap;
    }
    finish=clock();
    double tot=double(start-finish)/CLOCKS_PER_SEC;
    avertime[0][n]+=tot;
    return ;
}

void glob_sort(int n){
    bool key=false;
    clock_t start,finish;
    start=clock();
    for(int i=n-1;i>=1;i--){
//        key=0;
        for(int j=0;j<i;j++){
            if(array2[j+1]>array2[j]){
                int swap=array2[j];
                array2[j]=array2[j+1];
                array2[j+1]=swap;
//                key=true;
            }
        }
//        if(!key) break;
    }
    finish=clock();
    double tot=double(start-finish)/CLOCKS_PER_SEC;
    avertime[1][n]+=tot;
    return ;
}

int main(){
    srand(time(0));
    printf("\t\tselect_sort  glob_sort\n");
    for(int i=2;i<=3000;i++){
        for(int j=1;j<=5;j++){
            make(i);
            select_sort(i);
            glob_sort(i);
            avertime[0][i]/=5.0;
            avertime[1][i]/=5.0;
        }
        printf("N=%3d\t%.6fs *%.3f* %.6fs ||\n",i,avertime[0][i],avertime[1][i]/avertime[0][i],avertime[1][i]);
    }
    printf("======over!======");
    return 0;
}
