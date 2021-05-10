/*URLify a given string (Replace spaces is %20)*/
#include<bits/stdc++.h>
using namespace std;

void solve(string &s){
    int spaces = 0, n = s.size();
    for(int x: s){
        if(x == ' ')
            spaces++;
    }
    int i = n-1;
    while(s[i] == ' '){
        spaces--;
        i--;
    }
    int index = i + 2*spaces;
    for(int j = i; j >= 0; j--){
        if(s[j] == ' '){
            s[index - 2] = '%';
            s[index - 1] = '2';
            s[index] = '0';
            index -= 3;
        }else{
            s[index] = s[j];
            index--;
        }
    }
}

int main(){
    string s; getline(cin, s);
    solve(s);
    cout << s;
    return 0;
}