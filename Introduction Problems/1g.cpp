#include <bits/stdc++.h>

using namespace std;

#define ll long long

/*
 * Correct but exceeds time
 */

// int main(){
//     int k, boardArea, it;

//     ll ans = 0;
//     ll curSols = 0;

//     cin >> k;

//     for(int i = 1; i <= k; i++){
//         ans = 0;
//         boardArea = i * i;
//         it = 1;
//         for(int y = 0; y < i; y++){
//             for(int x = 0; x < i; x++){
//                 // Place a knight on current square, count how many squares it doesn't attack
//                 curSols = boardArea - it;
//                 if(x + 2 < i && y + 1 < i){
//                     curSols--;
//                 }
//                 if(x + 1 < i && y + 2 < i){
//                     curSols--;
//                 }
//                 if(x - 2 >= 0 && y + 1 < i){
//                     curSols--;
//                 }  
//                 if(x - 1 >= 0 && y + 2 < i){
//                     curSols--;
//                 }     
//                 ans+= curSols;
//                 it++;
//             }
//         }
//         cout << ans << endl;
//     }

//     return 0;
// }

int main(){
    int k;
    cin >> k;
    ll boardArea;
    ll totalPossible;
    ll attackingConfigs;
    ll ans;

    for(int i = 1; i <= k; i++){
        boardArea = i*i;
        totalPossible = boardArea * (boardArea - 1) / 2;
        attackingConfigs = 4 * (i-1) * (i-2);
        ans = totalPossible - attackingConfigs;
        cout << ans << endl;
    }

    
    

    return 0;
}