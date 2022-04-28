#include <iostream>
#include <fstream>
using namespace std;

class BINHCHUA
{
public:
    BINHCHUA()
    {
        dai = 0;
        rong = 0;
        cao = 0;
    }

    BINHCHUA(float a, float b, float c)
    {
        dai = a;
        rong = b;
        dai = c;
    }

    friend istream &operator>>(istream &in, BINHCHUA &b)
    {
        cout << "Dai= ";
        in >> b.dai;
        cout << "Rong= ";
        in >> b.rong;
        cout << "Cao= ";
        in >> b.cao;
        return in;
    }
    friend ostream &operator<<(ostream &out, BINHCHUA b)
    {
        out << "(" << b.dai << "," << b.rong << "," << b.cao << ")";
        return out;
    }

    bool operator==(BINHCHUA b)
    {
        if (dai * rong * cao == b.dai * b.rong * b.cao)
        {
            return true;
        }
        else
            return false;
    }

    bool isHLP()
    {
        if (dai == rong && dai == cao)
        {
            return true;
        }
        else
            return false;
    }

private:
    float dai;
    float rong;
    float cao;
};

int main()
{
    BINHCHUA a;
    BINHCHUA b;
    fstream f;
    f.open("KQ.txt", ios::out);
    cin >> a;
    cin >> b;
    f << "BC a: " << a;
    f << "\nBC b: " << b;
    cout << "BC a: " << a;
    cout << "\nBC b: " << b;
    if (a == b)
    {
        cout << "\nThe tich bang nhau";
        f << "\nThe tich bang nhau";
    }
    else
    {
        cout << "\nThe tich ko bang nhau";
        f << "\nThe tich ko bang nhau";
    }
    if (a.isHLP())
    {
        cout << "\nA la Hinh lap phuong";
        f << "\nA la Hinh lap phuong";
    }
    else
    {
        cout << "\nA ko la Hinh lap phuong";
        f << "\nA ko la Hinh lap phuong";
    }
    if (b.isHLP())
    {
        cout << "\nB la Hinh lap phuong";
        f << "\nB la Hinh lap phuong";
    }
    else
    {
        cout << "\nB ko la Hinh lap phuong";
        f << "\nB ko la Hinh lap phuong";
    }
}