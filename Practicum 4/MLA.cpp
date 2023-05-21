#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Fungsi ini bisa dibilang buat ngecek linear atau tidaknya suatu graph yaitu ngecek edge yang dimiliki
// masing-masing vertex itu lebih dari 2 atau tidak jika lebih maka graph tersebut tidak linear
bool isLinkedList(vector<vector<int>> &adjList) {
    for (auto it : adjList) {
        if (!(it.size() <= 2 && it.size() > 0)) return 0;
    }
    return 1;
}
// Jika tidak linear, maka antara 2 kemungkinan antara graph tersebut merupakan sebuah tree atau graph biasa
// agar mempermudah dalam pengimplementasiannya, aku mencari siklik sebuah graph dulu dengan metode dfs
// jadi graph tersebut akan memiliki cycle jika tidak ada vertex yang memiliki parent.
bool hasCycle(vector<vector<int>> &adjList, int vertex, vector<bool> &vis, int parent) {
    vis[vertex] = 1;
    for (auto it : adjList[vertex]) {
        if (!vis[it]) {
            if (hasCycle(adjList, it, vis, vertex)) return 1; // dfs ke semua vertex untuk cari ada yg punya parent tidak   
        } 
        else if (vis[it] && it != parent) return 1;
    }
    return 0;
}
int main() {
    int n, v, e, v1, v2; cin >> n;
    while (n--) {
        cin >> e >> v;
        vector<vector<int>> adjList(e);
        for (int i = 0; i < v; i++) {
            cin >> v1 >> v2;
            adjList[--v1].push_back(--v2);
            adjList[v2].push_back(v1);
        }
        if (isLinkedList(adjList)) cout << "Hewan" << "\n"; 
        else {
            vector<bool> vis(e, 0);
            if (!hasCycle(adjList, 0, vis, -1)) cout << "Pohon" << "\n";
            else cout << "Bukan keduanya" << "\n";
        }
    }
    return 0;
}
