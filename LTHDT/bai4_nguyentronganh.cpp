#include <iostream>
#include <iomanip>

using namespace std;

void NHAPDAYSO(int *&ds, int &n)
{
    do
    {
        cout << "so phan tu: ";
        cin >> n;
    } while (n <= 0);
    ds = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap so thu " << i + 1 << ": ";
        cin >> *(ds + i);
    }
}
void XUATDAYSO(int *ds, int n)
{
    cout << "day so vua nhap la: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(ds + i);
        cout << setw(10);
    }
}
float TONGDAYSO(int *ds, int n)
{
    for (int i = n; i > 0; i--)
    {
        return ds[i - 1] + TONGDAYSO(ds, n - 1);
    }
}
int main()
{
    int *ds;
    int n;
    NHAPDAYSO(ds, n);
    XUATDAYSO(ds, n);
    cout << "\ntong day so la: " << TONGDAYSO(ds, n);
}