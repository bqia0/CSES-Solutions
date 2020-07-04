#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool visited[7][7] = {false};
int ans;
string description;

// prev is for the pruning test
void dfs(int x, int y, int step, char prev){
    // cout << x << " " << y << " " << step << endl;
    char dir;

    if(x == 0 && y == 6){
        if(step == 48)
            ans++;
        return;
    }

    if(step == 48){
        return;
    }

    if(visited[x][y])
        return;

    //Pruning: can't move forward but can move perpendicular in either dir means failure
    if((prev == 'R' && !(x+1 < 7 && !visited[x+1][y])) || (prev == 'L' && !(x-1 >= 0 && !visited[x-1][y]))) {
        // Can we move up and down?
        if((y+1 < 7 && !visited[x][y+1]) && (y-1 >= 0 && !visited[x][y-1]))
            return;
    }

    if((prev == 'D' && !(y+1 < 7 && !visited[x][y+1])) || (prev == 'U' && !(y-1 >= 0  && !visited[x][y-1]))) {
        // Can we move right and left?
        if((x+1 < 7 && !visited[x+1][y]) && (x - 1 >= 0 && !visited[x-1][y]))
            return;
    }


    dir = description[step];
    visited[x][y] = true;

    if(x+1 < 7 && !visited[x+1][y] && (dir == '?' || dir == 'R')){
        dfs(x+1, y, step+1, 'R');
    }
    if(x - 1 >= 0 && !visited[x-1][y] && (dir == '?' || dir == 'L')){
        dfs(x-1, y, step+1, 'L');
    }
    if(y+1 < 7 && !visited[x][y+1] && (dir == '?' || dir == 'D')){
        dfs(x, y+1, step+1, 'D');
    }
    if(y-1 >= 0 && !visited[x][y-1] && (dir == '?' || dir == 'U')){
        dfs(x, y-1, step+1, 'U');
    }

    visited[x][y] = false;
}

int main(){
    cin >> description;

    ans = 0;

    dfs(0, 0, 0, 'N'); // 'N' is a sentinal value
    cout << ans << endl;

    return 0;
}

