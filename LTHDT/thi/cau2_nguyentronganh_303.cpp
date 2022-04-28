#include <iostream>
#include <fstream>

using namespace std;

class THUADAT
{
private:
    float chieudai, chieurong;
    long giatien;

public:
    THUADAT()
    {
        chieudai = 0;
        chieurong = 0;
        giatien = 0;
    }
    THUADAT(float d, float r, long gt)
    {
        chieudai = d;
        chieurong = r;
        giatien = gt;
    }
    float dientich()
    {
        return chieudai * chieurong;
    }
    bool operator==(THUADAT a)
    {
        if (dientich() == a.dientich() && giatien == a.giatien)
        {
            return true;
        }
        else
            return false;
    }
    friend istream &operator>>(istream &in, THUADAT &a)
    {
        cout << "nhap chieu dai: ";
        in >> a.chieudai;
        cout << "nhap chieu rong: ";
        in >> a.chieurong;
        cout << "nhap gia tien: ";
        in >> a.giatien;
        return in;
    }
    friend ostream &operator<<(ostream &out, THUADAT a)
    {
        out << "chieu dai: " << a.chieudai << endl;
        out << "chieu rong: " << a.chieurong << endl;
        out << "gia tien: " << a.giatien << endl;
        return out;
    }
};
int main()
{
    THUADAT a, b;
    fstream f;
    f.open("KETQUA.TXT", ios::out);
    cout << "nhap thong tin thua dat a: " << endl;
    cin >> a;
    cout << "thong tin thua dat a: " << endl;
    f << "thong tin thua dat a:\n " << a << endl;
    cout << a;
    cout << "nhap thong tin thua dat b: " << endl;
    cin >> b;
    cout << "thong tin thua dat b: " << endl;
    cout << b;
    f << "thong tin thua dat b:\n " << b << endl;
    if (a == b)
    {
        cout << "2 thua a va b co cung gia tien va dien tich ! " << endl;
        f << "2 thua a va b co cung gia tien va dien tich !" << endl;
    }
    else
    {
        cout << "2 thua a va b khong cung gia tien va dien tich !" << endl;
        f << "2 thua a va b khong cung gia tien va dien tich !" << endl;
    }
}