#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class OTO;
class MOTO;
class VEHICLE
{
protected:
    char nhanhieu[20];
    char namSX[5];
    char hang[10];

public:
    void nhap()
    {
        cout << "nhap nhan hieu : ";
        fflush(stdin);
        gets(nhanhieu);
        cout << "nhap nam san xuat : ";
        fflush(stdin);
        gets(namSX);
        cout << "nhap hang : ";
        fflush(stdin);
        gets(hang);
    }
    void xuat();
    friend class OTO;
    friend class MOTO;
};
class OTO : public VEHICLE
{
    int sochongoi;
    char dungtich[15];

public:
    void nhap()
    {
        VEHICLE::nhap();
        cout << "nhap so cho ngoi: ";
        cin >> sochongoi;
        cout << "nhap dung tich oto: ";
        fflush(stdin);
        gets(dungtich);
    }
    void xuat()
    {
        cout << left << setw(20) << nhanhieu << setw(20) << namSX << setw(20) << hang << setw(20) << sochongoi << setw(20) << dungtich << endl;
    }
};
class MOTO : public VEHICLE
{
    float phankhoi;

public:
    void nhap()
    {
        VEHICLE::nhap();
        cout << "nhap phan khoi: ";
        cin >> phankhoi;
    }
    void xuat()
    {
        cout << left << setw(20) << nhanhieu << setw(20) << namSX << setw(20) << hang << setw(20) << phankhoi << endl;
    }
};
int main()
{
    OTO a;
    MOTO b;
    cout << "\n------nhap thong tin xe oto------" << endl;
    a.nhap();
    cout << "\n--------thong tin xe oto-------" << endl;
    cout << left << setw(20) << "nhan hieu" << setw(20) << "nam SX" << setw(20) << "hang" << setw(20) << "so cho ngoi" << setw(20) << "dung tich" << endl;
    a.xuat();
    cout << "\n------nhap thong tin xe moto------" << endl;
    b.nhap();
    cout << "\n--------thong tin xe moto-------" << endl;
    cout << left << setw(20) << "nhan hieu" << setw(20) << "nam SX" << setw(20) << "hang" << setw(20) << "phan khoi" << endl;
    b.xuat();
}
