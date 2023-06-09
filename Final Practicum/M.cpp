#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

bool isOpen(char c)
{
    if(c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool isBalanced(char p, char n){
    map<char, char> brackets = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    return brackets[p] == n;
}

int main(){
    stack<char> s;
    string str;
    cin >> str;
    int no = 0;
    for(int i = 0; i < str.length(); i++){
        char n = str[i];
        if(isOpen(n)) s.push(n);
        
        else{
            char p;
            if(s.size() > 0){
                p = s.top();
                s.pop();
            }
            else{
                no = 1;
                break;
            }
            if(isBalanced(p, n))
                continue;
            else{
                no = 1;
                break;
            }
        }
    }
    if(s.size() != 0) no = 1;
    if(no) cout<<"unvaldi\n";
    else cout<<"valdi\n";
    return 0;
}
