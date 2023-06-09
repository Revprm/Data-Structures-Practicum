#include <iostream>
#include <vector>
#define Fast ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;
const int MAX_N = 100;

vector<vector<int>> mapper(MAX_N, vector<int>(MAX_N, 0));
vector<pair<int, int>> minato;
int N;

void aqutan(int x, int y, int value) {
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    if (mapper[x][y] > 0 && mapper[x][y] < value) return;
    mapper[x][y] = value;
    value++;
    if (value == 2){
        aqutan(x - 1, y, 2);
        aqutan(x + 1, y, 2);
        aqutan(x, y - 1, 2);
        aqutan(x, y + 1, 2);        
    }
    else if (value == 3){
        aqutan(x - 1, y, 3);
        aqutan(x + 1, y, 3);
        aqutan(x, y - 1, 3);
        aqutan(x, y + 1, 3);        
    }
    else if (value == 4){
        aqutan(x - 1, y, 4);
        aqutan(x + 1, y, 4);
        aqutan(x, y - 1, 4);
        aqutan(x, y + 1, 4);        
    }
    else return;
}

void aqutan(int M) {
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        minato.push_back({x - 1, y - 1});
    }

    for (const auto& bakaqua : minato) {
        aqutan(bakaqua.first, bakaqua.second, 1);
    }
}

void suich() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mapper[j][i] << " ";
        }
        cout << '\n';
    }
}

int main() {
    int M;
    cin >> N >> M;

    aqutan(M);
    suich();

    return 0;
}
