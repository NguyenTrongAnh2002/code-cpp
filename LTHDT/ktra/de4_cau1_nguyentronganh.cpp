#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class PERSON;
class BENHNHAN;
class HOSPITAL
{
    char tenBV[20];
    char diachi[30];
    char tengiamdoc[20];
    int tuoigd;
    friend class PERSON;
    friend class BENHNHAN;
    friend void vietduc(BENHNHAN *bn, int n);
    friend void benhnhan(BENHNHAN *bn, int n);
    friend void xoabenhnhan(BENHNHAN *bn, int &n);
};
class PERSON
{
    char hoten[20];
    int tuoi;
    HOSPITAL giamdoc;
    friend class BENHNHAN;
    friend void vietduc(BENHNHAN *bn, int n);
    friend void benhnhan(BENHNHAN *bn, int n);
    friend void xoabenhnhan(BENHNHAN *bn, int &n);

public:
    void nhap()
    {
        cout << "nhap ho ten giam doc: ";
        fflush(stdin);
        gets(giamdoc.tengiamdoc);
        cout << "nhap tuoi giam doc: ";
        cin >> giamdoc.tuoigd;
    }
    void xuat()
    {
        cout << left << setw(15) << giamdoc.tengiamdoc << setw(15) << giamdoc.tuoigd << endl;
    }
    friend class HOSPITAL;
};
class BENHNHAN : public PERSON
{
    char tiensu[20];
    char chuandoan[20];
    HOSPITAL benhvien;

public:
    void nhap()
    {
        cout << "nhap ten benh nhan: ";
        fflush(stdin);
        gets(hoten);
        cout << "nhap tuoi benh nhan: ";
        cin >> tuoi;
        cout << "nhap ten benh vien: ";
        fflush(stdin);
        gets(benhvien.tenBV);
        cout << "nhap dia chi: ";
        fflush(stdin);
        gets(benhvien.diachi);
        cout << "nhap tien su: ";
        fflush(stdin);
        gets(tiensu);
        cout << "nhap chuan doan: ";
        fflush(stdin);
        gets(chuandoan);
        PERSON ::nhap();
    }
    void xuat()
    {
        cout << left << setw(15) << hoten << setw(15) << tuoi << setw(15) << benhvien.tenBV << setw(15) << benhvien.diachi << setw(15) << tiensu << setw(15) << chuandoan;
        PERSON ::xuat();
    }
    friend void vietduc(BENHNHAN *bn, int n);
    friend void benhnhan(BENHNHAN *bn, int n);
    friend void xoabenhnhan(BENHNHAN *bn, int &n);
};

void nhapds(BENHNHAN *&bn, int &n)
{
    do
    {
        cout << "nhap so luong benh nhan: ";
        cin >> n;
    } while (n < 0);
    bn = new BENHNHAN[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap benh nhan thu " << i + 1 << endl;
        bn[i].nhap();
    }
}
void xuatds(BENHNHAN *bn, int n)
{
    cout << left << setw(15) << "ten benh nhan" << setw(15) << "tuoi" << setw(15) << "ten giam doc" << setw(15) << "tuoi gd" << setw(15) << "ten benh tien" << setw(15) << "dia chi" << setw(15) << "chuan doan" << setw(15) << "tien su" << endl;
    for (int i = 0; i < n; i++)
    {
        bn[i].xuat();
    }
}
void vietduc(BENHNHAN *bn, int n)
{
    cout << left << setw(15) << "ten benh nhan" << setw(15) << "tuoi" << setw(15) << "ten giam doc" << setw(15) << "tuoi gd" << setw(15) << "ten benh tien" << setw(15) << "dia chi" << setw(15) << "chuan doan" << setw(15) << "tien su" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(bn[i].benhvien.tenBV, "vietduc") == 0)
        {
            bn[i].xuat();
        }
    }
}
void benhnhan(BENHNHAN *bn, int n)
{
    char ten[20];
    cout << "nhap ten muon tim: ";
    fflush(stdin);
    gets(ten);
    cout << left << setw(15) << "ten benh nhan" << setw(15) << "tuoi" << setw(15) << "ten giam doc" << setw(15) << "tuoi gd" << setw(15) << "ten benh tien" << setw(15) << "dia chi" << setw(15) << "chuan doan" << setw(15) << "tien su" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(bn[i].hoten, ten) == 0)
        {
            bn[i].xuat();
        }
    }
}
void xoabenhnhan(BENHNHAN *bn, int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (bn[i].tuoi >= 30)
        {
            for (int j = i; j < n - 1; j++)
            {
                bn[j] = bn[j + 1];
            }
            n--;
            i--;
        }
    }
}
int main()
{
    BENHNHAN *bn;
    int n;
    cout << "=======nhap thong tin==========" << endl;
    nhapds(bn, n);
    cout << "=========danh dach========" << endl;
    xuatds(bn, n);
    cout << "========benh vien VIET DUC=========" << endl;
    vietduc(bn, n);
    cout << "=========tim benh nhan=========" << endl;
    benhnhan(bn, n);
    xoabenhnhan(bn, n);
    cout << "==========danh sach sau khi xoa===========" << endl;
    xuatds(bn, n);
}
