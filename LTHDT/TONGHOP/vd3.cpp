#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class date{
	private :
		int d,m,y;
	public :
		void nhap();
		void xuat();
};
class NhanSu{
	private:
		char mans[20];
		char hoten[50];
		date NS;
	public:
		void nhap();
		void xuat();

};
void date::nhap(){
	cout<<"nhap ngay, thang, nam: ";
	cin>>d>>m>>y;
}
void date::xuat(){
	cout<<d<<"/"<<m<<"/"<<y<<endl;
}
void NhanSu::nhap(){
	cout<<"nhap ma ns: ";fflush(stdin);gets(mans);
	cout<<"nhap ho ten: ";fflush(stdin);gets(hoten);
	NS.nhap();	
}
void NhanSu::xuat(){
	cout<<setw(5)<<mans<<setw(20)<<hoten<<setw(10);
	NS.xuat();
}
int main(){
	NhanSu a;
	a.nhap();
	cout<<"thong tin nhan su vua nhap la: "<<endl;
	a.xuat();
}









