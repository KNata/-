#include<iostream>
#include<cmath>

using namespace std;

double f(double x)
{
    return 1/(4*sqrt(x+2) + 8);
}

int main()
{
    int n = 0;
    int i = 0;
    double a = 0.0;
    double b = 0.0;
    double h = 0;
    double sum = 0.0;
    double result = 0;
    
    cout << "Enter a = " << endl;
    cin >> a;
    cout << "b = " << endl;
    cin >> b;
    cout << "Enter n = " << endl;
    cin >> n;
    
    double x[n+1];
    double y[n+1];
    
    h = (b - a) / n;
    
    for (i = 0; i < n+1; i++)
    {
        x[i] = a + i*h;
        y[i] = f(x[i]);
    }
    
    for (i = 1; i < n; i+=2)
    {
        sum = sum + 4*y[i];
    }
    for (i = 2; i < n-1; i+=2)
    {
        sum = sum + 2*y[i];
        
    }
    result = h/3 * (y[0] + y[n] + sum);
    cout<<"Result = "<<result<<endl;
    return 0;
}