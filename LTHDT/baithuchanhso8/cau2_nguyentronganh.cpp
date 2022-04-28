#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class PHIEU;
class KIEMKE
{
private:
    char tenNV[20];
    char chucvu[20];

public:
    void nhap();
    void xuat();
};
class PHONGKK
{
private:
    char tenP[20];
    char maP[10];
    char tenTP[20];

public:
    void nhap();
    void xuat();
};
class TAISAN
{
private:
    char tenTS[20];
    int soluong;
    char tinhtrang[20];

public:
    void nhap();
    void xuat();
    friend class PHIEU;
};
class PHIEU
{
private:
    char maP[10];
    char ngaykiem[20];
    int n;
    KIEMKE k;
    PHONGKK p;
    TAISAN t[20];

public:
    void nhap();
    void xuat();
    void tensanpham();
    void xoataisan();
};
void KIEMKE::nhap()
{
    cout << "nhap ten nguoi kiem ke: ";
    fflush(stdin);
    gets(tenNV);
    cout << "nhap chuc vu nguoi kiem ke: ";
    fflush(stdin);
    gets(chucvu);
}
void KIEMKE::xuat()
{
    cout << "NHAN VIEN KK: " << tenNV << setw(60) << "chuc vu: " << chucvu << endl;
}
void PHONGKK::nhap()
{
    cout << "nhap ten phong kiem ke : ";
    fflush(stdin);
    gets(tenP);
    cout << "nhap ma kiem ke: ";
    fflush(stdin);
    gets(maP);
    cout << "nhap ten truong phong: ";
    fflush(stdin);
    gets(tenTP);
}
void PHONGKK::xuat()
{
    cout << "KK TAI PHONG: " << tenP << setw(60) << "MA PHONG: " << maP << endl;
    cout << "truong phong: " << tenTP << endl;
}
void TAISAN::nhap()
{
    cout << "nhap ten tai san : ";
    fflush(stdin);
    gets(tenTS);
    cout << "nhap so luong : ";
    cin >> soluong;
    cout << "nhap tinh trang tai san : ";
    fflush(stdin);
    gets(tinhtrang);
}
void TAISAN::xuat()
{
    cout << setw(20) << tenTS << setw(20) << soluong << setw(20) << tinhtrang << endl;
}
void PHIEU::nhap()
{
    cout << "nhap ma phieu : ";
    fflush(stdin);
    gets(maP);
    cout << "nhap ngay kiem : ";
    fflush(stdin);
    gets(ngaykiem);
    k.nhap();
    p.nhap();
    do
    {
        cout << "nhap so luong tai san: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout << "nhap tai san thu: " << i + 1 << endl;
        t[i].nhap();
    }
}
void PHIEU::xuat()
{
    cout << "ma phieu: " << maP << setw(60) << "ngay kiem: " << ngaykiem << endl;
    k.xuat();
    p.xuat();
    cout << setw(20) << "ten TS" << setw(20) << "so luong" << setw(20) << "tinh trang" << endl;
    for (int i = 0; i < n; i++)
    {
        t[i].xuat();
    }
    long tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += t[i].soluong;
    }
    cout << "so tai san da kiem ke: " << n << setw(40) << "tong so luong: " << tong << endl;
}
void PHIEU::tensanpham()
{
    for (int i = 0; i < n; i++)
    {
        if (t[i].soluong > 5)
        {
            t[i].xuat();
        }
    }
}
void PHIEU::xoataisan()
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(t[i].tinhtrang, "het khau hao") == 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                t[i] = t[j + 1];
            }
            n--;
            i--;
        }
    }
}
int main()
{
    PHIEU p1;
    cout << "\n\n\t\t------nhap thong tin phieu----------" << endl;
    p1.nhap();
    cout << "\n\t--------phieu kiem ke tai san-------" << endl;
    p1.xuat();
    cout << "\n\t--------ten cac san pham co sl>5---------" << endl;
    p1.tensanpham();
    p1.xoataisan();
    cout << "\n\t--------ten cac san pham sau khi xoa---------" << endl;
    p1.xuat();
}