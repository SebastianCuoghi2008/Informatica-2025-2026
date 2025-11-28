#include <stdio.h>
#include <stdlib.h>

int main(){
    int *Array;

    Array=(int*)malloc(sizeof(int)*11);
    for(int i=0; i<11; i++){
        Array[i]= 10*i;
        if(Array[i]>0){
            printf("%d\t", Array[i]);
        }
    }
    return 0;
}