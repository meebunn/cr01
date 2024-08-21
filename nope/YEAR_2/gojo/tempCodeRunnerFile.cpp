#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> a(n + 10);
    vector<int> c(n + 10); 

    fill(a.begin(), a.end(), -99999999); // Initialize a with zeros

    int sum = 0; 

    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; 
    }

    for(int i = 1; i <= n; ++i) {
        cin >> c[i]; 
    }

    int i = 1; // Start index from 1

    while(i <= n) {
        
        if(a[i] > 0) {
            sum += a[i]; 
            // cout << sum << endl; 
            i++;
        }
        else if(a[i+1] > 0) {
            sum += a[i+1]; 
            // cout << sum << endl;
            i += 2; 
        }
        else if(a[i+2] > 0) {
            sum += a[i+2]; 
            // cout << sum << endl;
            i += 3;
        }
        else if(a[i+3] > 0) {
            sum += a[i+3]; 
            // cout << sum << endl;
            i += 4;
        }
        else {

            int maxx = -9999999;
            int id = 0; 
            for(int j = 0; j < 4; j++) {
                // cout <<a[i+j] << endl ;

                if(a[i+j] > maxx) {
            
                    maxx = a[i+j]; 
                    id = j;
                }
            }
            // cout << maxx << " " << id << endl ;

            sum += maxx; 
            // cout << sum << endl;
            i += id;
        }
    }
    cout << sum; 
    return 0;
}
/*
10
5 1 -2 3 -3 -2 -1 -6 5 4
0 0 0 0 0 0 0 0 0 0
*/

