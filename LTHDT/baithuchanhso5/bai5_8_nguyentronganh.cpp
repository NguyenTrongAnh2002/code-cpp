#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class HOADON;
class SANPHAM
{
protected:
    char tenSP[20];
    char namSX[4];
    long giathanh;

public:
    void nhap()
    {
        cout << "nhap ten san pham: ";
        fflush(stdin);
        gets(tenSP);
        cout << "nhap nam san xuat: ";
        fflush(stdin);
        gets(namSX);
        cout << "nhap gia thanh: ";
        cin >> giathanh;
    }
    void xuat();
};
class HOADON : public SANPHAM
{
    int soluongban;
    long giaban;
    int i;

public:
    long thanhtien()
    {
        return soluongban * giaban;
    }
    long thue()
    {
        return thanhtien() * 10 / 100;
    }
    long lai()
    {
        return ((giaban - giathanh) * soluongban) - thue();
    }
    void nhap()
    {
        SANPHAM::nhap();
        cout << "nhap so luong ban: ";
        cin >> soluongban;
        cout << "nhap gia ban: ";
        cin >> giaban;
    }
    void xuat()
    {
        cout << left << setw(15) << tenSP << setw(15) << giathanh << setw(15) << soluongban << setw(15) << giaban << setw(20) << thanhtien() << setw(15) << thue() << setw(15) << lai() << endl;
    }
    friend void sapxep(HOADON *hd, int n);
    friend void tonghoadon(HOADON *hd, int n);
    friend void thuecaonhat(HOADON *hd, int n);
};
void nhapds(HOADON *&hd, int &n)
{
    do
    {
        cout << "nhap so luong hoa don: ";
        cin >> n;
    } while (n <= 0);
    hd = new HOADON[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap hoa don thu " << i + 1 << endl;
        hd[i].nhap();
    }
}
void xuatds(HOADON *hd, int n)
{
    cout << left << setw(10) << "STT" << setw(15) << "ten SP" << setw(15) << "gia thanh" << setw(15) << "so luong ban" << setw(15) << "gia ban" << setw(20) << "thanh tien" << setw(15) << "thue" << setw(15) << "lai" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << i + 1;
        hd[i].xuat();
    }
}
void sapxep(HOADON *hd, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (hd[i].lai() < hd[j].lai())
            {
                swap(hd[i], hd[j]);
            }
        }
    }
}
void tonghoadon(HOADON *hd, int n)
{
    long tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += hd[i].thanhtien();
    }
    cout << "tong tien cua cac hoa don la: " << tong << endl;
}
void thuecaonhat(HOADON *hd, int n)
{
    long max = hd[0].thue();
    for (int i = 0; i < n; i++)
    {
        if (hd[i].thue() > max)
        {
            max = hd[i].thue();
        }
    }
    cout << left << setw(10) << "STT" << setw(15) << "ten SP" << setw(15) << "gia thanh" << setw(15) << "so luong ban" << setw(15) << "gia ban" << setw(20) << "thanh tien" << setw(15) << "thue" << setw(15) << "lai" << endl;
    for (int i = 0; i < n; i++)
    {
        if (hd[i].thue() == max)
        {
            cout << setw(10) << i + 1;
            hd[i].xuat();
        }
    }
}
int main()
{
    HOADON *hd;
    int n;
    cout << "\n------nhap thong tin hoa don-------" << endl;
    nhapds(hd, n);
    sapxep(hd, n);
    cout << "\n-------danh sach hoa don sau khi sap xep--------" << endl;
    xuatds(hd, n);
    cout << "\n---------tong tien cac hoa don--------" << endl;
    tonghoadon(hd, n);
    cout << "\n--------hoa don co thue cao nhat--------" << endl;
    thuecaonhat(hd, n);
}