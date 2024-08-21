#include <stdio.h>
char rev(char x){
  if(x=='{') return '}' ;
  if(x=='(') return ')';
  if(x=='[') return ']';
}
int main() {
    printf("%c",rev('{'));
}