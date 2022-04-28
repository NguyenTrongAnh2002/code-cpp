#include <iostream>

using namespace std;

class MATRAN
{
    int **a;
    int m, n;

public:
    MATRAN operator++();
    MATRAN operator--();
    friend ostream &operator<<(ostream &out, MATRAN y)
    {
        for (int i = 0; i < y.m; i++)
        {
            for (int j = 0; j < y.n; j++)
            {
                cout << "\t" << y.a[i][j];
            }
            cout << endl;
        }
    }
    friend istream &operator>>(istream &in, MATRAN &y)
    {
        for (int i = 0; i < y.m; i++)
        {
            cout << "nhap dong thu" << i + 1 << endl;
            for (int j = 0; j < y.n; j++)
            {
                cout << "\ta[" << i << "][" << j << "] = ";
                cin >> y.a[i][j];
            }
        }
    }
};
MATRAN MATRAN::operator++()
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
    return *this;
}
MATRAN MATRAN::operator--()
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
    return *this;
}
istream &operator>>(istream &in, MATRAN &y)
{
    cout << "n=";
    in >> y.n;
    cout << "m=";
    in >> y.m;
    y.a = new int[y.n][y.m];
    for (int i = 0; i < y.n; i++)
    {
        for (int j = i + 1; j < y.n; j++)
        {
            cout << "a[" << i << "]=";
            cin >> y.a[i][j];
        }
    }
    return in;
}
ostream &operator<<(ostream &out, MATRAN y)
{
    for (int i = 0; i < y.n; i++)
    {
        for (int j = i + 1; j < y.n; j++)
        {
            cout << y.a[i][j] << " ";
            return out;
        }
    }
}

int main()
{
    MATRAN x;
    cout << "Nhap mang x:" << endl;
    cin >> x;
    cout << x;
    x = ++x;
    cout << "Mang x da sap tang: " << endl;
    cout << x << endl;
    x = --x;
    cout << "Mang x da sap giam:" << endl;
    cout << x << endl;
    return 0;
}