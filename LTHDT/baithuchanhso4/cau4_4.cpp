#include <iostream>
#include <math.h>

using namespace std;

class PTBAC2
{
private:
    float a, b, c;

public:
    void nhap()
    {
        cout << "nhap he so a= ";
        cin >> a;
        cout << "nhap he so b= ";
        cin >> b;
        cout << "nhap he so c= ";
        cin >> c;
    }
    PTBAC2()
    {
        a = 0;
        b = 0;
        c = 0;
    }
    PTBAC2(float a1, float b1, float c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }

    void xuat();
    void giaiptbac2()
    {
        if (a == 0)
        {
            cout << "pt khong ton tai!" << endl;
        }
        else
        {
            float delta = b * b - 4 * a * c;
            if (delta < 0)
            {
                cout << "pt vo nghiem" << endl;
            }
            else if (delta == 0)
            {
                cout << "pt co nghiem kep x1 = x2 = " << -b / (2 * a);
            }
            else
            {
                cout << "phuong trinh co nghiem x1= " << (-b - sqrt(delta)) / (2 * a) << endl;
                cout << "phuong trinh co nghiem x2= " << (-b + sqrt(delta)) / (2 * a);
            }
        }
    }
};
void PTBAC2::xuat()
{
    cout << a << "x^2 + " << b << "x + " << c << endl;
}
int main()
{
    PTBAC2 Q, P(1, 2, 3);
    cout << "Phuong trinh bac 2 P la:\nP= ";
    P.xuat();
    cout << "nhap phuong trinh bac 2 Q: " << endl;
    Q.nhap();
    Q.xuat();
    Q.giaiptbac2();
    return 0;
}
