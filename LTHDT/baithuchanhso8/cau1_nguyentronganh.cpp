#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class TIVI;
class DATE
{
    int d, m, y;

public:
    void nhap();
    void xuat();
    friend class TIVI;
    friend void tenTV(TIVI *tv, int n);
};
class NSX
{
    char tenNSX[20];
    char diachi[30];

public:
    void nhap();
    void xuat();
    friend class TIVI;
    friend void tenTV(TIVI *tv, int n);
};
class HANG
{
    char tenhang[20];
    NSX x;
    long double dongia;

public:
    void nhap();
    void xuat();
    friend class TIVI;
    friend void tenTV(TIVI *tv, int n);
    friend void sapxep(TIVI *tv, int n);
    friend void xoaTV(TIVI *tv, int &n);
};
class TIVI : public HANG
{
    char kichthuoc[15];
    DATE ngaynhap;

public:
    void nhap()
    {
        cout << "nhap ten nha san xuat: ";
        fflush(stdin);
        gets(x.tenNSX);
        cout << "nhap dia chi nha san xuat: ";
        fflush(stdin);
        gets(x.diachi);
        cout << "nhap ten hang san xuat : ";
        fflush(stdin);
        gets(tenhang);
        cout << "nhap kich thuoc : ";
        fflush(stdin);
        gets(kichthuoc);
        cout << "nhap don gia: ";
        cin >> dongia;
        cout << "nhap ngay nhap: ";
        cin >> ngaynhap.d >> ngaynhap.m >> ngaynhap.y;
    }
    void xuat()
    {
        cout << left << setw(20) << x.tenNSX << setw(20) << x.diachi << setw(20) << tenhang << setw(20) << kichthuoc << setw(20) << dongia << setw(1) << ngaynhap.d << "/" << ngaynhap.m << "/" << ngaynhap.y << endl;
    }
    friend void tenTV(TIVI *tv, int n);
    friend void sapxep(TIVI *tv, int n);
    friend void xoaTV(TIVI *tv, int &n);
};
void nhapds(TIVI *&tv, int &n)
{
    do
    {
        cout << "nhap so luong ti vi: ";
        cin >> n;
    } while (n <= 0);
    tv = new TIVI[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap ti vi thu " << i + 1 << endl;
        tv[i].nhap();
    }
}
void xuatds(TIVI *tv, int n)
{
    cout << left << setw(20) << "ten NSX" << setw(20) << "dia chi" << setw(20) << "ten hang" << setw(20) << "kich thuoc" << setw(20) << "don gia" << setw(20) << "ngay nhap" << endl;
    for (int i = 0; i < n; i++)
    {
        tv[i].xuat();
    }
}
void tenTV(TIVI *tv, int n)
{
    cout << left << setw(20) << "ten NSX" << setw(20) << "dia chi" << setw(20) << "ten hang" << setw(20) << "kich thuoc" << setw(20) << "don gia" << setw(20) << "ngay nhap" << endl;
    for (int i = 0; i < n; i++)
    {
        if ((strcmp(tv[i].tenhang, "SamSung") == 0) & tv[i].ngaynhap.y == 2020)
        {
            tv[i].xuat();
        }
    }
}
void sapxep(TIVI *tv, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tv[i].dongia > tv[j].dongia)
            {
                swap(tv[i], tv[j]);
            }
        }
    }
}
void xoaTV(TIVI *tv, int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(tv[i].tenhang, "LG") == 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                tv[i] = tv[j + 1];
            }
            n--;
            i--;
        }
    }
}
int main()
{
    TIVI *tv;
    int n;
    cout << "\n\t\t=======nhap thong tin========" << endl;
    nhapds(tv, n);
    cout << "\n\t=========danh sach TIVI==========" << endl;
    xuatds(tv, n);
    cout << "\n\t========danh sach TIVI SamSung=======" << endl;
    tenTV(tv, n);
    sapxep(tv, n);
    cout << "\n\t========danh sach TIVI da sap xep=======" << endl;
    xuatds(tv, n);
    xoaTV(tv, n);
    cout << "\n\t========danh sach TIVI sau khi xoa=======" << endl;
    xuatds(tv, n);
}