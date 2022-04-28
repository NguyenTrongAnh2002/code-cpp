#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class DOANHNGHIEP;
class DATE
{
public:
    int d, m, y;
    void nhap();
    void xuat();
    friend void doanhthu(DOANHNGHIEP *dn, int n);
    friend void tongdoanhthu(DOANHNGHIEP *dn, int n);
    friend void xuatdoanhnghiep(DOANHNGHIEP *dn, int n);
    friend void sapxepten(DOANHNGHIEP *dn, int n);
};
class DIACHI
{
public:
    char dienthoai[12];
    char phuong[30];
    char quan[30];
    char thanhpho[30];
    friend void doanhthu(DOANHNGHIEP *dn, int n);
    friend void tongdoanhthu(DOANHNGHIEP *dn, int n);
    friend void xuatdoanhnghiep(DOANHNGHIEP *dn, int n);
    friend void sapxepten(DOANHNGHIEP *dn, int n);
};
class DOANHNGHIEP
{
private:
    char maDN[20];
    char tenDN[60];
    DATE ngayTL;
    DIACHI diachi;
    char giamdoc[30];
    long doanhthu;
    int n;

public:
    void nhap()
    {
        cout << "nhap ma doanh nghiep: ";
        fflush(stdin);
        gets(maDN);
        cout << "nhap ten doanh nghiep: ";
        fflush(stdin);
        gets(tenDN);
        cout << "nhap ngay thanh lap: ";
        cin >> ngayTL.d >> ngayTL.m >> ngayTL.y;
        cout << "nhap so dien thoai: ";
        fflush(stdin);
        gets(diachi.dienthoai);
        cout << "nhap phuong: ";
        fflush(stdin);
        gets(diachi.phuong);
        cout << "nhap quan: ";
        fflush(stdin);
        gets(diachi.quan);
        cout << "nhap thanh pho: ";
        fflush(stdin);
        gets(diachi.thanhpho);
        cout << "nhap ten giam doc: ";
        fflush(stdin);
        gets(giamdoc);
        cout << "nhap doanh thu: ";
        cin >> doanhthu;
    }
    void xuat()
    {
        cout << left << setw(15) << maDN << setw(15) << tenDN << setw(1) << ngayTL.d << "/" << ngayTL.m << "/" << ngayTL.y << "       " << setw(20) << diachi.thanhpho << setw(15) << giamdoc << setw(15) << doanhthu << endl;
    }
    friend void doanhthu(DOANHNGHIEP *dn, int n);
    friend void tongdoanhthu(DOANHNGHIEP *dn, int n);
    friend void xuatdoanhnghiep(DOANHNGHIEP *dn, int n);
    friend void sapxepten(DOANHNGHIEP *dn, int n);
};
void nhapds(DOANHNGHIEP *&dn, int &n)
{
    do
    {
        cout << "nhap so luong doanh nghiep: ";
        cin >> n;
    } while (n < 0);
    dn = new DOANHNGHIEP[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap doanh nghiep thu " << i + 1 << endl;
        dn[i].nhap();
    }
}
void xuatds(DOANHNGHIEP *dn, int n)
{
    cout << left << setw(15) << "ma DN" << setw(15) << "ten DN" << setw(15) << "ngay tl" << setw(20) << "thanh pho" << setw(15) << "ten giam doc" << setw(15) << "doanh thu" << endl;
    for (int i = 0; i < n; i++)
    {
        dn[i].xuat();
    }
}
void doanhthu(DOANHNGHIEP *dn, int n)
{
    cout << "\n--------Danh sach doanh nghiep co doanh thu tren 3000000 -------\n";
    cout << left << setw(15) << "ma DN" << setw(15) << "ten DN" << setw(15) << "ngay tl" << setw(20) << "thanh pho" << setw(15) << "ten giam doc" << setw(15) << "doanh thu" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dn[i].doanhthu > 300000)
        {
            dn[i].xuat();
        }
    }
}
void tongdoanhthu(DOANHNGHIEP *dn, int n)
{
    long tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (dn[i].ngayTL.m == 6)
        {
            tong += dn[i].doanhthu;
        }
    }
    cout << "tong doanh thu thang 6: " << tong << endl;
}
void xuatdoanhnghiep(DOANHNGHIEP *dn, int n)
{
    cout << "\n--------Danh sach doanh nghiep muon tim-------\n";
    cout << left << setw(15) << "ma DN" << setw(15) << "ten DN" << setw(15) << "ngay tl" << setw(20) << "thanh pho" << setw(15) << "ten giam doc" << setw(15) << "doanh thu" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(dn[i].maDN, "DN201") == 0)
        {
            dn[i].xuat();
        }
    }
}
void sapxepten(DOANHNGHIEP *dn, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(dn[i].diachi.thanhpho, dn[j].diachi.thanhpho) < 0)
            {
                swap(dn[i], dn[j]);
            }
        }
    }
}
int main()
{
    DOANHNGHIEP *dn;
    int n;
    cout << "\n----------nhap thong tin----------- " << endl;
    nhapds(dn, n);
    cout << "\n\n------------danh sach doanh nghiep---------\n";
    xuatds(dn, n);
    doanhthu(dn, n);
    cout << "\n---tong doanh thu thang 6 ----\n";
    tongdoanhthu(dn, n);
    xuatdoanhnghiep(dn, n);
    sapxepten(dn, n);
    cout << "\n\n\t------danh sach doanh nghiep sau sap xep--------" << endl;
    xuatds(dn, n);
}