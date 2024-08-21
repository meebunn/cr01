#include <iostream>
#include <vector>
using namespace std;

const int maxrc = 30;
char maze[maxrc][maxrc];
bool visited[maxrc][maxrc];

// Function to perform DFS traversal
void dfs(int i, int j, int row, int col) {
    // Base cases for stopping the recursion
    if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || maze[i][j] == '#')
        return;

    visited[i][j] = true; // Mark the current cell as visited

    // If we reach the last row, print message and return
    if (i == row - 1) {
        cout << "Maze can be traversed from row 1 to the last one." << endl;
        exit(0);
    }

    // Recursive calls to neighboring cells
    dfs(i + 1, j, row, col); // Down
    dfs(i, j + 1, row, col); // Right
    dfs(i - 1, j, row, col); // Up
    dfs(i, j - 1, row, col); // Left
}

int main() {
    int row = 8, col = 14; // Maze dimensions
    // The given maze
    const string givenMaze[8] = {
        "##.###..####.#",
        "#######.####.#",
        "#######.######",
        "#..##.#.######",
        "####....######",
        "####.#########",
        "...#..##..###.",
        ""
    };

    // Copy the given maze to the maze array
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            maze[i][j] = givenMaze[i][j];
        }
    }

    // Perform DFS from each cell in the first row
    for (int j = 0; j < col; ++j) {
        if (maze[0][j] == '.') {
            // Initialize visited array
            for (int i = 0; i < row; ++i) {
                for (int k = 0; k < col; ++k) {
                    visited[i][k] = false;
                }
            }
            dfs(0, j, row, col); // Start DFS from cell (0, j)
        }
    }

    // If DFS doesn't find a path to the last row
    cout << "Maze cannot be traversed from row 1 to the last one." << endl;

    return 0;
}
