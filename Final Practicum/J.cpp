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
#include <climits>
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


ll aqua(ll n, ll mod) {
    ll base = 2;
    ll exp = n * (n - 1) / 2;
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res % mod;
}

int main() {
    Fast
    ll n, x; cin >> n;
    while (n--){
        cin >> x;
        ll res = aqua(x, modll);
        cout << "Zodiak found: " << res << " signs" << '\n';
    }
    return 0;
}
