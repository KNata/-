#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return 1/(4*sqrt(x+2) + 8);
}

int main()
{
    double a = 0.0;
    double b = 0.0;
    int n = 0;
    double result = 0.0;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "Enter n: " << endl;
    cin >> n;
    
    double h = double((b - a) / n);
    for (double i = a; i <= b; i+=h)
    {
        result += f(i - h / 2);
    }
    result *= h;
    
    cout << "Result = " <<result << endl;
    return 0;
}