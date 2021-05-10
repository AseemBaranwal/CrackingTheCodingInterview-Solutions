/* Implement an algorithm to determine if a string has all unique characters 
ASSUMPTION:: The given string is ASCII */
#include<bits/stdc++.h>
using namespace std;

bool solve(string s){
    vector<bool> cnt(128);
    for(char x: s){
        int ascii = (int)x;
        if(cnt[ascii])
            return false;
        cnt[ascii] = true;
    }
    return true;
}

int main(){
    string s; cin >> s;
    bool res = solve(s);
    if(res)
        cout << "Yes";
    else
        cout << "No";
}