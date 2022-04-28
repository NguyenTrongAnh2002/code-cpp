#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class DOTPRINTER;
class LASERPRINTER;
class PRINTER
{
protected:
    float trongluong;
    char hangSX[20];
    char namSX[4];
    char tocdo[20];

public:
    void nhap()
    {
        cout << "nhap hang san xuat : ";
        fflush(stdin);
        gets(hangSX);
        cout << "nhap nam san xuat : ";
        fflush(stdin);
        gets(namSX);
        cout << "nhap toc do : ";
        fflush(stdin);
        gets(tocdo);
        cout << "nhap trong luong: ";
        cin >> trongluong;
    }
    void xuat();
    friend class DOTPRINTER;
    friend class LASERPRINTER;
};
class DOTPRINTER : public PRINTER
{
    char matdokim[15];

public:
    void nhap()
    {
        PRINTER::nhap();
        cout << "nhap mat do kim: ";
        fflush(stdin);
        gets(matdokim);
    }
    void xuat()
    {
        cout << left << setw(20) << hangSX << setw(20) << namSX << setw(20) << tocdo << setw(20) << trongluong << setw(20) << matdokim << endl;
    }
};
class LASERPRINTER : public PRINTER
{
    float dophangiai;

public:
    void nhap()
    {
        PRINTER::nhap();
        cout << "nhap do phan giai: ";
        cin >> dophangiai;
    }
    void xuat()
    {
        cout << left << setw(20) << hangSX << setw(20) << namSX << setw(20) << tocdo << setw(20) << trongluong << setw(20) << dophangiai << endl;
    }
};
int main()
{
    DOTPRINTER a;
    LASERPRINTER b;
    cout << "\n------nhap thong tin may in kim------" << endl;
    a.nhap();
    cout << "\n--------thong tin may in kim-------" << endl;
    cout << left << setw(20) << "hang SX" << setw(20) << "nam SX" << setw(20) << "toc do" << setw(20) << "trong luong" << setw(20) << "mat do kim" << endl;
    a.xuat();
    cout << "\n------nhap thong tin may in laser------" << endl;
    b.nhap();
    cout << "\n--------thong tin may in laser-------" << endl;
    cout << left << setw(20) << "hang SX" << setw(20) << "nam SX" << setw(20) << "toc do" << setw(20) << "trong luong" << setw(20) << "do phan giai" << endl;
    b.xuat();
}
