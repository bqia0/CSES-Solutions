#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmx = 1000;

char world[nmx][nmx];
char dirs[nmx][nmx];

int visited[nmx][nmx];

int n, m;

int bfs(int sx, int sy){
    int x, y;
    queue<pair<int, int>> q;

    q.push(pair<int, int>(sx, sy));

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        x = curr.first;
        y = curr.second;

        if(visited[y][x])
            continue;

        visited[y][x] = 1;

        if(world[y][x] == 'B'){
            return 1;
        }

        if(x + 1 < m && !visited[y][x+1] && world[y][x+1] != '#'){
            q.push(pair<int, int>(x+1, y));
            dirs[y][x+1] = 'R';
        }

        if(y + 1 < n && !visited[y+1][x] && world[y+1][x] != '#'){
            q.push(pair<int, int>(x, y+1));
            dirs[y+1][x] = 'D';
        }

        if(y > 0 && !visited[y-1][x] && world[y-1][x] != '#'){
            q.push(pair<int, int>(x, y-1));
            dirs[y-1][x] = 'U';
        }

        if(x > 0 && !visited[y][x-1] && world[y][x-1] != '#'){
            q.push(pair<int, int>(x-1, y));
            dirs[y][x-1] = 'L';
        }
    }
    return 0;

}

int main(){
    pair<int, int> start, end, curr;
    string ans = "";
    char cdir;
    cin >> n >> m;

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> world[y][x];
            visited[y][x] = 0;
            dirs[y][x] = 'F';

            if(world[y][x] == 'A'){
                start.first = x;
                start.second = y;
            }
            if(world[y][x] == 'B'){
                end.first = x;
                end.second = y;
            }
        }
    }

    if(bfs(start.first, start.second)){
        cout << "YES" << endl;

        curr = end;

        do{
            cdir = dirs[curr.second][curr.first];
            ans.push_back(cdir);
            if(cdir == 'U'){
                curr = pair<int, int>(curr.first, curr.second + 1);
            }else if (cdir == 'D'){
                curr = pair<int, int>(curr.first, curr.second - 1);
            }else if (cdir == 'L'){
                curr = pair<int, int>(curr.first + 1, curr.second);
            }else if (cdir == 'R'){
                curr = pair<int, int>(curr.first - 1, curr.second);
            }
        }while(curr != start);

        reverse(ans.begin(), ans.end());
        cout << ans.length() << endl;
        cout << ans << endl;

    }else{
        cout << "NO" << endl;
    }
    return 0;
}