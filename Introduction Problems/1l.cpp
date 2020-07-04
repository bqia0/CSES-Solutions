#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    string x;
    string ans = "";
    bool singleFound = false;
    vector<int> charMap(26, 0);
    cin >> x;


    for(char d: x){
        charMap[d - 'A']++;
    }

    for(size_t i = 0; i < charMap.size(); i++){
        if(charMap[i] % 2 == 0){
            ans.insert(0, charMap[i] / 2, i+'A');
            ans.append(charMap[i] / 2, i+'A');
        }else{
            if(!singleFound){
                singleFound = true;
                ans.insert(ans.size() / 2, charMap[i], i+'A');
            }else{
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}