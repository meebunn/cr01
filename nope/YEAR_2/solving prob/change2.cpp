#include <iostream>
using namespace std;
int main() {
  int n,round=1;
  cin >> n;
  int arr[n],arr2[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
    arr2[i] = arr[i];
  }
  for(int a=0;a<n;a++){
    int count=0;
    for(int i=0;i<n;i++){
      if(arr[i]==i+1){
        count+=1;
        continue;
      }
      arr[i] = arr2[arr[i]-1];
    }
    if(count==n){
      break;
    }
    round+=1;
  }
  cout << round << "\n";
}