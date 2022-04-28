#include <iostream>

using namespace std;

class MATRAN
{
    double **a;
    int n, m;

public:
    friend istream &operator>>(istream &x, MATRAN &y)
    {
        cout << "nhap so hang va cot: ";
        cin >> y.n >> y.m;
        y.a = new double *[y.n];
        for (int i = 0; i < y.n; i++)
            y.a[i] = new double[y.m];
        for (int i = 0; i < y.n; i++)
        {
            for (int j = 0; j < y.m; j++)
            {
                cout << "a[" << i + 1 << "]"
                     << "[" << j + 1 << "]= ";
                cin >> y.a[i][j];
            }
        }
        return x;
    }
    friend ostream &operator<<(ostream &out, MATRAN y)
    {
        for (int i = 0; i < y.n; i++)
        {
            for (int j = 0; j < y.m; j++)
            {
                cout << y.a[i][j] << " ";
            }
            cout << "\n";
        }
        return out;
    }
    MATRAN operator+(MATRAN y);
};
MATRAN MATRAN ::operator+(MATRAN y)
{
    MATRAN tg;
    if (m == y.m && n == y.n)
    {
        tg.n = n;
        tg.m = m;
        tg.a = new double *[n];
        for (int i = 0; i < n; i++)
        {
            tg.a[i] = new double[m];
        }
        for (int i = 0; i < y.n; i++)
            for (int j = 0; j < y.m; j++)
            {
                tg.a[i][j] = a[i][j] + y.a[i][j];
            }
    }
    else
        cout << "ma tran khong cung kich thuoc!" << endl;
    return tg;
}
int main()
{
    MATRAN x, y, tg;
    cout << "nhap ma tran x: " << endl;
    cin >> x;
    cout << x;
    cout << "nhap ma tran y: " << endl;
    cin >> y;
    cout << y;
    tg = x + y;
    cout << "\nma tran sau khi cong la:\n"
         << tg;
}