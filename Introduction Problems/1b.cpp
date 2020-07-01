#include <bits/stdc++.h>

using namespace std;

#define ll long long

//(1 ^ 2 ^ 3) ^ (1 ^ 3) = (1 ^ 1) ^ (3 ^ 3) ^ 2 = 0 ^ 0 ^ 2 = 2

int main(){
    ll n, temp;
    ll x = 0;

    cin >> n;

    for(ll i = 1; i <= n; i++){
        x ^= i;
    }

    for(ll i = 0; i < n-1; i++){
        cin >> temp;
        x ^= temp;
    }
    cout << x << endl;

    return 0;
}