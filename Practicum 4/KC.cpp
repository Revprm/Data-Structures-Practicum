#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

bool rekomen(const vector<unordered_set<int>>& graph, int check) {
    for (const auto& g : graph) {
        if (g.count(check) > 0) return 1;
    }
    return 0;
}

bool tidakrekomen(const vector<unordered_set<int>>& graph, int check) {
    for (const auto& g : graph) {
        if (g.size() > 0 && g.count(check) == 0) return 1;
    }
    return 0;
}

int main() {
    int n, p1, p2; cin >> n;

    vector<unordered_set<int>> graph(n + 1);
    cin >> p1 >> p2;
    while (p1 != -1 && p2 != -1) {
        graph[p1].insert(p2);
        cin >> p1 >> p2;
    }

    bool chk = false;
    for (int i = 1; i <= n; i++) {
        if (rekomen(graph, i) && !tidakrekomen(graph, i)) {
            cout << "pilih ini aja chris " << i << endl;
            chk = true;
            break;
        }
    }

    if (!chk) cout << "ga ada yang direkomen" << endl;
    return 0;
}
