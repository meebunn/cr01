#include <iostream>
using namespace std;
int arr[400] ; 
int res;
int main() {
  int n,s;
  cin >> n ;
  for(int i=0;i<n;i++) cin >> s , arr[i] = s; 
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) if(arr[j] > arr[i] && j>i) res ++ ;
  }
  cout << res;
  
}