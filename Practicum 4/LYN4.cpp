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
#define FOR(i, n) for(i = 0; i < n; i++)
#define FORR(i, n) for(i = 0; i <= n; i++)
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1e9+7
#define modll 1000000007ll
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
ll res[10][10];
VI v, g; 
VVI adjl;

void suichan(){
    for (ll i = 0; i < 10; i++){
        res[0][i] = 1;
        res[i][0] = 1;
        res[i][i] = 1;
    }
}

ll aqua(char a, char b){
    if (a == 'X' && b == '1') return 1;
    else if (a == 'Y' && b == '1') return 2;
    else if (a == 'Z' && b == '1') return 3;
    else if (a == 'X' && b == '2') return 4;
    else if (a == 'Y' && b == '2') return 5;
    else if (a == 'Z' && b == '2') return 6;
    else if (a == 'X' && b == '3') return 7;
    else if (a == 'Y' && b == '3') return 8;
    else return 9;
}

void dfs(ll u){
    v[u] = 1;
    g.push_back(u);
    for (int i = 0; i < g.size(); i++){
        res[g[i]][u] = 1;
        res[u][g[i]] = 1;
    }
    for (ll i = 0; i < adjl[u].size(); i++){
        ll a = adjl[u][i];
        if (v[a] == -1)
            dfs(a);
    }
}

int main(){
    Fast
    ll i, j;
    v.assign(10, -1);
    adjl.assign(10, vector<int>()); 
    memset(res, 0, sizeof(res));
    suichan();
    int n; cin >> n;
    cin.ignore();
    string str;
    for (i = 0; i < n; i++){
        getline(cin, str);
        ll a = aqua(str[0], str[1]);
        ll b = aqua(str[7], str[8]);
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }
    ll ans = 0;
    for (i = 1; i <= 9; i++){
        if (v[i] == -1){
            dfs(i);
            g.clear();
        }
    }
    for (i = 1; i <= 9; i++){
        for (j = 1; j <= 9; j++){
            if (!res[i][j] && !res[j][i]){
                ans++;
                res[i][j] = 1;
                res[j][i] = 1;
            }
        }
    }
    cout << "Stars: " << ans << " not connected" << endl;
    return 0;
}
