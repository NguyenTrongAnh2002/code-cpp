#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class BENHAN;
class BENHNHAN
{
protected:
    char hoten[20];
    char quequan[30];
    float namsinh;

public:
    void nhap()
    {
        cout << "nhap ho ten: ";
        fflush(stdin);
        gets(hoten);
        cout << "nhap que quan: ";
        fflush(stdin);
        gets(quequan);
        cout << "nhap nam sinh: ";
        cin >> namsinh;
    }
    void xuat();
    friend class BENHAN;
};
class BENHAN : public BENHNHAN
{
    char tenBA[20];
    long tienvienphi;

public:
    long tuoihientai()
    {
        return 2021 - namsinh + 1;
    }
    void nhap()
    {
        BENHNHAN::nhap();
        cout << "nhap ten benh an: ";
        fflush(stdin);
        gets(tenBA);
        cout << "nhap so tien vien phi: ";
        cin >> tienvienphi;
    }
    void xuat()
    {
        cout << left << setw(15) << hoten << setw(15) << quequan << setw(15) << namsinh << setw(15) << tenBA << setw(15) << tienvienphi << setw(20) << tuoihientai() << endl;
    }
    friend void sapxep(BENHAN *ba, int n);
    friend void benhnhannhotuoi(BENHAN *ba, int n);
    friend void vienphicaonhat(BENHAN *ba, int n);
};
void nhapds(BENHAN *&ba, int &n)
{
    do
    {
        cout << "nhap so benh an: ";
        cin >> n;
    } while (n <= 0);
    ba = new BENHAN[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap benh an thu " << i + 1 << endl;
        ba[i].nhap();
    }
}
void xuatds(BENHAN *ba, int n)
{
    cout << left << setw(15) << "ho ten" << setw(15) << "que quan" << setw(15) << "nam sinh" << setw(15) << "ten BA" << setw(15) << "tien vien phi" << setw(20) << "tuoi" << endl;
    for (int i = 0; i < n; i++)
    {
        ba[i].xuat();
    }
}
void sapxep(BENHAN *ba, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ba[i].tuoihientai() < ba[j].tuoihientai())
            {
                swap(ba[i], ba[j]);
            }
        }
    }
}
void benhnhannhotuoi(BENHAN *ba, int n)
{
    cout << left << setw(15) << "ho ten" << setw(15) << "que quan" << setw(15) << "nam sinh" << setw(15) << "ten BA" << setw(15) << "tien vien phi" << setw(20) << "tuoi" << endl;
    for (int i = 0; i < n; i++)
    {
        if (ba[i].tuoihientai() <= 10)
        {
            ba[i].xuat();
        }
    }
}
void vienphicaonhat(BENHAN *ba, int n)
{
    long max = ba[0].tienvienphi;
    for (int i = 0; i < n; i++)
    {
        if (ba[i].tienvienphi > max)
        {
            max = ba[i].tienvienphi;
        }
    }
    cout << left << setw(15) << "ho ten" << setw(15) << "que quan" << setw(15) << "nam sinh" << setw(15) << "ten BA" << setw(15) << "tien vien phi" << setw(20) << "tuoi" << endl;
    for (int i = 0; i < n; i++)
    {
        if (ba[i].tienvienphi == max)
        {
            ba[i].xuat();
        }
    }
}
int main()
{
    BENHAN *ba;
    int n;
    cout << "\n------nhap thong tin benh an-------" << endl;
    nhapds(ba, n);
    cout << "\n-------danh sach benh an--------" << endl;
    xuatds(ba, n);
    sapxep(ba, n);
    cout << "\n-------danh sach benh an sau khi sap xep--------" << endl;
    xuatds(ba, n);
    cout << "\n---------danh sach benh nhan <=10 tuoi--------" << endl;
    benhnhannhotuoi(ba, n);
    cout << "\n--------benh nhan co vien phi cao nhat--------" << endl;
    vienphicaonhat(ba, n);
}