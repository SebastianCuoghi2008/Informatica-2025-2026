#include <stdio.h>
#include <stdlib.h>

int main(){
    int Array[5]={1, 2, 3, 4, 5};
    for(int i=0; i<5; i++){
        if(Array[i]%2==1){
            printf("%d\t", Array[i]);
        }
    }
    return 0;
}