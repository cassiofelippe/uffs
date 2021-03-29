#include<stdio.h>
#define N 3

int vetoresDisjuntos(int vetor1[], int vetor2[]){
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (vetor1[i] == vetor2[j])
                return 0;
    return 2;
}

int main(){
    int vetor1[N] = {1,2,3};
    int vetor2[N] = {4,5,6};    
    
    if (vetoresDisjuntos(vetor1, vetor2)){
        printf("Os vetores são disjuntos!");
    }else{
        printf("Os vetores não são disjuntos!");
    }

    return 0;
} 