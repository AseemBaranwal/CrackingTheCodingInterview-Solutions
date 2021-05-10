/*
 * Problem 1.6 Implement a method to perform basic string compression.
 * Example string aabcccccaaa should be compressed to a2b1c5a3,
 * however if compressed string is bigger than original string, return original string
 */
#include <bits/stdc++.h>
using namespace std;

string stringCompress(string str)
{
    bool changed = false;
    string res;
    int n = str.size(), i = 0;
    while (i < n)
    {
        int cnt = 1;
        while (i + 1 < n and str[i] == str[i + 1])
        {
            changed = true;
            cnt++, i++;
        }
        res += str[i] + to_string(cnt);
        i++;
    }
    return changed ? res : str;
}

int main()
{
    string str;
    cin >> str;
    cout << stringCompress(str) << endl;
    return 0;
}