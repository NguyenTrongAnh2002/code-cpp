#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class SANPHAM
{
protected:
    int maSP;
    char tenSP[20];
    char ngaySX[20];
    float trongluong;
    char mausac[10];

public:
    void nhap()
    {
        cout << "nhap ma san pham: ";
        cin >> maSP;
        cout << "nhap ten san pham: ";
        fflush(stdin);
        gets(tenSP);
        cout << "nhap ngay san xuat: ";
        fflush(stdin);
        gets(ngaySX);
        cout << "nhap trong luong: ";
        cin >> trongluong;
        cout << "nhap mau sac: ";
        fflush(stdin);
        gets(mausac);
    }
};
class HANGDIENTU : public SANPHAM
{
    float congsuat;
    char dongdien[10];

public:
    void nhap()
    {
        SANPHAM::nhap();
        cout << "nhap cong suat: ";
        cin >> congsuat;
        cout << "nhap loai dong dien(1 hay 2 chieu): ";
        fflush(stdin);
        gets(dongdien);
    }
    void xuat()
    {
        cout << left << setw(20) << maSP << setw(20) << tenSP << setw(20) << ngaySX << setw(20) << trongluong << setw(20) << mausac << setw(20) << congsuat << setw(20) << dongdien << endl;
    }
    friend void trongluongthapnhat(HANGDIENTU *dt, int n);
};
void nhapds(HANGDIENTU *&dt, int &n)
{
    do
    {
        cout << "nhap so luong san pham: ";
        cin >> n;
    } while (n <= 0);
    dt = new HANGDIENTU[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap san pham thu " << i + 1 << endl;
        dt[i].nhap();
    }
}
void xuatds(HANGDIENTU *dt, int n)
{
    cout << left << setw(20) << "ma SP" << setw(20) << "ten SP" << setw(20) << "ngay SX" << setw(20) << "trong luong" << setw(20) << "mau sac" << setw(20) << "cong suat" << setw(20) << "dong dien" << endl;
    for (int i = 0; i < n; i++)
    {
        dt[i].xuat();
    }
}
void trongluongthapnhat(HANGDIENTU *dt, int n)
{
    int min = dt[0].trongluong;
    for (int i = 0; i < n; i++)
    {
        if (dt[i].trongluong < min)
        {
            min = dt[i].trongluong;
        }
    }
    cout << left << setw(20) << "ma SP" << setw(20) << "ten SP" << setw(20) << "ngay SX" << setw(20) << "trong luong" << setw(20) << "mau sac" << setw(20) << "cong suat" << setw(20) << "dong dien" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dt[i].trongluong == min)
        {
            dt[i].xuat();
        }
    }
}
int main()
{
    HANGDIENTU *dt;
    int n;
    cout << "\n-----------nhap thong tin------------" << endl;
    nhapds(dt, n);
    cout << "\n-----------danh sach san pham------------" << endl;
    xuatds(dt, n);
    cout << "\n-----------san pham co trong luong thap nhat------------" << endl;
    trongluongthapnhat(dt, n);
}