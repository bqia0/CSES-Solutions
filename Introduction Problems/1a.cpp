#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n;

    cin >> n;

    while(n != 1){
        cout << n << " ";
        if(n % 2 == 0){
            n/=2;
        }else{
            n*=3;
            n++;
        }
    }
    cout << n << endl;

    return 0;
}