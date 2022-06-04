#include <iostream>
#include <iomanip>
#include <string.h>
#define MAX 8

using namespace std;

struct SINHVIEN
{
    char SBD[15];
    char hoten[30];
    float tong_diem_thi;
};
struct list
{
    int count;
    SINHVIEN sv[MAX];
};
void create(list &L)
{
    L.count = 0;
}
int empty(list L)
{
    return L.count == 0;
}
int full(list L)
{
    return L.count == MAX - 1;
}
int add(list &L, SINHVIEN sv)
{
    if (full(L))
    {
        return 0;
    }
    else
    {
        L.count++;
        L.sv[L.count] = sv;
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
void input(list &L)
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
void ht_danh_sach(list L)
{
    cout << left << setw(10) << "SBD ";
    cout << setw(30) << "ho va ten  ";
    cout << setw(30) << "tong diem thi " << endl;
    for (int i = 1; i <= L.count; i++)
    {
        hienthi_sinhvien(L.sv[i]);
    }
}
void chenvitridautien(list &L)
{
    SINHVIEN temp;
    temp = taosv("6", "nguyen van F", 8.0);
    for (int i = L.count; i >= 3; i--)
    {
        L.sv[i + 1] = L.sv[i];
    }
    L.sv[3] = temp;
    L.count++;
}

int main()
{
    list L;
    create(L);
    input(L);
    cout << "\n---Danh sach sinh vien---" << endl;
    ht_danh_sach(L);
    cout << "\n---Danh sach hang hoa sau khi chen---" << endl;
    chenvitridautien(L);
    ht_danh_sach(L);
}
