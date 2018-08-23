#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define N 1001
using namespace std;

class Graph {
    public:
        int adj[N][N];
        bool visited[N];
        int size;
        vector<pair<int,int> > distances;
        Graph(int n) {
            size = n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] = 0;
                }
                visited[i] = false;
            }
        }
    
        void add_edge(int u, int v) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        void bfs(int start){
            queue<int> q;
            int level = 1;
            q.push(start);
            while(!q.empty()){
                int front = q.front();
                q.pop();
                visited[front] = true;
                for(int i=0;i<size;i++){
                    if(visited[i]==false && adj[front][i]==1 && i!=front){
                        q.push(i);
                        distances.push_back({i,level*6});
                        //cout<<front<<" ";
                    }
                }
                level++;
            }
        }
        vector<int> shortest_reach(int start) {
            bfs(start);
            sort(distances.begin(),distances.end());
            vector<int> ret(size);
            for(int i=0;i<distances.size();i++){
                ret[distances[i].first] = distances[i].second; 
            }
            for(int i=0;i<size;i++){
                if(!visited[i]){
                    ret[i] = -1;
                }
            }
            return ret;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}