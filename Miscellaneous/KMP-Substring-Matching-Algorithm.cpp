/* String Matching algorithm KMP
 * Link : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
 * Video : https://www.youtube.com/watch?v=V5-7GzOfADQ
 * Time : O(N+M)
 * Space : O(M)
*/
#include <bits/stdc++.h>
using namespace std;

void calculateLPS(int lps[], string str)
{
    int i = 1, len = 0;
    lps[0] = 0;
    while (i < str.size()){
        if (str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if (len != 0)
                len = lps[len - 1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void solve(){
    string s1, s2; getline(cin >> ws, s1); getline(cin >> ws, s2);
    if (s1.size() < s2.size())
        swap(s1, s2);
    int lps[s2.size()];
    calculateLPS(lps, s2);
    vector<int> res;
    int i = 0, j = 0;
    while (i < s1.size()){
        if (s1[i] == s2[j])
            i++, j++;
        if (j == s2.size()){
            res.push_back(i-j);
            j = lps[j - 1];
        }else if (i < s1.size() and s1[i] != s2[j]){
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
    for (int x : res)
        cout << x << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(t--)
        solve();
    return 0;
}