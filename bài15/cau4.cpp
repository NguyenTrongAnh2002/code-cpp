#include <iostream>

using namespace std;

void sap_xep_noi_bot(int x[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] < x[j])
            {
                swap(x[i], x[j]);
            }
        }
    }
}
int main()
{
    int x[10] = {18, 73, 17, 56, 10, 86};
    sap_xep_noi_bot(x, 6);
    cout << "\n---DANH SACH SAU KHI SAP XEP--- " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << x[i] << " ";
    }
}