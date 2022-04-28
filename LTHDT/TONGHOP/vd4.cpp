#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class HH{
	private:
	   int maH;
	   char tenH[20];
	   long dongia;
	   int soluong;
    public:
    	void nhap();
    	void xuat();
    	long thanhtien(){
    		return soluong*dongia;
		}
};
class phieu{
	private:
		int maP;
		char tenkhach[50];
		char dienthoai[15];
		HH dsH[30];
		int n;
	public:
		void nhap();
		void xuat();
};
void HH::nhap(){
	cout<<"nhap ma hang: ";cin>>maH;
	cout<<"ten hang: ";fflush(stdin);gets(tenH);
	cout<<"nhap don gia: ";cin>>dongia;
	cout<<"nhap so luong: ";cin>>soluong;
}
void HH::xuat(){
	cout<<setw(3)<<maH<<setw(15)<<tenH<<setw(15)<<dongia<<setw(15)<<soluong<<setw(16)<<thanhtien()<<endl;	
}
void phieu::nhap(){
	cout<<"nhap ma phieu: ";cin>>maP;
	cout<<"nhap ten khach: ";fflush(stdin);gets(tenkhach);
	cout<<"nhap so dien thoai: ";fflush(stdin);gets(dienthoai);
	cout<<"nhap so luong hang: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"nhap hang hoa thu "<<i+1<<endl;
		dsH[i].nhap();
	}
}
void phieu::xuat(){
	cout<<"ma phieu: "<<maP<<endl;
	cout<<"ten khach hang"<<tenkhach<<endl;
	cout<<"dien thoai"<<dienthoai<<endl;
	cout<<"\nDanh sach hang hoa\n";
	cout<<setw(3)<<"ma hang"<<setw(15)<<"ten hang"<<setw(15)<<"don gia"<<setw(15)<<"so luong"<<setw(16)<<"thanh tien"<<endl;
	for(int i=0;i<n;i++){
		dsH[i].xuat();
	}
	long tong=0;
	for(int i=0;i<n;i++){
		tong+=dsH[i].thanhtien();
	}
	cout<<"\t\tTong thanh tien: \t\t\t"<<tong<<endl;
}
int main(){
	phieu p1;
	p1.nhap();
	cout<<setw(30)<<"phieu mua hang: \n";
	p1.xuat();
}


