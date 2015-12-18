#include <iostream>
#include "cmath"

using namespace std;

int main()
{
    double matrix[3][3];
    double b_vek[3];
    double x[3];
    double x_k[3];
    double r[3];
    double const e = 0.00001;
    
    // matrix initilization
    matrix[0][0] = 0.67;
    matrix[0][1] = 0.167;
    matrix[0][2] = 0.0;
    matrix[0][3] = 0.0;
    matrix[1][0] = 0.167;
    matrix[1][1] = 0.67;
    matrix[1][2] = 0.167;
    matrix[1][3] = 0.0;
    matrix[2][0] = 0.0;
    matrix[2][1] = 0.167;
    matrix[2][2] = 0.67;
    matrix[2][3] = 0.167;
    matrix[3][0] = 0.0;
    matrix[3][1] = 0.0;
    matrix[3][2] = 0.167;
    matrix[3][3] = 0.67;
    
    
    b_vek[0] = 0.42;
    b_vek[1] = 0.5;
    b_vek[2] = 0.5;
    b_vek[3] = 0.5;
    
    x[0] = b_vek[0];
    x[1] = b_vek[1];
    x[2] = b_vek[2];
    x[3] = b_vek[3];

    
    int n = 3;
    cout << "Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout<<" " << b_vek[i] << endl;
    };
    cout << " " << endl;
    double maxValue = 10000000000.0;
    int iteraction = 0;
    while (maxValue > e)
    {
        x_k[0] = (b_vek[0] - x[1] * matrix[0][1] - x[2] * matrix[0][2] - x[3] * matrix[0][3]) / matrix[0][0];
        x_k[1] = (b_vek[1] - x_k[0] * matrix[1][0] - x[2] * matrix[1][2] - x[3] * matrix[1][3]) / matrix[1][1];
        x_k[2] = (b_vek[2] - x_k[0] * matrix[2][0] - x_k[1] * matrix[2][1] - x[3] * matrix[2][3]) / matrix[2][2];
        x_k[3] = (b_vek[3] - x_k[0] * matrix[3][0] - x_k[1] * matrix[3][1] - x_k[2] * matrix[3][2]) / matrix[3][3];
        
        maxValue = abs(x_k[0] - x[0]);
        for (int i = 1; i < n; i++)
        {
            if (abs(x_k[i] - x[i]) > maxValue)
            {
                maxValue = abs(x_k[i] - x[i]);
            }
        };
        
        for (int i = 0; i < n; i++)
        {
            x[i] = x_k[i];
            
            r[i] = b_vek[i] - matrix[i][0] * x[0] - matrix[i][1] * x[1] - matrix[i][2] * x[2] - matrix[i][3] * x[3];
            cout <<" Result = " << r[i] << endl;
            cout << " " << endl;
        };
        cout << "End of № "<< iteraction <<" iteraction  "<<endl;
        cout << " " << endl;
        iteraction++;
    };
    
    
    cout<<"Total result: "<<endl;
    cout << " " << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << "X" << i << " = " << x[i] << endl;
    };
    
    return 0;
}