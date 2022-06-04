#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct SINHVIEN
{
    char SBD[15];
    char hoten[30];
    float tong_diem_thi;
};
struct node
{
    SINHVIEN dulieu;
    node *next;
};
typedef node *TRO;

void create(TRO &L)
{
    L = NULL;
}
void add(TRO &L, SINHVIEN sv)
{
    TRO P = new node;
    P->dulieu = sv;
    P->next = NULL;
    if (L == NULL)
    {
        L = P;
    }
    else
    {
        TRO Q = L;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}
SINHVIEN taosv(char *sbd, char *ht, float tdt)
{
    SINHVIEN sv;
    strcpy(sv.SBD, sbd);
    strcpy(sv.hoten, ht);
    sv.tong_diem_thi = tdt;
    return sv;
}
void input(TRO &L)
{
    add(L, taosv("1", "nguyen van A", 9.5));
    add(L, taosv("2", "nguyen van B", 8.5));
    add(L, taosv("3", "nguyen van C", 7.7));
    add(L, taosv("4", "nguyen van D", 8.5));
    add(L, taosv("5", "nguyen van E", 6.5));
}
void hienthi_sinhvien(SINHVIEN sv)
{
    cout << left << setw(10) << sv.SBD;
    cout << setw(30) << sv.hoten;
    cout << setw(30) << sv.tong_diem_thi << endl;
}
void hienthi_ds(TRO L)
{
    cout << left << setw(10) << "SBD ";
    cout << setw(30) << "ho va ten  ";
    cout << setw(30) << "tong diem thi " << endl;
    while (L != NULL)
    {
        hienthi_sinhvien(L->dulieu);
        L = L->next;
    }
}
void chenvitrithu3(TRO &L)
{
    SINHVIEN temp;
    temp = taosv("6", "nguyen van F", 8.0);
    int d = 1;
    TRO M, Q = L;
    while (Q != NULL && d < 3)
    {
        M = Q;
        Q = Q->next;
        d++;
    }
    if (Q == NULL)
    {
        cout << "\tVi tri khong thich hop" << endl;
        return;
    }
    TRO P = new node;
    P->dulieu = temp;
    P->next = M->next;
    M->next = P;
}
int main()
{
    TRO L;
    create(L);
    input(L);
    cout << "\n---Danh sach sinh vien---" << endl;
    hienthi_ds(L);
    cout << "\n----Danh sach sau khi chen---" << endl;
    chenvitrithu3(L);
    hienthi_ds(L);
}