/**
 * Cracking the coding interview 1.9
 * Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to "isSubstring".
 *
 * Approach:
 * example s1 = "waterbottle", and s2 = "erbottlewat", clearly s2 is rotation of s1.
 * lets say s1 = xy ==> wat + erbottle
 * similarly s2 = yx ==> erbottle + wat
 * Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
 * So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.
 */
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ALL(v) v.begin(), v.end()
#define REP(i,a,n) for(int i=a;i<=n;++i)

void solve(){
    string s1, s2;
    getline(cin >> ws, s1);
    getline(cin >> ws, s2);
    string s1s1 = s1 + s1;
    bool isRotation = s1s1.find(s2) != string::npos; // Check for substring
    if(isRotation)
        cout << "Rotation" << endl;
    else
        cout << "Not a rotation" << endl;
}

signed main(){
    fastio
    int t; cin >> t;
    while(t--){ 
        solve();
    }
}