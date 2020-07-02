#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;

    vector<int> s1, s2;

    if(n*(n+1) / 2 % 2 != 0 || n == 0){
        cout << "NO" << endl;
        return 0;
    }


    // Possible if n % 4 is 0 or 3
    if(n % 4 == 3){
        // Base case n = 3
        s1.push_back(1);
        s1.push_back(2);
        s2.push_back(3);

        // Inductive step: s1 <- s1 U {n+1, n+4}, s2 <- s2 U {n+2, n+3}
        // This works because (n+1) + (n+4) = (n+2) + (n+3)
        for(int i = 3; i < n; i+=4){
            s1.push_back(i + 1);
            s1.push_back(i + 4);
            s2.push_back(i + 2);
            s2.push_back(i + 3);
        }
    }else if (n % 4 == 0){
        // Base case n = 4
        s1.push_back(1);
        s1.push_back(4);
        s2.push_back(2);
        s2.push_back(3);

        // Inductive step: s1 <- s1 U {n+1, n+4}, s2 <- s2 U {n+2, n+3}
        // This works because (n+1) + (n+4) = (n+2) + (n+3)
        for(int i = 4; i < n; i+=4){
            s1.push_back(i + 1);
            s1.push_back(i + 4);
            s2.push_back(i + 2);
            s2.push_back(i + 3);
        }
    }

    cout << "YES" << endl;

    cout << s1.size() << endl;
    for(int d: s1)
        cout << d << " ";
    cout << endl;

    cout << s2.size() << endl;
    for(int d: s2)
        cout << d << " ";
    cout << endl;


    return 0;
}