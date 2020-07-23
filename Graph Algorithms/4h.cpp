#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmax = 1e5;
vector<pair<int, ll>> adj[nmax+1];
ll dist[nmax+1];
int processed[nmax+1];

struct nodePriority{
    bool operator()(const pair<int, ll> & a, const pair<int, ll> & b){
        return a.second > b.second;
    }
};

int main(){
    int n, m, a, b, c, u, v;
    pair<int, ll> curr;

    cin >> n >> m;

    memset(dist, -1, sizeof(dist));
    memset(processed, 0, sizeof(processed));

    dist[1] = 0;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dijkstra

    priority_queue<pair<int, ll>,vector<pair<int, ll>>, nodePriority> pq;
    pq.push(make_pair(1, dist[1]));

    while(!pq.empty()){
        curr = pq.top();
        pq.pop();
        u = curr.first;

        if(processed[u])
            continue;

        processed[u] = 1;

        for(pair<int, int> d: adj[u]){
            v = d.first;
            if(dist[v] == -1 || dist[u] + d.second < dist[v]){ //inf or tense
                dist[v] = dist[u] + d.second;
                pq.push(make_pair(v, dist[v]));

            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}