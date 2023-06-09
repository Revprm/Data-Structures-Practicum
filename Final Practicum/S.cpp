#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <math.h>


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

int aqua(VI &nums, int n, int k){
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int temp = nums[i] * pow(10, floor(log10(nums[j])) + 1) + nums[j];
                if (temp % k == 0) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
    Fast
    int n, k;cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << aqua(nums, n, k) << '\n';
    return 0;
}
