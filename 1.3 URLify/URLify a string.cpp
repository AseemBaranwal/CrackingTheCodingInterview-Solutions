/*URLify a given string (Replace spaces is %20)*/
#include<bits/stdc++.h>
using namespace std;
const int mx = 1000;
void solve(char s[]){
    int spaces = 0, i;
    for(i = 0; s[i]; i++){
        if(s[i] == ' ')
            spaces++;
    }
    while(s[i-1] == ' '){
        i--;
        spaces--;
    }
    int new_len = i + 1 + 2*spaces;
    int index = new_len - 1;
    s[index--] = '\0';
    for(int j = i-1; j >= 0; j--){
        if(s[j] == ' '){
            s[index - 2] = '%';
            s[index - 1] = '2';
            s[index] = '0';
            index -= 2;
        }else{
            s[index] = s[j];
        }
        index--;
    }
}

int main(){
    char s[mx];
    cin.getline(s, mx);
    solve(s);
    cout << s;
    return 0;
}