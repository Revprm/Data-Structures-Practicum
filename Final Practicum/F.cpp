#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct disjoint_set {
    vector<int> parent, size;

    disjoint_set(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            return 1;
        }
        return 0;
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {    
    Fast
    ll n, m, q, u, v, aquk;
    cin >> n >> m;
    vector<ll> k(n + 1);

    for (ll i = 1; i <= n; ++i)
        cin >> k[i];

    pair<pair<ll, ll>, ll> ansss[m];
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> aquk;
        ansss[i] = make_pair(make_pair(min(u, v), max(u, v)), aquk);
    }
    sort(ansss, ansss+m);

    disjoint_set dsu(n);

    for (auto i : ansss) {
        dsu.merge(i.first.first, i.first.second);
    }

    vector<multiset<ll>> aqutan(n + 1), ans(n + 1);
    for (ll i = 1; i <= n; ++i) {
        ll head = dsu.find(i);
        ans[head].insert(k[i]);
    }

    for (ll i = 0; i < m; ++i) {
        ll x = dsu.find(ansss[i].first.first);
        aqutan[x].insert(ansss[i].second);
    }
    ll t;
    char op;
    cin >> q;

    while (q--) {
        cin >> op;
        if (op == '?') {
            cin >> t;
            if (t == 1) {
                ll x;
                cin >> x;
                ll tmp = dsu.find(x);
                if (aqutan[tmp].empty()) cout << 0 << '\n';
                else cout << (*aqutan[tmp].begin()) << '\n';
            } else if (t == 2){
                ll a, b;
                cin >> a >> b;
                a = dsu.find(a);
                b = dsu.find(b);
                if (a == b) cout << 0 << '\n';
                else cout << (*prev(ans[a].end())) + (*prev(ans[b].end())) << '\n';

            }
        } 
        else if(op == '!') {
            cin >> t;
            if (t == 1) {
                ll a, x;
                cin >> a >> x;
                ll tmp = dsu.find(a);
                ans[tmp].erase(ans[tmp].lower_bound(k[a]));
                k[a] = x;
                ans[tmp].insert(k[a]);
            } else {
                ll x, y, w;
                cin >> x >> y >> w;
                if (x > y) swap(x, y);
                ll sui = dsu.find(x);
                ll idx = lower_bound(ansss, ansss + m, make_pair(make_pair(x, y), 0ll)) - ansss;
                aqutan[sui].erase(aqutan[sui].lower_bound(ansss[idx].second));
                ansss[idx].second = w;
                aqutan[sui].insert(ansss[idx].second);
            }
        }
    }

    return 0;
}
