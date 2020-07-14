#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int ans = 0;
    int n, m;
    ll k, t;
    cin >> n >> m >> k;

    vector<ll> apartments, applicants;

    for(int i = 0; i < n; i++){
        cin >> t;
        applicants.push_back(t);
    }

    for(int i = 0; i < m; i++){
        cin >> t;
        apartments.push_back(t);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    auto last_unclaimed = apartments.begin();
    for(int i = 0; i < n; i++){
        auto re = lower_bound(last_unclaimed, apartments.end(), applicants[i]-k);
        if(abs(applicants[i] - *re) <= k){
            ans++;
            last_unclaimed = re + 1;
        }
    }

    cout << ans << endl;


    return 0;
}