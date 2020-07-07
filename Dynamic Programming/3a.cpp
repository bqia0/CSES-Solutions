#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define llu unsigned long long


int main(){
    int n; 
    cin >> n;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i-j < 0){
                break;
            }

            dp[i] = (dp[i] + dp[i-j]) % (ll)(1e9+7); 
        }
    }

    cout << dp[n] << endl;
 
    return 0;
}