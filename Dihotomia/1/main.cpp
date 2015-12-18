#include <iostream>
#include <math.h>

using namespace std;

    double f(double x)
    {
        return pow(x, 3.0) - 0.2 * x * x + 0.5 * x - 1;
    }

int main()
{
    const double eps = 0.0001;
    double a = 2.3;
    double b = 0.0;
    double t = 0.0;
    double f1 = 0.0;
    double f2 = 0.0;
    double x = 0.0;
    
    while (fabs(b - a) > eps)
    {
        f1 = f(a);
        t = (a + b) / 2.0;
        f2 = f(t);
        if (f1 * f2 <= 0)
        {
            b = t;
        }
        else
        {
            a = t;
        }
    }
    
    x = (a + b) / 2.0;
    f1 = f(x);
    if (fabs(f1) <= eps)
    {
        cout << "X= " << x << endl;

        cout << "F(X)= " << f1 << endl;
    }
    else
    {
        cout << "No roots in this line " << endl;
    }
        return 0;
}