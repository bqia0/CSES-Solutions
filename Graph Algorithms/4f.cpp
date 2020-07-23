#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmax = 1e5;

vector<int> adj [nmax + 1];
int visited[nmax+1];
unordered_map <int, int> pred;

void isCyclic_dfs(int node, int prevNode){
    visited[node] = 1;

    for(int d: adj[node]){
        if(d == prevNode)
            continue;
        pred[d] = node;
        if(visited[d] == 1){
            vector<int> ans;
            ans.push_back(node);
            int curr = pred[node];
            while(curr != node){
                ans.push_back(curr);
                curr = pred[curr];
            }
            ans.push_back(node);
            cout << ans.size() << endl;
            for(int f: ans){
                cout << f << " ";
            }
            exit(0);

        }
        else if(visited[d] == 0){
            isCyclic_dfs(d, node);
        }
    }
    visited[node] = 2;
}

int main(){
    int n, m, a, b;

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
            isCyclic_dfs(i, -1);
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}