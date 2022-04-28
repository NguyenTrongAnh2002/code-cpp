#include <iostream>
#include <fstream>

using namespace std;

class HANG
{
private:
    int trongluong;
    long giatien;
    float thetich;

public:
    HANG()
    {
        trongluong = 0;
        giatien = 0;
        thetich = 0;
    }
    HANG(int tl, long gt, float tt)
    {
        trongluong = tl;
        giatien = gt;
        thetich = tt;
    }
    HANG operator+(HANG X)
    {
        HANG T;
        T.trongluong = trongluong + X.trongluong;
        T.giatien = giatien + X.giatien;
        T.thetich = thetich + X.thetich;
        return T;
    }
    bool operator==(HANG X)
    {
        if (X.trongluong == trongluong && X.giatien == giatien)
        {
            return true;
        }
        else
            return false;
    }
    friend istream &operator>>(istream &in, HANG &X)
    {
        cout << "nhap trong luong: ";
        in >> X.trongluong;
        cout << "nhap gia tien: ";
        in >> X.giatien;
        cout << "nhap the tich: ";
        in >> X.thetich;
        return in;
    }
    friend ostream &operator<<(ostream &out, HANG X)
    {
        out << " trong luong: " << X.trongluong << endl;
        out << " gia tien: " << X.giatien << endl;
        out << " the tich: " << X.thetich << endl;
        return out;
    }
};
int main()
{
    HANG X, Y;
    fstream f;
    f.open("KETQUA.TXT", ios::out);
    cout << "\tNhap mat hang X: " << endl;
    cin >> X;
    cout << "\tmat hang X: " << endl;
    cout << X;
    f << "\tmat hang X:\n"
      << X << endl;
    cout << "\tNhap mat hang Y: " << endl;
    cin >> Y;
    cout << "\tmat hang Y: " << endl;
    cout << Y;
    f << "\tmat hang Y:\n"
      << Y << endl;
    if (X == Y)
    {
        cout << "\n2 mat hang cung gia va cung trong luong . " << endl;
        f << "\n2 mat hang cung gia va cung trong luong . " << endl;
    }
    else
    {
        cout << "\n2 mat hang khong cung gia va khong cung trong luong . " << endl;
        f << "\n2 mat hang khong cung gia va khong cung trong luong . " << endl;
    }
}