#include <iostream>

using namespace std;

void sap_xep_chen(int x[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tam = x[i], j = i - 1;
        while (j > -1 && x[j] < tam)
        {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = tam;
    }
}
int main()
{
    int x[10] = {18, 73, 17, 56, 10, 86};
    sap_xep_chen(x, 6);
    cout << "\n---DANH SACH SAU KHI SAP XEP---" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << x[i] << " ";
    }
}
