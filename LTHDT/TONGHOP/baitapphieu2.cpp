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
    void sua();
    void sapxep();
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
    cout << setw(15) << tenTS << setw(15) << soluong << setw(15) << tinhtrang << endl;
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
    cout << setw(15) << "ten TS" << setw(15) << "so luong" << setw(15) << "tinh trang" << endl;
    for (int i = 0; i < n; i++)
    {
        t[i].xuat();
    }
}
void PHIEU::sua()
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(t[i].tenTS, "may vi tinh") == 0)
        {
            t[i].soluong = 20;
        }
    }
}
void PHIEU::sapxep()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].soluong > t[j].soluong)
            {
                swap(t[i], t[j]);
            }
        }
    }
}
int main()
{
    PHIEU p1;
    cout << "\n\n\t------nhap thong tin phieu----------" << endl;
    p1.nhap();
    cout << "\n\t--------phieu kiem ke tai san-------" << endl;
    p1.xuat();
    cout << "\n--------phieu sau khi sua---------" << endl;
    p1.sua();
    p1.xuat();
    p1.sapxep();
    cout << "\n-------tai san da sap xep-----\n";
    p1.xuat();
}