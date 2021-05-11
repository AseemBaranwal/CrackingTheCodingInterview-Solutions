/*
 * Cracking the coding interview edition 6
 * Problem 1.7 Rotate a matrix by 90' clockwise ( or anticlockwise).
 * Solution : I have done it two ways.
 * Approach: Take transpose of matrix and then reverse the rows for clockwise 90' rotation.
 * 			   Obviously if we reverse the columns we will get anticlockwise 90' rotation.
 */
#include <bits/stdc++.h>
using namespace std;

void rotateBy90(int n, int **matrix)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (i != j)
                swap(matrix[i][j], matrix[j][i]);
    int i = 0, j = n - 1;
    while (i < j)
    {
        for (int k = 0; k < n; k++)
            swap(matrix[k][i], matrix[k][j]);
        i++, j--;
    }
}

int main()
{
    int n;
    cin >> n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    rotateBy90(n, matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}