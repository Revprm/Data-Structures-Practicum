#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#define Fast ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void aqua(const map<string, string>& dataMember, const map<string, map<string, vector<string>>>& pesan) {
    for(auto a = dataMember.begin(); a != dataMember.end(); a++) {
        if (pesan.count(a->first) == 0 || pesan.at(a->first).empty())continue;
        cout << "===========\n";
        cout << "Mail:" << a->second << '\n';
        for (auto b = pesan.at(a->first).begin(); b != pesan.at(a->first).end(); b++) {
            cout << "From:" << dataMember.at(b->first) << '\n';
            
            for (const string& message : b->second) {
                cout << ">>" << message << '\n';
            }
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    map<string, string> dataMember;
    map<string, map<string, vector<string>>> pesan;
    
    for (int i = 0; i < N; i++) {
        string ip, name;
        cin >> ip;
        getline(cin, name);
        dataMember[ip] = name;
    }
    
    for (int i = 0; i < Q; i++) {
        string IpPengirim, IpPenerima, message;
        cin >> IpPengirim >> IpPenerima;
        getline(cin, message);
        if (dataMember.find(IpPengirim) != dataMember.end() && dataMember.find(IpPenerima) != dataMember.end()) {
            pesan[IpPenerima][IpPengirim].push_back(message);
        }
    }
    aqua(dataMember, pesan);

    return 0;
}
