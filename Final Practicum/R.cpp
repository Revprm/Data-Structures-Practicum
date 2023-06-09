#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string aqua(vector<int>& l1, vector<int>& l2) {
    reverse(l1.begin(), l1.end());
    reverse(l2.begin(), l2.end());
    vector<int> res;
    int x = 0;
    int size = max(l1.size(), l2.size());
    
    for (int i = 0; i < size; i++) {
        int ans = x;
        if (i < l1.size()) ans += l1[i];
        if (i < l2.size()) ans += l2[i];
        res.push_back(ans % 10);
        x = ans / 10;
    }
    if (x > 0) res.push_back(x);
    reverse(res.begin(), res.end());
    string ansStr;
    for (int it : res) ansStr += to_string(it);
    
    return ansStr;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> l1(M);
    vector<int> l2(N);
    for (int i = 0; i < M; i++) cin >> l1[i];
    for (int i = 0; i < N; i++) cin >> l2[i];
    
    string ans = aqua(l1, l2);
    cout << ans << endl;
    
    return 0;
}
