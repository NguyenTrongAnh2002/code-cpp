#include <iostream>
#include <iomanip>

using namespace std;
class HANGDIENTU;
class DATE
{
protected:
    int d, m, y;
    friend class HANGDIENTU;
    friend void hangtrongluongthap(HANGDIENTU *h, int n);
};
class SANPHAM
{
    int msp;
    char tensp[20];
    DATE nsx;
    float trongluong;
    char mau[10];
    friend class HANGDIENTU;
    friend void hangtrongluongthap(HANGDIENTU *h, int n);
};
class HANGDIENTU : public SANPHAM
{
    float congsuat;
    char loaidongdien[10];

public:
    void nhap()
    {
        cout << "nhap ma san pham: ";
        cin >> msp;
        cout << "nhap ten san pham: ";
        fflush(stdin);
        gets(tensp);
        cout << "nhap ngay san xuat: ";
        cin >> nsx.d >> nsx.m >> nsx.y;
        cout << "nhap trong luong: ";
        cin >> trongluong;
        cout << "nhap mau: ";
        fflush(stdin);
        gets(mau);
        cout << "nhap cong suat: ";
        cin >> congsuat;
        cout << "nhap loai dong dien su dung: ";
        fflush(stdin);
        gets(loaidongdien);
    }
    void xuat()
    {
        cout << left << setw(15) << msp << setw(15) << tensp << setw(1) << nsx.d << "/" << nsx.m << "/" << nsx.y << setw(20) << trongluong << setw(15) << mau << setw(15) << congsuat << setw(15) << loaidongdien << endl;
    }
    friend void hangtrongluongthap(HANGDIENTU *h, int n);
};
void nhapds(HANGDIENTU *&h, int &n)
{
    cout << "----nhap danh sach------" << endl;
    cout << "nhap so luong hang dien tu: ";
    cin >> n;
    h = new HANGDIENTU[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin hang thu " << i + 1 << endl;
        h[i].nhap();
    }
}
void xuatds(HANGDIENTU *h, int n)
{
    cout << "------danh sach hang------" << endl;
    cout << left << setw(15) << "ma sp" << setw(15) << "ten sp" << setw(15) << "ngay san xuat" << setw(20) << "trong luong" << setw(15) << "mau" << setw(15) << "cong suat" << setw(15) << "loai dong dien" << endl;
    for (int i = 0; i < n; i++)
    {
        h[i].xuat();
    }
}
void hangtrongluongthap(HANGDIENTU *h, int n)
{
    cout << "\n ---hang co trong luong thap nhat-----" << endl;
    float min = h[0].trongluong;
    for (int i = 0; i < n; i++)
    {
        if (h[i].trongluong < min)
        {
            min = h[i].trongluong;
        }
        cout << left << setw(15) << "ma sp" << setw(15) << "ten sp" << setw(15) << "ngay san xuat" << setw(20) << "trong luong" << setw(15) << "mau" << setw(15) << "cong suat" << setw(15) << "loai dong dien" << endl;
        for (int i = 0; i < n; i++)
            if (h[i].trongluong == min)
            {
                h[i].xuat();
            }
    }
}
int main()
{
    HANGDIENTU *h;
    int n;
    nhapds(h, n);
    xuatds(h, n);
    hangtrongluongthap(h, n);
}