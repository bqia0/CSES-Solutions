#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    string sequence;
    char start = 'z';
    ll maxLen, currLen;

    cin >> sequence;

    maxLen = 1;
    currLen = 1;

    for(auto it = sequence.cbegin(); it != sequence.cend(); it++){
        // cout << *it;
        if(*it != start){
            maxLen = max(maxLen, currLen);
            start = *it;
            currLen = 1;
        }else{
            currLen++;
        }
    }
    maxLen = max(maxLen, currLen);
    cout << maxLen << endl;

    return 0;
}