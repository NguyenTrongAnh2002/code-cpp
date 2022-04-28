#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class HocSinh
{
private:
	char hoten[30];
	int tuoi;
	char gioitinh[5];
	float dtoan, dhoa, dly;

public:
	HocSinh()
	{
		strcpy(hoten, "trong anh");
		tuoi = 19;
		dtoan = 9;
		dhoa = 9;
		dly = 9;
	}
	HocSinh(char *ht, int tuoi1, float t, float h, float l)
	{
		strcpy(hoten, ht);
		tuoi = tuoi1;
		dtoan = t;
		dhoa = h;
		dly = l;
	}
	void xuat()
	{
		cout << "ho ten: " << hoten << endl;
		cout << "tuoi: " << tuoi << endl;
		cout << "diem toan: " << dtoan << endl;
		cout << "diem ly : " << dly << endl;
		cout << "diem hoa: " << dhoa << endl;
	}
};

int main()
{
	HocSinh hs1, hs2("ngoc son", 19, 5, 5, 5);
	hs1.xuat();
	hs2.xuat();
}
