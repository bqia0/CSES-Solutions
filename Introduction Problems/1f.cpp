#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll x, y, setn, setSize, start, end;

    int dir;

    cin >> y;
    cin >> x;

    setn = max(x, y);

    if(setn == 1){
        cout << 1 << endl;
        return;
    }

    setSize = 2 * setn - 1;

    dir = setn % 2;

    // 1 + sum(2i - 1) from i = 1 to setn - 1
    start = setn * setn - 2 * setn + 2;

    end = start + setSize - 1;

    if(dir == 0){
        if(x < y){
            // if dir == 0 and x < y, decreasing x increases value
            cout << end - x + 1 << endl;        
        }else if (x > y){
            // if dir == 0 and x > y, increasing y increases value
            cout << start + y - 1 << endl;
        }else{
            cout << (start + end)/2 << endl;
        }
    }else if (dir == 1){
        if(x < y){
            // if dir == 1 and x < y, increasing x increases value
            cout << start + x - 1 << endl;        
        }else if (x > y){
            // if dir == 1 and x > y, decreasing y increases value
            cout << end - y + 1 << endl;
        }else{
            cout << (start + end)/2 << endl;
        }        
    }

}

int main(){
    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}