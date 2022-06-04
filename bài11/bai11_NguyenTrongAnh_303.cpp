#include <iostream>
#include <iomanip>
#include <string.h>
#define MAX 8

using namespace std;

struct SINHVIEN
{
    char maSV[10];
    char hodem[20];
    char ten[10];
    char gioitinh[10];
    int namsinh;
    float diemtongket;
    void taoSV(char *msv, char *hd, char *t, char *gt, int ns, float dtk)
    {
        strcpy(maSV, msv);
        strcpy(hodem, hd);
        strcpy(ten, t);
        strcpy(gioitinh, gt);
        namsinh = ns;
        diemtongket = dtk;
    }
};
struct vector
{
    int count;
    SINHVIEN sv[MAX];
};
void nhapds(vector &v)
{

    cout << "nhap so luong sinh vien: ";
    cin >> v.count;
    for (int i = 1; i <= v.count; i++)
    {
        cout << "\n\t-Nhap thong tin sinh vien thu " << i << endl;
        cout << "nhap ma sinh vien: ";
        fflush(stdin);
        gets(v.sv[i].maSV);
        cout << "nhap ho dem: ";
        fflush(stdin);
        gets(v.sv[i].hodem);
        cout << "nhap ten: ";
        fflush(stdin);
        gets(v.sv[i].ten);
        cout << "nhap gioi tinh: ";
        fflush(stdin);
        gets(v.sv[i].gioitinh);
        cout << "nhap nam sinh: ";
        cin >> v.sv[i].namsinh;
        cout << "nhap diem tong ket: ";
        cin >> v.sv[i].diemtongket;
    }
}
void hienthids(vector &v)
{
    cout << left << setw(10) << "STT" << setw(20) << "ma SV" << setw(20) << "ho dem" << setw(20) << "ten" << setw(20) << "gioi tinh" << setw(20) << "nam sinh" << setw(20) << "diem tong ket" << endl;
    for (int i = 1; i <= v.count; i++)
    {
        cout << left << setw(10) << i << setw(20) << v.sv[i].maSV << setw(20) << v.sv[i].hodem << setw(20) << v.sv[i].ten << setw(20) << v.sv[i].gioitinh << setw(20) << v.sv[i].namsinh << setw(20) << v.sv[i].diemtongket << endl;
    }
}
void xoa_pt_dau_tien(vector &v)
{
    if (v.count < 0)
    {
        cout << "\nDanh sach rong...!";
        return;
    }
    for (int i = 1; i <= v.count; i++)
    {
        v.sv[i - 1] = v.sv[i];
    }
    v.count--;
}
int insert(vector &v, int k, SINHVIEN X)
{
    if (k <= v.count + 1 && k > 0)
    {
        for (int i = v.count; i >= k - 1; i--)
            v.sv[i + 1] = v.sv[i];
        v.sv[k] = X;
        v.count++;
        return 1;
    }
    else
        return 0;
}
void chenSvVaoViTri3(vector &v)
{
    SINHVIEN chen;
    chen.taoSV("SV1006", "Le Thi", "Doan", "Nu", 1998, 7.6);
    if (insert(v, 3, chen))
    {
        cout << "\nChen thanh cong...!" << endl;
        cout << "\nDanh sach sau khi chen" << endl;
        hienthids(v);
    }
    else
    {
        cout << "\nChen khong thanh cong...!";
    }
}
void sapXepTheoTen(vector &v)
{
    int i, j, m;
    SINHVIEN tg;
    for (int i = 0; i < v.count; i++)
    {
        m = i;
        for (j = i + 1; j <= v.count; j++)
            if (strcmp(v.sv[j].ten, v.sv[m].ten) < 0)
                m = j;
        tg = v.sv[i];
        v.sv[i] = v.sv[m];
        v.sv[m] = tg;
    }
}
int main()
{
    vector v;
    nhapds(v);
    cout << "\n====DANH SACH SINH VIEN========" << endl;
    hienthids(v);
    cout << "\n====DANH SACH SINH VIEN SAU KHI XOA========" << endl;
    xoa_pt_dau_tien(v);
    hienthids(v);
    cout << "\n====DANH SACH SINH VIEN SAU KHI CHEN========" << endl;
    chenSvVaoViTri3(v);
    cout << "\n====DANH SACH SINH VIEN SAU KHI SAP XEP========" << endl;
    sapXepTheoTen(v);
    hienthids(v);
}