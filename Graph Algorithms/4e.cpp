#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmax = 1e5;

vector<int> adj [nmax + 1];
int colors[nmax+1];
int visited[nmax+1];

// color is color of predecessor
void dfs(int node, int prevColor){
    // cout << node << " " << prevColor << " " << colors[node] <<  endl;
    int newColor = 1 - prevColor;
    visited[node] = 1;

    colors[node] = newColor;

    for(int d: adj[node]){
        if(!visited[d]){
            dfs(d, newColor);

        }
    }

}

int main(){
    int n, m, a, b;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        colors[i] = -1;
        visited[i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // colors[1] = 1;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, 0);
        }
    }


    for(int i = 1; i <= n; i++){
        for(int d: adj[i]){
            if(colors[i] == colors[d]){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << colors[i] + 1 << " ";
    }


    return 0;
}