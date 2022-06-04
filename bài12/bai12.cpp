#include <iostream>
#include <iomanip>
#include <string.h>
#define MAX 8

using namespace std;

struct HANGHOA
{
    int maH;
    char tenH[20];
    char donvitinh[20];
    double dongia;
    int soluong;
    double thanhtien;
};
struct list
{
    int count;
    HANGHOA h[MAX];
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
int add(list &L, HANGHOA h)
{
    if (full(L))
    {
        return 0;
    }
    else
    {
        L.count++;
        L.h[L.count] = h;
    }
}
HANGHOA taoHH(int mh, char *ten, char *dvt, double dg, int sl, double tt)
{
    HANGHOA h;
    h.maH = mh;
    strcpy(h.tenH, ten);
    strcpy(h.donvitinh, dvt);
    h.dongia = dg;
    h.soluong = sl;
    h.thanhtien = tt;
    return h;
}
void input(list &L)
{
    add(L, taoHH(2001, "Vo", "quyen", 6500, 20, 130000));
    add(L, taoHH(2002, "but chi", "cai", 12000, 50, 600000));
    add(L, taoHH(2003, "hop but", "chiec", 35000, 15, 525000));
    add(L, taoHH(2004, "tay", "cai", 10000, 50, 500000));
    add(L, taoHH(2005, "thuoc ke", "cai", 7000, 55, 385000));
    add(L, taoHH(2006, "muc", "lo", 15000, 28, 420000));
}
void ht_hh(HANGHOA h)
{
    cout << left << setw(10) << h.maH;
    cout << setw(20) << h.tenH;
    cout << setw(20) << h.donvitinh;
    cout << setw(20) << h.dongia;
    cout << setw(20) << h.soluong;
    cout << setw(20) << h.thanhtien << endl;
}
void ht_danh_sach(list L)
{
    cout << left << setw(10) << "ma hang";
    cout << setw(20) << "ten hang";
    cout << setw(20) << "don vi tinh";
    cout << setw(20) << "don gia";
    cout << setw(20) << "so luong";
    cout << setw(20) << "thanh tien" << endl;
    for (int i = 1; i <= L.count; i++)
    {
        ht_hh(L.h[i]);
    }
}
void xoaHHthu3(list &L)
{
    if (empty(L))
    {
        cout << "\nDanh sach rong...!";
        return;
    }
    for (int i = 3; i <= L.count; i++)
    {
        L.h[i] = L.h[i + 1];
    }
    L.count--;
}
void chenvitridautien(list &L)
{
    HANGHOA hh;
    hh = taoHH(2007, "phan", "hop", 3000, 15, 45000);
    for (int i = L.count; i >= 1; i--)
    {
        L.h[i + 1] = L.h[i];
    }
    L.h[1] = hh;
    L.count++;
}
void sapxep(list &L)
{
    for (int i = 0; i < L.count; i++)
    {
        for (int j = i + 1; j < L.count; j++)
        {
            if (L.h[j].thanhtien < L.h[j + 1].thanhtien)
            {
                swap(L.h[j], L.h[j + 1]);
            }
        }
    }
}
int main()
{
    list L;
    create(L);
    input(L);
    cout << "==Danh sach hang hoa" << endl;
    ht_danh_sach(L);
    cout << "==Danh sach hang hoa sau khi xoa" << endl;
    xoaHHthu3(L);
    ht_danh_sach(L);
    cout << "==Danh sach hang hoa sau khi chen" << endl;
    chenvitridautien(L);
    ht_danh_sach(L);
    cout << "==Danh sach hang hoa sau khi sap xep" << endl;
    sapxep(L);
    ht_danh_sach(L);
}