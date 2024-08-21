#include <iostream>
#define maxrc 30
using namespace std;

char maze[maxrc][maxrc];
char new_maze[maxrc][maxrc];
bool visited[maxrc][maxrc];

void dfs(int i, int j, int row, int col) {

    if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || new_maze[i][j] == '#')
        return;

    visited[i][j] = true; 

 
    if (i == row - 1) {
        cout << "yes" << endl;
        exit(0);
    }

    // Recur
    dfs(i + 1, j, row, col); // Down
    dfs(i, j + 1, row, col); // Right
    dfs(i - 1, j, row, col); // Up
    dfs(i, j - 1, row, col); // Left
}

int main() {
    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> maze[i][j];
        }
    }

    for (auto& k : visited) {
        for (auto& b : k) {
            b = false;
        }
    }

    ///transform
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == row - 1) {
                new_maze[i][j] = maze[i][j];
            } else if (maze[i][j] == '.' && maze[i][j + 1] == '.' && maze[i + 1][j + 1] == '.' && maze[i + 1][j] == '.') {
                new_maze[i][j] = '.';
            } else {
                new_maze[i][j] = '#';
            }
        }
    }


    for (int j = 0; j < col; ++j) {
        if (new_maze[0][j] == '.') {

            for (int i = 0; i < row; ++i) {
                for (int k = 0; k < col; ++k) {
                    visited[i][k] = false;
                }
            }
            dfs(0, j, row, col);
        }
    }


    cout << "no" << endl;

    return 0;
}
