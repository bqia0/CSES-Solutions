#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n;
    ll ans = 0;
    ll div5 = 5;

    cin >> n;

    while(div5 <= n){
        ans += n / div5;
        div5 *= 5;
    }

    cout << ans << endl;
    return 0;
}