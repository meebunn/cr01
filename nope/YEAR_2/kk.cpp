#include <bits/stdc++.h>
#define int long long 
using namespace std;

void main() {
    int c;
    cin >> c;
    for(int ts = 1 ; ts <=c ; ts++) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            s[i] = b[i] - a[i];
        }

        sort(s.begin(), s.begin() + n);


        int sum = 0;
        for(int i = 0; i < n; i++){ 
            if(k && s[i] < 0){ 
                k--;
                continue;
            }
            sum += s[i]; 
        }


        if(sum > 0) cout << "Case " << ts << ": " << sum << endl;
        else cout << "Case " << ts << ": No Profit" << endl ;
    }
    return ;
}