#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s; cin >> s;
    map<char, int> map;
    for (char c : s) map[c]++;
    bool Jomb = 0;
    string Nondup = "";
    for (auto p : map) {
        if (p.second % 2 == 1) {
            Jomb = 1;
            Nondup += p.first;
            Nondup += " ";
        }
    }
    if (Jomb) cout << "Mereka sendirian: " << Nondup << endl;
    else cout << "Tidak ada yang sendiri" << endl;
    return 0;
}
