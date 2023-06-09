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

int aqua(const vector<int>& pcs) {
    MPII cnt;
    int mx = 0;

    for (int prc : pcs) {
        cnt[prc]++;
        mx = max(mx, cnt[prc]);
    }

    int dpcs = cnt.size();
    int tims = pcs.size();
    int li = 0;

    if (dpcs == 1) li = tims;
    
    else if (dpcs == 2) li = abs(cnt.begin()->second - cnt.rbegin()->second);
    else {
        if (mx <= tims / 2) li = tims % 2;
        else li = mx - (tims - mx);
    }

    return li;
}

int main() {
    Fast
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> pcs(n);
        for (int j = 0; j < n; j++) {
            cin >> pcs[j];
        }

        int li = aqua(pcs);
        cout << li << '\n';
    }

    return 0;
}
