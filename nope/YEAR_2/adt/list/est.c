#include <stdio.h>
int plan(int m , int n){
    int i,p2 ;
    if(m<=0 || n<=0) return 0 ;
     for(i= 0 ; i<100 ; i++){
        if(pow(2,i) <= n && pow(2, i)<= m){
            p2 = pow(2, i);
        }
        else{
            break;
        }
    }
    if(m==1 && n == 1) return 1; 
    else return plan(m-p2,n) + plan(p2,n-p2)+1;
}
int main(){
    int m,n,count ;
    scanf("%d %d",&m ,&n);
    count=plan(m,n);
    printf("%d", count);

}



