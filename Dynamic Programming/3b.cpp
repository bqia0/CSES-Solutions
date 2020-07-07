#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n, x, t;
    cin >> n >> x;
    vector<int> c;
    vector<int> dp(x+1, -1);

    for(int i = 0; i < n; i++){
        cin >> t;
        c.push_back(t);
        if(t <= x)
            dp[t] = 1;
    }

    for(int i = 1; i <= x; i++){
        for(int coin: c){
            if(i - coin  <= 0)
                continue;
            if(dp[i - coin] != -1){
                if(dp[i] == -1)
                    dp[i] = dp[i-coin] + 1;
                else
                    dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
    }

    // for(int d: dp)
    //     cout << d << " ";

    cout << dp[x] << endl;


    return 0;
}