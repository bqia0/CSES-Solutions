#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    ll t;
    cin >> n;

    set<ll> e;

    for(int i = 0; i < n; i++){
        cin >> t;
        e.insert(t);
    }

    cout << e.size() << endl;
    return 0;
}