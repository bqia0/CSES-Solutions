#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mx = 1000;
const int M = 1e9+7;

ll dp[mx][mx];
ll board[mx][mx];

int main(){
    int n;
    char t;
    cin >> n;

    dp[n-1][n-1] = 1;

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            cin >> t;
            board[j][i] = t;
            if(t == '*')
                dp[j][i] = 0;
        }
    }

    for(int j = n - 1; j >= 0; j--){
        for(int i = n-1; i >= 0; i--){
            if(board[j][i] == '*')
                continue;

            if(i+1 < n)
                dp[j][i] = (dp[j][i] + dp[j][i+1]) % M;
            if(j+1 < n)
                dp[j][i] = (dp[j][i] + dp[j+1][i]) % M;
        }
    }

    // for(int j = 0; j < n; j++){
    //     for(int i = 0; i < n; i++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[0][0] << endl;

    return 0;
}