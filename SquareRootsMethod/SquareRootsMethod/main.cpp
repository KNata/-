#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    float A[10][10];
    float U[10][10];
    float b[10];
    float x[10];
    float y[10];
    int n = 0;
    int k = 0;
    int i = 0;
    int j = 0;
    float temp;
    cout << "введіть розмірність матриці" << endl;
    cin >> n;
label:
    cout << "введіть елементи симетричної  матриці " << n << "x" << n << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            U[i][j] = 0;
        }
    }
    // check if matrix is simetric
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                cout << "матриця не симетрична" << endl;
                goto label;
            }
        }
    }
    cout << "введіть елементи вектора b" << n << "x" << n << endl;
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int k = 0; k < i; k++)
        {
            temp = temp + U[k][i] * U[k][i];
        }
        U[i][i] = sqrt(A[i][i] - temp);
        for (j = i; j < n; j++)
        {
            temp = 0;
            for (k = 0; k < i; k++)
                temp = temp + U[k][i] * U[k][j];
            U[i][j] = (A[i][j] - temp) / U[i][i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
        {
            cout << U[i][j]<<" ";
        }
        cout << endl;
    }
    for (i = 0; i < n; i++)
    {
        temp = 0;
        for (int k = 0; k < i; k++)
        {
            temp = temp + U[k][i] * y[k];
        }
        y[i] = (b[i] - temp) / U[i][i];
    }
    for (i = n - 1; i >= 0; i--)
    {
        temp = 0;
        for (int k = i + 1; k < n; k++)
        {
            temp = temp + U[i][k] * x[k];
        }
        x[i] = (y[i] - temp) / U[i][i];
    }
    for (i = 0; i < n; i++)
    {
        cout << "x" << i << "= " << x[i] << endl;
    }
}