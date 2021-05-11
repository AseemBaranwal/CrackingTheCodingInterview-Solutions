/* Programe to check whether a given string is a permutation of a palindrome*/
#include<bits/stdc++.h>
using namespace std;

bool solve(string st){
    vector<int> cnt(128);
    for(char x: cnt)
        cnt[x]++;
    int odd = 0;
    for(int x: cnt){
        if(x&1)
            odd++;
    }
    return odd<=1;
}

int main(){
    int t; cin >> t;
    while(t--){
        string st; getline(cin, st);
        bool res = solve(st);
        if(res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}