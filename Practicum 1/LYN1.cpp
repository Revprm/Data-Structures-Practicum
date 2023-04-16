#include <iostream>
#include <list>
using namespace std;
#define ll long long

int main(){
    int m, n; 
    cin >> m >> n;
    if (m < 0 || n < 0) {
        return 0;
    }
    list <string> l;
    string str;
    if (m == 0){
        cout << "Apa itu nol?" << endl;
    }
    else{
        while (m--){
            cin >> str;
            l.push_back(str);
        }
        while (!l.empty()){
            if (n == 0){
                cout << l.front() << " ";
                l.pop_front();
                if (!l.empty()) {
                    cout << l.back() << " ";
                    l.pop_back();
                }
            }
            else {
                cout << l.back() << " ";
                l.pop_back();
                if (!l.empty()) {
                    cout << l.front() << " ";
                    l.pop_front();
                }
            }
        }
    }
    cout << endl;
    return 0;
}

/*
    n = 0 -> Ambil dari kanan trus ambil kiri lalu diulangi sampai string abis
    n = 1 -> sebaliknya
    bisa dibilang cuma mainin front & back dan pop_front & pop_backnya aja

*/