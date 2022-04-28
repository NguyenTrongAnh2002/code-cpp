#include <iostream>
#include <fstream>

using namespace std;

class BOX
{
private:
    float d, r, c;

public:
    float tt()
    {
        return d * r * c;
    }
    friend float operator*(BOX BO1, BOX BO2)
    {
        return BO1.tt() * BO2.tt();
    }
    friend istream &operator>>(istream &in, BOX &BO1)
    {
        cout << "nhap chieu dai: ";
        in >> BO1.d;
        cout << "nhap chieu rong: ";
        in >> BO1.r;
        cout << "nhap chieu cao: ";
        in >> BO1.c;
        return in;
    }
    friend ostream &operator<<(ostream &out, BOX BO1)
    {
        out << "chieu dai: " << BO1.d << endl;
        out << "chieu rong: " << BO1.r << endl;
        out << "chieu cao: " << BO1.c << endl;
        return out;
    }
};
int main()
{
    BOX BO1, BO2;
    float T;
    cout << "\n\tnhap BOX BO1 : " << endl;
    cin >> BO1;
    cout << BO1;
    cout << "\n\tnhap BOX BO2 : " << endl;
    cin >> BO2;
    cout << BO2;
    cout << "\nthe tich BOX BO1 la: " << BO1.tt() << endl;
    cout << "\nthe tich BOX BO2 la: " << BO2.tt() << endl;
    T = BO1.tt() * BO2.tt();
    cout << "\nthe tich BOX BO1 * BO2 la: " << T << endl;
    ofstream f("Box.txt");
    f << "The tich BOX BO1: " << BO1.tt() << endl;
    f << "The tich BOX BO2: " << BO2.tt() << endl;
    f << "The tich BOX BO1 * BO2: " << T << endl;
    f.close();
}