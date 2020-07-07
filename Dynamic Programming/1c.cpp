#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define llu unsigned long long


int main(){
    ll n, x, t;
    cin >> n >> x;
    vector<ll> dp(x+1, 0);
    vector<ll> c;

    dp[0] = 1;

    for(ll i = 0; i < n; i++){
        cin >> t;
        c.push_back(t);
    }

    for(ll i = 1; i <= x; i++){
        for(ll j: c){
            if(i-j < 0){
                continue;
            }

            dp[i] = (dp[i] + dp[i-j]) % (ll)(1e9+7); 
        }
    }

    cout << dp[x] << endl;
 
    return 0;
}