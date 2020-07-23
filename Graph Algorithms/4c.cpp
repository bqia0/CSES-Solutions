#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmx = 1e5;
const int mmx = 2e5;

vector<int> adj [nmx+1];
int visited[nmx+1];

void dfs(int a){
    visited[a] = 1;

    for(int i = 0; i < adj[a].size(); i++){
        if(!visited[adj[a][i]]){
            dfs(adj[a][i]);
        }
    }
}

int main(){

    int n, m, a, b;
    int components = 0;
    vector<int> unconnected;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            unconnected.push_back(i);
            components++;
        }
    }

    cout << components - 1 << endl;

    for(int i = 1; i < components; i++){
        cout << unconnected[0] << " " << unconnected[i] << endl;
    }

    return 0;
}