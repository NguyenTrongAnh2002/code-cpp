#include <iostream>

using namespace std;
class NSX{
	private:
		int maNSX;
		char tenNSX[20];
		char dcNSX[30];
	friend class Hang;
};
class Hang{
	private:
		int maH;
		char tenH[20];
		long dongia;
		char trongluong[10];
		NSX x;
	public:
		void nhap();
		void xuat();
};
void Hang::nhap(){
	cout<<"nhap ma hang: "; cin>>maH;
	cout<<"nhap ten hang: ";fflush(stdin);gets(tenH);
	cout<<"nhap don gia: "; cin>>dongia;
	cout<<"nhap trong luong: "; fflush(stdin);gets(trongluong);
	cout<<"nhap ma NSX: ";cin>>x.maNSX;
	cout<<"nhap ten NSX: ";fflush(stdin);gets(x.tenNSX);
	cout<<"nhap dia chi NSX: ";fflush(stdin);gets(x.dcNSX);
}
void Hang::xuat(){
	cout<<" ma hang: "<<maH<<endl;
	cout<<"ten hang: "<<tenH<<endl;
	cout<<"don gia: "<<dongia<<endl;
	cout<<"trong luong: "<<trongluong<<endl;
	cout<<"ma NSX: "<<x.maNSX<<endl;
	cout<<"ten NSX: "<<x.tenNSX<<endl;
	cout<<"dia chi NSX: "<<x.dcNSX<<endl;
}
int main(){
	Hang h;
	h.nhap();
	cout<<"--------thong tin in ra la----------"<<endl;
	h.xuat();
}
