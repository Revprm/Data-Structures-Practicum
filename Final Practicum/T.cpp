#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


using namespace std;
#define Fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define FOR(i, n) for(i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1e9+7
#define modll 1000000009ll
typedef pair<int, int> PII;
typedef queue <int> QI;
typedef stack <int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<unordered_set<int>> VUSI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;    
typedef priority_queue<pair<int, int>> PQII;
typedef vector<bool> VB;

using namespace std;

vector<int> bfs(VVI& g, int a, int b) {
    int N = g.size();

    VB vis(N, 0);
    vector<int> parent(N, -1);

    queue<int> q;
    q.push(a);
    vis[a] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == b) {
            vector<int> path;
            while (curr != -1) {
                path.push_back(curr + 1); 
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int it : g[curr]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = true;
                parent[it] = curr;
            }
        }
    }

    return {}; 
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<int>> g(N + 1);

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        g[A - 1].push_back(B - 1);  
        g[B - 1].push_back(A - 1); 
    }

    int a = 0; 
    int b = N - 1; 

    vector<int> path = bfs(g, a, b);

    if (path.empty()) {
        cout << "RIP LAPET 2023" << '\n';
    } else {
        cout << path.size() << '\n';  
        for (int node : path) {
            cout << node << " ";
        }
        cout << '\n';
    }

    return 0;
}
