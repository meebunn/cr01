#include <stdio.h>
int arr[100][100];
int num,i,j,pat ;
void printMaze();

int main(void) {
  scanf("%d %d",&num,&pat);
  ////////////1//////////
  if(pat == 1){
    for(i=1 ; i <= num ; i++){
      for(j=1 ; j <=num ; j++){
        printf("%d " , i+(j-1)*num);
      }
    printf("\n");
    }
  }
  ////////////2////////////
  // : 9 1 9 1 
  // : 7 3 7 3           
  // : 5 5 5 5
  // : 3 7 3 7
  // : 1 9 1 9
  if(pat == 2){
  int tt=0 ; 
    for(i= 1 ; i<=num ; i++){
      for(j=1 ; j<=num ; j++){
        if(j==1){
          printf("%d ",i);
          tt=i ;
        }
        else if (j%2 == 0 ){
          tt+= -2*i + 2*num+1 ;
          printf("%d ",tt);
        }
        else{
          tt+= 2*i-1 ;
          printf("%d ",tt);
        }
  
      }
      tt=0 ;
      printf("\n");    
    }
  }
  if(pat==4){
    int i=0,j=0,n=1 ;
    int x_start = 0;
    int y_start = 0;
    int x_end = num-1 ;
    int y_end = num-1 ; 
    

    while( n <= num*num){
      for(i=y_start;i<=y_end ;i++){
        arr[i][x_start ] = n++ ; 
      }
      x_start++;

      for(j=x_start ; j<=x_end ; j++){
        arr[y_end][j] = n++ ; 
      }
      y_end--;

      for(i=y_end;i>=y_start ;i--){
        arr[i][x_end] = n++ ; 
      }
      x_end--;
      for(i=x_end ; i>=x_start; i--){
        arr[y_start][i] = n++ ; 
      }
      y_start++ ; 
    }
  printMaze();
  }
  if(pat ==3){
    int n=1,i=num-1,j=0 ;
    int nub = 2 ;
    arr[i][j] = n++ ;
    arr[--i][j] = n++ ; 
    arr[++i][++j] = n++ ;
    arr[i][++j] = n++ ; 

    while(n != num*num){

      if(i==num-1 && j%2 ==0){
        while(j!=0){
          arr[--i][--j] = n++ ; 
        }
        if(i==0 && j ==0){
          break;
        }
        else{
          arr[--i][j]= n++ ; 
        }
        
      }
      if(j==0 ){
        while(i != num-1)
          arr[++i][++j] = n++ ; 
      }
    
      if(i != num-1 || j != num-1){
        arr[i][++j] = n++ ;
      }
      else{
        break;
      }
    }

  if(num%2==0){
    i=num-1;
    j=num-1;
  }
  if(i==0 && j==0){
    while(n != num*num){

      if(i%2 == 0){
        arr[i][++j] = n++ ;
        while(j!=num-1){
          arr[++i][++j] = n++ ;
        }
      }

      if (j%2==0){
        arr[--i][j] = n++ ;
        while(i!=0){
          arr[--i][--j] = n++;
          
          }
        }
      
      if(i==0 && j == num-1){
            break;
      }
    }
  }
  else{
    while(1){
      if(i%2==1 && j==num-1){
        arr[--i][j] = n++;
        while(i!=0){
          arr[--i][--j] = n++ ; 
        }
      }
      if(i==0){
        arr[i][++j] = n++ ;
        while(j!=num-1){
          arr[++i][++j] = n++ ;
        }
      }
      arr[0][num-1]= num*num ;
      if(n == num*num){
        break;
      }
    }
  }
  printMaze();
}

    
  

  
   
      
    } 
   
          
          
    
  


void printMaze() {
    for(int i=0 ; i<num ; i++){
      for(int j=0 ; j<num ; j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n"); 
  }
}
