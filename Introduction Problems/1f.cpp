#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll x, y;
    ll ans = 0;
    cin >> y;
    cin >> x;

    ans += (y-1) * 5 + x;

    cout << ans << endl;


}

int main(){
    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}