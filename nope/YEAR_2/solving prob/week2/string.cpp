#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<char> lst;
    string inp;

    int k = 1;
    auto it = lst.begin();
    while (getline(cin, inp)) {
        for (char i : inp) {
            if (i == '[') {
                k = 2;
                it = lst.begin() ; 
                continue;
            } 
            else if (i == ']') {
                k = 1;
                it = lst.end();
                continue;
            }
            if(k==1) {
                lst.push_back(i);
            }
            else if(k==2){
                lst.insert(it,i) ;
            }
        }
        for(const auto&element : lst) {
            cout << element ;
        }
        cout << endl ;
        lst.clear() ; 

    }