#include <bits/stdc++.h>
#define maxx 25

using namespace std;

int m, q, si, sj, ei, ej, key;
char maze[maxx][maxx];
int visited[maxx][maxx];
int check;

void reach(int i, int j, int key) {
    if (i < 1 || i > m || j < 1 || j > m || visited[i][j])
        return;
    if (maze[i][j] == '#')
        return;
    if (maze[i][j] == 'O') {
        if (key == 1)
            key--;
        else
            return;
    }
    if (i == ei && j == ej) {
        check = 1;
        return;
    }
    visited[i][j] = 1;

    reach(i, j + 1, key);
    reach(i, j - 1, key);
    reach(i + 1, j, key);
    reach(i - 1, j, key);
}

int main() {
    cin >> m >> q;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }

    while (q--) {
        cin >> si >> sj >> ei >> ej;
        check = 0;
    
        memset(visited, 0, sizeof(visited));
        reach(si, sj, 1);

        if (check)
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
    return 0;
}
