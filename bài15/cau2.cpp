#include <iostream>

using namespace std;

int sum(int a[], int left, int right)
{
    int sum = 0;
    int sum1, sum2 = 0;
    if (left == right)
    {
        sum = a[left];
        return sum;
    }
    else
    {
        int mid = (left + right) / 2;
        for (int i = 1; i <= mid; i++)
        {
            sum1 += a[i];
        }
        for (int i = mid + 1; i <= right; i++)
        {
            sum2 += a[i];
        }
        return (sum1 + sum2);
    }
}
int main()
{
    int a[10];
    int n;
    cout << " nhap so phan tu: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "nhap so thu " << i << ": ";
        cin >> a[i];
    }
    cout << "Sum= " << sum(a, 1, n);
}