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
    for (int i = 0; i < n; i++)
    {
        cout << *(ds + i);
        cout << setw(10);
    }
}
void SAPXEP(int *ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (ds[i] > ds[j])
            {
                swap(ds[i], ds[j]);
                SAPXEP(ds, n - 1);
            }
        }
    }
}
int main()
{
    int *ds;
    int n;
    NHAPDAYSO(ds, n);
    cout << "\nday so vua nhap la: " << endl;
    XUATDAYSO(ds, n);
    SAPXEP(ds, n);
    cout << "\nday so da sap xep la: " << endl;
    XUATDAYSO(ds, n);
}