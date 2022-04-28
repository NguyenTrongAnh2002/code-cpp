#include <iostream>
#include <iomanip>

using namespace std;

class QUANLY{
    private:
       int maql;
       char hoten[20];
    public:
       void nhap();
       void xuat();
};
class MAY{
    private:
       int mamay;
       char kieumay[10];
       char tinhtrang[20];
    public:
       void nhap();
       void xuat();
};
class PHONGMAY{
    private:
       int maphong;
       char tenphong[20];
       float dientich;
       QUANLY x;
       MAY y[20];
       int n;
    public:
       void nhap();
       void xuat();
};
void QUANLY::nhap(){
    cout<<"nhap ma quan ly: ";cin>>maql;
    cout<<"nhap ten quan ly: ";fflush(stdin);gets(hoten);
}
void QUANLY::xuat(){
    cout<<"ma quan ly: "<<maql<<endl;
    cout<<"ten quan ly: "<<hoten<<endl;
}
void MAY::nhap(){
    cout<<"nhap ma may: ";cin>>mamay;
    cout<<"nhap kieu may: ";fflush(stdin);gets(kieumay);
    cout<<"nhap tinh trang may: ";fflush(stdin);gets(tinhtrang);
}
void MAY::xuat(){
    cout<<left<<setw(15)<<mamay<<setw(15)<<kieumay<<setw(15)<<tinhtrang<<endl;
}
void PHONGMAY::nhap(){
    x.nhap();
    cout<<"nhap ma phong: ";cin>>maphong;
    cout<<"nhap ten phong: ";fflush(stdin);gets(tenphong);
    cout<<"nhap dien tich phong: ";cin>>dientich;
    cout<<"nhap so luong may: ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"nhap may thu "<<i+1<<endl;
        y[i].nhap();
    }
}
void PHONGMAY::xuat(){
    x.xuat();
    cout<<"ma phong: "<<maphong<<endl;
    cout<<"ten phong: "<<tenphong<<endl;
    cout<<"dien tich phong: "<<dientich<<" met vuong"<<endl;
    cout<<left<<setw(15)<<"ma may"<<setw(15)<<"kieu may"<<setw(15)<<"tinh trang"<<endl;
    for(int i=0;i<n;i++){
        y[i].xuat();
    }
}
int main(){
    PHONGMAY a;
    cout<<"\n\n\t---------nhap thong tin----------"<<endl;
    a.nhap();
    cout<<"\n\n\t----------danh sach----------"<<endl;
    a.xuat();
}