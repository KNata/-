#include <iostream>
#include <cmath>
using namespace std;

#define eps 0.0001

double function1(double x, double y)
{
    return sin(x + y) - 1.2*x;
}

double function2(double x, double y)
{
    return x*x + y*y - 1;
}

double function11(double x, double y)
{
    return cos(x + y) - 1.2;
}

double function12(double x, double y)
{
    return cos(x + y);
}

double function21(double x, double y)
{
    return 2*x;
}

double function22(double x, double y)
{
    return 2*y;
}

void ober_matr(double a[2][2])
{
    double det = 0.0;
    double aa = 0.0;
    if (det != 0.0 && a[0][0] != 0.0)
    {
        det = a[0][0] * a[1][1] - a[0][1] *a [1][0];
        aa = a[0][0];
        a[0][0] = a[1][1] / det;
        a[1][1] = aa / det;
        aa = a[0][1];
        a[0][1] = -a[0][1] / det;
        a[1][0] = -a[1][0] / det;
    }
}

void newtonMethod(double x, double y)
{
    int i = 1;
    double a[2][2];
    double dx = 0.0;
    double dy = 0.0;
    double b[2];
    double norm = 0;;
    do
    {
        a[0][0] = function11(x, y);
        a[0][1] = function12(x, y);
        a[1][0] = function21(x, y);
        a[1][1] = function22(x, y);
              ober_matr(a);
        dx = -a[0][0]*function1(x, y) + -a[0][1]*function2(x, y);
        dy = -a[1][0]*function1(x, y) + -a[1][1]*function2(x, y);
        x = x + dx;
        y = y + dy;
        b[0] = function1(x, y);
        b[1] = function2(x, y);
        norm = sqrt(b[0]*b[0]+b[1]*b[1]);
        i++;
    }
    while (norm >= eps);
    
    cout << x << endl << y << endl;
}
int main()
{
    double x = 0.0;
    double y = 0.0;
    cout << "Please, enter x = ";
    cin >> x;
    cout << "Please, enter y = ";
    cin >> y;
    newtonMethod(x, y);
    cout << endl;
    return 0;
}