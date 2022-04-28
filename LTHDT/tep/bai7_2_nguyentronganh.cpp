#include <iostream>
#include <iomanip>

using namespace std;

class PHIEU;
class NHACUNGCAP
{
private:
    char maNCC[12];
    char tenNCC[20];
    char diachi[30];
    char sdt[12];

public:
    void nhap();
    void xuat();
};
class SANPHAM
{
private:
    char maSP[10];
    char tenSP[20];
    long double dongia, soluong;

public:
    void nhap();
    void xuat();
    long thanhtien()
    {
        return dongia * soluong;
    }
    friend class PHIEU;
};
class PHIEU
{
private:
    char maphieu[10];
    char ngaylap[20];
    NHACUNGCAP a;
    SANPHAM s[20];
    int n;

public:
    void nhap();
    void xuat();
    void sapxep();
};
void NHACUNGCAP::nhap()
{
    cout << "nhap ma nha cung cap: ";
    fflush(stdin);
    gets(maNCC);
    cout << "nhap ten nha cung cap: ";
    fflush(stdin);
    gets(tenNCC);
    cout << "nhap dia chi nha cung cap: ";
    fflush(stdin);
    gets(diachi);
    cout << "nhap so dien thoai nha cung cap: ";
    fflush(stdin);
    gets(sdt);
}
void NHACUNGCAP::xuat()
{
    cout << "ma ncc: " << maNCC << setw(30) << "ten ncc: " << tenNCC << endl;
    cout << diachi << setw(30) << sdt << endl;
}
void SANPHAM::nhap()
{
    cout << "nhap ma san pham: ";
    fflush(stdin);
    gets(maSP);
    cout << "nhap ten san pham: ";
    fflush(stdin);
    gets(tenSP);
    cout << "nhap don gia: ";
    cin >> dongia;
    cout << "nhap so luong: ";
    cin >> soluong;
}
void SANPHAM::xuat()
{
    cout << left << setw(15) << maSP << setw(15) << tenSP << setw(15) << dongia << setw(15) << soluong << setw(15) << thanhtien() << endl;
}
void PHIEU::nhap()
{
    cout << "nhap ma phieu: ";
    fflush(stdin);
    gets(maphieu);
    cout << "nhap ngay lap : ";
    fflush(stdin);
    gets(ngaylap);
    a.nhap();
    do
    {
        cout << "nhap so luong san pham: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout << "nhap san pham thu " << i + 1 << endl;
        s[i].nhap();
    }
}
void PHIEU::xuat()
{
    cout << "ma phieu: " << maphieu << setw(25) << "ngaylap: " << ngaylap << endl;
    a.xuat();
    cout << left << setw(15) << "ma SP" << setw(15) << "ten san pham" << setw(15) << "don gia" << setw(15) << "so luong" << setw(15) << "thanh tien" << endl;
    for (int i = 0; i < n; i++)
    {
        s[i].xuat();
    }
    long tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += s[i].thanhtien();
    }
    cout << setw(60) << "tong thanh tien: " << tong << endl;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].soluong < 80)
        {
            dem++;
        }
    }
    cout << "so san pham co luong nhap nho hon 80 la: " << dem << endl;
}
void PHIEU::sapxep()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].dongia > s[j].dongia)
            {
                swap(s[i], s[j]);
            }
        }
    }
}
int main()
{
    PHIEU p;
    cout << "\n\n\t------nhap thong tin phieu----------" << endl;
    p.nhap();
    cout << "\nDai hoc Victory" << endl;
    cout << "\n\t--------PHIEU NHAP VAN PHONG PHAM-------" << endl;
    p.xuat();
    p.sapxep();
    cout << "\n-------mat hang da sap xep-----\n";
    p.xuat();
}
