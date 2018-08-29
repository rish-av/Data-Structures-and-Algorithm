#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int bfs(int i,vector<int> adj[],vector<long> &ids,int val){
    queue<int> q;
    q.push(i);
    //cout<<i;
    int dist = 1;
    bool visited[ids.size()];
    for(int i=0;i<ids.size();i++){
        visited[i] = false;
    }
    while(!q.empty()){
        int size = q.size();
        //cout<<adj[q.front()].size()<<size<<" ";
        while(size--){
            int r = q.front();
            q.pop();
            visited[r] = true;
            for(int i=0;i<adj[r].size();i++){
                if(!visited[adj[r][i]]){
                    q.push(adj[r][i]);
                    if(ids[adj[r][i]]==val){
                        //cout<<dist;
                        return dist;
                    }
                }
            }
        }
        dist++;
    }
    return -1;
}
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    vector<int> adj[graph_nodes];
    for(int i=0;i<graph_from.size();i++){
        adj[graph_from[i]-1].push_back(graph_to[i]-1);
        adj[graph_to[i]-1].push_back(graph_from[i]-1);
        //cout<<graph_from[i]-1<<" "<<adj[graph_from[i]-1].size()<<"\n";
    }
    //cout<<adj[3].size();
    int prevret = 0;
    int finalret = 3000000;
    for(int i=0;i<graph_nodes;i++){
        if(ids[i]==val){
            prevret = bfs(i,adj,ids,val);
            if(prevret==-1)
                return -1;
            if(prevret<finalret)
                finalret = prevret;
        }
    }
    if(finalret!=3000000)
        return finalret;
    else 
        return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";
    cout<<ans;

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
