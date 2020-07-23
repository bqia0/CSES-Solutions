#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmax = 100;
const int xmax = 1000;
const int Wmax = nmax * xmax;

// bool possible[Wmax+1];
bool dp[Wmax+1][nmax+1];

int main(){
    int n, t, W;
    W = 0;
    vector<int> coins;
    // vector<int> ans;
    set<int> ans;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> t;
        W += t;
        coins.push_back(t);
    }
    
    dp[0][0] = true;
    for(int i = 1; i <= W; i++)
        dp[i][0] = false;

    for(int k = 1; k <= n; k++){
        for(int x = 0; x <= W; x++){
            if(x - coins[k-1] >= 0)
                dp[x][k] = dp[x-coins[k-1]][k-1];
            dp[x][k] |= dp[x][k-1];
            if(dp[x][k] && x != 0)
                ans.insert(x);
        }
    }

    cout << ans.size() << endl;

    for(int d: ans){
        cout << d << " ";
    }
    return 0;
}

// int main(){
//     int n, t, W;
//     W = 0;
//     vector<int> coins;
//     vector<int> ans;
//     cin >> n;

//     for(int i = 0; i < n; i++){
//         cin >> t;
//         W += t;
//         coins.push_back(t);
//     }
//     // cout << __LINE__ << endl;
//     possible[0] = true;
//     possible[W] = true;
//     // cout << __LINE__ << endl;

//     for(int k = 0; k < n; k++){
//         for(int x = W; x >= 0; x--){
//             if(possible[x]){
//                 if(x+coins[k] <= W)
//                     possible[x+coins[k]] = true;
//             }
//         }
//     }
//     // cout << __LINE__ << endl;
//     for(int i = 1; i <= W; i++){
//         if(possible[i])
//             ans.push_back(i);
//     }

//     cout << ans.size() << endl;

//     for(int d: ans){
//         cout << d << " ";
//     }


    


//     return 0;
// }