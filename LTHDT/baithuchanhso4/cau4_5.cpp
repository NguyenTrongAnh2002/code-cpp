#include <iostream>
#include <iomanip>

using namespace std;

class MANG
{
    int *value;
    int n;

public:
    MANG()
    {
        n = 0;
    }
    MANG(int n1)
    {
        n = n1;
        value = new int[n];
        for (int i = 0; i < n; i++)
        {
            value[i] = 0;
        }
    }
    ~MANG()
    {
        n = 0;
        delete[] value;
    }
    void nhap()
    {
        cout << "nhap so luong phan tu: ";
        cin >> n;
        value = new int[n];
        for (int i = 0; i < n; i++)
        {
            cout << "nhap phan tu thu " << i + 1 << endl;
            cin >> value[i];
        }
    }
    void xuat()
    {
        for (int i = 0; i < n; i++)
        {
            cout << value[i] << " ";
        }
    }
};
int main()
{
    MANG a(5);
    int n;
    cout << "mang vua khoi tao: " << endl;
    a.xuat();
    cout << "\nnhap mang: " << endl;
    a.nhap();
    cout << "\nmang vua nhap: " << endl;
    a.xuat();
}