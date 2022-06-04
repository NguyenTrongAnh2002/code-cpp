#include <iostream>
#include <math.h>

using namespace std;

float f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return 2 * f(n - 1);
    }
}
int main()
{
    cout << "2 mu 7=  " << f(7);
}