#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    int mv;
    stack<int> mvs;

    while (N--){
        cin >> mv;
        if (mv == 1){
            if (mvs.empty()){
                mvs.push(1);
                mvs.push(0);
            }
            else if (!mvs.empty()){
                if (mvs.top() == 1 && mvs.size() >= 2){
                    mvs.pop();
                }
                else if (mvs.top() == 0 && mvs.size() == 1) continue;
                else if (mvs.top() == 0 && mvs.size() > 1){
                    mvs.pop();
                    mvs.push(1);
                    mvs.push(0);
                    mvs.push(1);
                    mvs.push(0);
                }
            }
        }
        else if (mv == 0){
            if (mvs.empty()){
                mvs.push(0);
            }
            else if (!mvs.empty()){
                if (mvs.top() == 0 && mvs.size() == 1){
                    mvs.pop();
                }
                else if(mvs.top() == 0 && mvs.size() > 1){
                    mvs.pop();
                }
                else if (mvs.top() == 1 && mvs.size() == 1){
                    mvs.push(0);
                }
                else if(mvs.top() == 1 && mvs.size() > 1){
                    mvs.push(0);
                }
            }
        }
    }
    cout << mvs.size() << '\n';

    return 0;
}
