#include <iostream>

using namespace std;

class PS
{
private:
    float TS, MS;

public:
    void nhap();
    void xuat();
    PS operator+(PS y);
    PS operator-(PS y);
    PS operator*(PS y);
    PS operator/(PS y);
};
void PS::nhap()
{
    cout << "nhap tu so: ";
    cin >> TS;
    cout << "nhap mau so: ";
    cin >> MS;
}
void PS::xuat()
{
    cout << TS << "/" << MS << endl;
}
PS PS::operator+(PS y)
{
    PS z;
    z.TS = TS * y.MS + MS * y.TS;
    z.MS = MS * y.MS;
    return z;
}
PS PS::operator-(PS y)
{
    PS h;
    h.TS = TS * y.MS - MS * y.TS;
    h.MS = MS * y.MS;
    return h;
}
PS PS::operator*(PS y)
{
    PS t;
    t.TS = TS * y.TS;
    t.MS = MS * y.MS;
    return t;
}
PS PS::operator/(PS y)
{
    PS th;
    th.TS = TS * y.MS;
    th.MS = MS * y.TS;
    return th;
}
int main()
{
    PS x, y, z, h, t, th;
    cout << "nhap phan so thu nhat " << endl;
    x.nhap();
    cout << "nhap phan so thu hai " << endl;
    y.nhap();
    z = x + y;
    h = x - y;
    t = x * y;
    th = x / y;
    cout << "cong 2 phan so " << endl;
    z.xuat();
    cout << "tru 2 phan so " << endl;
    h.xuat();
    cout << "tich 2 phan so " << endl;
    t.xuat();
    cout << "thuong 2 phan so " << endl;
    th.xuat();
}