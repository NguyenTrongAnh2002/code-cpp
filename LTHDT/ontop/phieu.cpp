#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class PHIEU;
class KHACHHANG
{
private:
    char maKH[10];
    char tenkhoan[30];
    int soluong;
    long tamung;
    long conlai;

public:
    void nhap()
    {
        cout << "nhap ma khach hang: ";
        fflush(stdin);
        gets(maKH);
        cout << "nhap ten khoan: ";
        fflush(stdin);
        gets(tenkhoan);
        cout << "nhap so luong: ";
        cin >> soluong;
        cout << "nhap tam ung: ";
        cin >> tamung;
        cout << "nhap con lai: ";
        cin >> conlai;
    }
    void xuat()
    {
        cout << left << setw(20) << maKH << setw(20) << tenkhoan << setw(20) << soluong << setw(20) << tamung << setw(20) << conlai << endl;
    }
    friend class PHIEU;
};
class NHANVIEN
{
private:
    char maNV[10];
    char tenNV[30];

public:
    void nhap()
    {
        cout << "nhap ma nhan vien: ";
        fflush(stdin);
        gets(maNV);
        cout << "nhap ten nhan vien: ";
        fflush(stdin);
        gets(tenNV);
    }
    friend class PHIEU;
};
class PHONGBAN
{
private:
    char maPB[10];
    char tenPB[20];

public:
    void nhap()
    {
        cout << "nhap ma phong ban: ";
        fflush(stdin);
        gets(maPB);
        cout << "nhap ten phong ban: ";
        fflush(stdin);
        gets(tenPB);
    }
    friend class PHIEU;
};
class PHIEU
{
private:
    char maP[10];
    char ngaylap[20];
    int thangtinhluong;
    int nam;
    KHACHHANG *kh;
    NHANVIEN nv;
    PHONGBAN pb;
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
        pb.nhap();
        cout << "nhap thang tinh luong: ";
        cin >> thangtinhluong;
        cout << "nhap nam: ";
        cin >> nam;
        do
        {
            cout << "nhap so khach hang: ";
            cin >> n;
        } while (n < 0);
        kh = new KHACHHANG[n];
        for (int i = 0; i < n; i++)
        {
            cout << "nhap khach hang thu " << i + 1 << endl;
            kh[i].nhap();
        }
    }
    void xuat()
    {
        cout << left << "CONG TY MEGA" << endl;
        cout << setw(60) << "PHIEU LUONG" << endl;
        cout << left << setw(15) << "Ma phieu: " << setw(20) << maP << "ngay lap: " << setw(20) << ngaylap << endl;
        cout << left << setw(15) << "Ma nhan vien: " << setw(20) << nv.maNV << "Ten nhan vien: " << setw(20) << nv.tenNV << "ma phong ban: " << setw(20) << pb.maPB << endl;
        cout << left << setw(15) << "Ten phong ban: " << setw(20) << pb.tenPB << "thang tinh luong : " << setw(20) << thangtinhluong << "nam: " << setw(20) << nam << endl;
        cout << left << setw(20) << "ma KH" << setw(20) << "ten khoan" << setw(20) << "so luong" << setw(20) << "tam ung" << setw(20) << "con lai" << endl;
        for (int i = 0; i < n; i++)
        {
            kh[i].xuat();
        }
        int tong = 0;
        for (int i = 0; i < n; i++)
        {
            tong += kh[i].conlai;
        }
        cout << right << setw(60) << "TONG: " << setw(60) << tong << endl;
        cout << right << setw(120) << "Ha Noi, ngay ... thang ... nam 2021" << endl;
    }
    void suaNGAYTL()
    {
        char sua[20] = "25/12/2021";
        strcpy(ngaylap, sua);
    }
    void SAPXEP()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (kh[i].conlai > kh[j].conlai)
                {
                    swap(kh[i], kh[j]);
                }
            }
        }
    }
};
int main()
{
    PHIEU p;
    cout << "===========nhap thong tin phieu============" << endl;
    p.nhap();
    cout << "===========thong tin phieu============" << endl;
    p.xuat();
    p.suaNGAYTL();
    cout << "\tDA SUA PHIEU! " << endl;
    cout << "===========sau khi sap xep============" << endl;
    p.SAPXEP();
    p.xuat();
}