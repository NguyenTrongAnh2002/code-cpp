#include <iostream>

using namespace std;

int ucln(int p, int q)
{
    int r = p % q;
    while (r != 0)
    {
        p = q;
        q = r;
        r = p % q;
    }
    return q;
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