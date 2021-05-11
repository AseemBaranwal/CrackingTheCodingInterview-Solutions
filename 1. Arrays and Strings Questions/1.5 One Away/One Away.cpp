/* 
 * Problem: There are three possible edits that can be performed on a string.
 * 1. Insert a char.
 * 2. Delete a char.
 * 3. Replace a char.
 *
 * Given two strings, determine if they are one or 0 edit away.
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool checkOneAway(string str1, string str2)
{
    int m = str1.size(), n = str2.size();
    if (abs(m - n) > 1)
        return false;
    if (m < n)
    {
        swap(str1, str2);
        swap(m, n);
    }
    int i = 0, j = 0;
    bool changePossible = true;
    while (i < m and j < n)
    {
        if (str1[i] != str2[j] and changePossible)
        {
            changePossible = false;
            if (m > n)
            {
                i++;
                continue;
            }
        }
        else if (!changePossible and str1[i] != str2[j])
            return false;
        i++, j++;
    }
    if (i < m and changePossible)
        i++;
    return i == m and j == n;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bool res = checkOneAway(s1, s2);
    if (res)
        cout << "One Away";
    else
        cout << "Not one away";
    return 0;
}