#include <iostream>

using namespace std;

int ucln(int p, int q)
{
    int r = p % q;
    if (r == 0)
        return q;
    else
        return ucln(q, r);
}

int main()
{
    int p, q;
    cout << "nhap p: ";
    cin >> p;
    cout << "nhap q: ";
    cin >> q;
    cout << " UCLN la: " << ucln(p, q);
}