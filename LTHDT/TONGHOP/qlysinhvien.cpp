#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class SINHVIEN;
class DATE
{
    int d, m, y;
    friend class SINHVIEN;
    friend void themSV(SINHVIEN *&sv, int &n);
    friend void xoaSV(SINHVIEN *sv, int &n);
    friend void suaSV(SINHVIEN *&sv, int &n);
    friend void timSV(SINHVIEN *sv, int n);
};
class SINHVIEN
{
private:
    int maSV;
    char hoten[20];
    char quequan[30];
    DATE ngaysinh;

public:
    void nhap()
    {
        cout << "nhap ma sinh vien: ";
        cin >> maSV;
        cout << "nhap ten sinh vien: ";
        fflush(stdin);
        gets(hoten);
        cout << "nhap que quan: ";
        fflush(stdin);
        gets(quequan);
        cout << "nhap ngay sinh: ";
        cin >> ngaysinh.d >> ngaysinh.m >> ngaysinh.y;
    }
    void xuat()
    {
        cout << left << setw(20) << maSV << setw(25) << hoten << setw(15) << quequan << setw(15) << ngaysinh.d << "/" << ngaysinh.m << "/" << ngaysinh.y << endl;
    } // dòng 29 là để xuất thành 1 hàng ngang nhìn cho đẹp
    friend void xoaSV(SINHVIEN *sv, int &n);
    friend void suaSV(SINHVIEN *&sv, int &n);
    friend void timSV(SINHVIEN *sv, int n);
};
void nhapds(SINHVIEN *&sv, int &n)
{
    cout << "---------nhap danh sach sinh vien---------" << endl;
    cout << "nhap so luong sinh vien: ";
    cin >> n;
    sv = new SINHVIEN[n];
    for (int i = 0; i < n; i++)
    {
        cout << "sinh vien thu " << i + 1 << endl;
        sv[i].nhap();
    }
}
void xuatds(SINHVIEN *sv, int n)
{
    cout << left << setw(20) << "ma sinh vien" << setw(25) << "ho ten" << setw(15) << "que quan" << setw(15) << "ngay sinh" << endl;
    for (int i = 0; i < n; i++)
    {
        sv[i].xuat();
    }
}
void themSV(SINHVIEN *&sv, int &n)
{
    int k;
    SINHVIEN temp; // dòng 52 ,53 để tạo thêm 1 sinh viên muốn thêm
    temp.nhap();
    for (int i = n; i > k; i--)
    { // dòng 54,55 để lùi các phần tử 1 đơn vị
        sv[i] = sv[i - 1];
    }
    sv[k + 1] = temp; // gắn cái thông tin sv mới vào cái mình cấp thêm
    n++;              // cấp thêm 1 ô trống
}
void xoaSV(SINHVIEN *sv, int &n)
{
    int x;
    cout << "nhap ma sinh vien muon xoa: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].maSV == x)
        {
            for (int j = i; j < n - 1; j++)
            {
                sv[j] = sv[j + 1];
                n--;
                i--;
            }
        }
    }
}
void suaSV(SINHVIEN *&sv, int &n)
{
    int s;
    cout << "nhap ma sinh vien muon sua: ";
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].maSV == s)
        {
            sv[i].nhap();
        }
    }
}
void timSV(SINHVIEN *sv, int n)
{
    char t[20];
    cout << " nhap ho ten sinh vien muon tim: ";
    fflush(stdin);
    gets(t);
    cout << endl;
    cout << left << setw(20) << "ma sinh vien" << setw(25) << "ho ten" << setw(15) << "que quan" << setw(15) << "ngay sinh" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(sv[i].hoten, t) == 0)
        { // câu lệnh so sánh 2 chuỗi
            sv[i].xuat();
        }
    }
}
int main()
{
    SINHVIEN *sv;
    int n;
    do
    {
        cout << "\n======CHUONG TRINH quan ly sinh vien=======" << endl;
        cout << "Chon 1 chuc nang" << endl;
        cout << "\t1. xuat danh sach sinh vien" << endl;
        cout << "\t2. them thong tin sinh vien" << endl;
        cout << "\t3. xoa thong tin sinh vien" << endl;
        cout << "\t4. sua thong tin sinh vien" << endl;
        cout << "\t5. tim kiem sinh vien" << endl;
        cout << "\t0. Thoat chuong trinh" << endl;
        int chon;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 2:
            themSV(sv, n);
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 3:
            xoaSV(sv, n);
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 4:
            suaSV(sv, n);
            cout << "\n-----danh sach sinh vien------" << endl;
            xuatds(sv, n);
            break;
        case 5:
            cout << "\n-----danh sach sinh vien------" << endl;
            timSV(sv, n);
            break;
        case 0:
            cout << "Da dong ung dung" << endl;
            return 0;
        default:
            cout << "Lua chon khong hop le" << endl;
        }
    } while (true);
}
