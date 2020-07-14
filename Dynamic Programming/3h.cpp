#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmx = 1e5;

ll dp[nmx];

int main(){
    int n, m, t;
    cin >> n >> m;
    vector<int> nums;

    for(int i = 0; i < n; i++){
        cin >> t;
        nums.push_back(t);
    }

    dp[n] = 1;

    return 0;
}