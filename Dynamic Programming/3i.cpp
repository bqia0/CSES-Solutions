#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int nxm = 5000;

int dp[nxm][nxm];


int main(){
    string a, b;
    int n, m, replace;
    cin >> a >> b;

    n = a.size();
    m = b.size();



    for(int i = 0; i <= n; i++){
        dp[0][i] = i;
    }
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }

    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            replace = a[i-1] != b[j-1] ? 1 : 0;
            replace += dp[j-1][i-1];
            dp[j][i] = min({replace, dp[j-1][i] + 1, dp[j][i-1] + 1});
            // cout << j << " " << i << " " << dp[j][i] << endl;
        }
    }

    // for(int j = 0; j <= m; j++){
    //     for(int i = 0; i <= n; i++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[m][n] << endl;

    return 0;
}