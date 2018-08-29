#include <bits/stdc++.h>

using namespace std;

// Complete the maxRegion function below.
#define N 11
bool visited[N][N];
bool valid(int i,int j,int m,int n){
    if(i>=0 && i<n && j>=0 && j<m)
        return true;
    return false;
}
void dfs(vector<vector<int>> grid,int i,int j,int &count,int dir[8][2]){
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j] = true; 
    count++;
    for(int l=0;l<8;l++){
        if(valid(i+dir[l][0],j+dir[l][1],m,n) && grid[i+dir[l][0]][j+dir[l][1]]==1 && !visited[i+dir[l][0]][j+dir[l][1]]){
            dfs(grid,i+dir[l][0],j+dir[l][1],count,dir);
        }
    }
}
int maxRegion(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    int dir[8][2]= {{1,1},{1,-1},{-1,1},{1,0},{0,1},{-1,0},{-1,-1},{0,-1}};
    vector<int> counts;
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]==1){
                count = 0;
                dfs(grid,i,j,count,dir); 
                counts.push_back(count);
            }
        }
    }
    int max = counts[0];
    for(int i=0;i<counts.size();i++){
        if(counts[i]>max)
            max  = counts[i];
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";
    cout<<res;

    fout.close();

    return 0;
}
