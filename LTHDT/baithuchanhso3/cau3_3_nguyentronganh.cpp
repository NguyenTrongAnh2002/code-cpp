#include <iostream>
#include <iomanip>

using namespace std;

class PHIEU;
class HANG
{
private:
    char tenhang[10];
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
    int maphieu;
    char ngay[20];
    HANG x[20];
    int n;

public:
    void nhap();
    void xuat();
};
void HANG::nhap()
{
    cout << "nhap ten hang: ";
    fflush(stdin);
    gets(tenhang);
    cout << "nhap don gia: ";
    cin >> dongia;
    cout << "nhap so luong: ";
    cin >> soluong;
}
void HANG::xuat()
{
    cout << left << setw(15) << tenhang << setw(15) << dongia << setw(15) << soluong << setw(15) << thanhtien() << endl;
}
void PHIEU::nhap()
{
    cout << "nhap ma phieu: ";
    cin >> maphieu;
    cout << "nhap ngay: ";
    fflush(stdin);
    gets(ngay);
    do
    {
        cout << "nhap so luong hang: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout << "nhap hang thu " << i + 1 << endl;
        x[i].nhap();
    }
}
void PHIEU::xuat()
{
    cout << "ma phieu: " << maphieu << setw(25) << ngay << endl;
    cout << left << setw(15) << "tenhang" << setw(15) << "dongia" << setw(15) << "soluong" << setw(15) << "thanh tien" << endl;
    for (int i = 0; i < n; i++)
    {
        x[i].xuat();
    }
    long tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += x[i].thanhtien();
    }
    cout << setw(30) << "tong thanh tien: " << tong << endl;
}
int main()
{
    PHIEU a;
    cout << "\n\n\t------nhap thong tin phieu----------" << endl;
    a.nhap();
    cout << "\n\t--------phieu mua hang-------\n"
         << endl;
    a.xuat();
}
