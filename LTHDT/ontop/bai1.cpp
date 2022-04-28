#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class PHUONGTIEN
{
public:
    void Nhap()
    {
        cout << "Nhap ma phuong tien: ";
        fflush(stdin);
        gets(maPT);
        cout << "Nhap loai: ";
        fflush(stdin);
        gets(loai);
        cout << "Nhap gia: ";
        cin >> gia;
        cout << "Nhap hang sx: ";
        fflush(stdin);
        gets(hangSX);
    }

    void Xuat()
    {
        cout << "\n"
             << setw(20) << maPT << setw(20) << loai << setw(20) << gia << setw(20) << hangSX;
    }

protected:
    char maPT[10];
    char loai[10];
    long gia;
    char hangSX[20];
};

class XEMAY : public PHUONGTIEN
{
public:
    void Nhap()
    {
        PHUONGTIEN::Nhap();
        cout << "Nhap ma xe: ";
        getline(cin, maxe);
        cout << "Nhap ten xe: ";
        getline(cin, tenxe);
        cout << "Nhap dung tich: ";
        cin >> dungtich;
        cin.ignore();
        cout << "Nhap bien so: ";
        getline(cin, bienso);
    }
    void Xuat()
    {
        PHUONGTIEN::Xuat();
        cout << setw(20) << maxe << setw(20) << tenxe << setw(20) << dungtich << setw(20) << bienso;
    }
    float getDungTich()
    {
        return dungtich;
    }

private:
    string maxe;
    string tenxe;
    float dungtich;
    string bienso;
};

class BAIXE
{
public:
    void Nhap()
    {
        cout << "Nhap ma bai xe: ";
        fflush(stdin);
        gets(mabx);
        cout << "Nhap ten bai xe: ";
        fflush(stdin);
        gets(tenbx);
        cout << "Nhap dien tich: ";
        cin >> dientich;
        cout << "Nhap so xe may hien co: ";
        cin >> n;
        cin.ignore();
        x = new XEMAY[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap xe may thu " << i << "\n";
            x[i].Nhap();
        }
    }
    void Xuat()
    {
        cout << "\nMa bai xe: " << mabx;
        cout << "\nTen bai xe: " << tenbx;
        cout << "\n"
             << setw(20) << "Ma phuong tien" << setw(20) << "Loai" << setw(20) << "Gia" << setw(20) << "Hang san xuat" << setw(20) << "Ma xe" << setw(20) << "Ten xe" << setw(20) << "Dung tich" << setw(20) << "Bien so";
        for (int i = 0; i < n; i++)
        {
            x[i].Xuat();
        }
    }
    void SapXep()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (x[i].getDungTich() > x[j].getDungTich())
                {
                    XEMAY temp;
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }
    }
    void SuaTenBX()
    {
        char ten[10] = "mai dich";
        strcpy(tenbx, ten);
    }

private:
    char mabx[10];
    char tenbx[20];
    float dientich;
    XEMAY *x;
    int n;
};

int main()
{
    BAIXE a;
    a.Nhap();
    cout << "\n\n================BAI DO XE==============\n";
    a.Xuat();
    a.SuaTenBX();
    cout << "\nDa sua ten bai xe";
    cout << "\n\n=============SAP XEP============\n";
    a.SapXep();
    a.Xuat();
}