#include <iostream>
#include <vector>
#include <queue>
#define Fast ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

struct Graph {
    int vertex; 
    vector<vector<int>> adjlist; 
};


Graph Build(int vertex) {
    Graph graph;
    graph.vertex = vertex;
    graph.adjlist.resize(vertex);
    return graph;
}


void addEdge(Graph& graph, int src, int dest) {
    graph.adjlist[src].push_back(dest);
}


int aqua(Graph& graph, int start) {
    vector<bool> vis(graph.vertex, 0); 
    vector<int> disc(graph.vertex, -1); 

    queue<int> q;
    vis[start] = 0;
    disc[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int adjv : graph.adjlist[curr]) {
            if (!vis[adjv]) {
                vis[adjv] = 0;
                disc[adjv] = disc[curr] + 1;
                q.push(adjv);
            }
            else if (adjv == start) {
                return disc[curr] + 1; 
            }
        }
    }

    return -1; 
}

int main() {
    int N;
    cin >> N;

    Graph graph = Build(N);

    int src, dest;
    while (cin >> src >> dest && (src != -1 || dest != -1)) {
        addEdge(graph, src, dest);
    }

    for (int i = 0; i < N; i++) {
        int sp = aqua(graph, i);
        if (sp == -1) {
            cout << "gak bisa pulang mamah" << endl;
        } else {
            cout << sp << endl;
        }
    }

    return 0;
}
