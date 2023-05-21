#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <cstring>
#include <cmath>
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int Res[10][10];
vector<int> visited(10, -1), graph; 
vector<vector<int>> AdjList;

void checker(){ 
    for (int i = 0; i < 10; i++){
        Res[0][i] = 1;
        Res[i][0] = 1;
        Res[i][i] = 1;
    }
}

int Convert(char a, char b){
    if (a == 'X' && b == '1') return 1;
    else if (a == 'Y' && b == '1') return 2;
    else if (a == 'Z' && b == '1') return 3;
    else if (a == 'X' && b == '2') return 4;
    else if (a == 'Y' && b == '2') return 5;
    else if (a == 'Z' && b == '2') return 6;
    else if (a == 'X' && b == '3') return 7;
    else if (a == 'Y' && b == '3') return 8;
    else return 9;
}
void dfs(int u){
    visited[u] = 1;
    graph.push_back(u);
    for (int i = 0; i < graph.size(); i++){
        Res[graph[i]][u] = 1;
        Res[u][graph[i]] = 1;
    }
    cout << endl;
    for (int i = 0; i < AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if (visited[v] == -1) dfs(v);
    }
}

int main(){
    fast
    AdjList.assign(10, vector<int>()); 
    memset(Res, 0, sizeof(Res));
    checker();
    int n; cin >> n;
    cin.ignore();
    string str;
    for (int i = 0; i < n; i++){
        getline(cin, str);
        int a = Convert(str[0], str[1]);
        int b = Convert(str[7], str[8]);
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    int res = 0;
    for (int i = 1; i <= 9; i++){
        if (visited[i] == -1){
            dfs(i);
            graph.clear();
        }
    }   
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            if (!Res[i][j] && !Res[j][i]){
                res++;
                Res[i][j] = 1;
                Res[j][i] = 1;
            }
        }
    }
    cout << "Stars: " << res << " not connected" << endl;
    return 0;
}
