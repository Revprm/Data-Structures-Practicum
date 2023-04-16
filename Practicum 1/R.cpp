#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int n, b = 0, c = 0; cin >> n;    
    stack <int> s;  
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        s.push(a);
    }
    for (int i = 0; i < n; i++){
        int ck; cin >> ck;
        if (ck == 1)b++;
        else c++;
    }
    while (!s.empty()){
        if (s.top() == 1) b--;
        else c--;
        if (b < 0 || c < 0){
            break;
        }
        s.pop();
    }
    if (s.empty()) cout << "Yeay semua dapet" << "\n";
    else cout << "Yah " << s.size() << " orang ga dapet" << "\n";
    return 0;
}

/*
5
1 1 0 0 1
1 1 1 0 0
Masuk Stack jadi:
1 0 0 1 1
Dari soal, seolah-olah kita perlu memakai antrian
tapi sebenarnya gaperlu karena yang perlu dibandingkan
hanya jumlah orang yang membutuhkan roti tersebut dengan
roti yang ada di paling atas tumpukan
*/
