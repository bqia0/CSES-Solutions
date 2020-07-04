#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    string x;
    cin >> x;
    vector<string> p;

    sort(x.begin(), x.end()); 
  
    do { 
       p.push_back(x); 
    } while (next_permutation(x.begin(), x.end())); 

    cout << p.size() << endl;

    for(string d: p){
        cout << d << endl;
    }

    return 0;
}