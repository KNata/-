#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f1(double c)//новая функция фи
{
    double z=7/(2*c+6);
    return(pow(10, z));
}

int main()
{
    int n=0;
    double a,b,E,x,z,g;
    
    cout<<"vvedite a"<<endl;
    cin>>a;
    cout<<"vvedite b"<<endl;
    cin>>b;
    cout<<"vvedite E"<<endl;
    cin>>E;
    
    
    x=(a+b)/2;
    do
    {
        z=x;
        x=f1(x);
        n++;
    }
    while ((fabs(x-z))>=E);
    
    cout<<endl;
    cout<<"x="<<x<<endl;
    cout<<"n="<<n<<endl;
    return 0;
}