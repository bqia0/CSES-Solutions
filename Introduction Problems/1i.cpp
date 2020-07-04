#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n;
    cin >> n;

    ll ans = 1;

    // https://en.wikipedia.org/wiki/Modular_exponentiation#Memory-efficient_method
    for(ll i = 0; i < n; i++){
        ans = ans * 2 % (ll)(1e9+7);
    }

    cout << ans << endl;
    return 0;
}