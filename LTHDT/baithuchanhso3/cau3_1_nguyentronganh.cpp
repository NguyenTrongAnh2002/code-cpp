#include <iostream>

using namespace std;

class NHANSU;
class DATE
{
private:
    int d, m, y;

public:
    void nhap();
    void xuat();
    friend class NHANSU;
};
class NHANSU
{
private:
    int maNS;
    char hoten[20];
    DATE a;

public:
    void nhap()
    {
        cout << "nhap ma nhan su: ";
        cin >> maNS;
        cout << "nhap ho ten: ";
        fflush(stdin);
        gets(hoten);
        cout << "nhap ngay sinh: ";
        cin >> a.d >> a.m >> a.y;
    }
    void xuat()
    {
        cout << "\n\t-------thong tin nhan su----------" << endl;
        cout << "ma nhan su: " << maNS << endl;
        cout << "ho ten: " << hoten << endl;
        cout << "ngay sinh: " << a.d << "/" << a.m << "/" << a.y << endl;
    }
};
int main()
{
    NHANSU p;
    cout << "\n\n\t------nhap thong tin------" << endl;
    p.nhap();
    p.xuat();
}
