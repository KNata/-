//
//  main.cpp
//  ChebushevPolinomial
//
//  Created by Natalia on 12/1/15.
//  Copyright © 2015 Home. All rights reserved.
//


#include <cmath>
#include <iostream>

using namespace std;

double calculateA(int kIndex, double (*f)(double), double x, int n);

double f(double x)
{
    return acos(x);
}


double T0(double x)
{
    return 1.0 ;
}


inline double T1(double x)
{
    return x ;
}


double T2(double x)
{
    return (2.0 * x*x) - 1.0 ;
}


double Tn(unsigned int n, double x)
{
    if (n == 0.0)
    {
        return T0(x) ;
    }
    else if (n == 1.0)
    {
        return T1(x) ;
    }
    else if (n == 2.0)
    {
        return T2(x) ;
    }
    
    
    double tnm1(T2(x)) ;
    double tnm2(T1(x)) ;
    double tn(tnm1) ;
    
    for ( int l = 3 ; l <= n ; l++)
    {
        tn = (2.0 * x * tnm1) - tnm2 ;
        tnm2 = tnm1;
        tnm1 = tn;
    }
    
    return tn ;
}

double calculateChebushov(double (*f)(double), double x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += calculateA(i, f, x, n) * Tn(n, x);
    }
    return sum;
}


double calculateA(int kIndex, double (*f)(double), double x, int n)
{
    double aSum = 0;
    
    double factor = M_PI / (2.0 * n + 2.0);
    for (int i = 0; i < n; i++)
        {
            double  xi = cos (factor * (2.0 * i + 1.0));
            double tn = cos(kIndex * factor * (2.0 * i + 1.0));

            aSum += f(xi) * tn;
        }
    
    return (2.0 / (n+1.0)) * aSum;
}

int main(int argc, const char * argv[]) {
    
    double x;
    int n ;
    
//    cout<< "Enter x: " << endl;
//    cin >> x;
//    cout<< "Enter n: " << endl;
//    cin >> n;
    x = 0.7;
    n = 9;
    double result = calculateChebushov(&f, x, n);
    cout << "Result = " << result << endl;
    cout << acos(x) << endl;

    return 0;
}

