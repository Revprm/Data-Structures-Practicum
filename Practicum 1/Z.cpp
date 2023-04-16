#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
using namespace std;

int main(){
    fst
    int n; cin >> n;
    while (n--){
        ll m; cin >> m;
        deque <int> dq;
        while (m){
            int a = m % 2;
            if (dq.empty()) dq.push_front(a);
            else if (dq.front() == a) dq.pop_front();
            else dq.push_front(a);
            m >>= 1; 
        }
        m = 0;
        while (!dq.empty()){
            m <<= 1;
            m+=dq.front();
            dq.pop_front();
        }
        cout << m << endl;
    }
    return 0;
}

/*
    untuk masalah Z, simpelnya kita memakai ilmu Sisdig(sistem digital)
    yang sudah kita pelajari yaitu konversi bilangan desimal ke bilangan biner

    untuk ADT, kita bisa memakai kurang lebih semua ADT karena
    yang perlu kita bandingkan hanya data yang ada di dalamnya dengan
    data yang ingin dimasukkan

*/