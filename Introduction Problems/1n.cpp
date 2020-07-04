#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<string> board;
int q[8] = {-1}; 

int ans;

// http://jeffe.cs.illinois.edu/teaching/algorithms/book/02-backtracking.pdf
void queens(int row){
    if(row == 8){
        ans++;
        return;
    }

    bool legal = true;
    for(int x = 0; x < 8; x++){
        legal = true;

        if(board[row][x] == '*')
            continue;

        for(int i = 0; i < row; i++){
            if(q[i] == x || q[i] == x+row-i || q[i] == x-row+i)
                legal = false;
        }
        if(legal){
            q[row] = x;
            queens(row+1);
        }
    }

}

int main(){
    string temp;
    ans = 0;

    for(size_t i = 0; i < 8; i++){
        cin >> temp;
        board.push_back(temp);
    }

    queens(0);
    cout << ans << endl;
    return 0;
}