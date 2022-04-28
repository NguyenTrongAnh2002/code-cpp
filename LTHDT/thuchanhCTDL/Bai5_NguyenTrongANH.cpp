#include <iostream>

using namespace std;

long power(int a, int n)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        long x = power(a, n / 2);
        if (n % 2 == 0)
        {
            return x * x;
        }
        else
            return x * x * a;
    }
}
int main()
{
    int a, n;
    cout << "nhap co so a= ";
    cin >> a;
    cout << "nhap so mu n= ";
    cin >> n;
    cout << a << " mu " << n << "= " << power(a, n);
}