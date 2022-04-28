#include <iostream>
using namespace std;

class Matrix
{
private:
    double **a;
    int m, n;

public:
    Matrix operator--();
    Matrix operator-(Matrix b);
    friend istream &operator>>(istream &is, Matrix &b);
    friend ostream &operator<<(ostream &os, Matrix b);
};
istream &operator>>(istream &is, Matrix &b)
{
    cout << "nhap m: ";
    do
    {
        cin >> b.m;
    } while (b.m <= 0);
    cout << "nhap n: ";
    do
    {
        cin >> b.n;
    } while (b.n <= 0);
    b.a = new double *[b.m];
    for (int i = 0; i < b.m; i++)
    {
        b.a[i] = new double[b.n];
    }
    for (int i = 0; i < b.m; i++)
    {
        for (int j = 0; j < b.n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> b.a[i][j];
        }
    }
    return is;
}
ostream &operator<<(ostream &os, Matrix b)
{
    for (int i = 0; i < b.m; i++)
    {
        for (int j = 0; j < b.n; j++)
        {
            cout << b.a[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}
Matrix Matrix::operator--()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = -a[i][j];
        }
    }
}

Matrix Matrix::operator-(Matrix b)
{
    Matrix c;
    if (m == b.m && n == b.n)
    {
        c.m = m;
        c.n = n;
        c.a = new double *[m];
        for (int i = 0; i < m; i++)
        {
            c.a[i] = new double[n];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c.a[i][j] = a[i][j] - b.a[i][j];
            }
        }
    }
    else
    {
        cout << "2 ma tran khong bang nhau" << endl;
    }
    return c;
}

int main()
{
    Matrix P, Q;
    cout << "nhap P" << endl;
    cin >> P;
    cout << "nhap Q" << endl;
    cin >> Q;
    --P;
    --Q;
    cout << "MA TRAN P: " << endl;
    cout << P << endl;
    cout << "MA TRAN Q: " << endl;
    cout << Q << endl;
    cout << "Hieu: " << endl;
    cout << P - Q << endl;
    return 0;
}