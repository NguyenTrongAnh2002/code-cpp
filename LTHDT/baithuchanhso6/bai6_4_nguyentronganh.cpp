#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

class TAMTHUC
{
    int a, b, c;

public:
    friend ostream &operator<<(ostream &out, TAMTHUC &A)
    {
        out << A.a << "x^2 + " << A.b << "x + " << A.c << endl;
    }
    friend istream &operator>>(istream &in, TAMTHUC &A)
    {
        cout << "nhap he so x^2: ";
        in >> A.a;
        cout << "nhap he so x: ";
        in >> A.b;
        cout << "nhap he so tu do: ";
        in >> A.c;
        return in;
    }
    TAMTHUC operator+(TAMTHUC A);
    TAMTHUC operator-(TAMTHUC A);
    TAMTHUC operator-();
};
TAMTHUC TAMTHUC::operator+(TAMTHUC A)
{
    TAMTHUC T;
    T.a = a + A.a;
    T.b = b + A.b;
    T.c = c + A.c;
    return T;
}
TAMTHUC TAMTHUC::operator-(TAMTHUC A)
{
    TAMTHUC H;
    TAMTHUC T;
    T.a = a - A.a;
    T.b = b - A.b;
    T.c = c - A.c;
    return H;
}
TAMTHUC TAMTHUC::operator-()
{
    TAMTHUC DD;
    DD.a = -a;
    DD.b = -b;
    DD.c = -c;
    return DD;
}
int main()
{
    TAMTHUC A, B, T, H, DD;
    cout << "nhap tam thuc thu nhat: " << endl;
    cin >> A;
    cout << A;
    cout << "nhap tam thuc thu hai: " << endl;
    cin >> B;
    cout << B;
    T = A + B;
    H = A - B;
    DD = -A;
    cout << "ket qua cong 2 tam thuc la: " << T << endl;
    cout << "ket qua tru 2 tam thuc la: " << H << endl;
    cout << " doi dau" << DD;
}
