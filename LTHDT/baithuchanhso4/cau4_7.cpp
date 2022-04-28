#include <bits/stdc++.h>

using namespace std;
class DOANHNGHIEP;
class DATE{
    public:
    int d,m,y;
    void nhap();
    void xuat();
    friend void tongdoanhthu(DOANHNGHIEP *dn,int n);
    friend void suaDN(DOANHNGHIEP *&dn,int &n);
};
class DIACHI{
    public:
     char dienthoai[12];
     char phuong[30];
     char quan[30];
     char thanhpho[30];
     friend void xuatHANOI(DOANHNGHIEP *dn,int n);
     friend void suaDN(DOANHNGHIEP *&dn,int &n);
};
class DOANHNGHIEP{
    private:
       int maDN;
       char tenDN[20];
       DATE ngayTL;
       DIACHI diachi;
       char giamdoc[30];
       long doanhthu;
       int n;
    public:
       void nhap(){
           cout<<"nhap ma doanh nghiep: "; cin>>maDN;
           cout<<"nhap ten doanh nghiep: "; fflush(stdin);gets(tenDN);
           cout<<"nhap ngay thanh lap: "; cin>>ngayTL.d>>ngayTL.m>>ngayTL.y;
           cout<<"nhap so dien thoai: "; fflush(stdin);gets(diachi.dienthoai);
           cout<<"nhap phuong: "; fflush(stdin);gets(diachi.phuong);
           cout<<"nhap quan: "; fflush(stdin);gets(diachi.quan);
           cout<<"nhap thanh pho: "; fflush(stdin);gets(diachi.thanhpho);
           cout<<"nhap ten giam doc: "; fflush(stdin);gets(giamdoc);
           cout<<"nhap doanh thu: "; cin>>doanhthu;
       }
       void xuat(){
           cout<<setw(15)<<maDN<<setw(15)<<tenDN<<setw(15)<<ngayTL.d<<"/"<<ngayTL.m<<"/"<<ngayTL.y<<setw(15)<<diachi.thanhpho<<setw(15)<<giamdoc<<setw(15)<<doanhthu<<endl;
       }
       friend void xuatHANOI(DOANHNGHIEP *dn,int n);
       friend void tongdoanhthu(DOANHNGHIEP *dn,int n);
       friend void suaDN(DOANHNGHIEP *&dn,int &n);
       
};
void nhapds(DOANHNGHIEP *&dn, int &n){
    cout<<"nhap so luong doanh nghiep: "; cin>>n;
    dn= new DOANHNGHIEP[n];
    for(int i=0; i<n; i++){
               cout<<"nhap doanh nghiep thu "<<i+1<<endl;
               dn[i].nhap();
    }
}
void xuatds( DOANHNGHIEP *dn, int n){
    cout<<setw(15)<<"ma DN"<<setw(15)<<"ten DN"<<setw(15)<<"ngay tl"<<setw(20)<<"thanh pho"<<setw(15)<<"ten giam doc"<<setw(15)<<"doanh thu"<<endl;
    for(int i=0; i<n; i++){
        dn[i].xuat();
    }
}
void xuatHANOI(DOANHNGHIEP *dn, int n){
    cout<<"\n--------Danh sach doanh nghiep o HA NOI-------\n"<<endl; 
    cout<<setw(15)<<"ma DN"<<setw(15)<<"ten DN"<<setw(15)<<"ngay tl"<<setw(20)<<"thanh pho"<<setw(15)<<"ten giam doc"<<setw(15)<<"doanh thu"<<endl;
    for(int i=0;i<n;i++){
        if (strcmp(dn[i].diachi.thanhpho,"ha noi")==0){
            dn[i].xuat();
        }
    }
}
void tongdoanhthu(DOANHNGHIEP *dn,int n){
    for(int i=0;i<n;i++){
        int tong =0 ;
        if(dn[i].ngayTL.y==2015){
            tong += dn[i].doanhthu;
        }
        cout<<"tong doanh thu 2015: "<<tong<<endl;
    }
}
void suaDN(DOANHNGHIEP *&dn,int &n){
    int s;
    cout<<"nhap ma doanh nghiep muon sua: "; cin>>s;
    for (int i=0;i<n;i++){
        if (dn[i].maDN == s){
            dn[i].nhap();
        }
    }
}
 int main(){
     DOANHNGHIEP *dn;
     int n;
     nhapds(dn,n);
     cout<<"\n\n------------danh sach doanh nghiep---------\n"<<endl;
     xuatds(dn,n);
     xuatHANOI(dn,n);
     tongdoanhthu(dn,n);
     cout<<"\n-----danh sach doanh nghiep moi-------"<<endl;
     suaDN(dn,n);
     xuatds(dn,n);
 }