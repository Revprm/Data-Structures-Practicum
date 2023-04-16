#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    stack <int> s;
    int n, m, ttl = 0; cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    // 4 9 36 100
    for (int i = 0; i < n; i++){
        s.push(arr[i]);
    }
    // 100 36 9 4
    while (m--){
        int a = s.top();
        s.push(sqrt(a));
        for (int i = 0; i < n; i++){
            arr[i] = s.top();
            s.pop();
        }
        sort(arr, arr+n);
        for (int i = 0; i < n; i++){
            s.push(arr[i]);
        }
        // 36 10 9 4
        s.pop();
    }
    while (n--){
        ttl+=s.top();
        s.pop();
    }
    cout << ttl;
}
/*
testcase:
4 3
36 9 100 4 

*/
