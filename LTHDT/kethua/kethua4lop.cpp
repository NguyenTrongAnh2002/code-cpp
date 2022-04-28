#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class HANG;
class TIVI;
class NSX
{
    char tenNSX[20];
    char diachi[20];

public:
    void nhap();
    void xuat();
    friend class HANG;
    friend class TIVI;
};
class HANG
{
    char tenhang[20];
    NSX x;
    float dongia;

public:
    void nhap();
    void xuat();
    HANG()
    {
        strcpy(tenhang, "ti vi");
        dongia = 1000;
        strcpy(x.tenNSX, "panasonic");
        strcpy(x.diachi, "nhat ban");
    }
    friend class TIVI;
};
class DATE
{
    int d, m, y;

public:
    void nhap();
    void xuat();
    friend class TIVI;
};
class TIVI : public HANG
{
    int kichthuoc;
    DATE ngaynhap;

public:
    void nhap();
    void xuat();
    TIVI()
    {
        kichthuoc = 20;
        ngaynhap.d = 20;
        ngaynhap.m = 12;
        ngaynhap.y = 2017;
    }
};
void TIVI::xuat()
{
    cout << "ten nha san xuat: " << x.tenNSX << endl;
    cout << " dia chi: " << x.diachi << endl;
    cout << "don gia: " << dongia << endl;
    cout << "ngay nhap: " << ngaynhap.d << "/" << ngaynhap.m << "/" << ngaynhap.y << endl;
    cout << "kich thuoc: " << kichthuoc << endl;
}
int main()
{
    TIVI tv1;
    tv1.xuat();
}