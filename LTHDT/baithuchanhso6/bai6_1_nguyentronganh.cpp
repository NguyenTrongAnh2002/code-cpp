#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

class VECTOR
{
    int x, y;

public:
    friend ostream &operator<<(ostream &out, VECTOR &A)
    {
        out << "(" << A.x << "," << A.y << ")" << endl;
    }
    friend istream &operator>>(istream &in, VECTOR &A)
    {
        cout << "nhap toa do x: ";
        in >> A.x;
        cout << "nhap toa do y: ";
        in >> A.y;
        return in;
    }
    VECTOR operator+(VECTOR A);
    VECTOR operator-(VECTOR A);
};
VECTOR VECTOR::operator+(VECTOR A)
{
    VECTOR T;
    T.x = x + A.x;
    T.y = y + A.y;
    return T;
}
VECTOR VECTOR::operator-(VECTOR A)
{
    VECTOR H;
    H.x = x - A.x;
    H.y = y - A.y;
    return H;
}
int main()
{
    VECTOR A, B, T, H;
    cout << "nhap vector A: " << endl;
    cin >> A;
    cout << A;
    cout << "nhap vector B: " << endl;
    cin >> B;
    cout << B;
    T = A + B;
    H = A - B;
    cout << "ket qua cong vector la: " << T << endl;
    cout << "ket qua tru vector la: " << H << endl;
}
