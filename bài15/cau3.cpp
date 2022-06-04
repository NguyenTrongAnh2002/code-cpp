#include <iostream>
#include <iomanip>

using namespace std;

void sap_tang_dan(int a[], int n)
{
    for (int i = 1; i <= n ; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
void gready(int a[], int n, long s)
{
    int so_goi_hang_duoc_chon;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < s)
        {
            so_goi_hang_duoc_chon = s / a[i];
            s -= so_goi_hang_duoc_chon * a[i];
            cout << "chon " << so_goi_hang_duoc_chon << " goi hang co thoi gian van chuyen la " << a[i]  << endl;
        }
    }
}

int main()
{
    int a[10];
    int n;

    do
    {
        cout << "nhap so luong goi hang: ";
        cin >> n;
    } while (n < 0);
    for (int i = 1; i <= n; i++)
    {
        cout << "nhap thoi gian goi hang " << i << ": ";
        cin >> a[i];
    }
    sap_tang_dan(a, n);
    gready(a, n, 10);
}
    do
    {
        cout << "nhap so luong goi hang: ";
        cin >> n;
    } while (n < 0);
    for (int i = 1; i <= n; i++)
    {
        cout << "nhap thoi gian goi hang " << i << ": ";
        cin >> a[i];
    }
    sap_tang_dan(a, n);
    gready(a, n, 10);
}
