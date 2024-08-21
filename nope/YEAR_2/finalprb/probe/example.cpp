#include <iostream>
#include "probelib.h"

void bnry_search(int i, int j) {
    while (true) {
        int mid = (i + j) / 2;
        bool left = probe_check(i, mid );
        if (j - i <= 1) {
            if (left) 
            probe_answer(i);
            probe_answer(j);
        }
        
        if (left) {
            j = mid;
        }
        else {
            i = mid + 1;
        }
    }
    probe_answer(j);
}

int main(void) {
    int n = probe_init();
    bnry_search(0, n - 1);
    return 0;
}