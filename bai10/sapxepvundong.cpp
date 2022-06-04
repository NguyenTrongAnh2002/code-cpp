#include <iostream>

using namespace std;

void vun_dong(int x[], int k, int n)
{
    if (k <= n / 2 - 1)
    {
        int j = 2 * k + 1;
        if (j < n - 1 && x[j] < x[j + 1])
            j = j + 1;
        if (x[k] < x[j])
        {
            int tg = x[k];
            x[k] = x[j];
            x[j] = tg;
            vun_dong(x, j, n);
        }
    }
}
void tao_dong_dau_tien(int x[], int n)
{
    for (int k = n / 2 - 1; k >= 0; k--)
        vun_dong(x, k, n);
}
void heapSort(int x[], int n)
{
    tao_dong_dau_tien(x, n);
    for (int i = n; i >= 2; i--)
    {
        int tg = x[0];
        x[0] = x[i - 1];
        x[i - 1] = tg;
        vun_dong(x, 0, i - 1);
    }
}

int main()
{
    int x[10] = {14, 24, 54, 84, 64, 94, 74};
    heapSort(x, 8);
    cout << "\nday sau khi sap xep la: " << endl;
    for (int i = 0; i < 8; i++)
        cout << x[i] << " ";
    return 0;
}