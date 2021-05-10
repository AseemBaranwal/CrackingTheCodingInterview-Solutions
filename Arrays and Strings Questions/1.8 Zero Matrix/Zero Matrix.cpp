/*
 * Cracking the coding interview 1.8
 * Problem : Write a space efficient algorithm, such that if an element in MxN is 0, the entire row and column containing it are 0.
 *
 * Approach:
 * We can use a boolean matrix of MxN or a bit vector to mark row and columns to be nullified in first iteration, but it wont be space efficient.
 * 
 * Space Complexity : O(N) additional space
 * Time Complexity : O(N*N)
 */
#include <bits/stdc++.h>
using namespace std;

void zerofy(int m, int n, int **matrix)
{
    vector<bool> row(m), col(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (row[i] == 1 or col[j] == 1)
                matrix[i][j] = 0;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **matrix = new int *[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    zerofy(m, n, matrix);
    //Printing result after change
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}