#include <bits/stdc++.h>
#define Fast ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

typedef pair<long, long> pll;
typedef pair<int, int> ii;

struct graph {
    long vertexCount, edgeCount;
    vector<vector<ii>> adjList;
    vector<string> RNames;
    vector<long> Rprices;

    void init(long v) {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i <= vertexCount; i++) {
            adjList.push_back({});
        }
    }

    void add_edge(long vertex1, long vertex2, long weight) {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    vector<long> dijkstra(long source) {
        vector<long> distance(vertexCount + 1, INT_MAX);
        distance[source] = 0;

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push(make_pair(0, source));

        while (!pq.empty()) {
            long u = pq.top().second;
            long dist = pq.top().first;
            pq.pop();

            if (dist > distance[u]) {
                continue;
            }

            for (auto edge : adjList[u]) {
                long v = edge.first;
                long weight = edge.second;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        return distance;
    }
};

int main() {
    Fast

    graph g;
    long V, E;
    cin >> V;

    g.init(V);

    for (long i = 0; i < V; i++) {
        string S;
        long P;
        cin >> S >> P;
        g.RNames.push_back(S);
        g.Rprices.push_back(P);
    }

    cin >> E;

    for (long i = 0; i < E; i++) {
        long V1, V2, W;
        cin >> V1 >> V2 >> W;
        g.add_edge(V1, V2, W);
    }

    long D;
    cin >> D;

    vector<long> distance = g.dijkstra(0);

    long termurah = INT_MAX;
    long terdekat = INT_MAX;
    string tpd;

    for (long i = 1; i < V; i++) {
        if (distance[i] <= D) {
            long price = g.Rprices[i-1];

            if (price < termurah) {
                termurah = price;
                terdekat = i;
                tpd = g.RNames[i-1];
            }
        }
    }

    cout << "hari ini makan di " << tpd << endl;

    return 0;
}
