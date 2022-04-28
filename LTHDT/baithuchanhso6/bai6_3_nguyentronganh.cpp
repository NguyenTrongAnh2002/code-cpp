#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

class SOPHUC
{
    int a, b;

public:
    friend ostream &operator<<(ostream &out, SOPHUC &A)
    {
        out << "(" << A.a << "+" << A.b << "*i)" << endl;
    }
    friend istream &operator>>(istream &in, SOPHUC &A)
    {
        cout << "nhap phan thuc: ";
        in >> A.a;
        cout << "nhap phan ao: ";
        in >> A.b;
        return in;
    }
    SOPHUC operator+(SOPHUC A);
    SOPHUC operator-(SOPHUC A);
};
SOPHUC SOPHUC::operator+(SOPHUC A)
{
    SOPHUC T;
    T.a = a + A.a;
    T.b = b + A.b;
    return T;
}
SOPHUC SOPHUC::operator-(SOPHUC A)
{
    SOPHUC H;
    H.a = a - A.a;
    H.b = b - A.b;
    return H;
}
int main()
{
    SOPHUC A, B, T, H;
    cout << "nhap so phuc thu nhat: " << endl;
    cin >> A;
    cout << A;
    cout << "nhap so phuc thu hai: " << endl;
    cin >> B;
    cout << B;
    T = A + B;
    H = A - B;
    cout << "ket qua cong 2 so phuc la: " << T << endl;
    cout << "ket qua tru 2 so phuc la: " << H << endl;
}
