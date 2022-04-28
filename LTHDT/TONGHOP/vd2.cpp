#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class date
{
private:
	int d, m, y;

public:
	void nhap();
	void xuat();
};
class HS
{
private:
	char hoten[50];
	date ngsinh;
	char gioitinh[5];
	float dtb;

public:
	void nhap();
	void xuat();
};
void date::nhap()
{
	cout << "nhap ngay, thang, nam: ";
	cin >> d >> m >> y;
}
void date::xuat()
{
	cout << d << "/" << m << "/" << y << endl;
}
void HS::nhap()
{
	cout << "nhap ho ten HS: ";
	fflush(stdin);
	gets(hoten);
	cout << "nhap gioi tinh: ";
	fflush(stdin);
	gets(gioitinh);
	ngsinh.nhap();
	cout << "nhap diem tb: ";
	cin >> dtb;
}
void HS::xuat()
{
	cout << setw(5) << hoten << setw(10) << gioitinh << setw(20);
	ngsinh.xuat();
	cout << setw(10) << dtb;
}
int main()
{
	HS hs1;
	hs1.nhap();
	cout << setw(5) << "ho va ten" << setw(10) << "gioi tinh" << setw(20) << "ngay sinh" << setw(10) << "DTB" << endl;
	hs1.xuat();
}
