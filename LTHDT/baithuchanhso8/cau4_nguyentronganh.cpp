#include <iostream>
#include <fstream>

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
    MATRAN operator-(MATRAN y)
    {
        MATRAN H;
        if (m == y.m && n == y.n)
        {
            H.n = n;
            H.m = m;
            H.a = new double *[n];
            for (int i = 0; i < n; i++)
            {
                H.a[i] = new double[m];
            }
            for (int i = 0; i < y.n; i++)
                for (int j = 0; j < y.m; j++)
                {
                    H.a[i][j] = a[i][j] - y.a[i][j];
                }
        }
        else
            cout << "ma tran khong cung kich thuoc!" << endl;
        return H;
    }
    MATRAN operator--()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                a[i][j] = -a[i][j];
            }
    }
};
int main()
{
    MATRAN A, B, H;
    cout << "nhap ma tran A: " << endl;
    cin >> A;
    cout << "nhap ma tran B: " << endl;
    cin >> B;
    --A;
    --B;
    H = A - B;
    cout << "\nma tran A sau khi doi dau la: " << endl;
    cout << A << endl;
    cout << "\nma tran B sau khi doi dau la: " << endl;
    cout << B << endl;
    cout << "\nma tran sau khi tru la: " << endl;
    cout << H << endl;
    ofstream f("Matrix.txt");
    f << "ma tran A sau khi doi dau: " << A << endl;
    f << "ma tran B sau khi doi dau: " << B << endl;
    f << "ma tran sau khi tru: " << H << endl;
    f.close();
}