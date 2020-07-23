#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmx = 1e5;

vector<int> adj [nmx+1];
int visited[nmx+1];
unordered_map<int, int> pred;


int bfs(int start, int target){
    int curr;
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    pred.insert({start, -1});

    while(!q.empty()){
        curr = q.front();
        q.pop();

        if(curr == target)
            return 1;

        for(int c: adj[curr]){
            if(visited[c])
                continue;

            q.push(c);
            visited[c] = 1;
            pred.insert({c, curr});
        }
    }
    return 0;
}

int main(){
    int n, m, a, b, curr;
    int length = 0;
    vector<int> path;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(bfs(1, n)){
        int curr = n;

        while(curr != -1){
            path.push_back(curr);
            length++;
            curr = pred[curr];
        }

        reverse(path.begin(), path.end());
        cout << length << endl;
        
        for(int d: path){
            cout << d << " ";
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}