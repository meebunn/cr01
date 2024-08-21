#include <stdio.h>
#include <string.h>
#define MAXSIZE 100000
int main(){    
    int max=0;
    char inp1[MAXSIZE];
    int n=0;
    int start1=0;
    fgets(inp1, sizeof(inp1), stdin);
    int num1[MAXSIZE];
    for(int i =0 ; i<MAXSIZE ; i++){
        num1[i]=0;
    }
    for (int i = 0; inp1[i] != '\0' && inp1[i] != '\n'; i++) {
        if (inp1[i] >= '0' && inp1[i] <= '9') {
            num1[n] = inp1[i] - '0'; 
            n++;
        }
    }
    char inp2[MAXSIZE];
    int k=0;
    fgets(inp2, sizeof(inp2), stdin);
    int num2[MAXSIZE];
    for(int i =0 ; i<MAXSIZE ; i++){
        num2[i]=0;
    }
    for (int i = 0; inp2[i] != '\0' && inp2[i] != '\n'; i++) {
        if (inp2[i] >= '0' && inp2[i] <= '9') {
            num2[k] = inp2[i] - '0'; 
            k++;
        }
    }
    for(int i=0;i<n;i++){
        num1[MAXSIZE-i-1]=num1[n-i-1];
    }
    for(int i=0;i<k;i++){
        num2[MAXSIZE-i-1]=num2[k-i-1];
    }
    /////////////////

    if(n>=k){
        max =n;
    }
    else{
        max = k;
    }
    ////////main///////////////
    int last[MAXSIZE];
      for(int i =0 ; i<MAXSIZE ; i++){
        last[i]=0;
    }
    int l = max;
    int ses=0;
    for(int i=MAXSIZE-1;i>=10;i--){
      last[i]=num1[i]+num2[i]+ses;
      if(last[i]>=10){
        last[i] -=10;
        ses=1;
        max--;
        if(max == 0){
          break;
        }
      }
      else{
        ses=0;
        max--;
        if(max==0){
          break;
        }
      }
    /// assume l =4 ;
    }
    if(ses==1){
      last[MAXSIZE-1-l]= 1;
      for(int i=MAXSIZE-l-1;i<MAXSIZE;i++){
      
        printf("%d",last[i]);
    }
    }
    else{
      for(int i=MAXSIZE-l;i<MAXSIZE;i++){
        printf("%d",last[i]);
    }
    }
}