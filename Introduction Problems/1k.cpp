#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll p1, p2;
    cin >> p1;
    cin >> p2;

    // p1 = 2x + y
    // p2 = x + 2y
    // 2*p2 - p1 = 3y
    // 2*p1 - p2 = 3x
    
    if((2*p2 - p1)%3==0 && 2*p2 >= p1 && (2*p1 - p2)%3==0 && 2*p1 >= p2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}