#include <iostream>
#include <string.h>
using namespace std;

void DAOCHUOI(char *chuoi)
{

    if (*chuoi)
    {
        DAOCHUOI(chuoi + 1);
        cout << *chuoi;
    }
}
int main()
{
    char xaukytu[30];
    cout << "nhap vao mot xau ky tu: ";
    fflush(stdin);
    gets(xaukytu);
    cout << "xau ki tu sau khi dao nguoc la: ";
    DAOCHUOI(xaukytu);
}
