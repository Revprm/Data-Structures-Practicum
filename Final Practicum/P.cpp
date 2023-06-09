#include <iostream>
#include <vector>
#define Fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void aqua(vector<vector<char>>& map, vector<vector<int>>& visited, int x, int y) {
    if (visited[x][y] == 1 || map[x][y] == 'X') {
        return;
    }

    visited[x][y] = 1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size()) {
            aqua(map, visited, nx, ny);
        }
    }
}

int main() {
    Fast
    int M, N;
    cin >> M >> N;

    vector<vector<char>> map(M, vector<char>(N));
    vector<vector<int>> visited(M, vector<int>(N, 0));
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1 || map[i][j] == '^') {
                aqua(map, visited, i, j);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'O' && !visited[i][j]) {
                map[i][j] = 'X';
            }
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}
