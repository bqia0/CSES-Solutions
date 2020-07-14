#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmx = 100;
const int xmx = 1e6;
const int M = 1e9+7;

int dp[nmx+1][xmx+1];
int coins[nmx];

int main(){

    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for(int i = 0; i <= x; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            (dp[i][j] += dp[i-1][j]) %= M;
            if(j - coins[i-1] >= 0){
               //dp[i][j] +=  dp[i-1][j - coins[i-1]] % M;
                (dp[i][j] += dp[i][j - coins[i-1]]) %= M;
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}