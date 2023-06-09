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
struct g {
    int ds;
    int dl;
};

typedef vector<vector<g>> vvg;

int aqua(int n, const vvg& graph) {
    VI md(n + 1, numeric_limits<int>::max());
    VB vis(n + 1, 0);
    PQII pq;
    pq.push({0, 1}); 

    while (!pq.empty()) {
        int vld = pq.top().S;
        int dl = -pq.top().F;
        pq.pop();

        if (vis[vld]) continue;
        vis[vld] = 1;
        md[vld] = dl;

        for (const g& gr : graph[vld]) {
            int nv = gr.ds;
            int nd = max(dl, gr.dl);
            if (!vis[nv]) {
                pq.push({-nd, nv});
            }
        }
    }

    return md[n];
}

int main() {
    Fast
    int n, m, a, b, c; cin >> n >> m;
    vvg graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int md = aqua(n, graph);
    cout << md << endl;

    return 0;
}