#include <iostream>

using namespace std;

void sap_xep_lua_chon(int x[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (x[j] > x[m])
                m = j;
        int tg = x[m];
        x[m] = x[i];
        x[i] = tg;
    }
}
int main()
{
    int x[10] = {18, 73, 17, 56, 10, 86};
    sap_xep_lua_chon(x, 6);
    cout << "\n---DANH SACH SAU KHI SAP XEP---" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << x[i] << " ";
    }
}