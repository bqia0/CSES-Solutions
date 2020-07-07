#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    ll t;
    ll totalSum = 0;
    ll p1Sum = 0;
    ll p2Sum = 0;
    ll minDiff = LLONG_MAX;
    cin >> n;

    vector<ll> apples;

    for(int i = 0; i < n; i++){
        cin >> t;
        apples.push_back(t);
        totalSum+=t;
    }

    // Iterate over all subsets
    for(int b = 0; b < (1 << n); b++){
        p1Sum = 0;
        for(int i = 0; i < n; i++){
            // Is element i in subset?
            if((1 << i) & b){
                p1Sum += apples[i];
            }
        }
        p2Sum = totalSum - p1Sum;
        minDiff = min(minDiff, abs(p1Sum - p2Sum));
    }

    cout << minDiff << endl;

    return 0;
}