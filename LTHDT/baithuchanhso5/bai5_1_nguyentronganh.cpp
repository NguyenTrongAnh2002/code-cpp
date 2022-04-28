#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class KYSU;
class PERSON
{
protected:
    char hoten[20];
    char ngaysinh[20];
    char quequan[30];
    friend class KYSU;
    friend void timkysu(KYSU *ks, int n);
};
class KYSU : public PERSON
{
    char nganh[20];
    int namTN;

public:
    void nhap()
    {
        cout << "nhap ho ten ky su: ";
        fflush(stdin);
        gets(hoten);
        cout << "nhap ngay sinh ky su: ";
        fflush(stdin);
        gets(ngaysinh);
        cout << "nhap que quan ky su: ";
        fflush(stdin);
        gets(quequan);
        cout << "nhap nganh: ";
        fflush(stdin);
        gets(nganh);
        cout << "nhap nam tot nghiep: ";
        cin >> namTN;
    }
    void xuat()
    {
        cout << left << setw(20) << hoten << setw(20) << ngaysinh << setw(20) << quequan << setw(20) << nganh << setw(20) << namTN << endl;
    }
    friend void timkysu(KYSU *ks, int n);
};
void nhapds(KYSU *&ks, int &n)
{
    do
    {
        cout << "nhap so luong ky su: ";
        cin >> n;
    } while (n <= 0);
    ks = new KYSU[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap ky su thu " << i + 1 << endl;
        ks[i].nhap();
    }
}
void xuatds(KYSU *ks, int n)
{
    cout << left << setw(20) << "ho ten" << setw(20) << "ngay sinh" << setw(20) << "que quan" << setw(20) << "nganh" << setw(20) << "nam TN" << endl;
    for (int i = 0; i < n; i++)
    {
        ks[i].xuat();
    }
}
void timkysu(KYSU *ks, int n)
{
    int max = ks[0].namTN;
    for (int i = 0; i < n; i++)
    {
        if (ks[i].namTN > max)
        {
            max = ks[i].namTN;
        }
    }
    cout << left << setw(20) << "ho ten" << setw(20) << "ngay sinh" << setw(20) << "que quan" << setw(20) << "nganh" << setw(20) << "nam TN" << endl;
    for (int i = 0; i < n; i++)
    {
        if (ks[i].namTN == max)
        {
            ks[i].xuat();
        }
    }
}
int main()
{
    KYSU *ks;
    int n;
    cout << "\n------nhap danh sach---------" << endl;
    nhapds(ks, n);
    cout << "--------danh sach ky su---------" << endl;
    xuatds(ks, n);
    cout << "--------danh sach ky su tot nghiep gan nhat---------" << endl;
    timkysu(ks, n);
}