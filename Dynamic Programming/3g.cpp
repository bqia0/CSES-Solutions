#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define uint unsigned int

const uint nmx = 1000+1;
const uint xmx = 1e5+1;

int dp[nmx][xmx];
int prices[nmx];
int pages[nmx];


int main(){
    int n, x;

    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    for(int i = 0; i <= x; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int c = 0; c <= x; c++){
            if(c-prices[i-1] >= 0)
                dp[i][c] = max(dp[i-1][c], dp[i-1][c-prices[i-1]] + pages[i-1]);
            else
                dp[i][c] = dp[i-1][c];
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}