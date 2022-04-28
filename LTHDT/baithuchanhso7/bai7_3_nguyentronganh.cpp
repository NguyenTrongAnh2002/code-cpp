#include <iostream>
#include <iomanip>

using namespace std;
class PHIEUDIEM;
class MONHOC
{
    char tenMH[20];
    int sotrinh;
    float diem;

public:
    void nhap()
    {
        cout << "nhap ten mon hoc: ";
        fflush(stdin);
        gets(tenMH);
        cout << "nhap so trinh: ";
        cin >> sotrinh;
        cout << "nhap diem: ";
        cin >> diem;
    }
    void xuat()
    {
        cout << left << setw(20) << tenMH << setw(15) << sotrinh << setw(15) << diem << endl;
    }
    friend class PHIEUDIEM;
    friend float tongsotrinh();
    friend float tongsodiem();
    friend void tenmonhoc();
};
class PHIEUDIEM
{
private:
    char maSV[10];
    char tenSV[20];
    char tenlop[10];
    MONHOC a[20];
    int khoa;
    int n;

public:
    void nhap();
    void xuat();
    void tenmonhoc();
    void chen();
    float tongsotrinh()
    {
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            t += a[i].sotrinh;
        }
        return t;
    }
    float tongsodiem()
    {
        float td = 0;
        for (int i = 0; i < n; i++)
        {
            td += a[i].sotrinh * a[i].diem;
        }
        return td;
    }
};
void PHIEUDIEM::nhap()
{
    cout << "nhap ma sinh vien: ";
    fflush(stdin);
    gets(maSV);
    cout << "nhap ten sinh vien: ";
    fflush(stdin);
    gets(tenSV);
    cout << "nhap ten lop: ";
    fflush(stdin);
    gets(tenlop);
    cout << "nhap khoa: ";
    cin >> khoa;
    do
    {
        cout << "nhap so luong mon hoc: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout << "\t- nhap mon hoc thu " << i + 1 << endl;
        a[i].nhap();
    }
}
void PHIEUDIEM::xuat()
{
    cout << "Ma sinh vien: " << maSV << setw(30) << "Ten sinh vien: " << tenSV << endl;
    cout << "Lop: " << tenlop << setw(30) << "Khoa: " << khoa << endl;
    cout << "BANG DIEM: " << endl;
    cout << left << setw(20) << "Ten mon hoc" << setw(15) << "so trinh" << setw(15) << "diem" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    float dtb = tongsodiem() / tongsotrinh();
    cout << "diem trung binh la: " << dtb << endl;
}
void PHIEUDIEM::tenmonhoc()
{
    {
        cout << left << setw(20) << "Ten mon hoc" << setw(15) << "so trinh" << setw(15) << "diem" << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i].sotrinh > 3)
            {
                a[i].xuat();
            }
        }
    }
}
void PHIEUDIEM::chen()
{
    cout << "nhap thong tin chen: " << endl;
    MONHOC b;
    b.nhap();
    a[n] = b;
    n++;
}
int main()
{
    PHIEUDIEM p;
    p.nhap();
    cout << "\n\t\tPHIEU BAO DIEM" << endl;
    p.xuat();
    cout << "cac mon hoc co so trinh lon hon 3" << endl;
    p.tenmonhoc();
    p.chen();
    cout << "========phieu sau khi chen====" << endl;
    cout << "\n\t\tPHIEU BAO DIEM" << endl;
    p.xuat();
}