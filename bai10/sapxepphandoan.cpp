#include <iostream>

using namespace std;

void quick_sort(int x[], int left, int right)
{
    if (left < right)
    {
        int k = (left + right) / 2, t = x[k];
        int i = left, j = right;
        do
        {
            while (x[i] < t)
                i = i + 1;
            while (x[j] > t)
                j = j - 1;
            if (i <= j)
            {
                int tg = x[i];
                x[i] = x[j];
                x[j] = tg;
                i = i + 1;
                j = j - 1;
            }
        } while (i <= j);
        quick_sort(x, left, j);
        quick_sort(x, i, right);
    }
}
int main()
{
    int x[10] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    quick_sort(x, 0, 8);
    cout << "\nday sau khi sap xep la: " << endl;
    for (int i = 0; i < 9; i++)
        cout << x[i] << " ";
    return 0;
}
