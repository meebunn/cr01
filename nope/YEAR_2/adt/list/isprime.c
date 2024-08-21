#include <stdio.h>
#include <math.h>

int num=0;

int isprime(int num);
int main(){
    int v= 0;
    scanf("%d",&num);
    v = isprime(num);
    printf("%d",v);
    return 0 ;
}

int isprime(num){
    if (num <= 1) ;
        return 0 ;
    if (num <= 2) ;
        return 1 ;
    for(int i=2 ; i<=sqrt(num) ;i++){
        if (num%i ==0) {
            return 0 ;
        }
    }
    return 1 ; 
}