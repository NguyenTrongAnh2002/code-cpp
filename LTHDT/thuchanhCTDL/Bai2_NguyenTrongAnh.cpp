#include <iostream>

using namespace std;

void chuyen(int n, char a, char b, char c)
{
    int dem = 0;
    if (n == 1)
    {
        cout << a << "---sang--->" << c << endl;
        return;
    }
    chuyen(n - 1, a, b, c);
    chuyen(1, a, b, c);
    chuyen(n - 1, b, a, c);
    dem++;
}
int main()
{
    char a = 'A';
    char b = 'B';
    char c = 'C';
    int n;
    cout << "nhap n: ";
    cin >> n;
    chuyen(n, a, b, c);
}