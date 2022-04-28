#include <iostream>

using namespace std;

int fibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
        return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n;
    cout << "nhap so n: ";
    cin >> n;
    cout << "F= " << fibo(n) << endl;
    cout << " day fibonaci vua nhap la : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << fibo(i + 1) << "  ";
    }
}