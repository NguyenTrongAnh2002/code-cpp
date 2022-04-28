#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class MAYGIAT;
class TULANH;
class ELECTRONIC
{
    float congsuat;
    float dienap;
    void xuat()
    {
        cout << "cong suat: " << congsuat << endl;
        cout << "dien ap: " << dienap << endl;
    }
    ELECTRONIC(float c, float d)
    {
        congsuat = c;
        dienap = d;
    }
    friend class MAYGIAT;
    friend class TULANH;
};
class MAYGIAT : public ELECTRONIC
{
    float dungtich;
    char loai[15];

public:
    MAYGIAT(float dungtich1, char *l, float c, float d) : ELECTRONIC(c, d)
    {
        dungtich = dungtich1;
        strcpy(loai, l);
    }
    void xuat()
    {
        cout << "-----thong tin may giat------" << endl;
        cout << "dung tich: " << dungtich << endl;
        cout << "loai: " << loai << endl;
        ELECTRONIC::xuat();
    }
};
class TULANH : public ELECTRONIC
{
    float dungtich;
    int songan;

public:
    TULANH(float c, float d, float dungtich2, float songan2) : ELECTRONIC(c, d)
    {
        dungtich = dungtich2;
        songan = songan2;
    }
    void xuat()
    {
        cout << "----thong tin tu lanh-----" << endl;
        cout << "dung tich: " << dungtich << endl;
        cout << "so ngan: " << songan << endl;
        ELECTRONIC::xuat();
    }
};
int main()
{
    MAYGIAT a(2, "cua tren", 4, 3);
    TULANH b(5, 6, 7, 8);
    a.xuat();
    b.xuat();
}
