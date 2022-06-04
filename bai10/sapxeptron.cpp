#include <iostream>

using namespace std;

void merge(int *X, int bt1, int w1, int bt2, int w2, int *Z)
{

    int i = bt1, j = bt2, bp1 = bt1 + w1 - 1;
    int bp2 = bt2 + w2 - 1, k = bt1;

    while (i <= bp1 && j <= bp2)
    {
        if (X[i] < X[j])
        {
            Z[k] = X[i];
            i++;
            k++;
        }
        else
        {
            Z[k] = X[j];
            j++;
            k++;
        }
    }
    while (i <= bp1)
    {
        Z[k] = X[i];
        i++;
        k++;
    }
    while (j <= bp2)
    {
        Z[k] = X[j];
        j++;
        k++;
    }
}
void mergePass(int X[], int n, int K, int Z[])
{
    int cv = n / (2 * K);
    int s = 2 * K * cv;
    int r = n - s;
    for (int j = 1; j <= cv; j++)
    {
        int b1 = (2 * j - 2) * K;
        merge(X, b1, K, b1 + K, K, Z);
    }

    if (r <= K)
        for (int j = 0; j < r; j++)
        {
            Z[s + j] = X[s + j];
        }
    else
        merge(X, s, K, s + K, r - K, Z);
}
void mergeSort(int X[], int n)
{
    int Z[15];
    int K = 1;

    while (K < n)
    {

        mergePass(X, n, K, Z);

        mergePass(Z, n, 2 * K, X);
        K = K * 4;
    }
}
int main()
{
    int x[15] = {42, 23, 74, 11, 65, 58, 94, 36, 99, 87};
    mergeSort(x, 10);
    cout << "\nday sau khi sap xep la: " << endl;
    for (int i = 0; i < 10; i++)
        cout << x[i] << " ";
    return 0;
}
