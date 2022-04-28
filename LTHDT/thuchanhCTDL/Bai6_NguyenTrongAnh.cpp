#include <iostream>

using namespace std;

int f(int *a, int left, int right, int x)
{
    if (left > right)
        return 0;
    else if (left == right)
    {
        if (a[left] == x)
            return 1;
        else
            return 0;
    }
    else
    {
        int mid = (left + right) / 2;
        return f(a, left, mid, x) + f(a, mid + 1, right, x);
    }
}
int main()
{
    int *a;
    int x;
    cout << "nhap so x= ";
    cin >> x;
    int n;
    a = new int[n];
    cout << "nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan tu thu " << i + 1 << ": ";
        cin >> *(a + i);
    }
    cout << "so lan xuat hien=" << f(a, 0, n - 1, x);
}