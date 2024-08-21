#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        int b[2000];

        while (true) {
            stack<int> st;
            bool k = false;

            for (int i = 0; i < n; i++) {
                cin >> b[i];
                if (b[i] == 0) {
                    k = true;
                    break;
                }
            }

            if (k) break;

            int j = 1;
            bool isOk = true;

            for (int i = 0; i < n; i++) {
                while (j <= n && (st.empty() || st.top() != b[i])) {
                    st.push(j);
                    j++;
                }

                if (!st.empty() && st.top() == b[i]) {
                    st.pop();
                } else {
                    isOk = false;
                    break;
                }
            }

            if (isOk) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }

        cout << endl;
    }

    return 0;
}
