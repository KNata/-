#include "math.h"
#include "iostream"

// Natalia Kiselyk

using namespace std;

int i = 0;
int n = 0;
int k = 0;

int matrixSize = 0;

double z = 0.0;
double A[50][50];
double B[50];
double eps[50];
double X[50];
double et[50];

int main()
{
    cout << "Enter matrix size: ";
    cin >> matrixSize;
    
    cout << "Enter " << matrixSize << " lines  " << matrixSize << " numbers:" << endl;
    for (i = 0; i < matrixSize; i++)
    {
        for (k = 0; k < matrixSize; k++)
        {
            cin >> A[i][k];
        }
    }
    cout << "Matrix A: " << endl;
    for (i = 0; i < matrixSize; i++)
    {
        for (k = 0; k < matrixSize; k++)
        {
            cout << A[i][k] << "\t ";
        }
            cout << endl;
    }
    
    cout << "Enter " << matrixSize << " numbers:" << endl;
    for(i = 0; i < matrixSize; i++)
    {
        cin >> B[i];
    }
    cout<<"Matrix B:"<<endl;
    for (i = 0; i < matrixSize; i++)
    {
        cout << B[i] << endl;
    }
    n = matrixSize-1;
    eps[0] = -A[0][1]/A[0][0];
    et[0] = B[0] / A[0][0];
    
    for(i = 1; i < n; i++)
    {
        z = A[i][i] + A[i][i-1] * eps[i-1];
        eps[i] = -A[i][i+1] / z;
        et[i] = (B[i] - A[i][i-1] * et[i-1]) / z;
    }
    
    X[n] = (B[n] - A[n][n-1] * et[n-1]) / (A[n][n] + A[n][n-1] * eps[n-1]);
    
    for(i = n-1; i >= 0; i--)
    {
        X[i] = eps[i] * X[i+1] + et[i];
    }
    cout << "Result Matrix: " << endl;
    for(i = 0; i < matrixSize; i++)
    {
        cout << X[i] << endl;
    }
    return 0;
}