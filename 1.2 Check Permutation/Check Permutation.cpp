/*Check if given two strings are permutation of each other */
#include<bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    vector<int> cnt(126);
    for(char x: s1){
        int ascii = (int) x;
        cnt[ascii] ++;
    }
    for(char x: s2){
        int ascii = (int) x;
        cnt[ascii] --;
        if(cnt[ascii] < 0) return false;
    }
    return true;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    bool res = solve(s1, s2);
    if(res)
        cout << "Yes";
    else
        cout << "No";
        return 0;
}