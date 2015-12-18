#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void solve(const vector<float> matrix, //квадратна матриця
           const vector<float> vectorB, //вектор вільних елементів
           vector<float>& x, //сюди буде записано розв'язок
           const float eps) //допустима похибка
{
    const unsigned n = x.size();
    vector<float> tmp_x(n);
    
    float error;
    
    do
    {
        error = 0;
        
        tmp_x = vectorB;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    tmp_x[i] -= matrix[i * n + j] * x[j];
                }
            }
            
            //оновити x[i] та порахувати похибку
            const float x_updated = tmp_x[i] / matrix[i * (n + 1)];
            const float e = fabs(x[i] - x_updated);
            x[i] = x_updated;
            if (e > error) { error = e; }
        }
    }
    while (error > eps);
}

//приклад використання. Користувач вводить вхідні дані.
int main()
{
    unsigned n;
    
    cout << "\nВведіть розмір сиcтеми:\nn = ";
    cin >> n;
    
    vector<float> x(n);
    vector<float> a(n * n);
    vector<float> b(n);
    
    cout << "\nВведіть вектор вільних елементів: \n";
    for (auto& b_elem : b)
    {
        cin >> b_elem;
    }
    
    cout << "\nВведіть коефіцієнти системи: \n";
    for (auto& a_elem : a)
    {
        cin >> a_elem;
    }
    
    float allowed_error;
    cout << "\nВведіть допустиму похибку: \n";
    cin >> allowed_error;
    
    solve(a, b, x, allowed_error);
    
    cout << "\nРозвязок ситеми:: \n";
    for (unsigned i = 0; i < n; ++i)
    {
        cout << "\nx[" << i << "]=  " << x[i];
    }
}