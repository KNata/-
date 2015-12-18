#include <cmath>
#include <iostream>

using namespace std;

float trapezoidMethod(float a, float b, int nsub, float (*f)(float) )
{
    float psum = f(a) + f(b);
    float deltaX = (b - a) / nsub;
    
    for(int i = 1; i < nsub; i++)
    {
        psum = psum + 2.0 * f(a + i*deltaX);
    }
    
    psum = (deltaX / 2.0) * psum;
    return psum;
}


float f(float x)
{
    
    return 1/(4*sqrt(x+2) + 8);
}

int main()
{
    double a = 0.0;
    double b = 0.0;
    int n = 0;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << "Result = " << trapezoidMethod(a, b, n, &f) << endl;
    return 0;
}