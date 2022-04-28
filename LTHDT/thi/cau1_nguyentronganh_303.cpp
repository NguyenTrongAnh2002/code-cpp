#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class PHIEU;
class THIETBI
{
private:
    char maTB[10];
    char tenTB[20];
    int soluong;
    int dongia;

public:
    float thanhtien()
    {
        return soluong * dongia;
    }
    void nhap()
    {
        cout << "nhap ma thiet bi: ";
        fflush(stdin);
        gets(maTB);
        cout << "nhap ten thiet bi: ";
        fflush(stdin);
        gets(tenTB);
        cout << "nhap don gia: ";
        cin >> dongia;
        cout << "nhap so luong: ";
        cin >> soluong;
    }
    void xuat()
    {
        cout << left << setw(10) << maTB << setw(20) << tenTB << setw(20) << soluong << setw(20) << dongia << setw(20) << thanhtien() << endl;
    }
    friend class PHIEU;
};
class NHANVIEN
{
private:
    char maNV[10];
    char tenNV[20];
    char maCA[10];

public:
    void nhap()
    {
        cout << "nhap ma nhan vien: ";
        fflush(stdin);
        gets(maNV);
        cout << "nhap ten nhan vien: ";
        fflush(stdin);
        gets(tenNV);
        cout << "nhap ma ca: ";
        fflush(stdin);
        gets(maCA);
    }
    friend class PHIEU;
};
class KHO
{
private:
    char makho[10];
    char diachi[30];

public:
    void nhap()
    {
        cout << "nhap ma kho: ";
        fflush(stdin);
        gets(makho);
        cout << "nhap dia chi: ";
        fflush(stdin);
        gets(diachi);
    }
    friend class PHIEU;
};
class PHIEU
{
private:
    char maP[10];
    char ngaylap[20];
    THIETBI *tb;
    NHANVIEN nv;
    KHO k;
    int n;

public:
    void nhap()
    {
        cout << "nhap ma phieu: ";
        fflush(stdin);
        gets(maP);
        cout << "nhap ngay lap: ";
        fflush(stdin);
        gets(ngaylap);
        nv.nhap();
        k.nhap();
        do
        {
            cout << "nhap so luong thiet bi: ";
            cin >> n;
        } while (n < 0);
        tb = new THIETBI[n];
        for (int i = 0; i < n; i++)
        {
            cout << "nhap thiet bi thu " << i + 1 << endl;
            tb[i].nhap();
        }
    }
    void xuat()
    {
        cout << left << "DIEN MAY ABC" << endl;
        cout << "\t\t\t\tPHIEU NHAP KHO" << endl;
        cout << left << setw(15) << "Ma phieu: " << setw(25) << maP << "ngay lap: " << setw(25) << ngaylap << endl;
        cout << left << setw(15) << "Ma nhan vien: " << setw(25) << nv.maNV << "ho ten: " << setw(25) << nv.tenNV << "ma ca: " << setw(25) << nv.maCA << endl;
        cout << left << setw(15) << "Ma kho: " << setw(25) << k.makho << "dia chi kho: " << setw(25) << k.diachi << endl;
        cout << left << setw(10) << "ma TB" << setw(20) << "ten TB" << setw(20) << "so luong" << setw(20) << "don gia" << setw(20) << "thanh tien" << endl;
        for (int i = 0; i < n; i++)
        {
            tb[i].xuat();
        }
        int tong1 = 0;
        for (int i = 0; i < n; i++)
        {
            tong1 += tb[i].soluong;
        }
        int tong2 = 0;
        for (int i = 0; i < n; i++)
        {
            tong2 += tb[i].thanhtien();
        }
        cout << right << "tong so: " << setw(23) << tong1 << setw(43) << tong2 << endl;
        cout << right << setw(80) << "Ha Noi, ngay ... thang... nam 2021" << endl;
    }
    void SUAPHIEU()
    {
        char sua[20] = "22/12/2021";
        strcpy(ngaylap, sua);
    }
    void SAPXEP()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (tb[i].dongia > tb[j].dongia)
                {
                    swap(tb[i], tb[j]);
                }
            }
        }
    }
};
int main()
{
    PHIEU p;
    cout << "======nhap thong tin PHIEU ========" << endl;
    p.nhap();
    cout << "======thong tin PHIEU ========" << endl;
    p.xuat();
    p.SUAPHIEU();
    cout << "PHIEU da sua !" << endl;
    cout << "=======PHIEU da sap xep=======" << endl;
    p.SAPXEP();
    p.xuat();
}