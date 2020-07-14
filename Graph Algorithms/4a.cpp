#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmx = 1000;

char world[nmx][nmx];
int visited[nmx][nmx];

int n, m;

void dfs(int x, int y){
    visited[y][x] = 1;

    if(world[y][x] == '#')
        return;

    if(x + 1 < m && !visited[y][x+1]){
        dfs(x+1, y);
    }

    if(y + 1 < n && !visited[y+1][x]){
        dfs(x, y+1);
    }

    if(y > 0 && !visited[y-1][x]){
        dfs(x, y-1);
    }

    if(x > 0 && !visited[y][x-1]){
        dfs(x-1, y);
    }
}

int main(){
    int ans = 0;
    cin >> n >> m;

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> world[y][x];
            visited[y][x] = 0;
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(!visited[y][x] && world[y][x] != '#'){
                dfs(x, y);
                ans++;
            }
        }
    }
 
    cout << ans << endl;

    return 0;
}