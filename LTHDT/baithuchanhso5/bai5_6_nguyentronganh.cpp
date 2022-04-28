#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class KETQUA;
class SINHVIEN
{
protected:
    char hoTen[20];
    int soBD;

public:
    void nhap()
    {
        cout << "ho va ten: ";
        fflush(stdin);
        gets(hoTen);
        cout << "so bao danh: ";
        cin >> soBD;
    }
    void xuat()
    {
        cout << setw(5) << hoTen << setw(20) << soBD;
    }
};
class DIEMTHi : public SINHVIEN
{
protected:
    float mon1, mon2;

public:
    void nhap()
    {
        SINHVIEN::nhap();
        cout << "nhap diem mon 1: ";
        cin >> mon1;
        cout << "nhap diem mon 2: ";
        cin >> mon2;
    }
    void xuat()
    {
        cout << left << setw(20) << hoTen << setw(20) << soBD << setw(20) << mon1 << setw(20) << mon2 << endl;
    }
    friend class KETQUA;
};
class KETQUA
{
private:
    DIEMTHi a[99];
    int n;

public:
    void nhap();
    void xuat();
    void tongdiem();
};
void KETQUA::nhap()
{
    do
    {
        cout << "nhap so luong sinh vien: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin sinh vien thu " << i + 1 << endl;
        a[i].nhap();
    }
}
void KETQUA::xuat()
{
    cout << left << setw(10) << "STT" << setw(20) << "ho Ten" << setw(20) << "so bao danh" << setw(20) << "diem mon 1" << setw(20) << "diem mon 2" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << i + 1;
        a[i].xuat();
    }
}
void KETQUA::tongdiem()
{
    for (int i = 0; i < n; i++)
    {
        cout << "tong diem 2 mon cua sinh vien " << i + 1 << " la: " << a[i].mon1 + a[i].mon2 << endl;
    }
}
int main()
{
    KETQUA a;
    cout << "\n-----------nhap thong tin----------" << endl;
    a.nhap();
    cout << "\n-----------danh sach thong tin----------" << endl;
    a.xuat();
    cout << "\n----------- tong diem dat duoc cua sinh vien----------" << endl;
    a.tongdiem();
}