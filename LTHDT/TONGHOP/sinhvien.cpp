#include <iostream>
#include <iomanip>

using namespace std;

class DATE{
	private:
		int d,m,y;
		friend class SinhVien;
};
class SinhVien{
	private:
		int maSV;
		char hoten[30];
		char gioitinh[10];
		char nganh[20];
		float diem;
		DATE a;
	public:
		void nhap();
		void xuat();
};
void SinhVien::nhap(){
	cout<<"nhap ma sinh vien: "; cin>>maSV;
	cout<<"nhap ho ten sinh vien: ";fflush(stdin);gets(hoten);
	cout<<"nhap ngay sinh: "; cin>> a.d >> a.m >> a.y ;
	cout<<"nhap gioi tinh: ";fflush(stdin);gets(gioitinh);
	cout<<"nhap nganh hoc: ";fflush(stdin);gets(nganh);
	cout<<"nhap diem: "; cin>>diem;
}
void SinhVien::xuat(){
	
		cout<<setw(5)<<maSV<<setw(10)<<hoten<<setw(9)<<a.d<<"/"<<a.m<<"/"<<a.y<<setw(10)<<gioitinh<<setw(15)<<nganh<<setw(15)<<diem<<endl;
	
}
int main(){
	SinhVien *sv;
	int n;
	cout<<"nhap so sinh vien: ";cin>>n;
	sv= new SinhVien[n];
	for(int i=0;i<n;i++){
		sv[i].nhap();
	}
	cout<<"thong tin cac sinh vien: "<<endl;
	cout<<setw(5)<<"ma sv"<<setw(10)<<"ho ten"<<setw(15)<<"ngay sinh"<<setw(15)<<"gioi tinh"<<setw(15)<<"nganh"<<setw(15)<<"diem"<<endl;
	for(int i=0;i<=n;i++){
		sv[i].xuat();
	}
}
