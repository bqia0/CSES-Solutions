#include <bits/stdc++.h>

using namespace std;

#define ll long long

// int main(){
//     int n;
//     int curr;
//     int diff;

//     int ans = 0;
//     vector<int> arr;
    
//     cin >> n;

//     for(int i = 0; i < n; i++){
//         cin >> curr;
//         arr.push_back(curr);
//     }

//     for(int i = 1; i < n; i++){
//         diff = max(0, arr[i-1] - arr[i]);
//         arr[i] += diff;
//         ans += diff;
//     }

//     cout << ans << endl;

//     return 0;
// }

/*
 * O(1) Space
 */

int main(){
    int n;
    ll curr;
    ll mx = -1;

    ll ans = 0;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> curr;
        mx = max(mx, curr);
        ans += mx - curr;
    }

    cout << ans << endl;

    return 0;
}