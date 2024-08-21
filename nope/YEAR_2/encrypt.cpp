#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 20;

int a[MAX_SIZE];   
int b[MAX_SIZE];  
int n, s;
int k = 0 ; 
int c[MAX_SIZE][MAX_SIZE]; 

int main() {
    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    for(int j = n; j < MAX_SIZE; j++){
        a[j] = ++k ;
    }

    for(int i = 0 ; i < MAX_SIZE ; i++) {
        int id = (i+s)%MAX_SIZE ; 
        b[id] = a[i]; 
    }

    // for(int i = 0 ; i < MAX_SIZE; i++) {
    //     cout << b[i] << " "; 
    // }
    // // cout << endl;

    int x = 0, y = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        if(y > 4) {
            y = 0;
            x++;
        }
        c[x][y] = b[i]; 
        y++;
    }

    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 4 ; j++) {
            cout << c[j][i] << " " ; 
        }
        // cout << endl ;
    }
    return 0;
}
