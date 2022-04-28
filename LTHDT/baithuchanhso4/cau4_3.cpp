#include <iostream>
#include <iomanip>

using namespace std;

class HANG;
class DATE{
    int d,m,y;
    friend class HANG;
    friend void xuat2017(HANG *h,int n);
};
class HANG{
    private:
       int mahang;
       char tenhang[20];
       DATE ngaysx;
    public:
       void nhap(){
           cout<<"nhap ma hang: "; cin>>mahang;
           cout<<"nhap ten hang: "; fflush(stdin);gets(tenhang);
           cout<<"nhap ngay san xuat: "; cin>>ngaysx.d>>ngaysx.m>>ngaysx.y;
       }
       void xuat(){
           cout<<left<<setw(15)<<mahang<<setw(15)<<tenhang<<setw(1)<<ngaysx.d<<"/"<<ngaysx.m<<"/"<<ngaysx.y<<endl;
       }
       friend void xuat2017(HANG *h,int n);
};
void nhapds(HANG *&h, int &n){
    cout<<"nhap so luong hang: "; cin>>n;
    h=new HANG[n];
    for(int i=0;i<n;i++){
        cout<<"nhap hang thu "<<i+1<<endl;
        h[i].nhap();
    }
}
void xuatds(HANG *h, int n){
    cout<<left<<setw(15)<<"ma hang"<<setw(15)<<"ten hang"<<setw(15)<<"ngay san xuat"<<endl;
    for(int i=0;i<n;i++){
        h[i].xuat();
    }
}
void xuat2017(HANG *h,int n){
    cout<<left<<setw(15)<<"ma hang"<<setw(15)<<"ten hang"<<setw(15)<<"ngay san xuat"<<endl;
    for(int i=0;i<n;i++){
        if(h[i].ngaysx.y==2017){
            h[i].xuat();
        }
    }
}
int main(){
    HANG *h;
    int n;
    cout<<"\n\n------nhap thong tin------"<<endl;
    nhapds(h,n);
    cout<<"\n\n------danh sach hang--------"<<endl;
    xuatds(h,n);
    cout<<"\n\n-------danh sach hang 2017------"<<endl;
    xuat2017(h,n);
}