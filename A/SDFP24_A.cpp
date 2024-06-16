    #include <bits/stdc++.h>
    using namespace std;

    struct graph {
        long vertexCount, edgeCount;
        vector<vector<pair<long, long>>> adjList;

        void init(long v) {
            vertexCount = v;
            edgeCount = 0;
            adjList.resize(vertexCount);
        }

        void add_edge(long vertex1, long vertex2, long weight) {
            adjList[vertex1].push_back(make_pair(vertex2, weight));
            adjList[vertex2].push_back(make_pair(vertex1, weight));
            edgeCount++;
        }

        long dijkstra(long start, long end, long maxPotions) {
            vector<long> dist(vertexCount, LONG_MAX);
            priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;

            pq.push(make_pair(0, start));
            dist[start] = 0;

            while (!pq.empty()) {
                auto temp = pq.top();
                pq.pop();
                long currentDist = temp.first;
                long currentNode = temp.second;

                if (currentNode == end) {
                    return currentDist;
                }

                for (auto &vertex : adjList[currentNode]) {
                    long nextVertex = vertex.first;
                    long weight = vertex.second;

                    long nextDist = currentDist + weight;
                    if (nextDist < dist[nextVertex]) {
                        dist[nextVertex] = nextDist;
                        pq.push(make_pair(nextDist, nextVertex));
                    }
                }
            }
            return LONG_MAX;
        }
    };

    int main() {
        graph g;
        long n, m, k, e, a, b, p;
        cin >> n >> m >> k >> e;

        g.init(n);
        for (long i = 0; i < m; i++) {
            cin >> a >> b >> p;
            g.add_edge(a - 1, b - 1, p);
        }

        long totalPotionsNeeded = g.dijkstra(0, n - 1, k);

        if (totalPotionsNeeded == LONG_MAX) {
            cout << "muak gweh, butuh heal lagi" << endl;
            return 0;
        }

        long refillsNeeded = (totalPotionsNeeded - k); 
        long totalRefillTime = refillsNeeded * 3;
        if(totalRefillTime<=0){cout << 0 << endl;}
        else if (e < totalRefillTime) {
            cout << "muak gweh, butuh heal lagi" << endl;
        } else {
            cout << totalRefillTime << endl;
        }

        return 0;
    }
