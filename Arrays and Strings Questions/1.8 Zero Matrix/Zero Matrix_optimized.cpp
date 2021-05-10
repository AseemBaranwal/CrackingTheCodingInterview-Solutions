/*
 * Cracking the coding interview 1.8
 * Problem : Write a space efficient algorithm, such that if an element in MxN is 0, the entire row and column containing it are 0.
 *
 * Approach:
 * More space efficient would be to first check first row and column and if any of them contains zero, mark them to be nullified using two boolearn vars
 * let's say col0, and then iterate through rest of the matrix and store information in first row column elements, only when that row
 * and column is to be marked for nullified, this way we will only change values in first row and column which are already going to be 0 in final solution. 
 * 
 * Space Complexity : O(1) additional space
 * Time Complexity : O(N*N)
 */
#include <bits/stdc++.h>
using namespace std;

void zerofy(int m, int n, int **matrix)
{
    bool col0 = false;
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
            col0 = true;
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
                matrix[0][j] = matrix[i][0] = 0;
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (matrix[0][j] == 0 or matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
        if (col0)
            matrix[i][0] = 0;
    }
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