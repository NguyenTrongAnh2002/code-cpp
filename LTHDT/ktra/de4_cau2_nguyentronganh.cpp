#include <iostream>

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
    friend float operator+(BOX x, BOX y)
    {
        return x.tt() + y.tt();
    }
    friend float operator-(BOX x, BOX y)
    {
        float H;
        if (x.tt() > y.tt())
        {
            return H = x.tt() - y.tt();
        }
        else
            return H = y.tt() - x.tt();
    }
    friend istream &operator>>(istream &in, BOX &x)
    {
        cout << "nhap chieu dai: ";
        in >> x.d;
        cout << "nhap chieu rong: ";
        in >> x.r;
        cout << "nhap chieu cao: ";
        in >> x.c;
        return in;
    }
    friend ostream &operator<<(ostream &out, BOX x)
    {
        out << "chieu dai: " << x.d << endl;
        out << "chieu rong: " << x.r << endl;
        out << "chieu cao: " << x.c << endl;
        return out;
    }
};
int main()
{
    BOX x, y;
    float T, H;
    cout << "\n\tnhap BOX x : " << endl;
    cin >> x;
    cout << x;
    cout << "\n\tnhap BOX y : " << endl;
    cin >> y;
    cout << y;
    cout << "\nthe tich BOX X la: " << x.tt() << endl;
    cout << "\nthe tich BOX Y la: " << y.tt() << endl;
    T = x.tt() + y.tt();
    cout << "\nthe tich BOX X+Y la: " << T << endl;
    H = x.tt() - y.tt();
    if (H > 0)
    {
        cout << "\nthe tich BOX X-Y la: " << H << endl;
    }
    else
        cout << "\nthe tich BOX Y-X la: " << -H << endl;
}