#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmax = 1e5;
const int mmax = 100;
const int M = 1e9+7;

ll dp[nmax+1][mmax+1] = {0}; // dp[i][v] = # ways to fill to index i if x[i] == v
int nums[nmax];

int main(){
    int n, m;
    ll ans;
    cin >> n >> m;

    ans = 0;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    if(nums[0] != 0){
        dp[0][nums[0]] = 1;
    }else{
        for(int i = 1; i < mmax+1; i++){
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        if(nums[i] != 0){
            dp[i][nums[i]] = dp[i-1][nums[i]];
            if(nums[i] > 0){
                (dp[i][nums[i]] +=dp[i-1][nums[i] - 1])%=M;
            }
            if(nums[i] < m){
                (dp[i][nums[i]] +=dp[i-1][nums[i] + 1])%=M;               
            }
        }else{
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i-1][j];
                if(j > 0){
                    (dp[i][j] +=dp[i-1][j - 1])%=M;
                }
                if(j < m){
                    (dp[i][j] +=dp[i-1][j + 1])%=M;               
                }                
            }
        }
    }

    for(int i = 1; i <= m; i++){
        (ans += dp[n - 1][i]) %= M;
    }

    cout << ans << endl;

    return 0;
}