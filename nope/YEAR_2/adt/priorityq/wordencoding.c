#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

typedef struct Node {
    wchar_t data;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct HuffmanCode {
    wchar_t data;
    wchar_t* code;
} HuffmanCode;

Node* createNode(wchar_t data, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void swapNodes(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void heapify(Node* arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->frequency < arr[smallest]->frequency)
        smallest = left;

    if (right < n && arr[right]->frequency < arr[smallest]->frequency)
        smallest = right;

    if (smallest != i) {
        swapNodes(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

Node* buildHuffmanTree(Node* arr[], int n) {
    while (n > 1) {
        Node* left = arr[0];
        arr[0] = arr[n - 1];
        n--;

        heapify(arr, n, 0);

        Node* right = arr[0];

        Node* internalNode = createNode(L'\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        arr[n] = internalNode;
        heapify(arr, n + 1, 0);
    }

    return arr[0];
}

void generateHuffmanCodes(Node* root, wchar_t* code, int index, HuffmanCode huffmanCodes[], int* codeIndex) {
    if (root->left) {
        code[index] = L'0';
        generateHuffmanCodes(root->left, code, index + 1, huffmanCodes, codeIndex);
    }

    if (root->right) {
        code[index] = L'1';
        generateHuffmanCodes(root->right, code, index + 1, huffmanCodes, codeIndex);
    }

    if (root->left == NULL && root->right == NULL) {
        huffmanCodes[*codeIndex].data = root->data;
        huffmanCodes[*codeIndex].code = (wchar_t*)malloc((index + 1) * sizeof(wchar_t));
        wcsncpy(huffmanCodes[*codeIndex].code, code, index + 1);
        (*codeIndex)++;
    }
}

void sortHuffmanCodes(HuffmanCode huffmanCodes[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (huffmanCodes[i].data > huffmanCodes[j].data) {
                HuffmanCode temp = huffmanCodes[i];
                huffmanCodes[i] = huffmanCodes[j];
                huffmanCodes[j] = temp;
            }
        }
    }
}

void generateHuffmanForUserInput() {
    setlocale(LC_ALL, ""); // Set the locale to support wide characters
    int numInput;
    wprintf(L"Enter the number of inputs: ");
    scanf(L"%d", &numInput);
    wchar_t* input[numInput];
    int frequency[numInput];

    wprintf(L"Enter the input data and frequencies:\n");
    for (int i = 0; i < numInput; i++) {
        input[i] = (wchar_t*)malloc(100 * sizeof(wchar_t));
        wscanf(L"%ls %d", input[i], &frequency[i]);
    }

    Node* nodes[numInput];
    for (int i = 0; i < numInput; i++) {
        nodes[i] = createNode(input[i][0], frequency[i]);
    }

    Node* root = buildHuffmanTree(nodes, numInput);

    HuffmanCode huffmanCodes[numInput];
    int codeIndex = 0;
    wchar_t code[100];
    generateHuffmanCodes(root, code, 0, huffmanCodes, &codeIndex);

    sortHuffmanCodes(huffmanCodes, numInput);

    wprintf(L"\nHuffman Codes:\n");
    for (int i = 0; i < numInput; i++) {
        wprintf(L"%ls: %ls\n", huffmanCodes[i].data == L' ' ? L"space" : &huffmanCodes[i].data, huffmanCodes[i].code);
    }

    for (int i = 0; i < numInput; i++) {
        free(input[i]);
        free(nodes[i]);
        free(huffmanCodes[i].code);
    }
}

int main() {
    generateHuffmanForUserInput();
    return 0;
}
