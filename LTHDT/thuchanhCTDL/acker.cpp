#include <iostream>
#include <math.h>

using namespace std;

int Acker(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return Acker(m - 1, 1);
    }
    else
        return Acker(m - 1, Acker(m, n - 1));
}
int main()
{
    int m, n;
    cout << "nhap m: ";
    cin >> m;
    cout << "nhap n: ";
    cin >> n;
    cout << "F= " << Acker(m, n);
}