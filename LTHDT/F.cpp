#include <iostream>
#include <math.h>

using namespace std;

float F(float x)
{
    if (x == 0)
    {
        return cos(x);
    }
    else if (x < 0)
    {
        return x;
    }
    else
    {
        return F(x - M_PI) + F(x - M_PI / 2);
    }
}
int main()
{
    float x;
    cout << "\nnhap x: ";
    cin >> x;

    cout << "F= " << F(x * M_PI / 2);
}