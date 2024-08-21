#include <iostream>
using namespace std;

long long int merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    long long int inversions = 0; 

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
            inversions += (n1 - i); 
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }

    return inversions;
}

long long int mergeSort(int arr[], int l, int r) {
    long long int inversions = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        inversions += mergeSort(arr, l, m);
        inversions += mergeSort(arr, m + 1, r);

        inversions += merge(arr, l, m, r);
    }
    return inversions;
}

int main() {
    int c;
    cin >> c; 
    int* arr = new int[c]; 
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }
    long long int inversions = mergeSort(arr, 0, c - 1);
    cout << inversions << endl;
    delete[] arr; 
    
    return 0;
}
