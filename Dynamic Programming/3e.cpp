#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    string c;
    int cn;
    cin >> n;

    vector<int> dp(n+1, INT_MAX);

    for(int i = 0; i <= 9; i++){
        dp[i] = 1;
    }

    for(int i = 10; i <= n; i++){
        c = to_string(i);
        for(auto it = c.begin(); it != c.end(); it++){
            if(*it == '0'){
                continue;
            }
            cn = *it - '0';
            dp[i] = min(dp[i], 1+dp[i-cn]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}