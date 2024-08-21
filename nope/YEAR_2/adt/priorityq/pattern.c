#include <stdio.h>

int main(){
    int k = 4 ; 
    //// top
    for(int r=1 ; r<k+1;r++ ){ /////รอบ

        for(int i=1 ; i<k-r+1 ;i++){
            printf(" ") ; 
        }
        for(int j=1 ; j<(2*r-1)+1 ;  j++){
            printf("*") ; 
        }
    printf("\n");
    }
    //// bot 
    for(int r=1 ; r<k ; r++){

    }
}