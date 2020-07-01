#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;

    int found = 0;

    vector<int> p;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        p.push_back(i+1);
    }

    do {
        for(int i = 1; i < n; i++){
            if(p[i] - p[i-1] == 1 || p[i] - p[i-1] == -1){
                break;
            }
            if(i+1 == n){
                found = 1;
            }
        }

        if(found){
            for(int d: p){
                cout << d << " ";
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(p.begin(),p.end()));

    cout << "NO SOLUTION" << endl;
    return 0;
}