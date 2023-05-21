#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<pair<char, int>>> kav(N, vector<pair<char, int>>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> kav[i][j].first >> kav[i][j].second;
        }
    }
    int maxLuasKav = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (kav[i][j].first == 'K') {
                int LuasKav = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
              
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                  
                    if (x < 0 || x >= N || y < 0 || y >= M || kav[x][y].first != 'K') continue;
                    
                    LuasKav += kav[x][y].second;
                    kav[x][y].first = 'J'; 
                    q.push({x - 1, y});
                    q.push({x + 1, y});
                    q.push({x, y - 1});
                    q.push({x, y + 1});
                }
                maxLuasKav = max(maxLuasKav, LuasKav);
            }
        }
    }
    cout << maxLuasKav << endl;

    return 0;
}
